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
            closegraph();//关闭画图
				delay(1000);
			    exit(0);//退出程序
        }
    }
}




void baoan_1_screen(){
    int height = 40,i;
    int lineStart_y = 80,numBlank=9;

    setbkcolor(WHITE);
    //退出按键
     setcolor(LIGHTGRAY);
     setlinestyle(DOTTED_LINE,0,NORM_WIDTH);
     rectangle(595,0,640,45);
     setlinestyle(SOLID_LINE,0,THICK_WIDTH);
     line(595,0,640,45);
     line(640,0,595,45);
    //画线
    setcolor(LIGHTGRAY);
    setlinestyle(SOLID_LINE,0,NORM_WIDTH);
    for(i = 0 ;i <= numBlank;i++){
        line(0,lineStart_y+height*i,640,lineStart_y+height*i);

    }
//画三角形
    for(i = 0;i <= numBlank ; i++){
        if(i == 0 ||i == 4){
            continue;
        }
        draw_triangle(580,lineStart_y+height*(i-1),height);
    }
    draw_triangle(280,lineStart_y+height,height);
    draw_triangle(280,lineStart_y+height*6,height);
    puthz(5,lineStart_y-29,"事故基本信息",24,24,BROWN);
    puthz(5,lineStart_y+height-29,"时间",24,24,GREEN);
    puthz(5,lineStart_y+height*2-29,"地点",24,24,GREEN);
    puthz(325,lineStart_y+height*2-29,"天气",24,24,GREEN);
    puthz(5,lineStart_y+height*3-29,"事故类型",24,24,GREEN);
    puthz(5,lineStart_y+height*4-29,"当事人信息",24,24,BROWN);
    puthz(5,lineStart_y+height*5-29,"身份证号",24,24,GREEN);
    puthz(5,lineStart_y+height*6-29,"手机号",24,24,GREEN);
    puthz(5,lineStart_y+height*7-29,"车辆类型",24,24,GREEN);
    puthz(325,lineStart_y+height*7-29,"车牌号",24,24,GREEN);
    puthz(5,lineStart_y+height*8-29,"显著受损部位",24,24,GREEN);
    puthz(5,lineStart_y+height*9-29,"对方信息",24,24,BLUE);
    puthz(300,5,"报案",32,32,RED);

}
//画向右的三角形，x，y坐标表示框的左上坐标
void draw_triangle(int x, int y, int blank_width) {
    int a,points[6];
    a = blank_width - 16; // 计算三角形的一边长度

    // 定义三角形的三个顶点
    points[0] = x;               // 第一个顶点 (x, y+5)
    points[1] = y + 8;
    points[2] = x;               // 第二个顶点 (x, y + blank_width - 5)
    points[3] = y + blank_width - 8;
    points[4] = x + 0.87 * a;    // 第三个顶点 (x + 0.87*a, y + a / 2)
    points[5] = y + 8+ a/2;

    setfillstyle(SOLID_FILL, LIGHTGRAY);  // 设置填充颜色为灰色
    setcolor(CYAN);  // 设置边框颜色为青色

    fillpoly(3, points);  // 绘制并填充三角形
}

void baoan_1_click(AccidentInfo *p){
    int height = 40;
    int lineStart_y = 80,numBlank=9;
    
    //时间
    if(mouse_press(0,lineStart_y+height*0,640,lineStart_y+height*1)==1){
        input_time(60,lineStart_y+height*0+5,p->time,1,3);
        clrmous(MouseX, MouseY);
        delay(100);
        save_bk_mou(MouseX,MouseY);
        return;
    }
    //地点
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
    //车牌号
    if(mouse_press(325,lineStart_y+height*6,640,lineStart_y+height*7)==1){
        input_province(p->per1.car.province);
        puthz(410,lineStart_y+height*6+10,p->per1.car.province,24,24,LIGHTGRAY);
        clrmous(MouseX, MouseY);
        delay(100);
        save_bk_mou(MouseX,MouseY);
        return;
    }
    //受损部位
    if(mouse_press(0,lineStart_y+height*7,640,lineStart_y+height*8)==1){
        clrmous(MouseX, MouseY);
        delay(100);
        save_bk_mou(MouseX,MouseY);
        return;
    }
    //进入对方信息
    if(mouse_press(0,lineStart_y+height*8,640,lineStart_y+height*9)==1){
        clrmous(MouseX, MouseY);
        delay(100);
        save_bk_mou(MouseX,MouseY);
    return;
    }

}