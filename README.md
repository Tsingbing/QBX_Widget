﻿#### 开发环境
* Qt5.9.1 + msvc2015 + 64bit
* opencv3.2 + msvc2015 + 64bit
* 编译器 msvc2015 + 64bits

#### 文件说明
			 
| 文件夹名称 | 说明              | 未做 | 危险  |进行中| 测试 | 完成 |
| ---------- | :----:            |:----:|:----: |:----:|:----:|:----:|
|ALL         | 调用控件的集合    |      |       |   *   |      |      |
|INSTALL     | 程序打包          |   *    |       |      |      |      |
|Thread      | 线程              |      |       |   *    |      |      |
|Compass     | 航向仪            |      |       |      |   *    |      |
|Depth       | 深度仪            |      |       |      |   *    |      |
|Menu        | 菜单设置          |      |       |      |   *    |      |
|Video       | 视频处理控件      |      |       |      |   *    |      |
|Temperature | 温度仪            |      |       |      |   *    |      |
|MUI         | 倾斜角\俯仰角     |      |       |      |   *    |      |
|Voyage      | 航程总路程        |      |       |      |   *    |      |
|Serial      | 串口通信          |      |       |   *    |      |      |
|TCP         | 网络通信          |   *    |       |      |      |      |
|Power       | 电量显示          |      |       |   *    |      |      |
|OSG3D       | 3D仿真姿态显示    |   *    |       |      |      |      |
|Map         | 地图              |   *    |       |      |      |      |
|Plugin      | 插件系统          |   *    |       |      |      |      |
|Hydrophone  | 频谱图      |   *    |       |      |      |      |
|LaserScanning|3D图          |        |   *   |      |      |      |
|Welcome     | 启动界面          |   *    |       |      |      |      |
|Algorithms  | 算法集           |   *    |       |      |      |      |

* 每个文件夹内都readme.md,记录代码更新状态、版本信息和bug信息。
* 每个文件夹都是可执行的项目，都有测试代码。

#### API 设计规范
>参考 [Qt API设计原则](http://wiki.qt.io/API_Design_Principles)

>参考《C++ API设计规范》

>bug编号 qb-01
#### 测试主页面
-----

