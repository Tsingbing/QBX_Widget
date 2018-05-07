#include "demo_detect_track.h"


using namespace cv;
using namespace std;

static const string fomaskfile = "./Resources/data/fomask0.jpg";
static const string backmaskfile = "./Resources/data/backmask0.jpg";
static const string videofile = "./Resources/data/src0.mp4";
static const int target_w = 128;
static const int target_h = 64;

#define DEBUG

RobotTracker::RobotTracker() {
	tracker = Tracker::create("KCF");
}


bool EclipseDetector::boundaryCheck(Rect2d &src, Rect2d &dst, const Mat &frame) {
	bool state = true;
	if (src.x < 0) {
		dst.x = 0;
		state = false;
	}
	else if (src.width + src.x >= frame.cols) {
		dst.x = frame.cols - 1 - src.width;
		state = false;
	}
	else {
		dst.x = src.x;
	}

	if (src.y < 0) {
		dst.y = 0;
		state = false;
	}
	else if (src.height + src.y >= frame.rows) {
		dst.y = frame.rows - 1 - src.height;
		state = false;
	}
	else {
		dst.y = src.y;
	}

	if (src.width <= 0) {
		dst.width = target_w;
		state = false;
	}
	else {
		dst.width = src.width;
	}
	if (src.height <= 0) {
		dst.height = target_h;
		state = false;
	}
	else {
		dst.height = src.height;
	}
	return state;
}

EclipseDetector::EclipseDetector() {
	fomask = imread(fomaskfile);
	backmask = imread(backmaskfile);
	element = getStructuringElement(MORPH_RECT, Size(3, 3), Point(-1, -1));
	res = Mat::zeros(fomask.size(), CV_8UC3);
}

bool EclipseDetector::detectTracker(Mat & src) {
	if ((src.cols <= 0) || (src.rows <= 0) || (src.empty()))
		return false;
	Mat input_image;
	src.copyTo(input_image);
	output_mask = Mat::zeros(input_image.size(), CV_8UC1);
	cvtColor(input_image, ycrcb_image, CV_BGR2YCrCb);

	frameHitCount = 0;

	for (int i = 0; i < input_image.rows; i++)
	{
		uchar* p = (uchar*)output_mask.ptr<uchar>(i);
		Vec3b* ycrcb = (Vec3b*)ycrcb_image.ptr<Vec3b>(i);
		for (int j = 0; j < input_image.cols; j++)
		{
			if (fomask.at<Vec3b>(ycrcb[j][2], ycrcb[j][1])[0] > 0)
				p[j] = 255;
			if (backmask.at<Vec3b>(ycrcb[j][2], ycrcb[j][1])[0] > 0)
				p[j] = 0;
			if (p[j] == 255)
				frameHitCount++;
		}
	}
	//imshow("output_mask", output_mask);
	if (frameHitCount < 4) {
		cout << "did not target" << endl;
		return false;
	}
	else {
		return true;
	}
}

