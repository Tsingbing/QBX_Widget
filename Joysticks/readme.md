#### 2018.5.14.10.11
#### ����
- ͨ��ҡ�ˣ�����λ��������ʾ��б�ǡ������Ǻͼ��ٶȣ�ͬʱ����λ���������ݡ�

- ����3D��Ϸ������ҡ�˲�������Ϥ�����˵����á�
#### ���
- ���͸���λ�������ݽṹ�� 
   ```C
    typedef struct
    { /******�����Ƕȿ���������*****/
	    char  Speed;	//����100 //���Űٷֱ� ���������� 
	    char  Direction;//����100 //���� 
	    char  lightpower;//�豸�ƿ� 0-100 ���� 
	    char  Deepset;	//-100 ~ +100
	    char  Roll;    //�������  Ĭ�� 0�� 
	    char  Yaw;     //����  ENABLE:��ʼ����	DISABLE 
    }Data_MOVE_TypeDef;
  ```
- ��������joystick���󣬽�����ҡ�˺��Ƹˡ�
- ��ȷʹ��ģ����Ƹ�ä��.
  ``` C
    joystick->deadzone(i, (i != 2 && i != 5 ? 16000 : 0))
    joystick->bilinearEnable(true);
    joystick->bilinearConstant(1.25);
  ```

#### ʵ��
- [��Դ�����ַ](https://github.com/qbingx/JoyTest)
- SDL��ֱ�ӹ�עӲ����Ļ�����ǹ�עÿ��ƽ̨�µ���Ļ�������򡣱���window�µ�DirectX,linux�µ�x11 ,�Լ�android�µ�opengl es��
- DirectInput������DirectX��ɲ���һ������ͨ��Ӳ������㣨HAL����Ӳ������㣨HEL����ʵ�֡�
- ��������joystick���󣬷ֱ����������豸ID��
#### ����
#### bug
- ֻ����release�����У���ΪSDL.dllֻ��release��ģ���û��debug���(�޷�����)�������Լ�����Դ�������ɡ�
    - ����SDL2��debug�£�������SDL1��SDL2�ļ��������⣨ʱ����ȣ����������
- qt����Dxinput��ؿ�ʧ�ܣ���ѯ�ܾã���֪ԭ�򣬿ɽ���Qt����DX�����Ŀ���̣�ʱ����ȣ����������