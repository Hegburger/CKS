#include"common.h"
#include"IMAGE.h"
#include"verify.h"
#include"mouse.h"
#include"input.h"
/*
������������γ�һ�����ƴ��ͼ���û��������ɷ�����ͼ������������¹ʱ��棬�û������Ե���¹����鿴��Ӧ����ϸ����
���ߣ����
*/
void map_screen(char *user_idcard,AccidentInfo *p);
int page_map(char *user_idcard);
void draw_triangle(int x, int y, int blank_width);
int record_map(int num);
int page_map(char *user_idcard)
{
	AccidentInfo p;
	clrmous(MouseX,MouseY);
	delay(100);
	cleardevice();
	map_screen(user_idcard,&p);
	save_bk_mou(MouseX,MouseY);
	while(1)
	{
				mou_pos(&MouseX,&MouseY,&press);
                if(mouse_press(0, 0, 45, 45)==1){
		            return 3;//������ҳ��
		        }
				if(mouse_press(595,0,640,45)==1)//�˳��� 
				{
					closegraph();
					delay(1000);
					exit(0);
				}
				//�û����֮�������Ӧ���¹ʲ鿴����
				else if(mouse_press_circle(430,45+250,15)==1)
				{
					return 20;
				}
				else if(mouse_press_circle(450,45+155,15)==1)
				{
					return 21;
				}
				else if(mouse_press_circle(530,45+145,15)==1)
				{
					return 22;
				}
				else if(mouse_press_circle(250,35+145,15)==1)
				{
					return 23;
				}
				else if(mouse_press_circle(400,45+145,15)==1)
				{
					return 24;
				}
				else if(mouse_press_circle(525,45+250,15)==1)
				{
					return 25;
				}
				else if(mouse_press_circle(210,50+165,15)==1)
				{
					return 26;
				}
				else if(mouse_press_circle(230,35+240,15)==1)
				{
					return 27;
				}
				else if(mouse_press_circle(130,45+220,15)==1)
				{
					return 28;
				}
	}
}
void map_screen(char *user_idcard,AccidentInfo *p)//��ͼ����
{
	FILE *fp;
	int row=24;
	int i;
	int num_accident[9]={0};
	fp = fopen("ACCIDENT.dat", "rb");
	setbkcolor(WHITE);//����ɫ����Ϊ��ɫ
	//�˳���
	setcolor(LIGHTGRAY);
	setlinestyle(DOTTED_LINE,0,NORM_WIDTH);
	rectangle(595,0,640,45);
    setlinestyle(SOLID_LINE,0,THICK_WIDTH);
    line(595,0,640,45);
    line(640,0,595,45);
    // ���Ʒ��ؼ�ͷ��"<" ��״��
    setcolor(BLUE);
    setlinestyle(SOLID_LINE, 0, THICK_WIDTH);
    line(30, 15, 15, 22);  // ���Ͻǵ���ͷ��
    line(15, 22, 30, 30);  // ��ͷ�⵽���½�
    //����
    puthz(240,10,"��ͼ",24,24,LIGHTGRAY);
    line(0,45,700,45);
    //��ͼ����
    bmp_convert("C:\\PROJECT\\photo\\MAP.bmp","C:\\PROJECT\\photo\\MAP.dbm");
    show_dbm(0,47,"C:\\PROJECT\\photo\\MAP.dbm",0);
    
    // �����ļ��е������¹ʼ�¼
    while (fread(p, sizeof(AccidentInfo), 1, fp) == 1) {
        //���������¹���Ϣ
        if(strcmp(p->location,"����¥��")==0)
        {
			num_accident[0]++;
		}
        else if(strcmp(p->location,"����¥ǰ·��")==0)
		{
			num_accident[1]++;
		} 
        else if(strcmp(p->location,"��Էʳ��·��")==0)
		{
			num_accident[2]++;
		}     
        else if(strcmp(p->location,"��԰���")==0)
		{
			num_accident[3]++;
		}
        else if(strcmp(p->location,"������")==0)
		{
			num_accident[4]++;
		}
        else if(strcmp(p->location,"����·")==0)
		{
			num_accident[5]++;
		}
        else if(strcmp(p->location,"����·")==0)
		{
			num_accident[6]++;
		}
        else if(strcmp(p->location,"�Ͼ�·")==0)
		{
			num_accident[7]++;
		}
        else if(strcmp(p->location,"��ݿ·")==0)
		{
			num_accident[8]++;
		}
    }
    fclose(fp);
    //�������ݿ����Բ��
    setcolor(LIGHTGRAY);
    //����¥��
    if(num_accident[0]<2)
    {
		circle(430,45+250,15);
		setfillstyle(SOLID_FILL,GREEN);
		floodfill(430,45+250,LIGHTGRAY);
	}
	else if(num_accident[0]>=2&&num_accident[0]<5)
	{
		circle(430,45+250,15);
		setfillstyle(SOLID_FILL,YELLOW);
		floodfill(430,45+250,LIGHTGRAY);
	}
	else if(num_accident[0]>=5)
	{
		circle(430,45+250,15);
		setfillstyle(SOLID_FILL,RED);
		floodfill(430,45+250,LIGHTGRAY);
	}
	//����¥ǰ·��
    if(num_accident[1]<2)
    {
		circle(450,45+155,15);
		setfillstyle(SOLID_FILL,GREEN);
		floodfill(450,45+155,LIGHTGRAY);
	}
	else if(num_accident[1]>=2&&num_accident[1]<5)
	{
		circle(450,45+155,15);
		setfillstyle(SOLID_FILL,YELLOW);
		floodfill(450,45+155,LIGHTGRAY);
	}
	else if(num_accident[1]>=5)
	{
		circle(450,45+155,15);
		setfillstyle(SOLID_FILL,RED);
		floodfill(450,45+155,LIGHTGRAY);
	}
	//��Էʳ��·��
    if(num_accident[2]<2)
    {
		circle(530,45+145,15);
		setfillstyle(SOLID_FILL,GREEN);
		floodfill(530,45+145,LIGHTGRAY);
	}
	else if(num_accident[2]>=2&&num_accident[2]<5)
	{
		circle(530,45+145,15);
		setfillstyle(SOLID_FILL,YELLOW);
		floodfill(530,45+145,LIGHTGRAY);
	}
	else if(num_accident[2]>=5)
	{
		circle(530,45+145,15);
		setfillstyle(SOLID_FILL,RED);
		floodfill(530,45+145,LIGHTGRAY);
	}
	//��԰���
    if(num_accident[3]<2)
    {
		circle(250,35+145,15);
		setfillstyle(SOLID_FILL,GREEN);
		floodfill(250,35+145,LIGHTGRAY);
	}
	else if(num_accident[3]>=2&&num_accident[0]<5)
	{
		circle(250,35+145,15);
		setfillstyle(SOLID_FILL,YELLOW);
		floodfill(250,35+145,LIGHTGRAY);
	}
	else if(num_accident[3]>=5)
	{
		circle(250,35+145,15);
		setfillstyle(SOLID_FILL,RED);
		floodfill(250,35+145,LIGHTGRAY);
	}
	//������
    if(num_accident[4]<2)
    {
		circle(400,45+145,15);
		setfillstyle(SOLID_FILL,GREEN);
		floodfill(400,45+145,LIGHTGRAY);
	}
	else if(num_accident[4]>=2&&num_accident[0]<5)
	{
		circle(400,45+145,15);
		setfillstyle(SOLID_FILL,YELLOW);
		floodfill(400,45+145,LIGHTGRAY);
	}
	else if(num_accident[4]>=5)
	{
		circle(400,45+145,15);
		setfillstyle(SOLID_FILL,RED);
		floodfill(400,45+145,LIGHTGRAY);
	}
	//����·
    if(num_accident[5]<2)
    {
		circle(525,45+250,15);
		setfillstyle(SOLID_FILL,GREEN);
		floodfill(525,45+250,LIGHTGRAY);
	}
	else if(num_accident[5]>=2&&num_accident[5]<5)
	{
		circle(525,45+250,15);
		setfillstyle(SOLID_FILL,YELLOW);
		floodfill(525,45+250,LIGHTGRAY);
	}
	else if(num_accident[5]>=5)
	{
		circle(525,45+250,15);
		setfillstyle(SOLID_FILL,RED);
		floodfill(525,45+250,LIGHTGRAY);
	}
	//����·
    if(num_accident[6]<2)
    {
		circle(210,50+165,15);
		setfillstyle(SOLID_FILL,GREEN);
		floodfill(210,50+165,LIGHTGRAY);
	}
	else if(num_accident[6]>=2&&num_accident[6]<5)
	{
		circle(210,50+165,15);
		setfillstyle(SOLID_FILL,YELLOW);
		floodfill(210,50+165,LIGHTGRAY);
	}
	else if(num_accident[6]>=5)
	{
		circle(210,50+165,15);
		setfillstyle(SOLID_FILL,RED);
		floodfill(210,50+165,LIGHTGRAY);
	}
	//�Ͼ�·
    if(num_accident[7]<2)
    {
		circle(230,35+240,15);
		setfillstyle(SOLID_FILL,GREEN);
		floodfill(230,30+240,LIGHTGRAY);
	}
	else if(num_accident[7]>=2&&num_accident[7]<5)
	{
		circle(230,35+240,15);
		setfillstyle(SOLID_FILL,YELLOW);
		floodfill(230,30+240,LIGHTGRAY);
	}
	else if(num_accident[7]>=5)
	{
		circle(230,35+240,15);
		setfillstyle(SOLID_FILL,RED);
		floodfill(230,30+240,LIGHTGRAY);
	}
	//��ݿ·
    if(num_accident[8]<2)
    {
		circle(130,45+220,15);
		setfillstyle(SOLID_FILL,GREEN);
		floodfill(130,50+220,LIGHTGRAY);
	}
	else if(num_accident[8]>=2&&num_accident[8]<5)
	{
		circle(130,45+220,15);
		setfillstyle(SOLID_FILL,YELLOW);
		floodfill(130,50+220,LIGHTGRAY);
	}
	else if(num_accident[8]>=5)
	{
		circle(130,45+220,15);
		setfillstyle(SOLID_FILL,RED);
		floodfill(130,50+220,LIGHTGRAY);
	}
	//�¹ʲ���һ��
	line(0,360,700,360);
	line(0,360+row,700,360+row);
	line(0,360+row*2,700,360+row*2);
	line(0,360+row*3,700,360+row*3);
	line(0,360+row*4,700,360+row*4);
	line(340,360,340,700);//�����и���
	line(160,360,160,700);//�¹ʵص��и���
	line(500,360,500,360+row*4);
	line(240,360,240,700);//�¹���������и���
	line(580,360,580,360+row*4);
	//�¹ʷ����ص�
	puthz(5,362,"����¥��",16,16,LIGHTGRAY);
	puthz(5,362+row,"����¥ǰ",16,16,LIGHTGRAY);
	puthz(5,362+row*2,"��Էʳ��",16,16,LIGHTGRAY);
	puthz(5,362+row*3,"��԰���",16,16,LIGHTGRAY);
	puthz(5,362+row*4,"������",16,16,LIGHTGRAY);
	puthz(5+340,362,"����·",16,16,LIGHTGRAY);
	puthz(5+340,362+row,"����·",16,16,LIGHTGRAY);
	puthz(5+340,362+row*2,"�Ͼ�·",16,16,LIGHTGRAY);
	puthz(5+340,362+row*3,"��ݿ·",16,16,LIGHTGRAY);
	//�¹ʷ������
	for(i=0;i<9;i++)
	{
		if(num_accident[i]<2)
		{
			if(i<5)
			{
				puthz(164,362+row*i,"����",16,16,GREEN);
				setfillstyle(SOLID_FILL,GREEN);
				bar(242,362+row*i,338,362-4+row*(i+1));
			}
			else if(i>=5)
			{
				puthz(164+340,362+row*(i-5),"����",16,16,GREEN);
				setfillstyle(SOLID_FILL,GREEN);
				bar(242+340,362+row*(i-5),678,362-4+row*(i+1-5));
			}
		}
		else if(num_accident[i]>=2&&num_accident[i]<5)
		{
			if(i<5)
			{
				puthz(164,362+row*i,"һ��",16,16,YELLOW);
				setfillstyle(SOLID_FILL,YELLOW);
				bar(242,362+row*i,338,362-4+row*(i+1));
			}
			else if(i>=5)
			{
				puthz(164+340,362+row*(i-5),"һ��",16,16,YELLOW);
				setfillstyle(SOLID_FILL,YELLOW);
				bar(242+340,362+row*(i-5),678,362-4+row*(i+1-5));
			}
		}
		else if(num_accident[i]>=5)
		{
			if(i<5)
			{
				puthz(164,362+row*i,"����",16,16,RED);
				setfillstyle(SOLID_FILL,RED);
				bar(242,362+row*i,338,362-4+row*(i+1));
			}
			else if(i>=5)
			{
				puthz(164+340,362+row*(i-5),"����",16,16,RED);
				setfillstyle(SOLID_FILL,RED);
				bar(242+340,362+row*(i-5),678,362-4+row*(i+1-5));
			}
		}
	}
}
//void draw_triangle(int x, int y, int blank_width) {
//    int a,points[6];
//    a = blank_width - 16; // ���������ε�һ�߳���
//
//    // ���������ε���������
//    points[0] = x;               // ��һ������ (x, y+5)
//    points[1] = y + 8;
//    points[2] = x;               // �ڶ������� (x, y + blank_width - 5)
//    points[3] = y + blank_width - 8;
//    points[4] = x + 0.87 * a;    // ���������� (x + 0.87*a, y + a / 2)
//    points[5] = y + 8+ a/2;
//
//    setfillstyle(SOLID_FILL, LIGHTGRAY);  // ���������ɫΪ��ɫ
//    setcolor(CYAN);  // ���ñ߿���ɫΪ��ɫ
//
//    fillpoly(3, points);  // ���Ʋ����������
//}

