#include"common.h"
#include"verify.h"
#include"input.h"
#include"file.h"
int baoan();
void baoan_1_screen();
void draw_triangle(int x,int y,int blank_width);
void baoan_1_click(AccidentInfo *p,int *page);
void baoan_2_click(AccidentInfo *p,int *page);
void baoan_2_screen();
int verify_baoan_1(AccidentInfo *p);
int verify_baoan_2(AccidentInfo *p);
int baoan(){
    AccidentInfo x;
    int page = 1;
    int height = 40;
    int lineStart_y = 80,numBlank=9;
    //��ʼ��
    x.location[0] = x.time[0] = x.weather[0] = x.accident_type='\0';
    x.per1_phone[0] = x.per2_phone[0] = x.per2_destroied_part[0]=x.per1_destroied_part[0]='\0';
    x.per1_idcard[0] = x.per2_idcard[0] = '\0';
    x.per1_car.plate[0] = x.per2_car.plate[0] = '\0';
    while (1)
    {
        switch (page)
        {
        case 1:
        baoan_1_screen();
        while(page ==1){
            mou_pos(&MouseX,&MouseY,&press);
            baoan_1_click(&x,&page);
            if(mouse_press(595,0,640,45)==1){
                    closegraph();//�رջ�ͼ
                    delay(1000);
                    exit(0);//�˳�����
            }
        }
            break;
        
        case 2:
        
        cleardevice();
        baoan_2_screen();
        puthz(50,lineStart_y+height*1+10,x.location,24,24,LIGHTGRAY);
        puthz(400,lineStart_y+height*1+10,x.weather,24,24,LIGHTGRAY);
        put_accident_type(x.accident_type,100,lineStart_y+height*2+10,24,24,LIGHTGRAY);
    
        while(1){
            mou_pos(&MouseX,&MouseY,&press);
            baoan_2_click(&x,&page);
            if(mouse_press(595,0,640,45)==1){
                    closegraph();//�رջ�ͼ
                    delay(1000);
                    exit(0);//�˳�����
            }
        }
            break;
        
        default:
            break;
        }
    }
    return page;
}






void baoan_1_screen(){
    int height = 40,i;
    int lineStart_y = 80,numBlank=9;

    setbkcolor(WHITE);
    //�˳�����
     setcolor(LIGHTGRAY);
     setlinestyle(DOTTED_LINE,0,NORM_WIDTH);
     rectangle(595,0,640,45);
     setlinestyle(SOLID_LINE,0,THICK_WIDTH);
     line(595,0,640,45);
     line(640,0,595,45);
    //����
    setcolor(LIGHTGRAY);
    setlinestyle(SOLID_LINE,0,NORM_WIDTH);
    for(i = 0 ;i <= numBlank;i++){
        line(0,lineStart_y+height*i,640,lineStart_y+height*i);

    }
//��������
    for(i = 0;i <= numBlank ; i++){
        if(i == 0 ||i == 4){
            continue;
        }
        draw_triangle(580,lineStart_y+height*(i-1),height);
    }
    draw_triangle(280,lineStart_y+height,height);
    draw_triangle(280,lineStart_y+height*6,height);
    puthz(5,lineStart_y-29,"�¹ʻ�����Ϣ",24,24,BROWN);
    puthz(5,lineStart_y+height-29,"ʱ��",24,24,GREEN);
    puthz(5,lineStart_y+height*2-29,"�ص�",24,24,GREEN);
    puthz(325,lineStart_y+height*2-29,"����",24,24,GREEN);
    puthz(5,lineStart_y+height*3-29,"�¹�����",24,24,GREEN);
    puthz(5,lineStart_y+height*4-29,"��������Ϣ",24,24,BROWN);
    puthz(5,lineStart_y+height*5-29,"���֤��",24,24,GREEN);
    puthz(5,lineStart_y+height*6-29,"�ֻ���",24,24,GREEN);
    puthz(5,lineStart_y+height*7-29,"��������",24,24,GREEN);
    puthz(325,lineStart_y+height*7-29,"���ƺ�",24,24,GREEN);
    puthz(5,lineStart_y+height*8-29,"��������λ",24,24,GREEN);
    puthz(5,lineStart_y+height*9-29,"�Է���Ϣ",24,24,BLUE);
    puthz(300,5,"����",32,32,RED);

}
//�����ҵ������Σ�x��y�����ʾ�����������
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

