#include"input.h"
#include"common.h"
#include"verify.h"
#include"mouse.h"
/*
主界面
彭减
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
		if(mouse_press(595,0,640,45)==1)//退出键 
		{
			closegraph();
			delay(1000);
			exit(0);
		}
		//转接其他界面
		if(mouse_press(50+50,440,50+longer+50,440+height)==1)//报案界面
		{
			return 4;
		}
		if(mouse_press(50+50+longer+40,440,50+50+longer*2+40,440+height)==1)//历史界面
		{
			return 5;
		}
		if(mouse_press(50+50+longer*2+40*2,440,50+50+longer*3+40*2,440+height)==1)//个人界面
		{
		    return 6;
		}
		if(mouse_press(300,360,380,400)==1)//地图界面
		{
			return 8;
		}
        if(mouse_press(50+50+longer*3+40*3,440,50+50+longer*4+40*3,440+height)==1){
            //反馈
            return 9;
        }
        if(mouse_press(0, 0, 45, 45)==1){
            return 2;//返回登录界面
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
    int read_count = 0;  // 实际读取的记录数
    int max_show = 5;    // 最大显示数量
    
    // 计算读取起始位置（考虑不足5条的情况）
    long read_pos;
	setbkcolor(WHITE);
	//退出键
	setcolor(LIGHTGRAY);
	setlinestyle(DOTTED_LINE,0,NORM_WIDTH);
	rectangle(595,0,640,45);
    setlinestyle(SOLID_LINE,0,THICK_WIDTH);
    line(595,0,640,45);
    line(640,0,595,45);
    //事故公告
    puthz(250,12,"事故公告",32,32,LIGHTGRAY);
    //公告通知
    puthz(50,30+12+y,"事故时间",24,24,GREEN);
    puthz(50+250,30+y+12,"事故类型",24,24,LIGHTGRAY);
    puthz(50+250*2-40,30+y+12,"处理状态",24,24,BROWN);
    //地图按钮
    puthz(50,360+12,"在地图中查看更多",24,24,LIGHTGRAY);
    setfillstyle(SOLID_FILL,GREEN);
    bar(300,360,380,400);
    puthz(300+25,360+12,"地图",24,24,WHITE);
    //更多信息按钮
    setfillstyle(SOLID_FILL,BLUE);
    bar(50+50,440,50+longer+50,440+height);
    bar(50+50+longer+40,440,50+50+longer*2+40,440+height);
    bar(50+50+longer*2+40*2,440,50+50+longer*3+40*2,440+height);
    bar(50+50+longer*3+40*3,440,50+50+longer*4+40*3,440+height);
    puthz(50+50,440+8,"报案",24,24,WHITE);
    puthz(50+50+longer+40,440+8,"历史",24,24,WHITE);
    puthz(50+50+longer*2+40*2,440+8,"个人",24,24,WHITE);
    puthz(50+50+longer*3+40*3,440+8,"反馈",24,24,WHITE);
     // 返回按键（左上角）
    setcolor(LIGHTGRAY);
    setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
    rectangle(0, 0, 45, 45); // 绘制返回按钮边框
    // 绘制返回箭头（"<" 形状）
    setcolor(BLUE);
    setlinestyle(SOLID_LINE, 0, THICK_WIDTH);
    line(30, 15, 15, 22);  // 右上角到箭头尖
    line(15, 22, 30, 30);  // 箭头尖到右下角
    // 打开二进制事故数据文件
    fp = fopen("ACCIDENT.dat", "rb");
    if (fp == NULL) {
        puthz(50, 300, "无事故公告！",16,16,RED);
        getch();
        closegraph();
        return;
    }


    fseek(fp, 0, SEEK_END);
    file_size = ftell(fp);
    total_records = file_size / sizeof(AccidentInfo);
    read_count = 0;  // 实际读取的记录数
    max_show = 5;    // 最大显示数量
    
    // 计算读取起始位置（考虑不足5条的情况）
    read_pos = (total_records > max_show) ? 
                   (total_records - max_show) * sizeof(AccidentInfo) : 0L;
    
    // 定位到读取起始位置
    fseek(fp, read_pos, SEEK_SET);
    
    // 遍历文件中的事故记录（最多5条）
    while (fread(&incident, sizeof(AccidentInfo), 1, fp) == 1 && read_count < max_show) {
        read_count++;  // 递增已显示数量
        // 显示位置计算
        display_y = 30 + y + 12 + read_count * y;  // 使用read_count代替current_row
        
        /* 原有显示代码保持不变 */
        setcolor(GREEN);
        settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
        outtextxy(20, display_y+5, incident.time);
        
        // 事故类型转换和显示...
        accident_type_trans(incident.accident_type, accident_type);
        puthz(300, display_y, accident_type, 24, 24, LIGHTGRAY);
        
        // 处理状态显示...
        if(incident.processed_status == '1') {
            puthz(50+250*2, display_y, "已处理", 24, 24, BROWN);
        } else {
            puthz(50+250*2, display_y, "未处理", 24, 24, BROWN);
        }
        

    }
    
    fclose(fp);

    // 如果未找到任何记录，则显示提示信息
    if (read_count == 0) {
        puthz(50, 30+y+12+y, "没有找到相关记录",24,24,LIGHTGRAY);
    }

}










