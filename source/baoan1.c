#include"common.h"
#include"verify.h"
#include"input.h"
void baoan_1_screen();
int baoan_1();
void draw_triangle(int x,int y,int blank_width);
void baoan_1_click(AccidentInfo *p);
int baoan_1(){
    AccidentInfo x;
    x.location[0] = x.time[0] = x.weather[0] = '\0';

    baoan_1_screen();
    while(1){
        mou_pos(&MouseX,&MouseY,&press);
        baoan_1_click(&x);
        if(mouse_press(595,0,640,45)==1){
            closegraph();//�رջ�ͼ
				delay(1000);
			    exit(0);//�˳�����
        }
    }
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

void baoan_1_click(AccidentInfo *p){
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
        input_str(100,lineStart_y+height*4+10,p->per1.idcard,1,3,18);
        clrmous(MouseX, MouseY);
        delay(100);
        save_bk_mou(MouseX,MouseY);
        return;
    }
    //phone number
    if(mouse_press(0,lineStart_y+height*5,640,lineStart_y+height*6)==1){
        input_str(100,lineStart_y+height*5+10,p->per1.phone,1,3,11);
        clrmous(MouseX, MouseY);
        delay(100);
        save_bk_mou(MouseX,MouseY);
        return;
    }
    //car type
    if(mouse_press(0,lineStart_y+height*6,325,lineStart_y+height*7)==1){
        input_car_type(p->per1.car.type);
        puthz(120,lineStart_y+height*6+10,p->per1.car.type,24,24,LIGHTGRAY);
        clrmous(MouseX, MouseY);
        delay(100);
        save_bk_mou(MouseX,MouseY);
        return;
    }
    //���ƺ�
    if(mouse_press(325,lineStart_y+height*6,640,lineStart_y+height*7)==1){
        input_province(p->per1.car.province);
        puthz(410,lineStart_y+height*6+10,p->per1.car.province,24,24,LIGHTGRAY);
        clrmous(MouseX, MouseY);
        delay(100);
        save_bk_mou(MouseX,MouseY);
        return;
    }
    //����λ
    if(mouse_press(0,lineStart_y+height*7,640,lineStart_y+height*8)==1){
        clrmous(MouseX, MouseY);
        delay(100);
        save_bk_mou(MouseX,MouseY);
        return;
    }
    //����Է���Ϣ
    if(mouse_press(0,lineStart_y+height*8,640,lineStart_y+height*9)==1){
        clrmous(MouseX, MouseY);
        delay(100);
        save_bk_mou(MouseX,MouseY);
    return;
    }

}