Rect2d EclipseDetector::detectAll(const Mat & src) {
	src.copyTo(input_image);
	output_mask = Mat::zeros(input_image.size(), CV_8UC1);
	cvtColor(input_image, ycrcb_image, CV_BGR2YCrCb);

	for (int i = 0; i < input_image.rows; i++)
	{
		uchar* p = (uchar*)output_mask.ptr<uchar>(i);
		Vec3b* ycrcb = (Vec3b*)ycrcb_image.ptr<Vec3b>(i);
		for (int j = 0; j < input_image.cols; j++)
		{
			if (fomask.at<Vec3b>(ycrcb[j][2], ycrcb[j][1])[0] > 0)
				p[j] = 255;
			if (backmask.at<Vec3b>(ycrcb[j][2], ycrcb[j][1])[0] > 0)
				p[j] = 0;
		}
	}
	morphologyEx(output_mask, output_mask, MORPH_CLOSE, element);

	vector< vector<Point> > contours;
	vector< vector<Point> > filterContours;
	vector< Vec4i > hierarchy;

	contours.clear();
	hierarchy.clear();
	filterContours.clear();
	findContours(output_mask, contours, hierarchy, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE);
	// È¥³ýÎ±ÂÖÀª 

	for (size_t i = 0; i < contours.size(); i++)
	{
		if (fabs(contourArea(Mat(contours[i]))) > 20/*&&fabs(arcLength(Mat(contours[i]),true))<2000*/)
			filterContours.push_back(contours[i]);
	}
	output_mask.setTo(0);
	drawContours(output_mask, filterContours, -1, Scalar(255, 0, 0), CV_FILLED); //8, hierarchy);   
	input_image.copyTo(output_image, output_mask);

	contours.clear();
	hierarchy.clear();
	cvtColor(output_image, output_image, CV_BGR2GRAY);
	threshold(output_image, threshold_output, thresh, 255, THRESH_BINARY);
	findContours(threshold_output, contours, hierarchy, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE, Point(0, 0));
	vector<vector<Point> > contours_poly(contours.size());
	vector<Rect> boundRect(contours.size());
	vector<Point2f>center(contours.size());
	vector<float>radius(contours.size());
	RNG rng(12345);

	for (int i = 0; i < contours.size(); i++) {
		approxPolyDP(Mat(contours[i]), contours_poly[i], 3, true);
		minEnclosingCircle(contours_poly[i], center[i], radius[i]);
	}
	Mat drawing = Mat::zeros(threshold_output.size(), CV_8UC3);
	int i_count = 0;
	float max_count = 0;
	if (radius.size() > 0)
		max_count = radius[0];
	if (radius.size() > 1) {
		for (int i = 0; i < radius.size() - 1; i++) {
			if (radius[i] < radius[i + 1]) {
				i_count = i + 1;
				max_count = radius[i + 1];
			}
		}
	}
	if (radius.size() > 0) {
		circle(input_image, center[i_count], 1, Scalar(0), 2, 8, 0);
		circle(input_image, center[i_count], (int)radius[i_count], Scalar(0), 2, 8, 0);
	}
	//imshow("drawing", input_image);
	output_image.setTo(0);
	//imshow("res", res);
	Rect2d rect2d, res2d;
	if (center.size() > 0) {
		rect2d.x = center[i_count].x - target_w / 2;
		rect2d.y = center[i_count].y - target_h / 2;
	}
	else {
		rect2d.x = -1;
		rect2d.y = -1;
	}
	rect2d.width = target_w;
	rect2d.height = target_h;
	return rect2d;
}


int ImageProcessing::robotTrackDetect(VideoCapture &cap) {
	//Mat frame;
	//RobotTracker robotTracker;
	//EclipseDetector epdetect;
	//cap >> frame;

	//Rect2d detectRes = epdetect.detectAll(frame);

	////VideoWriter writer("./result_detect_track.avi", CV_FOURCC('M', 'J', 'P', 'G'), 25.0, frame.size());
	//if (epdetect.boundaryCheck(detectRes, robotTracker.detectMask, frame)) {
	//	robotTracker.roi = detectRes;
	//}
	//else {
	//	cout << "could not target the original roi ,please DIY" << endl;
	//	robotTracker.roi = selectROI("tracker", frame);
	//}
	////cout << "roi" << roi << endl;
	//if (robotTracker.roi.width == 0 || robotTracker.roi.height == 0)
	//	return 0;
	//robotTracker.tracker->init(frame, robotTracker.roi);
	robotTrackInit(cap);

	for (;;) {
		cap >> frame;
		if (frame.empty())
			break;
		if (frame.rows == 0 || frame.cols == 0)
			break;
#ifdef DEBUG
		double t = (double)cvGetTickCount();
#endif

		epdetect.boundaryCheck(robotTracker.roi, robotTracker.detectMask, frame);
		robotTracker.roi = robotTracker.detectMask;


		robotTracker.tracker->update(frame, robotTracker.roi);
		

		bool check = epdetect.boundaryCheck(robotTracker.roi, robotTracker.detectMask, frame);
		//cout << "detectMask" << robotTracker.detectMask << endl;
		
		if (!check) {
			epdetect.frameLostCount++;
			epdetect.frameLoseCount++;
		}
		else {
			robotTracker.roi = robotTracker.detectMask;
			if (!epdetect.detectTracker(Mat(frame, robotTracker.detectMask))) {
				epdetect.frameLostCount++;
				epdetect.frameLoseCount++;
			}
		}
		if (epdetect.frameLostCount > 4) {
			epdetect.frameLostCount = 0;
			Rect2d rect2d = epdetect.detectAll(frame);
			if (epdetect.boundaryCheck(rect2d, robotTracker.detectMask, frame)) {
				epdetect.frameLoseCount = 0;
				robotTracker.roi = robotTracker.detectMask;
				//	robotTracker.tracker->clear();
				//	robotTracker.tracker = Tracker::create("KCF");
				robotTracker.tracker->init(frame, robotTracker.roi);
				cout << "auto target successfully!" << endl;
			}
			else {
				cout << "lose target while could not detect!" << endl;
			}
		}
#ifdef DEBUG
		Mat drawing;
		frame.copyTo(drawing);
		//	if (epdetect.frameLoseCount < 7) {	
		rectangle(drawing, robotTracker.roi, Scalar(255, 0, 0), 2, 1);
		cout << robotTracker.roi << endl;
		
		//	}
#endif
		imshow("tracker", drawing);
#ifdef DEBUG
	//	t = (double)cvGetTickCount() - t;
		//printf("run time = %gms\n", t / (cvGetTickFrequency() * 1000));
		//writer << drawing;
#endif
		if (waitKey(1) == 27)
			break;
	}
	return 0;
}

