#include "common.h"
#include "mouse.h"
#include <stdio.h>
#include"verify.h"
#include"input.h"
/***
������Ϣ����
��� 
*/ 
void person_screen();
int page_person();
void draw_triangle(int x, int y, int blank_width);
int page_person()
{
	int longer=500;
	int height=30;
	int x1=100;
	int y=80;
	User x;
    FILE *fw;
    x.phone[0]=x.username[0]=x.idcard[0]=x.student_id[0]='\0';
    x.driver_license_type[0]=x.driver_license_validity[0]='\0';
    x.car.province[0]=x.car.plate[0]=x.car.type[0]='\0';
    x.ebike.campus_plate[0]=x.ebike.wuhan_plate[0]='\0';
    clrmous(MouseX, MouseY);
    delay(100);
    cleardevice();
    person_screen();
    save_bk_mou(MouseX,MouseY);
    while(1)
    {
		mou_pos(&MouseX,&MouseY,&press);
		if(mouse_press(595,0,640,45)==1)//�˳����� 
		{
			closegraph();
			delay(1000);
			exit(0);
		}
        if(mouse_press(x1,y-height+5,x1+longer,y-5)==1)//�����û��� 
		{
            setfillstyle(SOLID_FILL,WHITE);
            bar(x1+16,y-height+5,x1+longer,y-5);
            input_str(x1+16,y-height,x.username,1,3,20);
            clrmous(MouseX, MouseY);
		    delay(100);
		    save_bk_mou(MouseX,MouseY);
        }
        else if(mouse_press(x1,y,x1+longer,y+height)==1)//�������֤ 
		{
            setfillstyle(SOLID_FILL,WHITE);
            bar(x1+16,y+5,x1+longer,y+height-5);
            input_str(x1+16,y,x.idcard,1,3,18);
            clrmous(MouseX, MouseY);
		    delay(100);
		    save_bk_mou(MouseX,MouseY);
        }
        else if(mouse_press(x1,y+height,x1+longer,y+height*2)==1)//�����ֻ����� 
		{
            setfillstyle(SOLID_FILL,WHITE);
            bar(x1+16,y+height+5,x1+longer,y+height*2-5);
            input_str(x1+16,y+height,x.phone,1,3,11);
            clrmous(MouseX, MouseY);
		    delay(100);
		    save_bk_mou(MouseX,MouseY);
        }
        else if(mouse_press(x1,y+height*2,x1+longer,y+height*3)==1)//����ѧ�� 
		{
	        setfillstyle(SOLID_FILL,WHITE);
	        bar(x1+16,y+height*2+5,x1+longer,y+height*3-5);
	        input_str(x1+16,y+height*2,x.student_id,1,3,10);
            clrmous(MouseX, MouseY);
		    delay(100);
		    save_bk_mou(MouseX,MouseY);
	    }
        else if(mouse_press(x1,y+height*3,x1+longer,y+height*4)==1)//�����ʻ֤���� 
		{
	        setfillstyle(SOLID_FILL,WHITE);
	        bar(x1+40,y+height*3+5,x1+longer,y+height*4-5);
	        input_str(x1+40,y+height*3,x.driver_license_type,1,3,20);
            clrmous(MouseX, MouseY);
		    delay(100);
		    save_bk_mou(MouseX,MouseY);
	    }
        else if(mouse_press(x1,y+height*4,x1+longer,y+height*5)==1)//�����ʻ֤��Ч�� 
		{
	        setfillstyle(SOLID_FILL,WHITE);
	        bar(x1+50,y+height*4+5,x1+longer,y+height*5-5);
	        input_str(x1+50,y+height*4,x.driver_license_validity,1,3,20);
            clrmous(MouseX, MouseY);
		    delay(100);
		    save_bk_mou(MouseX,MouseY);
	    }
        else if(mouse_press(x1,y+height*5,x1+longer,y+height*6)==1)//������������ 
		{
	        setfillstyle(SOLID_FILL,WHITE);
	        bar(x1+26,y+height*5+5,x1+longer,y+height*6-5);
	        input_car_type(x.car.type);
            clrmous(MouseX, MouseY);
		    delay(100);
		    save_bk_mou(MouseX,MouseY);
	        puthz(x1+26,y+5+height*5,x.car.type,24,24,LIGHTGRAY);
            clrmous(MouseX, MouseY);
		    delay(100);
		    save_bk_mou(MouseX,MouseY);
	    }
        else if(mouse_press(x1,y+height*6,x1+longer,y+height*7)==1)//���복�ƺ� 
		{
	        setfillstyle(SOLID_FILL,WHITE);
	        bar(x1+40,y+height*6+5,x1+longer,y+height*7-5);
            clrmous(MouseX, MouseY);
		    delay(100);
		    save_bk_mou(MouseX,MouseY);
	        input_province(x.car.province);//���ƺŵ�ʡ�� 
	        puthz(x1+50,y+height*6,x.car.province,24,24,LIGHTGRAY);
	        input_str(x1+75,y+height*6,x.car.plate,1,3,6);//ʣ�³��ƺŵ���������ĸ 
            clrmous(MouseX, MouseY);
		    delay(100);
		    save_bk_mou(MouseX,MouseY);
	    }
        else if(mouse_press(x1,y+height*7,x1+longer,y+height*8)==1)//����綯����У԰���ƺ� 
		{
	        setfillstyle(SOLID_FILL,WHITE);
	        bar(x1+100,y+height*7+5,x1+longer,y+height*8-5);
	        input_str(x1+100,y+height*7,x.ebike.campus_plate,1,3,20);
            clrmous(MouseX, MouseY);
		    delay(100);
		    save_bk_mou(MouseX,MouseY);
	    }
        else if(mouse_press(x1,y+height*8,x1+longer,y+height*9)==1)//����綯�����人���ƺ� 
		{
	        setfillstyle(SOLID_FILL,WHITE);
	        bar(x1+100,y+height*8+5,x1+longer,y+height*9-5);
	        input_str(x1+100,y+height*8,x.ebike.wuhan_plate,1,3,20);
            clrmous(MouseX, MouseY);
		    delay(100);
		    save_bk_mou(MouseX,MouseY);
	    }
	    else if(mouse_press(300,400,300+100,400+30)==1)
	    {
			if(validate_phone(x.phone)==1)
			{
				if(validate_idcard(x.idcard)==1)
				{
					if(validate_plate(x.car.plate)==1)
					{
						if(validate_student_id(x.student_id)==1)
						{
							if(x.username!='\0'||x.driver_license_type!='\0'||x.driver_license_validity!='\0'||x.ebike.campus_plate!='\0'||x.ebike.wuhan_plate!='\0')
							{
    							if((fw = fopen("list,dat","rb"))==NULL)
								{
									setfillstyle(SOLID_FILL,WHITE);
									bar(50,400-20,260,400+20); 
									puthz(50,400,"���ݿ��ʧ��",16,16,RED);
								}
								else{
									fwrite(&x,sizeof(User),1,fw);
									fclose(fw);
									setfillstyle(SOLID_FILL,WHITE);
									bar(50,390,260,400+20); 
									puthz(50,400,"����ɹ�",16,16,GREEN);
									delay(1000);
									clrmous(MouseX,MouseY);
									return 3; 
								}	
							}
							else
							{
								setfillstyle(SOLID_FILL,WHITE);
								bar(50,390,260,400+20);
								puthz(50,400,"�п�λû����д",16,16,RED);
							}
						}	
						else
						{
							setfillstyle(SOLID_FILL,WHITE);
							bar(50,390,260,400+20);
							puthz(50,400,"ѧ�����벻�Ϲ淶",16,16,RED);
						}
					}
					else
					{
					    setfillstyle(SOLID_FILL,WHITE);
					    bar(50,390,260,400+20); 
						puthz(50,400,"���ƺ����벻�Ϲ淶",16,16,RED);
					}
				}
				else
				{
					setfillstyle(SOLID_FILL,WHITE);
					bar(50,390,260,400+20); 
					puthz(50,400,"���֤�������벻�Ϲ淶",16,16,RED);
				}
			} 
			else{
				setfillstyle(SOLID_FILL,WHITE);
				bar(50,390,260,400+20); 
				puthz(50,400,"�ֻ������벻�Ϲ淶",16,16,RED);
			}
		}
	}
} 

