#### 2018.5.10.15.43

#### ����
- ʵ��ˮ����32G���ݵ�Ƶ�׽�����ʾ


#### ���
- ʹ�ô�����Ƶ
  - ˮ���ɼ�����/��
  - ���Ϳ����������ȡ����
- ʹ��WIFI����
  - ����32GƵ�����ݣ�PC��������ˣ���λ�����ͻ��ˡ�
- ��λ���ṹ�����
>> ```
>>    typedef struct
>>    {
>>    	quint8 RorWCro; 	        //��ʼ���������ݣ�����ջ���R:0  W:1  clear��2 NO:0XFF
>>    	quint8 GetFS;	 	        //ˮ����Ƶ�����ݿ���  �����������ȡ������������һ�β�����Ƶ�� 
>>    }Data_SOUNDCONTROL_TypeDef;
>>    
>>    typedef struct
>>    {
>>    	unsigned char FScode[250];  //512��fft 
>>    }Data_SOUNDFSACK_TypeDef;
>>    
>>    typedef struct
>>    {
>>    	unsigned char EnOrDisEN;	//ENABLE	DISABLE
>>    	long long	cnt;            //������ ���� 
>>    }Data_SOUNDAck_TypeDef;
>>
>> ```