void baoan_1_click(AccidentInfo *p,int *page){
    int height = 40;
    int lineStart_y = 80,numBlank=9;
    
    //ʱ��
    if(mouse_press(0,lineStart_y+height*0,640,lineStart_y+height*1)==1){
        input_time(60,lineStart_y+height*0+5,p->time,1,3);
        clrmous(MouseX, MouseY);
        delay(100);
        save_bk_mou(MouseX,MouseY);
        return;
    }
    //�ص�
    if(mouse_press(0,lineStart_y+height*1,325,lineStart_y+height*2)==1){
        setfillstyle(SOLID_FILL,WHITE);
        bar(50,lineStart_y+height*1+10,150,lineStart_y+height*1+10+28);
        input_location(p->location);
        puthz(50,lineStart_y+height*1+10,p->location,24,24,LIGHTGRAY);
        clrmous(MouseX, MouseY);
        delay(100);
        save_bk_mou(MouseX,MouseY);
    return;
    }
    //weather
    if(mouse_press(325,lineStart_y+height*1,640,lineStart_y+height*2)==1){
        input_weather(p->weather);
        puthz(400,lineStart_y+height*1+10,p->weather,24,24,LIGHTGRAY);
        clrmous(MouseX, MouseY);
        delay(100);
        save_bk_mou(MouseX,MouseY);
        return;
    }
    //accident type
    if(mouse_press(0,lineStart_y+height*2,640,lineStart_y+height*3)==1){
        input_accident_type(&(p->accident_type));
        put_accident_type(p->accident_type,100,lineStart_y+height*2+10,24,24,LIGHTGRAY);
        clrmous(MouseX, MouseY);
        delay(100);
        save_bk_mou(MouseX,MouseY);
        return;
    }
    //id card
    if(mouse_press(0,lineStart_y+height*4,640,lineStart_y+height*5)==1){
        input_str(100,lineStart_y+height*4+10,p->per1_idcard,1,3,18);
        clrmous(MouseX, MouseY);
        delay(100);
        save_bk_mou(MouseX,MouseY);
        return;
    }
    //phone number
    if(mouse_press(0,lineStart_y+height*5,640,lineStart_y+height*6)==1){
        input_str(100,lineStart_y+height*5+10,p->per1_phone,1,3,11);
        clrmous(MouseX, MouseY);
        delay(100);
        save_bk_mou(MouseX,MouseY);
        return;
    }
    //car type
    if(mouse_press(0,lineStart_y+height*6,325,lineStart_y+height*7)==1){
        input_car_type(p->per1_car.type);
        puthz(120,lineStart_y+height*6+10,p->per1_car.type,24,24,LIGHTGRAY);
        clrmous(MouseX, MouseY);
        delay(100);
        save_bk_mou(MouseX,MouseY);
        return;
    }
    //���ƺ�
    if(mouse_press(325,lineStart_y+height*6,640,lineStart_y+height*7)==1){
        input_province(p->per1_car.province);
        puthz(410,lineStart_y+height*6+10,p->per1_car.province,24,24,LIGHTGRAY);
        input_str(430,lineStart_y+height*6+10,p->per1_car.plate,1,3,6);
        clrmous(MouseX, MouseY);
        delay(100);
        save_bk_mou(MouseX,MouseY);
        return;
    }
    //����λ
    if(mouse_press(0,lineStart_y+height*7,640,lineStart_y+height*8)==1){
        input_destroy_part(p->per1_destroied_part);
        puthz(160,lineStart_y+height*7+10,p->per1_destroied_part,24,24,LIGHTGRAY);
        clrmous(MouseX, MouseY);
        delay(100);
        save_bk_mou(MouseX,MouseY);
        return;
    }
    //����Է���Ϣ
    if(mouse_press(0,lineStart_y+height*8,640,lineStart_y+height*9)==1){
        if(verify_baoan_1(p)==1){
            *page =2;
            clrmous(MouseX, MouseY);
            delay(100);
            save_bk_mou(MouseX,MouseY);

        }
        clrmous(MouseX, MouseY);
        delay(100);
        save_bk_mou(MouseX,MouseY);
    return;
    }

}


