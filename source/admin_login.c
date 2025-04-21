#include "common.h"
#include "login.h"
#include "verify.h"
#include "input.h"

/****
function: ��������˵�¼���棬ʵ�ֵ�¼����
author: HUANG CHENGKAI
****/
void admin_login_screen();
int page_admin_login();

int page_admin_login() {
    int gap, height;
    char input_account[20];   // �洢�û�������˺�
    char input_pass[20];      // �洢�û����������
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
        // �����˺�
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
        // ��������
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
        // ���ȷ����ť
        else if (mouse_press(290+70+90, 128+height*2+gap*2, 290+70+90+70, 128+height*2+gap*2+50) == 1) {
            // �����ʾ����
            setfillstyle(SOLID_FILL, WHITE);
            bar(310, 128+height*2+gap+5, 610, 128+height*2+gap+25);
            
            // �򿪴��й���Ա�˺�������ļ� admin.bat
            if ((fp = fopen("admin.dat", "rb")) == NULL) {
                puthz(310, 128+height*2+gap+5, "���ݿ��ʧ��", 16, 16, RED);
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
                    puthz(310, 128+height*2+gap+5, "��¼�ɹ�", 16, 16, GREEN);

                    delay(1000);
                    return 11;  // ��¼�ɹ���������������
                } else {
                    puthz(310, 128+height*2+gap+5, "�˺Ż��������", 16, 16, RED);
                }
            }
        } 
        // ������Ͻ��˳���ť
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
        // ���ذ��������Ͻǣ�
        setcolor(LIGHTGRAY);
        setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
        rectangle(220,0,220+45,45); // ���Ʒ��ذ�ť�߿�
        // ���Ʒ��ؼ�ͷ��"<" ��״��
        setcolor(BLUE);
        setlinestyle(SOLID_LINE, 0, THICK_WIDTH);
        line(220+30, 15, 220+15, 22);  // ���Ͻǵ���ͷ��
        line(220+15, 22, 220+30, 30);  // ��ͷ�⵽���½�
    // �����˳�����
    setcolor(LIGHTGRAY);
    setlinestyle(DOTTED_LINE, 0, NORM_WIDTH);
    rectangle(595, 0, 640, 45);
    setlinestyle(SOLID_LINE, 0, THICK_WIDTH);
    line(595, 0, 640, 45);
    line(640, 0, 595, 45);
    
    // ���ñ�������ɫ��������ʽ
    setbkcolor(WHITE);
    setcolor(BLUE);
    setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    
    // ���ƽ���ָ��ߣ���ѡ��������Ҫ������
    line(220, 0, 220, 480);
    
    // ������������ͱ�ǩ
    // �˺�����
    bar(265, 128, 265+65, 128+height);          // ��ǩ����
    bar(265+65, 128, 265+65+280, 128+height);     // ��������
    // ��������
    bar(265, 128+height+gap, 265+65, 128+height*2+gap);
    bar(265+65, 128+height+gap, 265+65+280, 128+height*2+gap);
    
    // ����ȷ����ť
    setfillstyle(SOLID_FILL, LIGHTBLUE);
    bar(290+70+90, 128+height*2+gap*2, 290+70+90+70, 128+height*2+gap*2+50);
    
    // �����ı�
    setcolor(BROWN);
    puthz(265, 128, "�˺�", 32, 32, BROWN);
    puthz(265, 128+height+gap, "����", 32, 32, BROWN);
    puthz(290+70+90, 128+height*2+gap*2, "ȷ��", 32, 32, LIGHTRED);

    bar(300, 50,550,100);
    puthz(300+15, 50, "����Ա��¼", 48, 48, BROWN);
    
	bmp_convert("C:\\PROJECT\\photo\\H.bmp","C:\\PROJECT\\photo\\H.dbm");
	show_dbm(0,0,"C:\\PROJECT\\photo\\H.dbm",0);
	puthz(5,410,"�з��ˣ�",24,24,BLUE);
	puthz(5,440,"���",24,24,RED);
	puthz(70,440,"�Ƴǿ�",24,24,RED);
}
