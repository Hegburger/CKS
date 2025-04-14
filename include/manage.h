#ifndef _MANAGE_
#define _MANAGE_
//管理端账号个人信息
typedef struct{
	char username[15];//管理员用户名
	char password[20];//管理员密码
}Manager;
//管理员对于用户事故的评估
typedef struct{
	//评估
	char description1[17];
	char description2[17];
	char description3[17];
	char description4[17];
	//影响因素
	char factor1[20];
	char factor2[20];
	char factor3[20];
	//最终定罪
	char final_per1_duty[11];
	char final_per2_duty[11];
	char final_money[20];
	//惩罚类型
	char final_punish[13];
	//惩罚时间
	char final_time[11];
	//审理单位
	char final_log[13];
}Judge;
#endif