void person_screen()
{
	int height=30;
	int i;
	int x=100,y=80;
	int blank=10
;	setbkcolor(WHITE);
	//�˳� 
     setcolor(LIGHTGRAY);
     setlinestyle(DOTTED_LINE,0,NORM_WIDTH);
     rectangle(595,0,640,45);
     setlinestyle(SOLID_LINE,0,THICK_WIDTH);
     line(595,0,640,45);
     line(640,0,595,45);
     //��
	 setcolor(LIGHTGRAY);
	 setlinestyle(SOLID_LINE,0,NORM_WIDTH);
	 for(i=0;i<=blank;i++)
	 {
	 	line(0,y+height*i,640,y+height*i);
	 } 
	 for(i=0;i<=blank;i++)
	 {
	 	draw_triangle(580,y+height*(i-1),height);
	 }
	puthz(200,20,"������Ϣ",32,32,RED);
	puthz(5,y-29,"����",24,24,GREEN);
	puthz(5,y+height-29,"���֤��",24,24,GREEN);
	puthz(5,y+height*2-29,"�ֻ���",24,24,GREEN);
	puthz(5,y+height*3-29,"ѧ��",24,24,GREEN);
	puthz(5,y+height*4-29,"��ʻ֤����",24,24,GREEN);
	puthz(5,y+height*5-29,"��ʻ֤��Ч��",24,24,GREEN);
	puthz(5,y+height*6-29,"��������",24,24,GREEN);
	puthz(5,y+height*7-29,"�������ƺ�",24,24,GREEN);
	puthz(5,y+height*8-29,"�綯��У԰���ƺ�",24,24,GREEN);
	puthz(5,y+height*9-29,"�綯���人���ƺ�",24,24,GREEN);
	setfillstyle(SOLID_FILL,GREEN);
	bar(300,400,300+100,400+30);
	puthz(300,400,"����",32,32,WHITE);
}

void draw_triangle(int x, int y, int blank_width) {
    int a,points[6];
    a = blank_width - 16; // ���������ε�һ�߳���

    // ���������ε���������
    points[0] = x;               // ��һ������ (x, y+5)
    points[1] = y + 8;
    points[2] = x;               // �ڶ������� (x, y + blank_width - 5)
    points[3] = y + blank_width - 8;
    points[4] = x + 0.87 * a;    // ���������� (x + 0.87*a, y + a / 2)
    points[5] = y + 8+ a/2;

    setfillstyle(SOLID_FILL, LIGHTGRAY);  // ���������ɫΪ��ɫ
    setcolor(CYAN);  // ���ñ߿���ɫΪ��ɫ

    fillpoly(3, points);  // ���Ʋ����������
}

































