#pragma once
#include <opencv2/opencv.hpp>
#include <opencv2/tracking.hpp>

class RobotTracker {
public:
	RobotTracker();
	~RobotTracker() {}
	cv::Ptr<cv::Tracker> tracker;
	cv::Rect2d roi;
	cv::Rect2d detectMask;
};

class EclipseDetector {
public:
	EclipseDetector();
	~EclipseDetector() {}
	cv::Rect2d detectAll(const cv::Mat &src);
	bool EclipseDetector::detectTracker(cv::Mat & src);
	bool boundaryCheck(cv::Rect2d &src, cv::Rect2d &dst, const cv::Mat &frame);
	int frameLostCount = 0;
	int frameHitCount = 0;
	int frameLoseCount = 0;
protected:
	cv::Mat fomask, backmask, element, res;
	cv::Mat ycrcb_image, input_image, output_mask, output_image, mask;
	//std::vector< std::vector<cv::Point> > contours;   // 轮廓   
	//std::vector< std::vector<cv::Point> > filterContours; // 筛选后的轮廓
	//std::vector< cv::Vec4i > hierarchy;    // 轮廓的结构信息 
	cv::Mat threshold_output;
	const int thresh = 100;
	const int max_thresh = 255;
};

class ImageProcessing
{
public:
	ImageProcessing();
	~ImageProcessing();

	int robotTrackInit(cv::VideoCapture &cap);
	int robotTrackDetect(cv::VideoCapture &cap);
	cv::Mat robotTrackDetect1(cv::Mat frame);
private:
	cv::Mat frame;
	RobotTracker robotTracker;
	EclipseDetector epdetect;
};


//int robotTrackDetect(cv::VideoCapture &cap);
