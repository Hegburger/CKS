#include"input.h"
#include"common.h"
#include"verify.h"
#include"mouse.h"
/*
主界面
彭减
*/
void screen(char *user_idcard);
int page_screen(char*user_idcard);
int page_screen(char *user_idcard)
{
	int height=40;
	int longer=60;
	int y=30;
	int i;
	clrmous(MouseX,MouseY);
	delay(100);
	cleardevice();
	screen(user_idcard);
	save_bk_mou(MouseX,MouseY);
	while(1)
	{
		mou_pos(&MouseX,&MouseY,&press);
		if(mouse_press(595,0,640,45)==1)//退出键 
		{
			closegraph();
			delay(1000);
			exit(0);
		}
		//转接其他界面
		if(mouse_press(50+50,440,50+longer+50,440+height)==1)//报案界面
		{
			return 4;
		}
		if(mouse_press(50+50+longer+40,440,50+50+longer*2+40,440+height)==1)//历史界面
		{
			return 5;
		}
		if(mouse_press(50+50+longer*2+40*2,440,50+50+longer*3+40*2,440+height)==1)//个人界面
		{
		    return 6;
		}
		if(mouse_press(300,360,380,400)==1)//地图界面
		{
			return 8;
		}
        if(mouse_press(50+50+longer*3+40*3,440,50+50+longer*4+40*3,440+height)==1){
            //反馈
            return 9;
        }
	}
}
void screen(char *user_idcard)
{
	FILE *fp;
	char accident_type[20];
	int height=40;
	int longer=60;
	int y=30;
	int i;
    AccidentInfo incident;
    int current_row = 0;
    int display_y;
	setbkcolor(WHITE);
	//退出键
	setcolor(LIGHTGRAY);
	setlinestyle(DOTTED_LINE,0,NORM_WIDTH);
	rectangle(595,0,640,45);
    setlinestyle(SOLID_LINE,0,THICK_WIDTH);
    line(595,0,640,45);
    line(640,0,595,45);
    //事故公告
    puthz(250,12,"事故公告",32,32,LIGHTGRAY);
    //公告通知
    puthz(50,30+12+y,"事故时间",24,24,LIGHTGRAY);
    puthz(50+250,30+y+12,"事故类型",24,24,LIGHTGRAY);
    puthz(50+250*2-40,30+y+12,"处理状态",24,24,LIGHTGRAY);
    //地图按钮
    puthz(50,360+12,"在地图中查看更多",24,24,LIGHTGRAY);
    setfillstyle(SOLID_FILL,GREEN);
    bar(300,360,380,400);
    puthz(300+25,360+12,"地图",24,24,WHITE);
    //更多信息按钮
    setfillstyle(SOLID_FILL,BLUE);
    bar(50+50,440,50+longer+50,440+height);
    bar(50+50+longer+40,440,50+50+longer*2+40,440+height);
    bar(50+50+longer*2+40*2,440,50+50+longer*3+40*2,440+height);
    bar(50+50+longer*3+40*3,440,50+50+longer*4+40*3,440+height);
    puthz(50+50,440+8,"报案",24,24,WHITE);
    puthz(50+50+longer+40,440+8,"历史",24,24,WHITE);
    puthz(50+50+longer*2+40*2,440+8,"个人",24,24,WHITE);
    puthz(50+50+longer*3+40*3,440+8,"反馈",24,24,WHITE);
    // 打开二进制事故数据文件
    fp = fopen("ACCIDENT.dat", "rb");
    if (fp == NULL) {
        puthz(50, 300, "无事故公告！",16,16,RED);
        getch();
        closegraph();
        return;
    }


    // 遍历文件中的所有事故记录
    while (fread(&incident, sizeof(AccidentInfo), 1, fp) == 1) {
        // 检查是否为该用户的记录（匹配身份证）
        if (strcmp(incident.per1_idcard, user_idcard) == 0 ||
            strcmp(incident.per2_idcard, user_idcard) == 0) {
            current_row++;
            display_y = 30+y+12 + current_row * y;
            // 显示事故发生时间
            settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
            outtextxy(20, display_y+5, incident.time);
            // 显示事故类型（转换为文字描述）
            //puthz(col_type, display_y, "事故类型",16,16,GRAY);
            accident_type_trans(incident.accident_type,accident_type);
            puthz(300, display_y,accident_type,24,24,LIGHTGRAY);
            // 显示处理状态，这里默认显示“已处理”
            if(incident.processed_status=='1')
            {
                puthz(50+250*2, display_y, "已处理",24,24,LIGHTGRAY);	
			}
			else 
			{
	            puthz(50+250*2, display_y, "未处理",24,24,LIGHTGRAY);
			}
        }
    }
    fclose(fp);

    // 如果未找到任何记录，则显示提示信息
    if (current_row == 0) {
        puthz(50, 30+y+12+y, "没有找到相关记录",24,24,LIGHTGRAY);
    }

}











