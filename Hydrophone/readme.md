#### 2018.5.10.15.43

#### 需求
- 实现水听器32G数据的频谱解析显示


#### 设计
- 使用串口射频
  - 水声采集卡开/关
  - 发送开启或结束获取命令
- 使用WIFI网卡
  - 返回32G频谱数据，PC端作服务端，下位机作客户端。
- 下位机结构体设计
>> ```
>>    typedef struct
>>    {
>>    	quint8 RorWCro; 	        //开始读所有数据，并清空缓存R:0  W:1  clear：2 NO:0XFF
>>    	quint8 GetFS;	 	        //水听器频谱数据控制  开启或结束获取，开启。触发一次并返回频谱 
>>    }Data_SOUNDCONTROL_TypeDef;
>>    
>>    typedef struct
>>    {
>>    	unsigned char FScode[250];  //512点fft 
>>    }Data_SOUNDFSACK_TypeDef;
>>    
>>    typedef struct
>>    {
>>    	unsigned char EnOrDisEN;	//ENABLE	DISABLE
>>    	long long	cnt;            //包长度 计数 
>>    }Data_SOUNDAck_TypeDef;
>>
>> ```