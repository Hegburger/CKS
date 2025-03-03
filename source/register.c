#include"common.h"
#include"verify.h"
#include"input.h"
/****
function:����ע��������ע�����
author:Chengkai Huang
*****/
void register_screen();
int page_register();
int page_register(){
    int gap,height;
    char password[20];
    User x;
    FILE *fw;
    gap = 30; 
    height = 35; 
    password[0]='\0';
    x.username[0] = x.password[0] = x.phone[0] = '\0';
    clrmous(MouseX,MouseY);
    delay(100);
    cleardevice();
    register_screen();
    save_bk_mou(MouseX,MouseY);
    while(1){
        mou_pos(&MouseX,&MouseY,&press);
        if(mouse_press(265+65,128,265+65+280,128+height)==1){
            setfillstyle(SOLID_FILL,LIGHTGRAY);
            bar(265+65+16,128,265+65+280,128+height);
            input_str(265+65+16,128+5,x.phone,1,3,20);
        }else if(mouse_press(265+65,128+height+gap,265+65+280,128+height*2+gap)==1){
            setfillstyle(SOLID_FILL,LIGHTGRAY);
            bar(265+65+16,128+height+gap,265+65+280,128+height*2+gap);
            input_str(265+65+16,128+height+gap+5,x.username,1,3,20);
        }else if(mouse_press(265+65,128+height*2+gap*2,265+65+280,128+height*3+gap*2)==1){
            setfillstyle(SOLID_FILL,LIGHTGRAY);
            bar(265+65+16,128+height*2+gap*2,265+65+280,128+height*3+gap*2);
            input_password(265+65+16,128+height*2+gap*2+5,x.password,1,3,20);
        }else if(mouse_press(265+65,128+height*3+gap*3,265+65+280,128+height*4+gap*3)==1){
            setfillstyle(SOLID_FILL,LIGHTGRAY);
            bar(265+65+16,128+height*3+gap*3,265+65+280,128+height*4+gap*3);
            input_password(265+65+16,128+height*3+gap*3+5,password,1,3,20);
        }else if(mouse_press(290,128+height*4+gap*4,290+70,128+height*4+gap*4+50)==1){
            setfillstyle(SOLID_FILL,WHITE);
            bar(310,128+height*4+gap*3+5,610,128+height*4+gap*3+25);
        if(validate_phone(x.phone)==1){
            if(len_verify(x.username,3,18)==1){
                if(strcmp(x.password,password)==0){
                    if(validate_password(x.password)==1){
                        if((fw = fopen("list.dat","ab"))==NULL){
                            puthz(310,128+height*4+gap*3+5,"���ݿ��ʧ��",16,16,RED);    //���ļ�ʧ��
                        }else{
                            fwrite(&x,sizeof(User),1,fw);
                            fclose(fw);
                            puthz(310,128+height*4+gap*3+5,"ע��ɹ�",16,16,GREEN);//���ע��
                            delay(1000);
                            clrmous(MouseX,MouseY);
                            return 2;
                        }
                    }else{
                        puthz(310,128+height*4+gap*3+5,"�������ٺ������ַ��ҳ��Ⱥ���",16,16,RED);//���벻�Ϸ�
                    }
                }else{
                    puthz(310,128+height*4+gap*3+5,"���벻һ��",16,16,RED);
                }
            }else{
                puthz(310,128+height*4+gap*3+5,"�û������Ȳ�����",16,16,RED);//id 3-18λ
            }
        }else{
            puthz(310,128+height*4+gap*3+5,"�ֻ��Ų��Ϸ�",16,16,RED);//�ֻ��Ų��Ϸ�
        }
        }else if(mouse_press(290+70+90,128+height*4+gap*4,290+70+90+70,128+height*4+gap*4+50)==1){
            return 2;//�����¼ҳ��
        }else if(mouse_press(595,0,640,45)==1){
            closegraph();//�رջ�ͼ
				delay(1000);
			    exit(0);//�˳�����
        }
    }
}



void register_screen(){
    int gap,height,i;
    gap = 30; //行间�?
    height = 35; //行高
    //�˳�����
    setcolor(LIGHTGRAY);
    setlinestyle(DOTTED_LINE,0,NORM_WIDTH);
    rectangle(595,0,640,45);
    setlinestyle(SOLID_LINE,0,THICK_WIDTH);
    line(595,0,640,45);
    line(640,0,595,45);
    //����
    setbkcolor(WHITE);
    setcolor(BLUE);
    setlinestyle(SOLID_LINE,0,NORM_WIDTH);
    setfillstyle(SOLID_FILL,LIGHTGRAY);
    line(220,0,220,480);
    bar(350,50,350+132,50+58);//“注册�?

    bar(265,128,265+65,128+height);//“手机号�???
    bar(265+65,128,265+65+280,128+height);
    
    bar(265,128+height+gap,265+65,128+height*2+gap);//“用户名�???
    bar(265+65,128+height+gap,265+65+280,128+height*2+gap);

    bar(265,128+height*2+gap*2,265+65,128+height*3+gap*2);//“serect�???
    bar(265+65,128+height*2+gap*2,265+65+280,128+height*3+gap*2);

    bar(265,128+height*3+gap*3,265+65,128+height*4+gap*3);//“secret again�???
    bar(265+65,128+height*3+gap*3,265+65+280,128+height*4+gap*3);

    setfillstyle(SOLID_FILL,LIGHTBLUE);
    bar(290,128+height*4+gap*4,290+70,128+height*4+gap*4+50);//ȷ��
    bar(290+70+90,128+height*4+gap*4,290+70+90+70,128+height*4+gap*4+50);//��¼

    setcolor(BROWN);
    for(i =0;i<4;i++){
        line(265+80,128+height*i+gap*i,265+80,128+height*(i+1)+gap*i);
    }
    puthz(350+15,50,"ע��",48,48,BROWN);
    puthz(265,128,"�ֻ���",24,24,BROWN);
    puthz(270,128+height+gap,"�û���",24,24,BROWN);
    puthz(270,128+height*2+gap*2,"����",24,24,BROWN);
    puthz(270,128+height*3+gap*3+10,"ȷ������",16,16,BROWN);
    puthz(290,128+height*4+gap*4,"ȷ��",32,32,LIGHTRED);
    puthz(290+70+90,128+height*4+gap*4,"��¼",32,32,LIGHTRED);
    
}