void baoan_2_screen(){
    int height = 40,i;
    int lineStart_y = 80,numBlank=8;

    setbkcolor(WHITE);
    //�˳�����
     setcolor(LIGHTGRAY);
     setlinestyle(DOTTED_LINE,0,NORM_WIDTH);
     rectangle(595,0,640,45);
     setlinestyle(SOLID_LINE,0,THICK_WIDTH);
     line(595,0,640,45);
     line(640,0,595,45);
    //����
    setcolor(LIGHTGRAY);
    setlinestyle(SOLID_LINE,0,NORM_WIDTH);
    for(i = 0 ;i <= numBlank;i++){
        line(0,lineStart_y+height*i,640,lineStart_y+height*i);

    }
//��������
    for(i = 0;i <= numBlank ; i++){
        if(i == 0 ||i == 4){
            continue;
        }
        draw_triangle(580,lineStart_y+height*(i-1),height);
    }
    draw_triangle(280,lineStart_y+height,height);
    draw_triangle(280,lineStart_y+height*6,height);
    //����һ����ť
    setcolor(GREEN);
    setfillstyle(SOLID_FILL,GREEN);
    rectangle(270,lineStart_y+height*8+5,390,lineStart_y+height*8+40);
    puthz(280,lineStart_y+height*8+5,"��һ��",32,32,GREEN);

    puthz(5,lineStart_y-29,"�¹ʻ�����Ϣ",24,24,BROWN);
    puthz(5,lineStart_y+height-29,"ʱ��",24,24,GREEN);
    puthz(5,lineStart_y+height*2-29,"�ص�",24,24,GREEN);
    puthz(325,lineStart_y+height*2-29,"����",24,24,GREEN);
    puthz(5,lineStart_y+height*3-29,"�¹�����",24,24,GREEN);
    puthz(5,lineStart_y+height*4-29,"�Է���Ϣ",24,24,BROWN);
    puthz(5,lineStart_y+height*5-29,"���֤��",24,24,GREEN);
    puthz(5,lineStart_y+height*6-29,"�ֻ���",24,24,GREEN);
    puthz(5,lineStart_y+height*7-29,"��������",24,24,GREEN);
    puthz(325,lineStart_y+height*7-29,"���ƺ�",24,24,GREEN);
    puthz(5,lineStart_y+height*8-29,"��������λ",24,24,GREEN);
    
    puthz(300,5,"����",32,32,RED);

    


}

void baoan_2_click(AccidentInfo *p,int *page){

    int height = 40;
    int lineStart_y = 80,numBlank=9;
    
    //ʱ��
    if(mouse_press(0,lineStart_y+height*0,640,lineStart_y+height*1)==1){
        input_time(60,lineStart_y+height*0+5,p->time,1,3);
        clrmous(MouseX, MouseY);
        delay(100);
        save_bk_mou(MouseX,MouseY);
        return;
    }
    //�ص�
    if(mouse_press(0,lineStart_y+height*1,325,lineStart_y+height*2)==1){
        setfillstyle(SOLID_FILL,WHITE);
        bar(50,lineStart_y+height*1+10,150,lineStart_y+height*1+10+28);
        input_location(p->location);
        puthz(50,lineStart_y+height*1+10,p->location,24,24,LIGHTGRAY);
        clrmous(MouseX, MouseY);
        delay(100);
        save_bk_mou(MouseX,MouseY);
    return;
    }
    //weather
    if(mouse_press(325,lineStart_y+height*1,640,lineStart_y+height*2)==1){
        input_weather(p->weather);
        puthz(400,lineStart_y+height*1+10,p->weather,24,24,LIGHTGRAY);
        clrmous(MouseX, MouseY);
        delay(100);
        save_bk_mou(MouseX,MouseY);
        return;
    }
    //accident type
    if(mouse_press(0,lineStart_y+height*2,640,lineStart_y+height*3)==1){
        input_accident_type(&(p->accident_type));
        put_accident_type(p->accident_type,100,lineStart_y+height*2+10,24,24,LIGHTGRAY);
        clrmous(MouseX, MouseY);
        delay(100);
        save_bk_mou(MouseX,MouseY);
        return;
    }
    //id card
    if(mouse_press(0,lineStart_y+height*4,640,lineStart_y+height*5)==1){
        input_str(100,lineStart_y+height*4+10,p->per2_idcard,1,3,18);
        clrmous(MouseX, MouseY);
        delay(100);
        save_bk_mou(MouseX,MouseY);
        return;
    }
    //phone number
    if(mouse_press(0,lineStart_y+height*5,640,lineStart_y+height*6)==1){
        input_str(100,lineStart_y+height*5+10,p->per2_phone,1,3,11);
        clrmous(MouseX, MouseY);
        delay(100);
        save_bk_mou(MouseX,MouseY);
        return;
    }
    //car type
    if(mouse_press(0,lineStart_y+height*6,325,lineStart_y+height*7)==1){
        input_car_type(p->per2_car.type);
        puthz(120,lineStart_y+height*6+10,p->per2_car.type,24,24,LIGHTGRAY);
        clrmous(MouseX, MouseY);
        delay(100);
        save_bk_mou(MouseX,MouseY);
        return;
    }
    //���ƺ�
    if(mouse_press(325,lineStart_y+height*6,640,lineStart_y+height*7)==1){
        input_province(p->per2_car.province);
        puthz(410,lineStart_y+height*6+10,p->per2_car.province,24,24,LIGHTGRAY);
        input_str(430,lineStart_y+height*6+10,p->per2_car.plate,1,3,6);
        clrmous(MouseX, MouseY);
        delay(100);
        save_bk_mou(MouseX,MouseY);
        return;
    }
    //����λ
    if(mouse_press(0,lineStart_y+height*7,640,lineStart_y+height*8)==1){
        input_destroy_part(p->per2_destroied_part);
        puthz(160,lineStart_y+height*7+10,p->per2_destroied_part,24,24,LIGHTGRAY);
        clrmous(MouseX, MouseY);
        delay(100);
        save_bk_mou(MouseX,MouseY);
        return;
    }
    
    //��һ��
    if(mouse_press(270,lineStart_y+height*8+5,390,lineStart_y+height*8+40)==1){
        if(verify_baoan_2(p)==1){
            if(save_accident_info(p)==1){
                puthz(250,450,"�����ɹ�",16,16,GREEN);
                *page =3;
            }else{
                puthz(250,450,"����ʧ��",16,16,RED);
            }
            clrmous(MouseX, MouseY);
            delay(100);
            save_bk_mou(MouseX,MouseY);
            return;
        }
        clrmous(MouseX, MouseY);
        delay(100);
        save_bk_mou(MouseX,MouseY);
        return;
    }

}
/*
function:��֤��Ϣ�Ƿ��걸���걸����1������������㲢����-1
author:CHENGKAI HAUNG
time:2025/3/9
 */

