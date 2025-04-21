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
        if(mouse_press(0, 0, 45, 45)==1){
            return 2;//���ص�¼����
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
    long file_size ;
    int total_records;
    int read_count = 0;  // ʵ�ʶ�ȡ�ļ�¼��
    int max_show = 5;    // �����ʾ����
    
    // �����ȡ��ʼλ�ã����ǲ���5���������
    long read_pos;
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
    puthz(50,30+12+y,"�¹�ʱ��",24,24,GREEN);
    puthz(50+250,30+y+12,"�¹�����",24,24,LIGHTGRAY);
    puthz(50+250*2-40,30+y+12,"����״̬",24,24,BROWN);
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
     // ���ذ��������Ͻǣ�
    setcolor(LIGHTGRAY);
    setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
    rectangle(0, 0, 45, 45); // ���Ʒ��ذ�ť�߿�
    // ���Ʒ��ؼ�ͷ��"<" ��״��
    setcolor(BLUE);
    setlinestyle(SOLID_LINE, 0, THICK_WIDTH);
    line(30, 15, 15, 22);  // ���Ͻǵ���ͷ��
    line(15, 22, 30, 30);  // ��ͷ�⵽���½�
    // �򿪶������¹������ļ�
    fp = fopen("ACCIDENT.dat", "rb");
    if (fp == NULL) {
        puthz(50, 300, "���¹ʹ��棡",16,16,RED);
        getch();
        closegraph();
        return;
    }


    fseek(fp, 0, SEEK_END);
    file_size = ftell(fp);
    total_records = file_size / sizeof(AccidentInfo);
    read_count = 0;  // ʵ�ʶ�ȡ�ļ�¼��
    max_show = 5;    // �����ʾ����
    
    // �����ȡ��ʼλ�ã����ǲ���5���������
    read_pos = (total_records > max_show) ? 
                   (total_records - max_show) * sizeof(AccidentInfo) : 0L;
    
    // ��λ����ȡ��ʼλ��
    fseek(fp, read_pos, SEEK_SET);
    
    // �����ļ��е��¹ʼ�¼�����5����
    while (fread(&incident, sizeof(AccidentInfo), 1, fp) == 1 && read_count < max_show) {
        read_count++;  // ��������ʾ����
        // ��ʾλ�ü���
        display_y = 30 + y + 12 + read_count * y;  // ʹ��read_count����current_row
        
        /* ԭ����ʾ���뱣�ֲ��� */
        setcolor(GREEN);
        settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
        outtextxy(20, display_y+5, incident.time);
        
        // �¹�����ת������ʾ...
        accident_type_trans(incident.accident_type, accident_type);
        puthz(300, display_y, accident_type, 24, 24, LIGHTGRAY);
        
        // ����״̬��ʾ...
        if(incident.processed_status == '1') {
            puthz(50+250*2, display_y, "�Ѵ���", 24, 24, BROWN);
        } else {
            puthz(50+250*2, display_y, "δ����", 24, 24, BROWN);
        }
        

    }
    
    fclose(fp);

    // ���δ�ҵ��κμ�¼������ʾ��ʾ��Ϣ
    if (read_count == 0) {
        puthz(50, 30+y+12+y, "û���ҵ���ؼ�¼",24,24,LIGHTGRAY);
    }

}










