#include "common.h"
#include "login.h"
#include "verify.h"
#include "input.h"

/****
function: 画出管理端登录界面，实现登录操作
author: HUANG CHENGKAI
****/
void admin_login_screen();
int page_admin_login();

int page_admin_login() {
    int gap, height;
    char input_account[20];   // 存储用户输入的账号
    char input_pass[20];      // 存储用户输入的密码
    Admin a;
    FILE *fp;
    
    gap = 30;
    height = 35;
    input_account[0] = '\0';
    input_pass[0] = '\0';
    
    clrmous(MouseX, MouseY);
    delay(100);
    cleardevice();
    admin_login_screen();
    save_bk_mou(MouseX, MouseY);
    
    while (1) {
        mou_pos(&MouseX, &MouseY, &press);
        if(mouse_press(220,0,220+45,45)==1){
            delay(100);
            return 2;
        }
        // 输入账号
        if (mouse_press(265+65, 128, 265+65+280, 128+height) == 1) {
        	            clrmous(MouseX, MouseY);
					    delay(100);
					    save_bk_mou(MouseX,MouseY);
            setfillstyle(SOLID_FILL, LIGHTGRAY);
            bar(265+65+16, 128+5, 265+65+280, 128+height);
            input_str(265+65+16, 128+5, input_account, 1, 3, 20);
                        clrmous(MouseX, MouseY);
					    delay(100);
					    save_bk_mou(MouseX,MouseY);
        } 
        // 输入密码
        else if (mouse_press(265+65, 128+height+gap, 265+65+280, 128+height*2+gap) == 1) {
        	            clrmous(MouseX, MouseY);
					    delay(100);
					    save_bk_mou(MouseX,MouseY);
            setfillstyle(SOLID_FILL, LIGHTGRAY);
            bar(265+65+16, 128+height+gap+5, 265+65+280, 128+height*2+gap);
            input_password(265+65+16, 128+height+gap+5, input_pass, 1, 3, 20);
                        clrmous(MouseX, MouseY);
					    delay(100);
					    save_bk_mou(MouseX,MouseY);
        }
        // 点击确定按钮
        else if (mouse_press(290+70+90, 128+height*2+gap*2, 290+70+90+70, 128+height*2+gap*2+50) == 1) {
            // 清除提示区域
            setfillstyle(SOLID_FILL, WHITE);
            bar(310, 128+height*2+gap+5, 610, 128+height*2+gap+25);
            
            // 打开存有管理员账号密码的文件 admin.bat
            if ((fp = fopen("admin.dat", "rb")) == NULL) {
                puthz(310, 128+height*2+gap+5, "数据库打开失败", 16, 16, RED);
            } else {
                int login_success = 0;
                while (fread(&a, sizeof(Admin), 1, fp) == 1) {
                    if (strcmp(a.account, input_account) == 0 &&
                        strcmp(a.password, input_pass) == 0) {
                        login_success = 1;
                        break;
                    }
                }
                fclose(fp);
                
                if (login_success) {
                    puthz(310, 128+height*2+gap+5, "登录成功", 16, 16, GREEN);

                    delay(1000);
                    return 11;  // 登录成功，返回主界面编号
                } else {
                    puthz(310, 128+height*2+gap+5, "账号或密码错误", 16, 16, RED);
                }
            }
        } 
        // 点击右上角退出按钮
        else if (mouse_press(595, 0, 640, 45) == 1) {
            closegraph();
            delay(1000);
            exit(0);
        }
    }
}

void admin_login_screen() {
    int gap, height;
    gap = 30;
    height = 35;
        // 返回按键（左上角）
        setcolor(LIGHTGRAY);
        setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
        rectangle(220,0,220+45,45); // 绘制返回按钮边框
        // 绘制返回箭头（"<" 形状）
        setcolor(BLUE);
        setlinestyle(SOLID_LINE, 0, THICK_WIDTH);
        line(220+30, 15, 220+15, 22);  // 右上角到箭头尖
        line(220+15, 22, 220+30, 30);  // 箭头尖到右下角
    // 绘制退出按键
    setcolor(LIGHTGRAY);
    setlinestyle(DOTTED_LINE, 0, NORM_WIDTH);
    rectangle(595, 0, 640, 45);
    setlinestyle(SOLID_LINE, 0, THICK_WIDTH);
    line(595, 0, 640, 45);
    line(640, 0, 595, 45);
    
    // 设置背景、颜色、线条样式
    setbkcolor(WHITE);
    setcolor(BLUE);
    setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    
    // 绘制界面分割线（可选，根据需要调整）
    line(220, 0, 220, 480);
    
    // 绘制输入区域和标签
    // 账号区域
    bar(265, 128, 265+65, 128+height);          // 标签区域
    bar(265+65, 128, 265+65+280, 128+height);     // 输入区域
    // 密码区域
    bar(265, 128+height+gap, 265+65, 128+height*2+gap);
    bar(265+65, 128+height+gap, 265+65+280, 128+height*2+gap);
    
    // 绘制确定按钮
    setfillstyle(SOLID_FILL, LIGHTBLUE);
    bar(290+70+90, 128+height*2+gap*2, 290+70+90+70, 128+height*2+gap*2+50);
    
    // 绘制文本
    setcolor(BROWN);
    puthz(265, 128, "账号", 32, 32, BROWN);
    puthz(265, 128+height+gap, "密码", 32, 32, BROWN);
    puthz(290+70+90, 128+height*2+gap*2, "确定", 32, 32, LIGHTRED);

    bar(300, 50,550,100);
    puthz(300+15, 50, "管理员登录", 48, 48, BROWN);
    
	bmp_convert("C:\\PROJECT\\photo\\H.bmp","C:\\PROJECT\\photo\\H.dbm");
	show_dbm(0,0,"C:\\PROJECT\\photo\\H.dbm",0);
	puthz(5,410,"研发人：",24,24,BLUE);
	puthz(5,440,"彭减",24,24,RED);
	puthz(70,440,"黄城楷",24,24,RED);
}
