#ifndef _MANAGE_
#define _MANAGE_
//������˺Ÿ�����Ϣ
typedef struct{
	char username[15];//����Ա�û���
	char password[20];//����Ա����
}Manager;
//����Ա�����û��¹ʵ�����
typedef struct{
	//����
	char description1[19];
	char description2[19];
	char description3[19];
	char description4[19];
	//Ӱ������
	char factor1[13];
	char factor2[13];
	char factor3[13];
	//���ն���
	char final_per1duty[11];
	char final_per2duty[11];
	char final_money[13];
	//�ͷ�����
	char final_punish[13];
	//�ͷ�ʱ��
	char final_time[11];
	//����λ
	char final_log[13];
}Judge;
#endif
