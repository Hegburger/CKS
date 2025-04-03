#include "common.h"
#include "mouse.h"
#include <stdio.h>
#include"verify.h"
#include"input.h"
#include"file.h"
/***
个人信息界面
彭减 
*/ 
void person_screen();
int page_person(char *phone_number,char *id_card);
void draw_triangle(int x, int y, int blank_width);
int page_person(char *phone_number,char *id_card)
{
	int longer=500;
	int height=30;
	int x1=100;
	int y=80;
	User x;
    x.phone[0]=x.username[0]=x.idcard[0]=x.student_id[0]='\0';
    x.driver_license_type[0]=x.driver_license_validity[0]='\0';
    x.car.province[0]=x.car.plate[0]=x.car.type[0]='\0';
    x.ebike.campus_plate[0]=x.ebike.wuhan_plate[0]='\0';
    clrmous(MouseX, MouseY);
    delay(100);
    cleardevice();
    person_screen();
    save_bk_mou(MouseX,MouseY);
	match_user(phone_number,&x);
	
    while(1)
    {
		mou_pos(&MouseX,&MouseY,&press);
		if(mouse_press(595,0,640,45)==1)//退出按键 
		{
			closegraph();
			delay(1000);
			exit(0);
		}
        // if(mouse_press(x1,y-height+5,x1+longer,y-5)==1)//输入用户名 
		// {
        //     setfillstyle(SOLID_FILL,WHITE);
        //     bar(x1+16,y-height+5,x1+longer,y-5);
        //     input_str(x1+16,y-height,x.username,1,3,20);
        //     clrmous(MouseX, MouseY);
		//     delay(100);
		//     save_bk_mou(MouseX,MouseY);
        // }
        else if(mouse_press(x1,y,x1+longer,y+height)==1)//输入身份证 
		{
            setfillstyle(SOLID_FILL,WHITE);
            bar(x1+16,y+5,x1+longer,y+height-5);
            input_str(x1+16,y,x.idcard,1,3,18);
            clrmous(MouseX, MouseY);
		    delay(100);
		    save_bk_mou(MouseX,MouseY);
        }
        // else if(mouse_press(x1,y+height,x1+longer,y+height*2)==1)//输入手机号码 
		// {
        //     setfillstyle(SOLID_FILL,WHITE);
        //     bar(x1+16,y+height+5,x1+longer,y+height*2-5);
        //     input_str(x1+16,y+height,x.phone,1,3,11);
        //     clrmous(MouseX, MouseY);
		//     delay(100);
		//     save_bk_mou(MouseX,MouseY);
        // }
        else if(mouse_press(x1,y+height*2,x1+longer,y+height*3)==1)//输入学号 
		{
	        setfillstyle(SOLID_FILL,WHITE);
	        bar(x1+16,y+height*2+5,x1+longer,y+height*3-5);
	        input_str(x1+16,y+height*2,x.student_id,1,3,10);
            clrmous(MouseX, MouseY);
		    delay(100);
		    save_bk_mou(MouseX,MouseY);
	    }
        else if(mouse_press(x1,y+height*3,x1+longer,y+height*4)==1)//输入驾驶证类型 
		{
	        setfillstyle(SOLID_FILL,WHITE);
	        bar(x1+40,y+height*3+5,x1+longer,y+height*4-5);
	        input_str(x1+40,y+height*3,x.driver_license_type,1,3,20);
            clrmous(MouseX, MouseY);
		    delay(100);
		    save_bk_mou(MouseX,MouseY);
	    }
        else if(mouse_press(x1,y+height*4,x1+longer,y+height*5)==1)//输入驾驶证有效期 
		{
	        setfillstyle(SOLID_FILL,WHITE);
	        bar(x1+50,y+height*4+5,x1+longer,y+height*5-5);
	        input_time(x1+50,y+height*4,x.driver_license_validity,1,3);
            clrmous(MouseX, MouseY);
		    delay(100);
		    save_bk_mou(MouseX,MouseY);
	    }
        else if(mouse_press(x1,y+height*5,x1+longer,y+height*6)==1)//输入汽车类型 
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
        else if(mouse_press(x1,y+height*6,x1+longer,y+height*7)==1)//输入车牌号 
		{
	        setfillstyle(SOLID_FILL,WHITE);
	        bar(x1+40,y+height*6+5,x1+longer,y+height*7-5);
            clrmous(MouseX, MouseY);
		    delay(100);
		    save_bk_mou(MouseX,MouseY);
	        input_province(x.car.province);//车牌号的省份 
	        puthz(x1+50,y+height*6,x.car.province,24,24,LIGHTGRAY);
	        input_str(x1+75,y+height*6,x.car.plate,1,3,6);//剩下车牌号的数字与字母 
            clrmous(MouseX, MouseY);
		    delay(100);
		    save_bk_mou(MouseX,MouseY);
	    }
        else if(mouse_press(x1,y+height*7,x1+longer,y+height*8)==1)//输入电动车的校园车牌号 
		{
	        setfillstyle(SOLID_FILL,WHITE);
	        bar(x1+100,y+height*7+5,x1+longer,y+height*8-5);
	        input_str(x1+100,y+height*7,x.ebike.campus_plate,1,3,20);
            clrmous(MouseX, MouseY);
		    delay(100);
		    save_bk_mou(MouseX,MouseY);
	    }
        else if(mouse_press(x1,y+height*8,x1+longer,y+height*9)==1)//输入电动车的武汉车牌号 
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
					if(validate_licence_car(x.car.plate)==1)
					{
						if(validate_student_id(x.student_id)==1)
						{
							if(x.username!='\0'||x.driver_license_type!='\0'||x.driver_license_validity!='\0'||x.ebike.campus_plate!='\0'||x.ebike.wuhan_plate!='\0')
							{
								addInfo_user(phone_number,&x);
								strcpy(id_card,x.idcard);
								setfillstyle(SOLID_FILL,WHITE);
								bar(50,390,260,400+20); 
								puthz(50,400,"保存成功",16,16,GREEN);
								delay(1000);
								clrmous(MouseX,MouseY);
								return 3; 
								
							}
							else
							{
								setfillstyle(SOLID_FILL,WHITE);
								bar(50,390,260,400+20);
								puthz(50,400,"有空位没有填写",16,16,RED);
							}
						}	
						else
						{
							setfillstyle(SOLID_FILL,WHITE);
							bar(50,390,260,400+20);
							puthz(50,400,"学号输入不合规范",16,16,RED);
						}
					}
					else
					{
					    setfillstyle(SOLID_FILL,WHITE);
					    bar(50,390,260,400+20); 
						puthz(50,400,"车牌号输入不合规范",16,16,RED);
					}
				}
				else
				{
					setfillstyle(SOLID_FILL,WHITE);
					bar(50,390,260,400+20); 
					puthz(50,400,"身份证号码输入不合规范",16,16,RED);
				}
			} 
			else{
				setfillstyle(SOLID_FILL,WHITE);
				bar(50,390,260,400+20); 
				puthz(50,400,"手机号输入不合规范",16,16,RED);
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
	//退出 
     setcolor(LIGHTGRAY);
     setlinestyle(DOTTED_LINE,0,NORM_WIDTH);
     rectangle(595,0,640,45);
     setlinestyle(SOLID_LINE,0,THICK_WIDTH);
     line(595,0,640,45);
     line(640,0,595,45);
     //线
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
	puthz(200,20,"个人信息",32,32,RED);
	puthz(5,y-29,"姓名",24,24,GREEN);
	puthz(5,y+height-29,"身份证号",24,24,GREEN);
	puthz(5,y+height*2-29,"手机号",24,24,GREEN);
	puthz(5,y+height*3-29,"学号",24,24,GREEN);
	puthz(5,y+height*4-29,"驾驶证类型",24,24,GREEN);
	puthz(5,y+height*5-29,"驾驶证有效期",24,24,GREEN);
	puthz(5,y+height*6-29,"汽车类型",24,24,GREEN);
	puthz(5,y+height*7-29,"汽车车牌号",24,24,GREEN);
	puthz(5,y+height*8-29,"电动车校园车牌号",24,24,GREEN);
	puthz(5,y+height*9-29,"电动车武汉车牌号",24,24,GREEN);
	setfillstyle(SOLID_FILL,GREEN);
	bar(300,400,300+100,400+30);
	puthz(300,400,"保存",32,32,WHITE);
}

































