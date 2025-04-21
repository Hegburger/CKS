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
	char description1[19];
	char description2[19];
	char description3[19];
	char description4[19];
	//影响因素
	char factor1[13];
	char factor2[13];
	char factor3[13];
	//最终定罪
	char final_per1duty[11];
	char final_per2duty[11];
	char final_money[13];
	//惩罚类型
	char final_punish[13];
	//惩罚时间
	char final_time[11];
	//审理单位
	char final_log[13];
}Judge;
#endif
