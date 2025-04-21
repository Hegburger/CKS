#include"common.h"
#include"mouse.h"
#include"verify.h"
#include"input.h"
#include"IMAGE.h"
/*
证据界面
彭减 
*/
void evidence_screen();
int page_evidence(int numsolid,AccidentInfo *p);
int page_evidence(int num_solid,AccidentInfo *p)
{
	int height=40;
	int y=40;
	int longer=400;
	FILE *fw;
	p->evidence_per1[0]=p->evidence_per2[0]='\0';
	p->description1[0]=p->description2[0]=p->description3[0]=p->description4[0]='\0';
	clrmous(MouseX,MouseY);
	delay(100);
	cleardevice();
	evidence_screen();
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
		else if(mouse_press(30,0,30+longer,height)==1)//输入证人1 
		{
			setfillstyle(SOLID_FILL,WHITE);
			bar(90,10,30+longer,height);
            clrmous(MouseX, MouseY);
		    delay(100);
		    save_bk_mou(MouseX,MouseY);
			input_evidence(p->evidence_per1);
			puthz(90,17,p->evidence_per1,24,24,LIGHTGRAY);
            clrmous(MouseX, MouseY);
		    delay(100);
		    save_bk_mou(MouseX,MouseY);
		}
		else if(mouse_press(30,height,30+longer,height*2)==1)//输入证人2
		{
			setfillstyle(SOLID_FILL,WHITE); 
			bar(90,height+10,30+longer,height*2-3);
            clrmous(MouseX, MouseY);
		    delay(100);
		    save_bk_mou(MouseX,MouseY);
			input_evidence(p->evidence_per2);
			puthz(90,height+17,p->evidence_per2,24,24,LIGHTGRAY);
            clrmous(MouseX, MouseY);
		    delay(100);
		    save_bk_mou(MouseX,MouseY);
		} 
		else if(mouse_press(0,height*2+5,30+longer,height*3+100)==1)//输入证词
		{
            clrmous(MouseX, MouseY);
		    delay(100);
		    save_bk_mou(MouseX,MouseY);
			setfillstyle(SOLID_FILL,WHITE);
			bar(30,height*3+10,30+700,height*3+100-30);
            clrmous(MouseX, MouseY);
		    delay(100);
		    save_bk_mou(MouseX,MouseY);
		    
			input_description1(p->description1);
			puthz(30,height*3+10,p->description1,16,16,LIGHTGRAY);
            clrmous(MouseX, MouseY);
		    delay(100);
		    save_bk_mou(MouseX,MouseY);
		    
		    input_description2(p->description2); 
			puthz(160,height*3+10,p->description2,16,16,LIGHTGRAY);
            clrmous(MouseX, MouseY);
		    delay(100);
		    save_bk_mou(MouseX,MouseY);
		    
		    input_description3(p->description3); 
			puthz(30,height*3+10+30,p->description3,16,16,LIGHTGRAY);
            clrmous(MouseX, MouseY);
		    delay(100);
		    save_bk_mou(MouseX,MouseY);
		    
		    input_description4(p->description4); 
			puthz(160,height*3+10+30,p->description4,16,16,LIGHTGRAY);
            clrmous(MouseX, MouseY);
		    delay(100);
		    save_bk_mou(MouseX,MouseY);
		} 
		//录入图片
		if(mouse_press(8,45+height*3+100,5+130,45+height*3+100+100-13+45)==1)
		{
            clrmous(MouseX, MouseY);
		    delay(100);
		    save_bk_mou(MouseX,MouseY);
		    
		    input_image(8,45+height*3+100-1,p->photo1);
            clrmous(MouseX, MouseY);
		    delay(100);
		    save_bk_mou(MouseX,MouseY);
		} 
		
		if(mouse_press(8+130+30,45+height*3+100,5+130*2+30,45+height*3+100+100-13+45)==1)
		{
            clrmous(MouseX, MouseY);
		    delay(100);
		    save_bk_mou(MouseX,MouseY);
		    
		    input_image(8+130+30,45+height*3+100-1,p->photo2);
            clrmous(MouseX, MouseY);
		    delay(100);
		    save_bk_mou(MouseX,MouseY);
		} 
		
		if(mouse_press(8+130*2+60,45+height*3+100,5+130*3+60,45+height*3+100+100-13+45)==1)
		{
            clrmous(MouseX, MouseY);
		    delay(100);
		    save_bk_mou(MouseX,MouseY);
		    
		    input_image(8+130*2+60,45+height*3+100-1,p->photo3);
            clrmous(MouseX, MouseY);
		    delay(100);
		    save_bk_mou(MouseX,MouseY);
		} 
		
		if(mouse_press(8+130*3+90,45+height*3+100,5+130*4+90,45+height*3+100+100-13+45)==1)
		{
            clrmous(MouseX, MouseY);
		    delay(100);
		    save_bk_mou(MouseX,MouseY);
		    
		    input_image(8+130*3+90,45+height*3+100-1,p->photo4);
            clrmous(MouseX, MouseY);
		    delay(100);
		    save_bk_mou(MouseX,MouseY);
		} 
		//保存
		if(mouse_press(240,45+y*3+100+100+40,360,45+y*3+100+100+40+40)==1)
		{
			//检验证人是否填写
			if(p->evidence_per1!='\0'||p->evidence_per2!='\0')
			{
				//检验证词是否填写
				if(p->description1!='\0'&&p->description2!='\0'&&p->description3!='\0'&&p->description4!='\0')
				{
    							if((fw = fopen("accident.dat","rb"))==NULL)
								{
									setfillstyle(SOLID_FILL,WHITE);
									bar(10,365+40,200,365+80); 
									puthz(10,425,"数据库打开失败",16,16,RED);
								}
								else{
									fwrite(p,num_solid*sizeof(AccidentInfo),1,fw);
									fclose(fw);
									setfillstyle(SOLID_FILL,WHITE);
									bar(10,365+40,200,365+80); 
									puthz(10,425,"保存成功",16,16,GREEN);
									delay(4000);
									clrmous(MouseX,MouseY);
									return 17; 
								}	
				} 
				else
				{
					setfillstyle(SOLID_FILL,WHITE);
					bar(10,365+40,200,365+80);
					puthz(10,365+40+20,"证词未填写",16,16,RED);
				}
			} 
			else
			{
				setfillstyle(SOLID_FILL,WHITE);
				bar(10,365+40,200,365+80);
				puthz(10,365+40+20,"证人未填写",16,16,RED);
			}
		} 
	}
} 
void evidence_screen()
{
	int height=100;
	int longer=130;
	int i;
	int y=40;
	setbkcolor(WHITE);
	//退出键
	setcolor(LIGHTGRAY);
	setlinestyle(DOTTED_LINE,0,NORM_WIDTH);
	rectangle(595,0,640,45);
    setlinestyle(SOLID_LINE,0,THICK_WIDTH);
    line(595,0,640,45);
    line(640,0,595,45);
    //证人1
	setcolor(LIGHTGRAY);
    setlinestyle(SOLID_LINE,0,THICK_WIDTH);
    line(0,45+y,640,45+y);
    line(0,45,640,45);
    puthz(5,45-29,"证人一",24,24,BLUE);
    //证人2
	setcolor(LIGHTGRAY);
    setlinestyle(SOLID_LINE,0,THICK_WIDTH);
    //line(0,45+y*2,640,45+y*2);
    puthz(5,45+y-29,"证人二",24,24,BLUE);
    //证词
	setcolor(LIGHTGRAY);
    setlinestyle(SOLID_LINE,0,THICK_WIDTH);
    line(0,45+y+100+30,640,45+y+100+30);
    puthz(5,45+y*2-29,"证词",24,24,BLUE); 
    //证据
	puthz(5,45+y*2+100-29+30,"证据图片",24,24,BLUE);
	setfillstyle(SOLID_FILL,LIGHTGRAY);
	bar(8,45+y*3+100,5+longer,45+y*3+100+height-13+45);
	bar(8+longer+30,45+y*3+100,5+longer*2+30,45+y*3+100+height-13+45);
	bar(8+longer*2+60,45+y*3+100,5+longer*3+60,45+y*3+100+height-13+45);
	bar(8+longer*3+90,45+y*3+100,5+longer*4+90,45+y*3+100+height-13+45);
	//保存
	setfillstyle(SOLID_FILL,GREEN);
	bar(240,45+y*3+100+height+40,360,45+y*3+100+height+40+40);
	puthz(240,45+y*3+100+height+40+12,"保存证据",24,24,WHITE); 
}




















