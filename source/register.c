#include"common.h"
#include"verify.h"
#include"input.h"
/****
function:画出注册界面完成注册操作
author:Chengkai Huang
*****/
void register_screen();
int page_register();
int page_register(){
    int gap,height;
    char password[20];
    user x;
    FILE *fw;
    gap = 30; 
    height = 35; 
    password[0]='\0';
    x.id[0] = x.name[0] = x.password[0] = x.phone[0] = '\0';

    clrmous(MouseX,MouseY);
    delay(100);
    cleardevice();
    register_screen();
    save_bk_mou(MouseX,MouseY);
    while(1){
        mou_pos(&MouseX,&MouseY,&press);
        if(mouse_press(265+65,128,265+65+280,128+height)==1){
            input_str(265+65+16,128+5,x.phone,0,3);
        }else if(mouse_press(265+65,128+height+gap,265+65+280,128+height*2+gap)==1){
            input_str(265+65+16,128+height+gap+5,x.name,0,3);
        }else if(mouse_press(265+65,128+height*2+gap*2,265+65+280,128+height*3+gap*2)==1){
            input_str(265+65+16,128+height*2+gap*2+5,x.password,0,3);
        }else if(mouse_press(265+65,128+height*3+gap*3,265+65+280,128+height*4+gap*3)==1){
            input_str(265+65+16,128+height*3+gap*3+5,password,0,3);
        }else if(mouse_press(290,128+height*4+gap*4,290+70,128+height*4+gap*4+50)==1){
        if(validate_phone(x.phone)==1){
            if(len_verify(x.name,3,18)==1){
                if(strcmp(x.password,password)==0){
                    if(validate_password(x.password)==1){
                        if((fw = fopen("list.dat","ab"))==NULL){
                            puthz(310,128+height*4+gap*3+5,"数据库打开失败",16,16,RED);    //打开文件失败
                        }else{
                            fwrite(&x,sizeof(user),1,fw);
                            fclose(fw);
                            puthz(310,128+height*4+gap*3+5,"注册成功",16,16,RED);//完成注册
                            delay(1000);
                            clrmous(MouseX,MouseY);
                            return 2;
                        }
                    }else{
                        puthz(310,128+height*4+gap*3+5,"密码至少含三种字符且长度合适",16,16,RED);//密码不合法
                    }
                }else{
                    puthz(310,128+height*4+gap*3+5,"密码不一致",16,16,RED);
                }
            }else{
                puthz(310,128+height*4+gap*3+5,"用户名长度不合适",16,16,RED);//id 3-18位
            }
        }else{
            puthz(310,128+height*4+gap*3+5,"手机号不合法",16,16,RED);//手机号不合法
        }
        }else if(mouse_press(290+70+90,128+height*4+gap*4,290+70+90+70,128+height*4+gap*4+50)==1){
            return 2;//进入登录页面
        }else if(mouse_press(595,0,640,45)==1){
            closegraph();//关闭画图
				delay(1000);
			    exit(0);//退出程序
        }
    }
}



void register_screen(){
    int gap,height,i;
    gap = 30; //琛岄棿璺?
    height = 35; //琛岄珮
    //退出按键
    setcolor(LIGHTGRAY);
    setlinestyle(DOTTED_LINE,0,NORM_WIDTH);
    rectangle(595,0,640,45);
    setlinestyle(SOLID_LINE,0,THICK_WIDTH);
    line(595,0,640,45);
    line(640,0,595,45);
    //其他
    setbkcolor(WHITE);
    setcolor(BLUE);
    setlinestyle(SOLID_LINE,0,NORM_WIDTH);
    setfillstyle(SOLID_FILL,LIGHTGRAY);
    line(220,0,220,480);
    bar(350,50,350+132,50+58);//鈥滄敞鍐屸�?
    bar(265,128,265+65,128+height);//鈥滄墜鏈哄彿鈥?
    bar(265+65,128,265+65+280,128+height);
    
    bar(265,128+height+gap,265+65,128+height*2+gap);//鈥滅敤鎴峰悕鈥?
    bar(265+65,128+height+gap,265+65+280,128+height*2+gap);

    bar(265,128+height*2+gap*2,265+65,128+height*3+gap*2);//鈥渟erect鈥?
    bar(265+65,128+height*2+gap*2,265+65+280,128+height*3+gap*2);

    bar(265,128+height*3+gap*3,265+65,128+height*4+gap*3);//鈥渟ecret again鈥?
    bar(265+65,128+height*3+gap*3,265+65+280,128+height*4+gap*3);

    setfillstyle(SOLID_FILL,LIGHTBLUE);
    bar(290,128+height*4+gap*4,290+70,128+height*4+gap*4+50);//纭
    bar(290+70+90,128+height*4+gap*4,290+70+90+70,128+height*4+gap*4+50);//鐧诲綍

    setcolor(BROWN);
    for(i =0;i<4;i++){
        line(265+80,128+height*i+gap*i,265+80,128+height*(i+1)+gap*i);
    }
    puthz(350+15,50,"注册",48,48,BROWN);
    puthz(265,128,"手机号",24,24,BROWN);
    puthz(270,128+height+gap,"用户名",24,24,BROWN);
    puthz(270,128+height*2+gap*2,"密码",24,24,BROWN);
    puthz(270,128+height*3+gap*3+10,"确定密码",16,16,BROWN);
    puthz(290,128+height*4+gap*4,"确定",32,32,LIGHTRED);
    puthz(290+70+90,128+height*4+gap*4,"登录",32,32,LIGHTRED);
    
}