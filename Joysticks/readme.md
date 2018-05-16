#### 2018.5.14.10.11
#### 需求
- 通过摇杆，在上位机界面显示倾斜角、俯仰角和加速度，同时向下位机发送数据。

- 下载3D游戏，体验摇杆操作，熟悉操作杆的作用。
#### 设计
- 发送给下位机的数据结构体 
   ```C
    typedef struct
    { /******方向或角度控制左负右正*****/
	    char  Speed;	//正负100 //油门百分比 负数代表反向 
	    char  Direction;//正负100 //油门 
	    char  lightpower;//设备灯控 0-100 亮度 
	    char  Deepset;	//-100 ~ +100
	    char  Roll;    //定侧倾角  默认 0度 
	    char  Yaw;     //定向  ENABLE:开始锁定	DISABLE 
    }Data_MOVE_TypeDef;
  ```
- 建立两个joystick对象，接入手摇杆和推杆。
- 正确使用模拟控制杆盲区.
  ``` C
    joystick->deadzone(i, (i != 2 && i != 5 ? 16000 : 0))
    joystick->bilinearEnable(true);
    joystick->bilinearConstant(1.25);
  ```

#### 实现
- [开源代码地址](https://github.com/qbingx/JoyTest)
- SDL不直接关注硬件屏幕，而是关注每个平台下的屏幕驱动程序。比如window下的DirectX,linux下的x11 ,以及android下的opengl es。
- DirectInput和其他DirectX组成部分一样，是通过硬件抽象层（HAL）和硬件仿真层（HEL）来实现。
- 建立两个joystick对象，分别连接两个设备ID。
#### 测试
#### bug
- 只能在release下运行，因为SDL.dll只有release版的，并没有debug版的(无法调试)。可以自己根据源代码生成。
    - 更换SDL2（debug下），出现SDL1和SDL2的兼容性问题（时间紧迫，待解决）。
- qt调用Dxinput相关库失败，查询很久，不知原因，可建立Qt调用DX库的项目工程（时间紧迫，待解决）。