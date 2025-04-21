#include"common.h"
/****
function:main鍑芥暟锛屼富寰幆鎵€鍦?
author:Chengkai Huang
*****/
void main(){
    //初始化
    int page = -1;//页面索引
    //图形初始化
    int graphdriver = VGA;
    int	graphmode = VGAHI;
    char user_phone_number[12];
	char user_id_card[20];
	user_id_card[0]=user_phone_number[0]='\0';
    initgraph(&graphdriver, &graphmode, "BGI");
	//鼠标的初始化
	mouseinit();
    //主循环
    while(1)
	{
		switch(page)
		{   
			case -1://开始动画
				page = page_happen();
				continue;
            case 0://退出程序
				closegraph();//关闭画图
				delay(1000);
			    exit(0);//退出程序
                break;

			case 1://注册页面
			    page = page_register();
				continue;;
			case 2://登录页面
				page = page_login(user_phone_number,user_id_card);
				continue;
			case 3://主界面
				page = page_screen(user_phone_number);
				continue;
			case 4://报案界面
				if(user_id_card[0]=='\0'){
					warning_screen();
					page = 3;
				}else{
					page = baoan(user_phone_number);
				}
				continue;
			case 5://历史界面
				if(user_id_card[0]=='\0'){
					warning_screen();
					page = 3;
				}else{
					page = history_indi(user_id_card);
				}
				continue;
			case 6://个人界面
				page = page_person(user_phone_number,user_id_card);
				continue;
			case 7://管理登录
				page = page_admin_login();
				continue;
			case 8://map
				page = page_map();
				continue;
			case 9://反馈
				page = page_feedback();
				continue;
			case 10://反馈感谢
				page = page_thanks();
				continue;
			case 11://管理员主界面
				page = page_manage();
				printf("%d",page);
				continue;
			// case 12://管理-未处理事故
			// 	page = record_manage(page);
			// 	continue;
			// case 13://管理-已处理事故
			// 	page = record_manage(page);
			// 	continue;
//			case 14://管理-已处理事故-事故信息查看
//				page = ;
//				continue;
//			case 15://管理-未处理事故-事故信息查看
//				page = ;
//				continue;
			// case 16://管理-未处理事故-取证
			// 	page = page_evidence();
			// 	continue;
//			case 17://管理-未处理事故-认定
//				page = record_manage();
//				continue;

			case 20:
				page = record_map(0);
				continue;
			case 21:
				page = record_map(1);
				continue;
			case 22:
				page = record_map(2);
				continue;
			case 23:
				page = record_map(3);
				continue;
			case 24:
				page = record_map(4);
				continue;
			case 25:
				page = record_map(5);
				continue;
			case 26:
				page = record_map(6);
				continue;
			case 27:
				page = record_map(7);
				continue;
			case 28:
				page = record_map(8);
				continue;
			default:	
				closegraph();
				delay(1000);
			    exit(0);
				break;
		}
	}
}
