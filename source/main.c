#include"common.h"
/****
function:main函数，主循环所�?
author:Chengkai Huang
*****/
void main(){
    //初始�?
    int page = 1;//页面索引
    //图形初始�?
    int graphdriver = VGA;
    int	graphmode = VGAHI;

    initgraph(&graphdriver, &graphmode, "BGI");
	//鼠标的初始化
	mouseinit();
    //主循�?
    while(1)
	{
		switch(page)
		{   
            case 0://退出程�?
				closegraph();//关闭画图
				delay(1000);
			    exit(0);//退出程�?
                break;
			case 1://注册页面
			    page = page_register();
				continue;;
			case 2://登录页面
				page = page_login();
				continue;
			case 3://��ҳ��

			case 4://����

			case 5://��ʷ
			history_indi();
			default:	
				closegraph();
				delay(1000);
			    exit(0);
				break;
		}
	}
}