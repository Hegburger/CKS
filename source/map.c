#include"common.h"
#include"IMAGE.h"
#include"verify.h"
#include"mouse.h"
#include"input.h"
/*
这个函数用来形成一个华科大地图，用户可以自由翻看地图并看到上面的事故报告，用户还可以点击事故来查看对应的详细播报
作者：彭减
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
		            return 3;//返回主页面
		        }
				if(mouse_press(595,0,640,45)==1)//退出键 
				{
					closegraph();
					delay(1000);
					exit(0);
				}
				//用户点击之后进入相应的事故查看界面
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
void map_screen(char *user_idcard,AccidentInfo *p)//地图界面
{
	FILE *fp;
	int row=24;
	int i;
	int num_accident[9]={0};
	fp = fopen("ACCIDENT.dat", "rb");
	setbkcolor(WHITE);//背景色设置为白色
	//退出键
	setcolor(LIGHTGRAY);
	setlinestyle(DOTTED_LINE,0,NORM_WIDTH);
	rectangle(595,0,640,45);
    setlinestyle(SOLID_LINE,0,THICK_WIDTH);
    line(595,0,640,45);
    line(640,0,595,45);
    // 绘制返回箭头（"<" 形状）
    setcolor(BLUE);
    setlinestyle(SOLID_LINE, 0, THICK_WIDTH);
    line(30, 15, 15, 22);  // 右上角到箭头尖
    line(15, 22, 30, 30);  // 箭头尖到右下角
    //标题
    puthz(240,10,"地图",24,24,LIGHTGRAY);
    line(0,45,700,45);
    //地图呈现
    bmp_convert("C:\\PROJECT\\photo\\MAP.bmp","C:\\PROJECT\\photo\\MAP.dbm");
    show_dbm(0,47,"C:\\PROJECT\\photo\\MAP.dbm",0);
    
    // 遍历文件中的所有事故记录
    while (fread(p, sizeof(AccidentInfo), 1, fp) == 1) {
        //遍历所有事故信息
        if(strcmp(p->location,"东九楼下")==0)
        {
			num_accident[0]++;
		}
        else if(strcmp(p->location,"东九楼前路口")==0)
		{
			num_accident[1]++;
		} 
        else if(strcmp(p->location,"韵苑食堂路口")==0)
		{
			num_accident[2]++;
		}     
        else if(strcmp(p->location,"喻园大道")==0)
		{
			num_accident[3]++;
		}
        else if(strcmp(p->location,"绝望坡")==0)
		{
			num_accident[4]++;
		}
        else if(strcmp(p->location,"启明路")==0)
		{
			num_accident[5]++;
		}
        else if(strcmp(p->location,"华中路")==0)
		{
			num_accident[6]++;
		}
        else if(strcmp(p->location,"紫荆路")==0)
		{
			num_accident[7]++;
		}
        else if(strcmp(p->location,"紫菘路")==0)
		{
			num_accident[8]++;
		}
    }
    fclose(fp);
    //根据数据库绘制圆形
    setcolor(LIGHTGRAY);
    //东九楼下
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
	//东九楼前路口
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
	//韵苑食堂路口
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
	//喻园大道
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
	//绝望坡
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
	//启明路
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
	//华中路
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
	//紫荆路
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
	//紫菘路
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
	//事故播报一览
	line(0,360,700,360);
	line(0,360+row,700,360+row);
	line(0,360+row*2,700,360+row*2);
	line(0,360+row*3,700,360+row*3);
	line(0,360+row*4,700,360+row*4);
	line(340,360,340,700);//中央切割线
	line(160,360,160,700);//事故地点切割线
	line(500,360,500,360+row*4);
	line(240,360,240,700);//事故严重情况切割线
	line(580,360,580,360+row*4);
	//事故发生地点
	puthz(5,362,"东九楼下",16,16,LIGHTGRAY);
	puthz(5,362+row,"东九楼前",16,16,LIGHTGRAY);
	puthz(5,362+row*2,"韵苑食堂",16,16,LIGHTGRAY);
	puthz(5,362+row*3,"喻园大道",16,16,LIGHTGRAY);
	puthz(5,362+row*4,"绝望坡",16,16,LIGHTGRAY);
	puthz(5+340,362,"启明路",16,16,LIGHTGRAY);
	puthz(5+340,362+row,"华中路",16,16,LIGHTGRAY);
	puthz(5+340,362+row*2,"紫荆路",16,16,LIGHTGRAY);
	puthz(5+340,362+row*3,"紫菘路",16,16,LIGHTGRAY);
	//事故发生情况
	for(i=0;i<9;i++)
	{
		if(num_accident[i]<2)
		{
			if(i<5)
			{
				puthz(164,362+row*i,"正常",16,16,GREEN);
				setfillstyle(SOLID_FILL,GREEN);
				bar(242,362+row*i,338,362-4+row*(i+1));
			}
			else if(i>=5)
			{
				puthz(164+340,362+row*(i-5),"正常",16,16,GREEN);
				setfillstyle(SOLID_FILL,GREEN);
				bar(242+340,362+row*(i-5),678,362-4+row*(i+1-5));
			}
		}
		else if(num_accident[i]>=2&&num_accident[i]<5)
		{
			if(i<5)
			{
				puthz(164,362+row*i,"一般",16,16,YELLOW);
				setfillstyle(SOLID_FILL,YELLOW);
				bar(242,362+row*i,338,362-4+row*(i+1));
			}
			else if(i>=5)
			{
				puthz(164+340,362+row*(i-5),"一般",16,16,YELLOW);
				setfillstyle(SOLID_FILL,YELLOW);
				bar(242+340,362+row*(i-5),678,362-4+row*(i+1-5));
			}
		}
		else if(num_accident[i]>=5)
		{
			if(i<5)
			{
				puthz(164,362+row*i,"严重",16,16,RED);
				setfillstyle(SOLID_FILL,RED);
				bar(242,362+row*i,338,362-4+row*(i+1));
			}
			else if(i>=5)
			{
				puthz(164+340,362+row*(i-5),"严重",16,16,RED);
				setfillstyle(SOLID_FILL,RED);
				bar(242+340,362+row*(i-5),678,362-4+row*(i+1-5));
			}
		}
	}
}
//void draw_triangle(int x, int y, int blank_width) {
//    int a,points[6];
//    a = blank_width - 16; // 计算三角形的一边长度
//
//    // 定义三角形的三个顶点
//    points[0] = x;               // 第一个顶点 (x, y+5)
//    points[1] = y + 8;
//    points[2] = x;               // 第二个顶点 (x, y + blank_width - 5)
//    points[3] = y + blank_width - 8;
//    points[4] = x + 0.87 * a;    // 第三个顶点 (x + 0.87*a, y + a / 2)
//    points[5] = y + 8+ a/2;
//
//    setfillstyle(SOLID_FILL, LIGHTGRAY);  // 设置填充颜色为灰色
//    setcolor(CYAN);  // 设置边框颜色为青色
//
//    fillpoly(3, points);  // 绘制并填充三角形
//}

//事故信息排列表
int record_map(int num)
{
	int row=30;//每行间距
	int max=10;//只能显示10个事故
	int startx_1=20;//开始的位置
	int startx_2=300;
	int i=1;
	FILE *fp;
	AccidentInfo p;
	clrmous(MouseX,MouseY);
	delay(100);
	cleardevice();
	save_bk_mou(MouseX,MouseY);	
	fp = fopen("ACCIDENT.dat", "rb");
	//绘图
	setbkcolor(WHITE);//背景色设置为白色
	//退出键
	setcolor(LIGHTGRAY);
	setlinestyle(DOTTED_LINE,0,NORM_WIDTH);
	rectangle(595,0,640,45);
    setlinestyle(SOLID_LINE,0,THICK_WIDTH);
    line(595,0,640,45);
    line(640,0,595,45);
	//标题
	puthz(240,5,"事故一览",24,24,LIGHTGRAY);
	line(0,45,700,45);
	line(0,75,700,75);
	puthz(5,47,"地点",24,24,LIGHTGRAY);
	line(60,45,60,75);

		if(num==0){//东九楼下
		    puthz(70,47,"东九楼下",24,24,RED);}
		else if(num==1){//东九楼前路口
		    puthz(70,47,"东九楼前路口",24,24,RED);}
		else if(num==2){//韵苑食堂路口
		    puthz(70,47,"韵苑食堂路口",24,24,RED);}
		else if(num==3){//喻园大道
		    puthz(70,47,"喻园大道",24,24,RED);}
		else if(num==4){//绝望坡
		    puthz(70,47,"绝望坡",24,24,RED);}
		else if(num==5){//启明路
		    puthz(70,47,"启明路",24,24,RED);}
		else if(num==6){//华中路
		    puthz(70,47,"华中路",24,24,RED);}
		else if(num==7){//紫荆路
		    puthz(70,47,"紫荆路",24,24,RED);}
		else if(num==8){//紫菘路
		    puthz(70,47,"紫菘路",24,24,RED);}
	//绘制排列表
	puthz(startx_1,80,"事故发生时间",24,24,LIGHTGRAY);
	puthz(startx_2,80,"事故类型",24,24,LIGHTGRAY);
	settextstyle(1,0,2);
    // 遍历文件中的所有事故记录
    while (fread(&p, sizeof(AccidentInfo), 1, fp) == 1) {
        //遍历所有事故信息
        if(strcmp(p.location,"东九楼下")==0&&num==0&&num<=max)
        {
        	outtextxy(startx_1,80+row*i,p.time);
        	if(p.accident_type=='A')
        	{
				puthz(startx_2,80+row*i,"人与电动车",24,24,LIGHTGRAY);
			}
			else if(p.accident_type=='B')
			{
				puthz(startx_2,80+row*i,"人与汽车",24,24,LIGHTGRAY);
			}
			else if(p.accident_type=='C')
			{
				puthz(startx_2,80+row*i,"电动车与电动车",24,24,LIGHTGRAY);
			}
			else if(p.accident_type=='D')
			{
				puthz(startx_2,80+row*i,"电动车与汽车",24,24,LIGHTGRAY);
			}
			else if(p.accident_type=='E')
			{
				puthz(startx_2,80+row*i,"汽车与汽车",24,24,LIGHTGRAY);
			}
			i++;
		}
        else if(strcmp(p.location,"东九楼前路口")==0&&num==1&&num<=max)
		{
        	outtextxy(startx_1,80+row*i,p.time);
        	if(p.accident_type=='A')
        	{
				puthz(startx_2,80+row*i,"人与车辆",24,24,LIGHTGRAY);
			}
			else if(p.accident_type=='B')
			{
				puthz(startx_2,80+row*i,"车辆与车辆",24,24,LIGHTGRAY);
			}
			else if(p.accident_type=='C')
			{
				puthz(startx_2,80+row*i,"电动车与电动车",24,24,LIGHTGRAY);
			}
			else if(p.accident_type=='D')
			{
				puthz(startx_2,80+row*i,"电动车与汽车",24,24,LIGHTGRAY);
			}
			else if(p.accident_type=='E')
			{
				puthz(startx_2,80+row*i,"汽车与汽车",24,24,LIGHTGRAY);
			}
			i++;
		} 
        else if(strcmp(p.location,"韵苑食堂路口")==0&&num==2&&num<=max)
		{
        	outtextxy(startx_1,80+row*i,p.time);
        	if(p.accident_type=='A')
        	{
				puthz(startx_2,80+row*i,"人与车辆",24,24,LIGHTGRAY);
			}
			else if(p.accident_type=='B')
			{
				puthz(startx_2,80+row*i,"车辆与车辆",24,24,LIGHTGRAY);
			}
			else if(p.accident_type=='C')
			{
				puthz(startx_2,80+row*i,"电动车与电动车",24,24,LIGHTGRAY);
			}
			else if(p.accident_type=='D')
			{
				puthz(startx_2,80+row*i,"电动车与汽车",24,24,LIGHTGRAY);
			}
			else if(p.accident_type=='E')
			{
				puthz(startx_2,80+row*i,"汽车与汽车",24,24,LIGHTGRAY);
			}
			i++;
		}     
        else if(strcmp(p.location,"喻园大道")==0&&num==3&&num<=max)
		{
        	outtextxy(startx_1,80+row*i,p.time);
        	if(p.accident_type=='A')
        	{
				puthz(startx_2,80+row*i,"人与车辆",24,24,LIGHTGRAY);
			}
			else if(p.accident_type=='B')
			{
				puthz(startx_2,80+row*i,"车辆与车辆",24,24,LIGHTGRAY);
			}
			else if(p.accident_type=='C')
			{
				puthz(startx_2,80+row*i,"电动车与电动车",24,24,LIGHTGRAY);
			}
			else if(p.accident_type=='D')
			{
				puthz(startx_2,80+row*i,"电动车与汽车",24,24,LIGHTGRAY);
			}
			else if(p.accident_type=='E')
			{
				puthz(startx_2,80+row*i,"汽车与汽车",24,24,LIGHTGRAY);
			}
			i++;
		}
        else if(strcmp(p.location,"绝望坡")==0&&num==4&&num<=max)
		{
        	outtextxy(startx_1,80+row*i,p.time);
        	if(p.accident_type=='A')
        	{
				puthz(startx_2,80+row*i,"人与车辆",24,24,LIGHTGRAY);
			}
			else if(p.accident_type=='B')
			{
				puthz(startx_2,80+row*i,"车辆与车辆",24,24,LIGHTGRAY);
			}
			else if(p.accident_type=='C')
			{
				puthz(startx_2,80+row*i,"电动车与电动车",24,24,LIGHTGRAY);
			}
			else if(p.accident_type=='D')
			{
				puthz(startx_2,80+row*i,"电动车与汽车",24,24,LIGHTGRAY);
			}
			else if(p.accident_type=='E')
			{
				puthz(startx_2,80+row*i,"汽车与汽车",24,24,LIGHTGRAY);
			}
			i++;
		}
        else if(strcmp(p.location,"启明路")==0&&num==5&&num<=max)
		{
        	outtextxy(startx_1,80+row*i,p.time);
        	if(p.accident_type=='A')
        	{
				puthz(startx_2,80+row*i,"人与车辆",24,24,LIGHTGRAY);
			}
			else if(p.accident_type=='B')
			{
				puthz(startx_2,80+row*i,"车辆与车辆",24,24,LIGHTGRAY);
			}
			else if(p.accident_type=='C')
			{
				puthz(startx_2,80+row*i,"电动车与电动车",24,24,LIGHTGRAY);
			}
			else if(p.accident_type=='D')
			{
				puthz(startx_2,80+row*i,"电动车与汽车",24,24,LIGHTGRAY);
			}
			else if(p.accident_type=='E')
			{
				puthz(startx_2,80+row*i,"汽车与汽车",24,24,LIGHTGRAY);
			}
			i++;
		}
        else if(strcmp(p.location,"华中路")==0&&num==6&&num<=max)
		{
        	outtextxy(startx_1,80+row*i,p.time);
        	if(p.accident_type=='A')
        	{
				puthz(startx_2,80+row*i,"人与车辆",24,24,LIGHTGRAY);
			}
			else if(p.accident_type=='B')
			{
				puthz(startx_2,80+row*i,"车辆与车辆",24,24,LIGHTGRAY);
			}
			else if(p.accident_type=='C')
			{
				puthz(startx_2,80+row*i,"电动车与电动车",24,24,LIGHTGRAY);
			}
			else if(p.accident_type=='D')
			{
				puthz(startx_2,80+row*i,"电动车与汽车",24,24,LIGHTGRAY);
			}
			else if(p.accident_type=='E')
			{
				puthz(startx_2,80+row*i,"汽车与汽车",24,24,LIGHTGRAY);
			}
			i++;
		}
        else if(strcmp(p.location,"紫荆路")==0&&num==7&&num<=max)
		{
        	outtextxy(startx_1,80+row*i,p.time);
        	if(p.accident_type=='A')
        	{
				puthz(startx_2,80+row*i,"人与车辆",24,24,LIGHTGRAY);
			}
			else if(p.accident_type=='B')
			{
				puthz(startx_2,80+row*i,"车辆与车辆",24,24,LIGHTGRAY);
			}
			else if(p.accident_type=='C')
			{
				puthz(startx_2,80+row*i,"电动车与电动车",24,24,LIGHTGRAY);
			}
			else if(p.accident_type=='D')
			{
				puthz(startx_2,80+row*i,"电动车与汽车",24,24,LIGHTGRAY);
			}
			else if(p.accident_type=='E')
			{
				puthz(startx_2,80+row*i,"汽车与汽车",24,24,LIGHTGRAY);
			}
			i++;
		}
        else if(strcmp(p.location,"紫菘路")==0&&num==8&&num<=max)
		{
        	outtextxy(startx_1,80+row*i,p.time);
        	if(p.accident_type=='A')
        	{
				puthz(startx_2,80+row*i,"人与车辆",24,24,LIGHTGRAY);
			}
			else if(p.accident_type=='B')
			{
				puthz(startx_2,80+row*i,"车辆与车辆",24,24,LIGHTGRAY);
			}
			else if(p.accident_type=='C')
			{
				puthz(startx_2,80+row*i,"电动车与电动车",24,24,LIGHTGRAY);
			}
			else if(p.accident_type=='D')
			{
				puthz(startx_2,80+row*i,"电动车与汽车",24,24,LIGHTGRAY);
			}
			else if(p.accident_type=='E')
			{
				puthz(startx_2,80+row*i,"汽车与汽车",24,24,LIGHTGRAY);
			}
			i++;
		}
    }
    fclose(fp);
	if(i==1)
	{
		puthz(startx_1,80+row*i,"此地区没有事故发生",16,16,GREEN);
	}
    // 绘制返回箭头（"<" 形状）
    setcolor(BLUE);
    setlinestyle(SOLID_LINE, 0, THICK_WIDTH);
    line(30, 15, 15, 22);  // 右上角到箭头尖
    line(15, 22, 30, 30);  // 箭头尖到右下角
    
    
    
    
    
	while(1)
	{
		mou_pos(&MouseX,&MouseY,&press);
        if(mouse_press(0, 0, 45, 45)==1){
            return 8;//返回地图页面
        }
		if(mouse_press(595,0,640,45)==1)//退出键 
		{
			closegraph();
			delay(1000);
			exit(0);
		}	
	}
}








