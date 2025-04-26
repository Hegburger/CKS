#include "common.h"
#include "verify.h"
void judge_screen3();
void judge_screen4();
int show_judge(AccidentInfo *p)
{
	int page=1;
	FILE *fw;
	int row_height=30;
	clrmous(MouseX,MouseY);
	delay(100);
	cleardevice();
	judge_screen1();
	save_bk_mou(MouseX,MouseY);
	puthz(30,70,p->judge.description1,16,16,LIGHTGRAY);
	puthz(30+240,70,p->judge.description2,16,16,LIGHTGRAY);
	puthz(30,70+40,p->judge.description3,16,16,LIGHTGRAY);
	puthz(30+240,70+40,p->judge.description4,16,16,LIGHTGRAY);
	puthz(82+30,246,p->judge.factor1,16,16,LIGHTGRAY);
	puthz(82+30,246+30,p->judge.factor2,16,16,LIGHTGRAY);
	puthz(82+30,246+60,p->judge.factor3,16,16,LIGHTGRAY);
	puthz(82+50,396,p->judge.final_per1duty,16,16,LIGHTGRAY);
	puthz(402+50,396,p->judge.final_per2duty,16,16,LIGHTGRAY);
	puthz(82+40,426,p->judge.final_money,16,16,LIGHTGRAY);
	while(1)
	{
		if(page==1)
		{
			while(1)
			{
	    			mou_pos(&MouseX,&MouseY,&press);
					if(mouse_press(595,0,640,45)==1)//�˳��� 
					{
						closegraph();
						delay(1000);
						exit(0);
					}
					//�ص�ȡ֤
					else if(mouse_press(0,0,45,45)==1)
					{
						return 4;
					}
					//��ҳ��
					else if(mouse_press(0,450,300,480)==1)
					{
						page=2;
			            clrmous(MouseX, MouseY);
					    delay(100);
					    save_bk_mou(MouseX,MouseY);
						setfillstyle(SOLID_FILL,WHITE);
						bar(0,0,700,700);
						judge_screen3();
			            clrmous(MouseX, MouseY);
					    delay(100);
					    save_bk_mou(MouseX,MouseY);
						puthz(82+80,486-400,p->judge.final_punish,16,16,LIGHTGRAY);
						puthz(82+80,516-400,p->judge.final_time,16,16,LIGHTGRAY);
						puthz(82+80,546-400,p->judge.final_log,16,16,LIGHTGRAY);
						break;
					}
				}
		}
			while(1)
			{
	    		if(page==2)
				{
					mou_pos(&MouseX,&MouseY,&press);
					if(mouse_press(595,0,640,45)==1)//�˳��� 
					{
						closegraph();
						delay(1000);
						exit(0);
					}
					//��ҳ��
					else if(mouse_press(0,310,300,340)==1)
					{
						page=1;
			            clrmous(MouseX, MouseY);
					    delay(100);
					    save_bk_mou(MouseX,MouseY);
						setfillstyle(SOLID_FILL,WHITE);
						bar(0,0,700,700);
						judge_screen4();
			            clrmous(MouseX, MouseY);
					    delay(100);
					    save_bk_mou(MouseX,MouseY);
						puthz(30,70,p->judge.description1,16,16,LIGHTGRAY);
						puthz(30+240,70,p->judge.description2,16,16,LIGHTGRAY);
						puthz(30,70+40,p->judge.description3,16,16,LIGHTGRAY);
						puthz(30+240,70+40,p->judge.description4,16,16,LIGHTGRAY);
						puthz(82+30,246,p->judge.factor1,16,16,LIGHTGRAY);
						puthz(82+30,246+30,p->judge.factor2,16,16,LIGHTGRAY);
						puthz(82+30,246+60,p->judge.factor3,16,16,LIGHTGRAY);
						puthz(82+50,396,p->judge.final_per1duty,16,16,LIGHTGRAY);
						puthz(402+50,396,p->judge.final_per2duty,16,16,LIGHTGRAY);
						puthz(82+40,426,p->judge.final_money,16,16,LIGHTGRAY);
						break;
					}
					if(mouse_press(258,205+100+50,260+100,205+100+75)==1){
						clrmous(MouseX, MouseY);
					    delay(100);
					    save_bk_mou(MouseX,MouseY);
						return 0;
					}	
			}
		}
	}
}
void judge_screen3()
{
	int row_height=30;
	setbkcolor(WHITE);
	//�˳���
	setcolor(LIGHTGRAY);
	setlinestyle(DOTTED_LINE,0,NORM_WIDTH);
	rectangle(595,0,640,45);
    setlinestyle(SOLID_LINE,0,THICK_WIDTH);
    line(595,0,640,45);
    line(640,0,595,45);	
    //�ͷ��϶�
    line(110,80,110,170);
    puthz(5,424+30-400,"���ɳͷ�",24,24,RED);
    line(0,450+30-400,700,450+30-400);
    puthz(5,454+30-400,"�ͷ�����",24,24,LIGHTGRAY);
    line(0,480+30-400,700,480+30-400);
    puthz(5,484+30-400,"�ͷ�ʱ��",24,24,LIGHTGRAY);
    line(0,510+30-400,700,510+30-400);
    puthz(5,514+30-400,"����λ",24,24,LIGHTGRAY);
    line(0,540+30-400,700,540+30-400);
//    //����
//    setfillstyle(SOLID_FILL,GREEN);
//    bar(260,560+30-350,340,610+30-350);
//    puthz(275,564+30-350,"����",24,24,WHITE);
    //��ҳ��
    line(0,160+150,700,160+150);
    line(0,190+150,700,190+150);
    puthz(5,164+150,"����˴��л���һҳ",24,24,GREEN);
    draw_triangle(260,205+100,41);
	setcolor(LIGHTCYAN);
	setlinestyle(SOLID_LINE, 0, THICK_WIDTH);
	rectangle(258,205+100+50,260+100,205+100+75);
	puthz(263,205+100+50,"�����鿴",24,24,RED);
}
void judge_screen4()
{
	int row_height=30;
	setbkcolor(WHITE);
     // ���ذ��������Ͻǣ�
    setcolor(LIGHTGRAY);
    setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
    rectangle(0, 0, 45, 45); // ���Ʒ��ذ�ť�߿�
    // ���Ʒ��ؼ�ͷ��"<" ��״��
    setcolor(BLUE);
    setlinestyle(SOLID_LINE, 0, THICK_WIDTH);
    line(30, 15, 15, 22);  // ���Ͻǵ���ͷ��
    line(15, 22, 30, 30);  // ��ͷ�⵽���½�
	//�˳���
	setcolor(LIGHTGRAY);
	setlinestyle(DOTTED_LINE,0,NORM_WIDTH);
	rectangle(595,0,640,45);
    setlinestyle(SOLID_LINE,0,THICK_WIDTH);
    line(595,0,640,45);
    line(640,0,595,45);
    //����
    puthz(240,10,"�¹�����",24,24,LIGHTGRAY);
    //��һ�У���������
    setlinestyle(SOLID_LINE,0,THICK_WIDTH);
    //line(0,36,700,36);
    puthz(5,40,"�¹�����",24,24,RED);
    line(0,66,700,66);
    //puthz(40,80,"����˴���������",16,15,LIGHTGRAY);
    line(0,66+100,700,66+100);
    //�ڶ��У�Ӱ������
    puthz(5,180+30,"Ӱ������",24,24,RED);
    line(0,210+30,700,210+30);
    puthz(5,214+30,"����һ",24,24,LIGHTGRAY);
    line(0,240+30,700,240+30);
    puthz(5,244+30,"���ض�",24,24,LIGHTGRAY);
    line(0,270+30,700,270+30);
    puthz(5,274+30,"������",24,24,LIGHTGRAY);
    line(0,300+30,700,300+30);
    line(100,210+30,100,300+30);
    //�����У����ն���
    puthz(5,304+30,"���н��",24,24,RED);
    //�����϶�
    line(0,330+30,700,330+30);
    puthz(5,334+30,"�����϶�",24,24,LIGHTGRAY);
    line(0,360+30,700,360+30);
    puthz(5,364+30,"����������",24,24,LIGHTGRAY);
    line(0,390+30,700,390+30);
    line(320,360+30,320,390+30);
    puthz(325,364+30,"�ܺ�������",24,24,LIGHTGRAY);
    //�⳥�϶�
    puthz(5,394+30,"�⳥�϶�",24,24,LIGHTGRAY);
    line(0,420+30,700,420+30);
    //��ҳ��
    puthz(5,454,"����˴��л�����һҳ",24,24,GREEN);
    draw_triangle(260,445,41);
	
}