int verify_baoan_1(AccidentInfo *p){
    //time
    if(strlen(p->time)!=16){
        puthz(250,450,"ʱ���������",16,16,RED);
        return -1;
    }
    //location
    if(p->location[0]=='\0'){
        puthz(250,450,"�������¹ʷ����ص�",16,16,RED);
        return -1;
    }
    //weather
    if(p->weather[0]=='\0'){
        puthz(250,450,"�������·�ʱ����",16,16,RED);
        return -1;
    }
    //type
    if(p->accident_type=='\0'){
        puthz(250,450,"�������¹�����",16,16,RED);
        return -1;
    }
    //per_1_idcard
    if(validate_idcard(p->per1_idcard)!=1){
        puthz(250,450,"���֤�������",16,16,RED);
        return -1;
    }
    //per_1_phone
    if(validate_phone(p->per1_phone)!=1){
        puthz(250,450,"�ֻ����������",16,16,RED);
        return -1;
    }
    //per_1_type
    if(p->per1_car.type[0]=='\0'){
        puthz(250,450,"�����복������",16,16,RED);
        return -1;
    }
    //per_1_carplate
    if(validate_licence_car(p->per1_car.plate)!=1){
        puthz(250,450,"���ƺ��������",16,16,RED);
        return -1;
    }
    //per_1_despart
    if(p->per1_destroied_part[0]=='\0'){
        puthz(250,450,"����������λ",16,16,RED);
        return -1;
    }

    

     return 1;
}
int verify_baoan_2(AccidentInfo *p){
     //time
     if(strlen(p->time)!=16){
        puthz(250,450,"ʱ���������",16,16,RED);
        return -1;
    }
    //location
    if(p->location[0]=='\0'){
        puthz(250,450,"�������¹ʷ����ص�",16,16,RED);
        return -1;
    }
    //weather
    if(p->weather[0]=='\0'){
        puthz(250,450,"�������·�ʱ����",16,16,RED);
        return -1;
    }
    //type
    if(p->accident_type=='\0'){
        puthz(250,450,"�������¹�����",16,16,RED);
        return -1;
    }
     //per_2_idcard
     if(validate_idcard(p->per2_idcard)!=1){
        puthz(250,450,"���֤���������",16,16,RED);
        return -1;
     }
     //per_2_phone
     if(validate_phone(p->per2_phone)!=1){
        puthz(250,450,"�ֻ����������",16,16,RED);
        return -1;
     }
     //per_2_type
     if(p->per2_car.type[0]=='\0'){
        puthz(250,450,"�����복������",16,16,RED);
        return -1;
     }
     //per_2_carplate
     if(validate_licence_car(p->per2_car.plate)!=1){
        puthz(250,450,"���ƺ��������",16,16,RED);
        return -1;
     }
     //per_2_despart
     if(p->per2_destroied_part[0]=='\0'){
        puthz(250,450,"����������λ",16,16,RED);
        return -1;
     }
}