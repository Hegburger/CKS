#include"mouse.h"
#include"input.h"
#include"verify.h"
#include"IMAGE.h"
#include"common.h"
#include"manage.h"
/*
彭减
事故的发生模拟
*/
int page_happen();
void happen_screen();

int page_happen()
{
	clrmous(MouseX,MouseY);
	delay(100);
	cleardevice();
	happen_screen();
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
		if(mouse_press(240,340,300,400)==1)//下一步
		{
			return 1;
		}
	}
}
void happen_screen()
{
	int i;
	int start_l=20;
	int start_r=640-20-180;
	int row=140;
	int location=320;
	setbkcolor(WHITE);
	//退出键
	setcolor(LIGHTGRAY);
	setlinestyle(DOTTED_LINE,0,NORM_WIDTH);
	rectangle(595,0,640,45);
    setlinestyle(SOLID_LINE,0,THICK_WIDTH);
    line(595,0,640,45);
    line(640,0,595,45);
    //标题
    puthz(220,10,"事故模拟发生",24,24,LIGHTGRAY);
    setfillstyle(SOLID_FILL,WHITE);
    //播放动画
    bmp_convert("C:\\PROJECT\\photo\\CAR1.bmp","C:\\PROJECT\\photo\\CAR1.dbm");
	bmp_convert("C:\\PROJECT\\photo\\CAR2.bmp","C:\\PROJECT\\photo\\CAR2.dbm");
    for(i=0;i<=60;i++)
    {
    	bar(0,row,700,row+160);
		show_dbm(start_l+i*2,row,"C:\\PROJECT\\photo\\CAR1.dbm",0);
		show_dbm(start_r-i*2,row,"C:\\PROJECT\\photo\\CAR2.dbm",0);
		delay(20);
	}
	bmp_convert("C:\\PROJECT\\photo\\BOOM.bmp","C:\\PROJECT\\photo\\BOOM.dbm");
	show_dbm(start_l+120,row,"C:\\PROJECT\\photo\\BOOM.dbm",0);
	puthz(220,315,"有一场事故发生了！",16,16,RED);
	delay(1000);
	setfillstyle(SOLID_FILL,GREEN);
	bar(240,340,340,400);
	puthz(250,350,"下一步",24,24,WHITE);
}
