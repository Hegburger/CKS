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
	char description1[17];
	char description2[17];
	char description3[17];
	char description4[17];
	//Ӱ������
	char factor1[20];
	char factor2[20];
	char factor3[20];
	//���ն���
	char final_per1_duty[11];
	char final_per2_duty[11];
	char final_money[20];
	//�ͷ�����
	char final_punish[13];
	//�ͷ�ʱ��
	char final_time[11];
	//����λ
	char final_log[13];
}Judge;
#endif
