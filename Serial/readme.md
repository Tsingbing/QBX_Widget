##### 2018.5.8.15.38

#### 挣球计划表
| 名称      | 说明      | 未做 | 危险  |进行中| 测试 | 完成 |
| ------    |   :----:  |:----:|:----: |:----:|:----:|:----:|
|接口建立   | 用户接口  |   *  |       |      |      |      |
|需求确认   |           |      |       |      |    * |      |
|bug_01     |           |      |       |   *  |      |      |
|bug_02     | 结构体对齐|      |       |      |      |   *  |
|bug_03     |           |      |       |      |      |   *  |
|bug_04     |   cmd     |      |       |      |      |   *  |

#### 需求
* 协议的自定义，帧的格式。
* 显示返回状态信息。
* [QT串口接收十六进制数据在文本框中显示](https://blog.csdn.net/wingWC/article/details/72842504)
#### 设计
* 使用线程来编写
* 参考Qt示例
* [序列化和反序列化](https://blog.csdn.net/yj540993866/article/details/48367139)
* [QByteArray](http://doc.qt.io/qt-5.9/qbytearray.html)::fromHex("000c0dfffe")
* QByteArray::fromRawData((char*)&sData, sData.PackageLength)
* [互斥量、条件变量与pthread_cond_wait()函数的使用](https://www.cnblogs.com/cyyljw/p/7015774.html)
#### 建立接口
* 发送消息
* 接收消息
* 处理消息 

#### 附件协议
* shark协议表.xlsx

#### 文件说明
- MasterThread为串口线程。
  - 等待响应的时候，用线程，而不用sleep。  
- qbx_serial为用户接口，UI界面调用。
#### bug
- bug_02 结构体对齐导致数据不准。
  - 添加 #pragma pack(4) ... pragma pack()
- bug_03 读取QByteArray的char值 为0x00AA，无法做包头包尾判断。
- bug_04 setRequestData 和 getResponseData无法做出CMD跳转判断。_

#### 主要代码
```
QByteArray requestData;
//requestData.resize(sizeof(sData));
requestData[0] = 0xAA;
requestData[1] = sizeof(DataMove) + 6;
requestData[2] = 0xFE;
requestData[3] = 0x01;
requestData[4] = 0x00;
requestData += Code;
requestData += 0xBB;
```