//�¹���Ϣ���б�
int record_map(int num)
{
	int row=30;//ÿ�м��
	int max=10;//ֻ����ʾ10���¹�
	int startx_1=20;//��ʼ��λ��
	int startx_2=300;
	int i=1;
	FILE *fp;
	AccidentInfo p;
	clrmous(MouseX,MouseY);
	delay(100);
	cleardevice();
	save_bk_mou(MouseX,MouseY);	
	fp = fopen("ACCIDENT.dat", "rb");
	//��ͼ
	setbkcolor(WHITE);//����ɫ����Ϊ��ɫ
	//�˳���
	setcolor(LIGHTGRAY);
	setlinestyle(DOTTED_LINE,0,NORM_WIDTH);
	rectangle(595,0,640,45);
    setlinestyle(SOLID_LINE,0,THICK_WIDTH);
    line(595,0,640,45);
    line(640,0,595,45);
	//����
	puthz(240,5,"�¹�һ��",24,24,LIGHTGRAY);
	line(0,45,700,45);
	line(0,75,700,75);
	puthz(5,47,"�ص�",24,24,LIGHTGRAY);
	line(60,45,60,75);

		if(num==0){//����¥��
		    puthz(70,47,"����¥��",24,24,RED);}
		else if(num==1){//����¥ǰ·��
		    puthz(70,47,"����¥ǰ·��",24,24,RED);}
		else if(num==2){//��Էʳ��·��
		    puthz(70,47,"��Էʳ��·��",24,24,RED);}
		else if(num==3){//��԰���
		    puthz(70,47,"��԰���",24,24,RED);}
		else if(num==4){//������
		    puthz(70,47,"������",24,24,RED);}
		else if(num==5){//����·
		    puthz(70,47,"����·",24,24,RED);}
		else if(num==6){//����·
		    puthz(70,47,"����·",24,24,RED);}
		else if(num==7){//�Ͼ�·
		    puthz(70,47,"�Ͼ�·",24,24,RED);}
		else if(num==8){//��ݿ·
		    puthz(70,47,"��ݿ·",24,24,RED);}
	//�������б�
	puthz(startx_1,80,"�¹ʷ���ʱ��",24,24,LIGHTGRAY);
	puthz(startx_2,80,"�¹�����",24,24,LIGHTGRAY);
	settextstyle(1,0,2);
    // �����ļ��е������¹ʼ�¼
    while (fread(&p, sizeof(AccidentInfo), 1, fp) == 1) {
        //���������¹���Ϣ
        if(strcmp(p.location,"����¥��")==0&&num==0&&num<=max)
        {
        	outtextxy(startx_1,80+row*i,p.time);
        	if(p.accident_type=='A')
        	{
				puthz(startx_2,80+row*i,"����綯��",24,24,LIGHTGRAY);
			}
			else if(p.accident_type=='B')
			{
				puthz(startx_2,80+row*i,"��������",24,24,LIGHTGRAY);
			}
			else if(p.accident_type=='C')
			{
				puthz(startx_2,80+row*i,"�綯����綯��",24,24,LIGHTGRAY);
			}
			else if(p.accident_type=='D')
			{
				puthz(startx_2,80+row*i,"�綯��������",24,24,LIGHTGRAY);
			}
			else if(p.accident_type=='E')
			{
				puthz(startx_2,80+row*i,"����������",24,24,LIGHTGRAY);
			}
			i++;
		}
        else if(strcmp(p.location,"����¥ǰ·��")==0&&num==1&&num<=max)
		{
        	outtextxy(startx_1,80+row*i,p.time);
        	if(p.accident_type=='A')
        	{
				puthz(startx_2,80+row*i,"���복��",24,24,LIGHTGRAY);
			}
			else if(p.accident_type=='B')
			{
				puthz(startx_2,80+row*i,"�����복��",24,24,LIGHTGRAY);
			}
			else if(p.accident_type=='C')
			{
				puthz(startx_2,80+row*i,"�綯����綯��",24,24,LIGHTGRAY);
			}
			else if(p.accident_type=='D')
			{
				puthz(startx_2,80+row*i,"�綯��������",24,24,LIGHTGRAY);
			}
			else if(p.accident_type=='E')
			{
				puthz(startx_2,80+row*i,"����������",24,24,LIGHTGRAY);
			}
			i++;
		} 
        else if(strcmp(p.location,"��Էʳ��·��")==0&&num==2&&num<=max)
		{
        	outtextxy(startx_1,80+row*i,p.time);
        	if(p.accident_type=='A')
        	{
				puthz(startx_2,80+row*i,"���복��",24,24,LIGHTGRAY);
			}
			else if(p.accident_type=='B')
			{
				puthz(startx_2,80+row*i,"�����복��",24,24,LIGHTGRAY);
			}
			else if(p.accident_type=='C')
			{
				puthz(startx_2,80+row*i,"�綯����綯��",24,24,LIGHTGRAY);
			}
			else if(p.accident_type=='D')
			{
				puthz(startx_2,80+row*i,"�綯��������",24,24,LIGHTGRAY);
			}
			else if(p.accident_type=='E')
			{
				puthz(startx_2,80+row*i,"����������",24,24,LIGHTGRAY);
			}
			i++;
		}     
        else if(strcmp(p.location,"��԰���")==0&&num==3&&num<=max)
		{
        	outtextxy(startx_1,80+row*i,p.time);
        	if(p.accident_type=='A')
        	{
				puthz(startx_2,80+row*i,"���복��",24,24,LIGHTGRAY);
			}
			else if(p.accident_type=='B')
			{
				puthz(startx_2,80+row*i,"�����복��",24,24,LIGHTGRAY);
			}
			else if(p.accident_type=='C')
			{
				puthz(startx_2,80+row*i,"�綯����綯��",24,24,LIGHTGRAY);
			}
			else if(p.accident_type=='D')
			{
				puthz(startx_2,80+row*i,"�綯��������",24,24,LIGHTGRAY);
			}
			else if(p.accident_type=='E')
			{
				puthz(startx_2,80+row*i,"����������",24,24,LIGHTGRAY);
			}
			i++;
		}
        else if(strcmp(p.location,"������")==0&&num==4&&num<=max)
		{
        	outtextxy(startx_1,80+row*i,p.time);
        	if(p.accident_type=='A')
        	{
				puthz(startx_2,80+row*i,"���복��",24,24,LIGHTGRAY);
			}
			else if(p.accident_type=='B')
			{
				puthz(startx_2,80+row*i,"�����복��",24,24,LIGHTGRAY);
			}
			else if(p.accident_type=='C')
			{
				puthz(startx_2,80+row*i,"�綯����綯��",24,24,LIGHTGRAY);
			}
			else if(p.accident_type=='D')
			{
				puthz(startx_2,80+row*i,"�綯��������",24,24,LIGHTGRAY);
			}
			else if(p.accident_type=='E')
			{
				puthz(startx_2,80+row*i,"����������",24,24,LIGHTGRAY);
			}
			i++;
		}
        else if(strcmp(p.location,"����·")==0&&num==5&&num<=max)
		{
        	outtextxy(startx_1,80+row*i,p.time);
        	if(p.accident_type=='A')
        	{
				puthz(startx_2,80+row*i,"���복��",24,24,LIGHTGRAY);
			}
			else if(p.accident_type=='B')
			{
				puthz(startx_2,80+row*i,"�����복��",24,24,LIGHTGRAY);
			}
			else if(p.accident_type=='C')
			{
				puthz(startx_2,80+row*i,"�綯����綯��",24,24,LIGHTGRAY);
			}
			else if(p.accident_type=='D')
			{
				puthz(startx_2,80+row*i,"�綯��������",24,24,LIGHTGRAY);
			}
			else if(p.accident_type=='E')
			{
				puthz(startx_2,80+row*i,"����������",24,24,LIGHTGRAY);
			}
			i++;
		}
        else if(strcmp(p.location,"����·")==0&&num==6&&num<=max)
		{
        	outtextxy(startx_1,80+row*i,p.time);
        	if(p.accident_type=='A')
        	{
				puthz(startx_2,80+row*i,"���복��",24,24,LIGHTGRAY);
			}
			else if(p.accident_type=='B')
			{
				puthz(startx_2,80+row*i,"�����복��",24,24,LIGHTGRAY);
			}
			else if(p.accident_type=='C')
			{
				puthz(startx_2,80+row*i,"�綯����綯��",24,24,LIGHTGRAY);
			}
			else if(p.accident_type=='D')
			{
				puthz(startx_2,80+row*i,"�綯��������",24,24,LIGHTGRAY);
			}
			else if(p.accident_type=='E')
			{
				puthz(startx_2,80+row*i,"����������",24,24,LIGHTGRAY);
			}
			i++;
		}
        else if(strcmp(p.location,"�Ͼ�·")==0&&num==7&&num<=max)
		{
        	outtextxy(startx_1,80+row*i,p.time);
        	if(p.accident_type=='A')
        	{
				puthz(startx_2,80+row*i,"���복��",24,24,LIGHTGRAY);
			}
			else if(p.accident_type=='B')
			{
				puthz(startx_2,80+row*i,"�����복��",24,24,LIGHTGRAY);
			}
			else if(p.accident_type=='C')
			{
				puthz(startx_2,80+row*i,"�綯����綯��",24,24,LIGHTGRAY);
			}
			else if(p.accident_type=='D')
			{
				puthz(startx_2,80+row*i,"�綯��������",24,24,LIGHTGRAY);
			}
			else if(p.accident_type=='E')
			{
				puthz(startx_2,80+row*i,"����������",24,24,LIGHTGRAY);
			}
			i++;
		}
        else if(strcmp(p.location,"��ݿ·")==0&&num==8&&num<=max)
		{
        	outtextxy(startx_1,80+row*i,p.time);
        	if(p.accident_type=='A')
        	{
				puthz(startx_2,80+row*i,"���복��",24,24,LIGHTGRAY);
			}
			else if(p.accident_type=='B')
			{
				puthz(startx_2,80+row*i,"�����복��",24,24,LIGHTGRAY);
			}
			else if(p.accident_type=='C')
			{
				puthz(startx_2,80+row*i,"�綯����綯��",24,24,LIGHTGRAY);
			}
			else if(p.accident_type=='D')
			{
				puthz(startx_2,80+row*i,"�綯��������",24,24,LIGHTGRAY);
			}
			else if(p.accident_type=='E')
			{
				puthz(startx_2,80+row*i,"����������",24,24,LIGHTGRAY);
			}
			i++;
		}
    }
    fclose(fp);
	if(i==1)
	{
		puthz(startx_1,80+row*i,"�˵���û���¹ʷ���",16,16,GREEN);
	}
    // ���Ʒ��ؼ�ͷ��"<" ��״��
    setcolor(BLUE);
    setlinestyle(SOLID_LINE, 0, THICK_WIDTH);
    line(30, 15, 15, 22);  // ���Ͻǵ���ͷ��
    line(15, 22, 30, 30);  // ��ͷ�⵽���½�
    
    
    
    
    
	while(1)
	{
		mou_pos(&MouseX,&MouseY,&press);
        if(mouse_press(0, 0, 45, 45)==1){
            return 8;//���ص�ͼҳ��
        }
		if(mouse_press(595,0,640,45)==1)//�˳��� 
		{
			closegraph();
			delay(1000);
			exit(0);
		}	
	}
}








