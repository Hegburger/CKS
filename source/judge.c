
#include"input.h"
#include"verify.h"
#include"IMAGE.h"
#include"common.h"
void judge_screen1();
int page_judge(AccidentInfo *p,int num_solid);
void draw_triangle(int x, int y, int blank_width);
void judge_screen2();
int page_judge(AccidentInfo *p,int num_solid)
{

	int check_pick[10]={0};
	int page=1;
	FILE *fw;
	int row_height=30;

    p->judge.final_log[0]=p->judge.final_time[0]=p->judge.final_punish[0]='\0';
    p->judge.description1[0]=p->judge.description2[0]=p->judge.description3[0]=p->judge.description4[0]='\0';
    p->judge.factor1[0]=p->judge.factor2[0]=p->judge.factor3[0]='\0';
    p->judge.final_per1duty[0]=p->judge.final_per2duty[0]='\0';
    p->judge.final_money[0]='\0';
	clrmous(MouseX,MouseY);
	delay(100);
	cleardevice();
	judge_screen1();
	save_bk_mou(MouseX,MouseY);
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
					//��������
					else if(mouse_press(0,66,700,66+100)==1)
					{
						check_pick[1]=1;
						setfillstyle(SOLID_FILL,WHITE);
						bar(0,68,700,164);
			            clrmous(MouseX, MouseY);
					    delay(100);
					    save_bk_mou(MouseX,MouseY);
					    
					    input_judge_des1(p->judge.description1);
					    puthz(30,70,p->judge.description1,16,16,LIGHTGRAY);
					    
			            clrmous(MouseX, MouseY);
					    delay(100);
					    save_bk_mou(MouseX,MouseY);
					    
					    input_judge_des2(p->judge.description2);
					    puthz(30+240,70,p->judge.description2,16,16,LIGHTGRAY);
					    
			            clrmous(MouseX, MouseY);
					    delay(100);
					    save_bk_mou(MouseX,MouseY);
					    
					    input_judge_des3(p->judge.description3);
					    puthz(30,70+40,p->judge.description3,16,16,LIGHTGRAY);
					    
			            clrmous(MouseX, MouseY);
					    delay(100);
					    save_bk_mou(MouseX,MouseY);
					    
					    input_judge_des4(p->judge.description4);
					    puthz(30+240,70+40,p->judge.description4,16,16,LIGHTGRAY);
					    
			            clrmous(MouseX, MouseY);
					    delay(100);
					    save_bk_mou(MouseX,MouseY);
					}
					//Ӱ������
					else if(mouse_press(80+30,210+30,700,240+30)==1)
					{
						check_pick[2]=1;
						setfillstyle(SOLID_FILL,WHITE);
						bar(80+30,242,700,238+30);
						
			            clrmous(MouseX, MouseY);
					    delay(100);
					    save_bk_mou(MouseX,MouseY);
					    
					    input_judge_infect(p->judge.factor1);
					    puthz(82+30,246,p->judge.factor1,16,16,LIGHTGRAY);
					    
			            clrmous(MouseX, MouseY);
					    delay(100);
					    save_bk_mou(MouseX,MouseY);
					}
					else if(mouse_press(80+30,210+30+30,700,240+30+30)==1)
					{
						check_pick[3]=1;
						setfillstyle(SOLID_FILL,WHITE);
						bar(80+30,242+30,700,238+30+30);
						
			            clrmous(MouseX, MouseY);
					    delay(100);
					    save_bk_mou(MouseX,MouseY);
					    
					    input_judge_infect(p->judge.factor2);
					    puthz(82+30,246+30,p->judge.factor2,16,16,LIGHTGRAY);
					    
			            clrmous(MouseX, MouseY);
					    delay(100);
					    save_bk_mou(MouseX,MouseY);
					}
					else if(mouse_press(80+30,210+30+60,700,240+30+60)==1)
					{
						check_pick[4]=1;
						setfillstyle(SOLID_FILL,WHITE);
						bar(80+30,242+60,700,238+30+60);
						
			            clrmous(MouseX, MouseY);
					    delay(100);
					    save_bk_mou(MouseX,MouseY);
					    
					    input_judge_infect(p->judge.factor3);
					    puthz(82+30,246+60,p->judge.factor3,16,16,LIGHTGRAY);
					    
			            clrmous(MouseX, MouseY);
					    delay(100);
					    save_bk_mou(MouseX,MouseY);
					}
					//�����϶�
					else if(mouse_press(80+50,390,320,420)==1)
					{
						check_pick[5]=1;
						check_pick[6]=1;
						setfillstyle(SOLID_FILL,WHITE);
						bar(80+50,392,318,418);
						setfillstyle(SOLID_FILL,WHITE);
						bar(400+50,392,700,418);
			            clrmous(MouseX, MouseY);
					    delay(100);
					    save_bk_mou(MouseX,MouseY);
					    
					    input_judge_duty(p->judge.final_per1duty);
					    puthz(82+50,396,p->judge.final_per1duty,16,16,LIGHTGRAY);
					    duty_auto(p->judge.final_per1duty,p->judge.final_per2duty);
						puthz(402+50,396,p->judge.final_per2duty,16,16,LIGHTGRAY);
			            clrmous(MouseX, MouseY);
					    delay(100);
					    save_bk_mou(MouseX,MouseY);
					}
					else if(mouse_press(400+50,390,700,420)==1)
					{	
						check_pick[5]=1;
						check_pick[6]=1;
						setfillstyle(SOLID_FILL,WHITE);
						bar(80+50,392,318,418);
						setfillstyle(SOLID_FILL,WHITE);
						bar(400+50,392,700,418);
			            clrmous(MouseX, MouseY);
					    delay(100);
					    save_bk_mou(MouseX,MouseY);
					    
					    input_judge_duty(p->judge.final_per2duty);
					    puthz(402+50,396,p->judge.final_per2duty,16,16,LIGHTGRAY);
						duty_auto(p->judge.final_per2duty,p->judge.final_per1duty);
						puthz(82+50,396,p->judge.final_per1duty,16,16,LIGHTGRAY);
			            clrmous(MouseX, MouseY);
					    delay(100);
					    save_bk_mou(MouseX,MouseY);
					}
					//�⳥�϶�
					else if(mouse_press(80+40,420,700,450)==1)
					{
						check_pick[7]=1;
						setfillstyle(SOLID_FILL,WHITE);
						bar(80+40,422,700,448);
						
			            clrmous(MouseX, MouseY);
					    delay(100);
					    save_bk_mou(MouseX,MouseY);
					    
					    input_judge_money(p->judge.final_money);
					    puthz(82+40,426,p->judge.final_money,16,16,LIGHTGRAY);
					    
			            clrmous(MouseX, MouseY);
					    delay(100);
					    save_bk_mou(MouseX,MouseY);
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
						judge_screen2();
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
					//���ɳͷ�
					if(mouse_press(80+40,480-400,700,510-400)==1)//�ͷ�����
					{
						check_pick[8]=1;
						setfillstyle(SOLID_FILL,WHITE);
						bar(80+40,482-400,700,508-400);
						
			            clrmous(MouseX, MouseY);
					    delay(100);
					    save_bk_mou(MouseX,MouseY);
					    
					    input_judge_punish(p->judge.final_punish);
					    puthz(82+40,486-400,p->judge.final_punish,16,16,LIGHTGRAY);
					    
			            clrmous(MouseX, MouseY);
					    delay(100);
					    save_bk_mou(MouseX,MouseY);
					}
					else if(mouse_press(80+40,510-400,700,540-400)==1)//�ͷ�ʱ��
					{
						check_pick[9]=1;
						setfillstyle(SOLID_FILL,WHITE);
						bar(80+40,512-400,700,538-400);
						
			            clrmous(MouseX, MouseY);
					    delay(100);
					    save_bk_mou(MouseX,MouseY);
					    
					    input_judge_time(p->judge.final_time);
					    puthz(82+40,516-400,p->judge.final_time,16,16,LIGHTGRAY);
					    
			            clrmous(MouseX, MouseY);
					    delay(100);
					    save_bk_mou(MouseX,MouseY);
					}
					else if(mouse_press(80+40,540-400,700,570-400)==1)//����λ
					{
						check_pick[10]=1;
						setfillstyle(SOLID_FILL,WHITE);
						bar(80+40,542-400,700,568-400);
						
			            clrmous(MouseX, MouseY);
					    delay(100);
					    save_bk_mou(MouseX,MouseY);
					    
					    input_judge_log(p->judge.final_log);
					    puthz(82+40,546-400,p->judge.final_log,16,16,LIGHTGRAY);
					    
			            clrmous(MouseX, MouseY);
					    delay(100);
					    save_bk_mou(MouseX,MouseY);
					}
					else if(mouse_press(260,560+30-350,340,610+30-350)==1)//����
					{
						if(check_pick[1]!=0)
						{
							if(check_pick[2]!=0||check_pick[3]!=0||check_pick[4]!=0)
							{
								if(check_pick[5]!=0&&check_pick[6]!=0)
								{
									if(check_pick[7]!=0)
									{
										if(check_pick[8]!=0)
										{
											if(check_pick[9]!=0)
											{
												if(check_pick[10]!=0)
												{
					    							if((fw = fopen("accident.dat","rb+"))==NULL)
													{
														setfillstyle(SOLID_FILL,WHITE);
														bar(20,590-350,240,640-350); 
														puthz(20,608-350,"���ݿ��ʧ��",16,16,RED);
													}
													else{
														p->processed_status='1';
														fseek(fw,(num_solid-1)*sizeof(AccidentInfo),SEEK_SET);
														fwrite(p,sizeof(AccidentInfo),1,fw);
														fclose(fw);
														setfillstyle(SOLID_FILL,WHITE);
														bar(20,590-350,240,640-350); 
														puthz(20,608-350,"����ɹ�",16,16,GREEN);
														delay(3000);
														clrmous(MouseX,MouseY);
														return 11;//���������ҳ��
													}	
												}
												else
												{
													setfillstyle(SOLID_FILL,WHITE);
													bar(20,590-350,240,640-350);
													puthz(20,608-350,"����λû����д",16,16,RED);
												}
											}
											else
											{
												setfillstyle(SOLID_FILL,WHITE);
												bar(20,590-350,240,640-350);
												puthz(20,608-350,"�ͷ�ʱ��û����д",16,16,RED);
											}
										}
										else
										{
											setfillstyle(SOLID_FILL,WHITE);
											bar(20,590-350,240,640-350);
											puthz(20,608-350,"�ͷ�����û����д",16,16,RED);
										}
									}
									else
									{
										setfillstyle(SOLID_FILL,WHITE);
										bar(20,590-350,240,640-350);
										puthz(20,608-350,"�⳥���û����д",16,16,RED);
									}
								}
								else
								{
									setfillstyle(SOLID_FILL,WHITE);
									bar(20,590-350,240,640-350);
									puthz(20,608-350,"�����϶�δ���",16,16,RED);
								}
							}
							else
							{
								setfillstyle(SOLID_FILL,WHITE);
								bar(20,590-350,240,640-350);
								puthz(20,608-350,"������дһ��Ӱ������",16,16,RED);
							}
						}
						else
						{
							setfillstyle(SOLID_FILL,WHITE);
							bar(20,590-350,240,640-350);
							puthz(20,608-350,"����û����д",16,16,RED);
						}
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
						judge_screen1();
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
			}
		}
	}
}
void judge_screen1()
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
void judge_screen2()
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
    //����
    setfillstyle(SOLID_FILL,GREEN);
    bar(260,560+30-350,340,610+30-350);
    puthz(275,564+30-350,"����",24,24,WHITE);
    //��ҳ��
    line(0,160+150,700,160+150);
    line(0,190+150,700,190+150);
    puthz(5,164+150,"����˴��л���һҳ",24,24,GREEN);
    draw_triangle(260,205+100,41);
}


















