#pragma once

#include <QWidget>
#define PackageMaxLength 256
#define PackageMinLength 7
#define PackageHead 0xAA
#define PackageTail 0xBB
#define MyID 0x00      //自身ID为0x01
#define SLAVEID 0x01 
#define SATCOMID 0x02
#define SONARID 0x03
#define RFID 0x04
#define UDPID 0x05

//////////////////////////////////////////////////////////////////////////////////
typedef struct
{
	quint8 Mode;  //0-only wing   1-only enrage   2-all
	quint8 PID_Heading_ENorDIS; //keep heaning
	quint8 PID_Deep_ENorDIS;    //keep pitch
	quint8 PID_Roll_ENorDIS;    //keep Roll
	short int  Speed;	   //速度0-100
	short int  heading;    //方向-100 - 100
	short int  pitch;	   //深度0 - 40
	short int  roll;       //侧倾运动控制 默认0度
}DATA_FREE_MOVE_TypeDef;
DATA_FREE_MOVE_TypeDef sDataFreeMove;

typedef struct
{
	quint8 Head;
	quint8 PackageLength;
	quint8 SendID;
	quint8 ReceivedID;
	quint8 Cmd;
	quint8 *Code;
	quint8 Tail;
}DataPackage_TypeDef;
DataPackage_TypeDef sData;