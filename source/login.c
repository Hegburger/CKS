#include "common.h"
#include "login.h"
#include "verify.h"
#include "input.h"
/****
function:画出登录界面，实现登录操作
author:Chengkai Huang
*****/
void login_screen();
int page_login(char *phone_nuber,char *id_card);

int page_login(char *phone_nuber,char *id_card) {
    int gap, height;
    char input_name[20];   // 存储用户输入的手机号或用户名
    char password[20];   // 存储用户输入的密码
    User x;
    FILE *fr;
    
    gap = 30;
    height = 35;
    input_name[0] = '\0';
    password[0] = '\0';
    clrmous(MouseX, MouseY);
    delay(100);
    cleardevice();
    login_screen();
    save_bk_mou(MouseX,MouseY);
    while (1) {
        mou_pos(&MouseX, &MouseY, &press);
        
        if (mouse_press(265+65, 128, 265+65+280, 128+height) == 1) {
            setfillstyle(SOLID_FILL,LIGHTGRAY);
            bar(265+120+1,128, 265+65+280, 128+height);
            input_str(265+120+16, 128+5, input_name, 1, 3,20);
        } else if (mouse_press(265+65, 128+height+gap, 265+65+280, 128+height*2+gap) == 1) {
            setfillstyle(SOLID_FILL,LIGHTGRAY);
            bar(265+65+16, 128+height+gap, 265+65+280, 128+height*2+gap);
            input_password(265+65+16, 128+height+gap+5, password, 1, 3,20);
        } else if (mouse_press(290+70+90, 128+height*2+gap*2, 290+70+90+70, 128+height*2+gap*2+50) == 1) {
            //更新提示行
            setfillstyle(SOLID_FILL,WHITE);
            bar(310,128+height*2+gap+5,610,128+height*2+gap+25);
            if ((fr = fopen("list.dat", "rb")) == NULL) {
                puthz(310, 128+height*2+gap*2+5, "数据库打开失败", 16, 16, RED);
            } else {
                int login_success = 0;
                
                while (fread(&x, sizeof(User), 1, fr)) {
                    if ((strcmp(x.phone, input_name) == 0 || strcmp(x.username, input_name) == 0) &&
                        strcmp(x.password, password) == 0) {
                        login_success = 1;
                        break;
                    }
                }
                fclose(fr);

                if (login_success) {
                    puthz(310, 128+height*2+gap+5, "登录成功", 16, 16, GREEN);
                    strcpy(phone_nuber,x.phone);
                    strcpy(id_card,x.idcard);
                    delay(1000);
                    return 3;  // 登录成功，跳转到主界面
                } else {
                    puthz(310, 128+height*2+gap+5, "手机号用户名或密码错误", 16, 16, RED);
                }
            }
        } else if (mouse_press(290, 128+height*2+gap*2, 290+70, 128+height*2+gap*2+50) == 1) {
            return 1;  // 进入注册界面
        } else if (mouse_press(595, 0, 640, 45) == 1) {
            closegraph();
            delay(1000);
            exit(0);
        }
    }
}

void login_screen() {
    int gap, height, i;
    gap = 30;
    height = 35;

    // 退出按键
    setcolor(LIGHTGRAY);
    setlinestyle(DOTTED_LINE, 0, NORM_WIDTH);
    rectangle(595, 0, 640, 45);
    setlinestyle(SOLID_LINE, 0, THICK_WIDTH);
    line(595, 0, 640, 45);
    line(640, 0, 595, 45);

    // 其他UI界面元素
    setbkcolor(WHITE);
    setcolor(BLUE);
    setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    
    line(220, 0, 220, 480);
    
    bar(350, 50, 350+132, 50+58);
    bar(265, 128, 265+65, 128+height);
    bar(265+65, 128, 265+65+280, 128+height);
    
    bar(265, 128+height+gap, 265+65, 128+height*2+gap);
    bar(265+65, 128+height+gap, 265+65+280, 128+height*2+gap);

    setfillstyle(SOLID_FILL, LIGHTBLUE);
    bar(290, 128+height*2+gap*2, 290+70, 128+height*2+gap*2+50);
    bar(290+70+90, 128+height*2+gap*2, 290+70+90+70, 128+height*2+gap*2+50);

    setcolor(BROWN);
    line(265+120,128,265+120,128+height);
    line(265+80,128+height+gap,265+80,128+height*2+gap);
    puthz(350+15, 50, "登录", 48, 48, BROWN);
    puthz(265, 128, "手机号或用户名", 16, 16, BROWN);
    puthz(270, 128+height+gap, "密码", 24, 24, BROWN);
    puthz(290, 128+height*2+gap*2, "注册", 32, 32, LIGHTRED);
    puthz(290+70+90, 128+height*2+gap*2, "确定", 32, 32, LIGHTRED);
}
