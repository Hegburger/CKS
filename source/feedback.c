#include"common.h"
#include"IMAGE.h"
#include"verify.h"
#include"mouse.h"
#include"input.h"
/*
反馈
？
彭减
*/
int page_feedback();
void feedback_screen();
int page_thanks();
void thanks_screen();
int page_feedback()
{
	char fed1[20];
	char fed2[20];
	char fed3[20];
	char fed4[20];
	fed1[0]=fed2[0]=fed3[0]=fed4[0]='\0';
	clrmous(MouseX,MouseY);
	delay(100);
	cleardevice();
	feedback_screen();
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
		if(mouse_press(15,0,30,30)==1)//返回
		{
			return 3;
		}
		if(mouse_press(260,325,360,400)==1)//提交
		{
			return 10;
			delay(100);
		}
		if(mouse_press(0,45,700,275)==1)//反馈
		{
			setfillstyle(SOLID_FILL,WHITE);
			bar(0,47,700,273);
            clrmous(MouseX, MouseY);
		    delay(100);
		    save_bk_mou(MouseX,MouseY);
			input_feedback1(fed1);
			puthz(20,47+20,fed1,24,24,LIGHTGRAY);
            clrmous(MouseX, MouseY);
		    delay(100);
		    save_bk_mou(MouseX,MouseY);
		    
            clrmous(MouseX, MouseY);
		    delay(100);
		    save_bk_mou(MouseX,MouseY);
			input_feedback2(fed2);
			puthz(300,47+20,fed2,24,24,LIGHTGRAY);
            clrmous(MouseX, MouseY);
		    delay(100);
		    save_bk_mou(MouseX,MouseY);
		    
            clrmous(MouseX, MouseY);
		    delay(100);
		    save_bk_mou(MouseX,MouseY);
			input_feedback3(fed3);
			puthz(20,147+20,fed3,24,24,LIGHTGRAY);
            clrmous(MouseX, MouseY);
		    delay(100);
		    save_bk_mou(MouseX,MouseY);
		    
            clrmous(MouseX, MouseY);
		    delay(100);
		    save_bk_mou(MouseX,MouseY);
			input_feedback4(fed4);
			puthz(300,147+20,fed4,24,24,LIGHTGRAY);
            clrmous(MouseX, MouseY);
		    delay(100);
		    save_bk_mou(MouseX,MouseY);
		}
	}
}
void feedback_screen()
{
    // 绘制返回箭头（"<" 形状）
    setcolor(BLUE);
    setlinestyle(SOLID_LINE, 0, THICK_WIDTH);
    line(30, 15, 15, 22);  // 右上角到箭头尖
    line(15, 22, 30, 30);  // 箭头尖到右下角
	//绘图
	setbkcolor(WHITE);//背景色设置为白色
	//退出键
	setcolor(LIGHTGRAY);
	setlinestyle(DOTTED_LINE,0,NORM_WIDTH);
	rectangle(595,0,640,45);
    setlinestyle(SOLID_LINE,0,THICK_WIDTH);
    line(595,0,640,45);
    line(640,0,595,45);
    //标题
    puthz(240,5,"反馈意见",24,24,LIGHTGRAY);
    line(0,45,700,45);
    line(0,275,700,275);
    setfillstyle(SOLID_FILL,GREEN);
    bar(260,325,360,400);
    puthz(280,345,"提交",24,24,WHITE);
}
int page_thanks()
{
	clrmous(MouseX,MouseY);
	delay(100);
	cleardevice();
	thanks_screen();
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
		if(mouse_press(15,0,30,30)==1)//返回
		{
			return 8;
			delay(100);
		}
		if(mouse_press(260,325,320,400)==1)
		{
			return 3;
		}
	}
}
void thanks_screen()
{
	    // 绘制返回箭头（"<" 形状）
	    setcolor(BLUE);
	    setlinestyle(SOLID_LINE, 0, THICK_WIDTH);
	    line(30, 15, 15, 22);  // 右上角到箭头尖
	    line(15, 22, 30, 30);  // 箭头尖到右下角
		//绘图
		setbkcolor(WHITE);//背景色设置为白色
		//退出键
		setcolor(LIGHTGRAY);
		setlinestyle(DOTTED_LINE,0,NORM_WIDTH);
		rectangle(595,0,640,45);
	    setlinestyle(SOLID_LINE,0,THICK_WIDTH);
	    line(595,0,640,45);
	    line(640,0,595,45);
	    //感谢语
	    line(70,100,70,300);
	    line(640-70,100,640-70,300);
	    line(70,100,640-70,100);
	    line(70,300,640-70,300);
	    puthz(120,140,"感谢您宝贵的意见！",24,24,GREEN);
	    puthz(130,200,"我们会继续努力！",24,24,GREEN);
	    setfillstyle(SOLID_FILL,GREEN);
	    bar(260,325+20,360,400+20);
	    puthz(280,345+20,"返回",24,24,WHITE);
}
