#### 2018.5.14.10.11
#### 需求
- 通过摇杆，给下位机发送油门、航线角、上浮，下潜等数据。
- 下载3D游戏，体验摇杆操作，熟悉操作杆的作用。
#### 设计
#### 实现
- [开源代码地址](https://github.com/qbingx/JoyTest)
- SDL不直接关注硬件屏幕，而是关注每个平台下的屏幕驱动程序。比如window下的DirectX,linux下的x11 ,以及android下的opengl es。
- DirectInput和其他DirectX组成部分一样，是通过硬件抽象层（HAL）和硬件仿真层（HEL）来实现。
#### 测试
#### bug
- 只能在release下运行，因为SDL.dll只有release版的，并没有debug版的。可以自己根据源代码生成。
- qt调用Dxinput相关库失败，查询很久，不知原因，可建立Qt调用DX库的项目工程。