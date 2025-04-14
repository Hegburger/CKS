#include"input.h"
#include"common.h"
#include"verify.h"
#include"mouse.h"
/*
������
���
*/
void screen(char *user_idcard);
int page_screen(char*user_idcard);
int page_screen(char *user_idcard)
{
	int height=40;
	int longer=60;
	int y=30;
	int i;
	clrmous(MouseX,MouseY);
	delay(100);
	cleardevice();
	screen(user_idcard);
	save_bk_mou(MouseX,MouseY);
	while(1)
	{
		mou_pos(&MouseX,&MouseY,&press);
		if(mouse_press(595,0,640,45)==1)//�˳��� 
		{
			closegraph();
			delay(1000);
			exit(0);
		}
		//ת����������
		if(mouse_press(50+50,440,50+longer+50,440+height)==1)//��������
		{
			return 4;
		}
		if(mouse_press(50+50+longer+40,440,50+50+longer*2+40,440+height)==1)//��ʷ����
		{
			return 5;
		}
		if(mouse_press(50+50+longer*2+40*2,440,50+50+longer*3+40*2,440+height)==1)//���˽���
		{
		    return 6;
		}
		if(mouse_press(300,360,380,400)==1)//��ͼ����
		{
			return 8;
		}
        if(mouse_press(50+50+longer*3+40*3,440,50+50+longer*4+40*3,440+height)==1){
            //����
            return 9;
        }
	}
}
void screen(char *user_idcard)
{
	FILE *fp;
	char accident_type[20];
	int height=40;
	int longer=60;
	int y=30;
	int i;
    AccidentInfo incident;
    int current_row = 0;
    int display_y;
	setbkcolor(WHITE);
	//�˳���
	setcolor(LIGHTGRAY);
	setlinestyle(DOTTED_LINE,0,NORM_WIDTH);
	rectangle(595,0,640,45);
    setlinestyle(SOLID_LINE,0,THICK_WIDTH);
    line(595,0,640,45);
    line(640,0,595,45);
    //�¹ʹ���
    puthz(250,12,"�¹ʹ���",32,32,LIGHTGRAY);
    //����֪ͨ
    puthz(50,30+12+y,"�¹�ʱ��",24,24,LIGHTGRAY);
    puthz(50+250,30+y+12,"�¹�����",24,24,LIGHTGRAY);
    puthz(50+250*2-40,30+y+12,"����״̬",24,24,LIGHTGRAY);
    //��ͼ��ť
    puthz(50,360+12,"�ڵ�ͼ�в鿴����",24,24,LIGHTGRAY);
    setfillstyle(SOLID_FILL,GREEN);
    bar(300,360,380,400);
    puthz(300+25,360+12,"��ͼ",24,24,WHITE);
    //������Ϣ��ť
    setfillstyle(SOLID_FILL,BLUE);
    bar(50+50,440,50+longer+50,440+height);
    bar(50+50+longer+40,440,50+50+longer*2+40,440+height);
    bar(50+50+longer*2+40*2,440,50+50+longer*3+40*2,440+height);
    bar(50+50+longer*3+40*3,440,50+50+longer*4+40*3,440+height);
    puthz(50+50,440+8,"����",24,24,WHITE);
    puthz(50+50+longer+40,440+8,"��ʷ",24,24,WHITE);
    puthz(50+50+longer*2+40*2,440+8,"����",24,24,WHITE);
    puthz(50+50+longer*3+40*3,440+8,"����",24,24,WHITE);
    // �򿪶������¹������ļ�
    fp = fopen("ACCIDENT.dat", "rb");
    if (fp == NULL) {
        puthz(50, 300, "���¹ʹ��棡",16,16,RED);
        getch();
        closegraph();
        return;
    }


    // �����ļ��е������¹ʼ�¼
    while (fread(&incident, sizeof(AccidentInfo), 1, fp) == 1) {
        // ����Ƿ�Ϊ���û��ļ�¼��ƥ�����֤��
        if (strcmp(incident.per1_idcard, user_idcard) == 0 ||
            strcmp(incident.per2_idcard, user_idcard) == 0) {
            current_row++;
            display_y = 30+y+12 + current_row * y;
            // ��ʾ�¹ʷ���ʱ��
            settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
            outtextxy(20, display_y+5, incident.time);
            // ��ʾ�¹����ͣ�ת��Ϊ����������
            //puthz(col_type, display_y, "�¹�����",16,16,GRAY);
            accident_type_trans(incident.accident_type,accident_type);
            puthz(300, display_y,accident_type,24,24,LIGHTGRAY);
            // ��ʾ����״̬������Ĭ����ʾ���Ѵ���
            if(incident.processed_status=='1')
            {
                puthz(50+250*2, display_y, "�Ѵ���",24,24,LIGHTGRAY);	
			}
			else 
			{
	            puthz(50+250*2, display_y, "δ����",24,24,LIGHTGRAY);
			}
        }
    }
    fclose(fp);

    // ���δ�ҵ��κμ�¼������ʾ��ʾ��Ϣ
    if (current_row == 0) {
        puthz(50, 30+y+12+y, "û���ҵ���ؼ�¼",24,24,LIGHTGRAY);
    }

}











