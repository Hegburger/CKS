#include"input.h"
#include"common.h"
#include"verify.h"
#include"mouse.h"
#include"IMAGE.h"
void manage_screen();
int page_manage();
int page_manage()
{
	int height=200;
	int longer=200;
	clrmous(MouseX,MouseY);
	delay(100);
	cleardevice();
	manage_screen();
	save_bk_mou(MouseX,MouseY);
	while(1)
	{
		mou_pos(&MouseX,&MouseY,&press);
		if(mouse_press(595,0,640,45)==1)//�˳��� 
		{
			closegraph();
			delay(1000);
			exit(0);
		}
		if(mouse_press(20,50,20+longer,50+height)==1)
		{
			if(record_manage('0') == 11){
				clrmous(MouseX, MouseY);
				delay(100);
				save_bk_mou(MouseX,MouseY);
				return 11;
			}
            clrmous(MouseX, MouseY);
		    delay(100);
		    save_bk_mou(MouseX,MouseY);
		}
		if(mouse_press(20+longer+30,50,20+longer*2+30,50+height)==1)
		{
			if(record_manage('1') == 11){
				clrmous(MouseX, MouseY);
				delay(100);
				save_bk_mou(MouseX,MouseY);
				return 11;
			}
            clrmous(MouseX, MouseY);
		    delay(100);
		    save_bk_mou(MouseX,MouseY);
		}
	}

}
void manage_screen()
{
	int height=200;
	int longer=200;
	setbkcolor(WHITE);
	//�˳���
	setcolor(LIGHTGRAY);
	setlinestyle(DOTTED_LINE,0,NORM_WIDTH);
	rectangle(595,0,640,45);
    setlinestyle(SOLID_LINE,0,THICK_WIDTH);
    line(595,0,640,45);
    line(640,0,595,45);
    //����
    puthz(240,12,"�����ն�",32,32,LIGHTGRAY);
    //δ�����¹�
    cir_bar(60,80,60+longer,80+height,BLUE);
    puthz(90,150,"δ�����¹�",32,32,RED);
    //�Ѵ����¹�
    cir_bar(60+longer+30,80,60+longer*2+30,80+height,BLUE);
    puthz(90+30+longer,150,"�Ѵ����¹�",32,32,RED);
    //���ѱ���
    puthz(190,300+100,"��׼���أ�����δȻ",24,24,RED);
}