int ImageProcessing::robotTrackInit(VideoCapture &cap)
{
	//Mat frame;
	//RobotTracker robotTracker;
	//EclipseDetector epdetect;
	cap >> frame;

	Rect2d detectRes = epdetect.detectAll(frame);

	//VideoWriter writer("./result_detect_track.avi", CV_FOURCC('M', 'J', 'P', 'G'), 25.0, frame.size());
	if (epdetect.boundaryCheck(detectRes, robotTracker.detectMask, frame)) {
		robotTracker.roi = detectRes;
	}
	else {
		cout << "could not target the original roi ,please DIY" << endl;
		robotTracker.roi = selectROI("tracker", frame);
	}
	//cout << "roi" << roi << endl;
	if (robotTracker.roi.width == 0 || robotTracker.roi.height == 0)
		return 0;
	robotTracker.tracker->init(frame, robotTracker.roi);

}

Mat ImageProcessing::robotTrackDetect1(Mat frame) {
	//Mat frame;
	//RobotTracker robotTracker;
	//EclipseDetector epdetect;
	
	//for (;;) {
		//cap >> frame;
		//if (frame.empty())
		//	break;
		//if (frame.rows == 0 || frame.cols == 0)
		//	break;
#ifdef DEBUG
		double t = (double)cvGetTickCount();
#endif

		epdetect.boundaryCheck(robotTracker.roi, robotTracker.detectMask, frame);
		robotTracker.roi = robotTracker.detectMask;


		robotTracker.tracker->update(frame, robotTracker.roi);


		bool check = epdetect.boundaryCheck(robotTracker.roi, robotTracker.detectMask, frame);
		//cout << "detectMask" << robotTracker.detectMask << endl;

		if (!check) {
			epdetect.frameLostCount++;
			epdetect.frameLoseCount++;
		}
		else {
			robotTracker.roi = robotTracker.detectMask;
			if (!epdetect.detectTracker(Mat(frame, robotTracker.detectMask))) {
				epdetect.frameLostCount++;
				epdetect.frameLoseCount++;
			}
		}
		if (epdetect.frameLostCount > 4) {
			epdetect.frameLostCount = 0;
			Rect2d rect2d = epdetect.detectAll(frame);
			if (epdetect.boundaryCheck(rect2d, robotTracker.detectMask, frame)) {
				epdetect.frameLoseCount = 0;
				robotTracker.roi = robotTracker.detectMask;
				//	robotTracker.tracker->clear();
				//	robotTracker.tracker = Tracker::create("KCF");
				robotTracker.tracker->init(frame, robotTracker.roi);
				cout << "auto target successfully!" << endl;
			}
			else {
				cout << "lose target while could not detect!" << endl;
			}
		}
#ifdef DEBUG
		Mat drawing;
		frame.copyTo(drawing);
		//	if (epdetect.frameLoseCount < 7) {	
		rectangle(drawing, robotTracker.roi, Scalar(255, 0, 0), 2, 1);
		cout << robotTracker.roi << endl;

		//	}
#endif
		//imshow("tracker", drawing);
#ifdef DEBUG
		//	t = (double)cvGetTickCount() - t;
		//printf("run time = %gms\n", t / (cvGetTickFrequency() * 1000));
		//writer << drawing;
#endif
		//if (waitKey(1) == 27)
		//	break;
	//}
	return drawing;
}

//int main() {
	//string video = ;
//	VideoCapture cap(0);
//	robotTrackDetect(cap);
//	return 0;
//}

ImageProcessing::ImageProcessing()
{
}

ImageProcessing::~ImageProcessing()
{
}
