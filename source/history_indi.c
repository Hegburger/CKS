#include"common.h"
#include"verify.h"
#include"input.h"
#include<stdlib.h>
int show_per1(AccidentInfo *x,char flag);
int show_per2(AccidentInfo *x,char flag);
int his_indi_screen(char *user_idcard,AccidentInfo *p);
void history_indi(char *user_idcard) {
    int num,end_y,num_press,page;
    int header_y = 50;
    int row_height = 50;
    AccidentInfo incident;
    int page_current = 0;
    int perpage_max = 6;
    int pagenum_max;
    int current_num;
    int flag;
    char date_filter [1];
    char status_filter,type_filter;
    status_filter = type_filter = date_filter[0]='\0';
    cleardevice();
    his_indi_screen(NULL,NULL);
    current_num = list(&incident,date_filter,type_filter,status_filter,user_idcard,page_current);
    pagenum_max = (current_num + perpage_max - 1) / perpage_max;
    pagefresh(page_current,pagenum_max);
    while(1){
        mou_pos(&MouseX,&MouseY,&press);
        if(mouse_press(595,0,640,45)==1){
                closegraph();//关闭画图
                delay(1000);
                exit(0);//退出程序
        }
        if(mouse_press(0, 0, 45, 45)==1){
            return 3;//返回主页面
        }

        if(mouse_press(30,430,120,460)==1&&page_current>0){
            page_current--;
            current_num =  list(&incident,date_filter,type_filter,status_filter,user_idcard,page_current);
            pagefresh(page_current,pagenum_max);
            delay(100);
            //点击上一页
        }
        if(mouse_press(540,430,620,460)==1&&page_current<pagenum_max-1){
            page_current++;
            current_num =  list(&incident,date_filter,type_filter,status_filter,user_idcard,page_current);
            pagefresh(page_current,pagenum_max);
            delay(100);
            //下一页
        }

        flag = record_click(&incident,page_current,date_filter,type_filter,status_filter,user_idcard,0);

        if(flag == 1){
            clrmous(MouseX,MouseY);
            his_indi_screen(NULL,NULL);
            current_num =  list(&incident,date_filter,type_filter,status_filter,user_idcard,page_current);
            pagenum_max = (current_num + perpage_max - 1) / perpage_max;
            page_current = 0;
            pagefresh(page_current,pagenum_max);
        }else if(flag == 11){
            return 11;
        }

        // if(mouse_press(0,header_y+row_height,640,end_y)==1){
        //     num_press = (MouseY-header_y-row_height)/row_height;//点击的结构体的序号（0开始）
        //     fp = fopen("ACCIDENT.dat", "rb");
        //     if (fp == NULL) {
        //         puthz(50, header_y + row_height, "无历史记录！",16,16,RED);
        //         getch();
        //         closegraph();
        //         return;
        //     }
        //     fseek(fp,num_press*sizeof(AccidentInfo),SEEK_SET);//将指针指在指定位置
        //     if(fread(&incident, sizeof(AccidentInfo), 1, fp) == 1){
        //         page =1;
        //         while(1){
        //             if(page == 0){
        //                 cleardevice();
        //                 num = his_indi_screen(user_idcard,&incident);
        //                 break;//点击返回
        //             }
        //             switch (page)
        //             {
        //             case 0 : //点击返回键
                       
        //                 break;
        //             case 1://第一人信息
        //                 page=show_per1(&incident);
        //                 delay(100);
        //                 break;
                    
        //             case 2://第二人信息
        //                 page = show_per2(&incident,'\0');
        //                 delay(100);
        //                 break;
                    
        //             default:
        //                 break;
        //             }
        //         }
        //         fclose(fp);

                
        //     }else{
        //         fclose(fp);
        //         puthz(50, header_y + row_height, "文件打开失败",16,16,RED);
        //         getch();
        //         closegraph();
        //         return;
        //     }
            

        // }
    }

}

int his_indi_screen(char *user_idcard,AccidentInfo *p){
    FILE *fp = NULL;
    int header_y = 50;
    int row_height = 50;
    int col_time = 78;              // 事故时间显示起始横坐标
    int col_type = col_time + 180;    // 事故类型显示起始横坐标
    int col_status = col_type + 180;  // 处理状态显示起始横坐标
    int current_row = 0;
    int display_y;
    char accident_type[20];
    clrmous(MouseX,MouseY);
    cleardevice();
    setbkcolor(WHITE);
    setcolor(DARKGRAY);
    puthz(50, 10, "历史报案记录",24,24,BLUE);

    // 绘制表头
    puthz(col_time, header_y, "事故时间",16,16,BROWN);
    puthz(col_type, header_y, "事故类型",16,16,BROWN);
    puthz(col_status, header_y, "处理状态",16,16,BROWN);
    // 绘制返回箭头（"<" 形状）
    setcolor(BLUE);
    setlinestyle(SOLID_LINE, 0, THICK_WIDTH);
    line(30, 15, 15, 22);  // 右上角到箭头尖
    line(15, 22, 30, 30);  // 箭头尖到右下角
     //退出按键
     setcolor(LIGHTGRAY);
     setlinestyle(DOTTED_LINE,0,NORM_WIDTH);
     rectangle(595,0,640,45);
     setlinestyle(SOLID_LINE,0,THICK_WIDTH);
     line(595,0,640,45);
     line(640,0,595,45);
     rectangle(30,430,120,460);
     puthz(30+5,430+2,"上一页",24,24,LIGHTBLUE);
     rectangle(540,430,620,460);
     puthz(540+5,430+2,"下一页",24,24,LIGHTBLUE);
    // // 打开二进制事故数据文件
    // fp = fopen("ACCIDENT.dat", "rb");
    // if (fp == NULL) {
    //     puthz(50, header_y + row_height, "无历史记录！",16,16,RED);
    //     getch();
    //     closegraph();
    //     return 0;
    // }


    // // 遍历文件中的所有事故记录
    // while (fread(p, sizeof(AccidentInfo), 1, fp) == 1) {
    //     // 检查是否为该用户的记录（匹配身份证）
    //     if (strcmp(p->per1_idcard, user_idcard) == 0 ||
    //         strcmp(p->per2_idcard, user_idcard) == 0) {
    //         current_row++;
    //         display_y = header_y + current_row * row_height;
    //         // 显示事故发生时间
    //         settextstyle(COMPLEX_FONT, HORIZ_DIR, 1);
    //         setcolor(LIGHTGREEN);
    //         outtextxy(col_time-20, display_y, p->time);
    //         // 显示事故类型（转换为文字描述）
    //         accident_type_trans(p->accident_type,accident_type);
    //         puthz(col_type, display_y,accident_type,24,24,DARKGRAY);
    //         // 显示处理状态
    //         if(p->processed_status == '1'){
    //             puthz(col_status, display_y, "已处理",24,24,GREEN);
    //         }else if(p->processed_status == '0'){
    //             puthz(col_status, display_y, "未处理",24,24,RED);
    //         }
                
    //     }
    // }
    // fclose(fp);

    // // 如果未找到任何记录，则显示提示信息
    // if (current_row == 0) {
    //     puthz(50, header_y + row_height, "没有找到相关记录",24,24,GREEN);
    // }
    // return current_row;
}

//展示第一个人信息，返回2进入第二个人信息
int show_per1(AccidentInfo *x,char flag){
    int height = 40,i,page;
    int lineStart_y = 80,numBlank=9;
    int check=0;
    int random=0;
    clrmous(MouseX,MouseY);
    delay(100);
    cleardevice();
    setbkcolor(WHITE);
    //退出按键
     setcolor(LIGHTGRAY);
     setlinestyle(DOTTED_LINE,0,NORM_WIDTH);
     rectangle(595,0,640,45);
     setlinestyle(SOLID_LINE,0,THICK_WIDTH);
     line(595,0,640,45);
     line(640,0,595,45);

     // 返回按键（左上角）
    setcolor(LIGHTGRAY);
    setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
    rectangle(0, 0, 45, 45); // 绘制返回按钮边框
    // 绘制返回箭头（"<" 形状）
    setcolor(BLUE);
    setlinestyle(SOLID_LINE, 0, THICK_WIDTH);
    line(30, 15, 15, 22);  // 右上角到箭头尖
    line(15, 22, 30, 30);  // 箭头尖到右下角
    
    //画线
    setcolor(LIGHTGRAY);
    setlinestyle(SOLID_LINE,0,NORM_WIDTH);
    for(i = 0 ;i <= numBlank;i++){
        line(0,lineStart_y+height*i,640,lineStart_y+height*i);

    }
    //原页面
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
    puthz(280,5,"报案记录",32,32,RED);
    if(x->processed_status=='0'&&flag=='\0')
    {
	    puthz(5,lineStart_y+height*10-29,"点击这里催一下管理员处理你的报案",24,24,LIGHTBLUE);
	    settextstyle(1,0,3);
	    setcolor(LIGHTBLUE);
	    outtextxy(410,lineStart_y+height*10-29-5,"\\(>w<)/");
	}

    //信息输入
    settextstyle(1, 0, 3);  // 对应的字体样式和大小
    outtextxy(60,lineStart_y+height*0+5,x->time);
    puthz(50,lineStart_y+height*1+10,x->location,24,24,LIGHTGRAY);
    puthz(400,lineStart_y+height*1+10,x->weather,24,24,LIGHTGRAY);
    put_accident_type(x->accident_type,100,lineStart_y+height*2+10,24,24,LIGHTGRAY);//type
    outtextxy(100,lineStart_y+height*4+10,x->per1_idcard);//idcard
    outtextxy(100,lineStart_y+height*5+10,x->per1_phone);//phone
    puthz(120,lineStart_y+height*6+10,x->per1_car.type,24,24,LIGHTGRAY);//car type
    puthz(410,lineStart_y+height*6+10,x->per1_car.province,24,24,LIGHTGRAY);
    outtextxy(430,lineStart_y+height*6+10,x->per1_car.plate);//plate
    puthz(160,lineStart_y+height*7+10,x->per1_destroied_part,24,24,LIGHTGRAY);//受损 
    setfillstyle(SOLID_FILL,WHITE);
	settextstyle(1,0,3);
    srand(time(NULL));
    //循环
    while (1)
    {
        mou_pos(&MouseX,&MouseY,&press);

        if(mouse_press(595,0,640,45)==1){//退出
            closegraph();//关闭画图
            delay(1000);
            exit(0);//退出程序
         }

        if(mouse_press(0,lineStart_y+height*8,640,lineStart_y+height*9)==1){
            page =2;
            break;
        }

        if(mouse_press(0, 0, 45, 45)==1){
            page =0;
            delay(100);
            break;
        }
	    if(mouse_press(0,451,450,480)==1&&check==0&&x->processed_status=='0')
	    {
	       	if(flag=='\0')
	       	{
				random=(rand()%6)+1;
				if(random==1)
				{
				            clrmous(MouseX, MouseY);
						    delay(100);
						    save_bk_mou(MouseX,MouseY);
					bar(0,451,700,480);
		            puthz(5,lineStart_y+height*10-29,"点击这里催一下管理员处理你的报案",24,24,LIGHTCYAN);
				    setcolor(LIGHTCYAN);
				    outtextxy(410,lineStart_y+height*10-29-5,"\\(>w<)/");
				    
				            clrmous(MouseX, MouseY);
						    delay(100);
						    save_bk_mou(MouseX,MouseY);
				}
				if(random==2)
				{
				            clrmous(MouseX, MouseY);
						    delay(100);
						    save_bk_mou(MouseX,MouseY);
					bar(0,451,700,480);
		            puthz(5,lineStart_y+height*10-29,"点击这里催一下管理员处理你的报案",24,24,LIGHTRED);
				    setcolor(LIGHTRED);
				    outtextxy(410,lineStart_y+height*10-29-5,"\\(>w<)/");
			
					            clrmous(MouseX, MouseY);
							    delay(100);
							    save_bk_mou(MouseX,MouseY);
				}
				if(random==3)
				{
				            clrmous(MouseX, MouseY);
						    delay(100);
						    save_bk_mou(MouseX,MouseY);
					bar(0,451,700,480);
		            puthz(5,lineStart_y+height*10-29,"点击这里催一下管理员处理你的报案",24,24,LIGHTGREEN);
				    setcolor(LIGHTGREEN);
				    outtextxy(410,lineStart_y+height*10-29-5,"\\(>w<)/");
				    
				            clrmous(MouseX, MouseY);
						    delay(100);
						    save_bk_mou(MouseX,MouseY);
				}
				if(random==4)
				{
				            clrmous(MouseX, MouseY);
						    delay(100);
						    save_bk_mou(MouseX,MouseY);
					bar(0,451,700,480);
		            puthz(5,lineStart_y+height*10-29,"点击这里催一下管理员处理你的报案",24,24,BLUE);
				    setcolor(BLUE);
				    outtextxy(410,lineStart_y+height*10-29-5,"\\(>w<)/");
		
				            clrmous(MouseX, MouseY);
						    delay(100);
						    save_bk_mou(MouseX,MouseY);
				}
				if(random==5)
				{
				            clrmous(MouseX, MouseY);
						    delay(100);
						    save_bk_mou(MouseX,MouseY);
					bar(0,451,700,480);
		            puthz(5,lineStart_y+height*10-29,"点击这里催一下管理员处理你的报案",24,24,LIGHTMAGENTA);
				    setcolor(LIGHTMAGENTA);
				    outtextxy(410,lineStart_y+height*10-29-5,"\\(>w<)/");
				    
				            clrmous(MouseX, MouseY);
						    delay(100);
						    save_bk_mou(MouseX,MouseY);
				}
				if(random==6)
				{
				            clrmous(MouseX, MouseY);
						    delay(100);
						    save_bk_mou(MouseX,MouseY);
					bar(0,451,700,480);
		            puthz(5,lineStart_y+height*10-29,"别催啦，管理员要头秃了",24,24,BROWN);
				    setcolor(BROWN);
				    outtextxy(410-100,lineStart_y+height*10-29-5,"_(QAQ)_");
				    check++;
				    
				            clrmous(MouseX, MouseY);
						    delay(100);
						    save_bk_mou(MouseX,MouseY);
				}
			}
		}
    }
    return page;

}
// flag = 1 表示管理端，可以进入取证
int show_per2(AccidentInfo *x, char flag) {
    int height = 40, i,page;
    int lineStart_y = 80, numBlank = 9;
    clrmous(MouseX, MouseY);
    delay(100);
    cleardevice();
    setbkcolor(WHITE);
    
    // 退出按键
    setcolor(LIGHTGRAY);
    setlinestyle(DOTTED_LINE, 0, NORM_WIDTH);
    rectangle(595, 0, 640, 45);
    setlinestyle(SOLID_LINE, 0, THICK_WIDTH);
    line(595, 0, 640, 45);
    line(640, 0, 595, 45);
    
    // 返回按键（左上角）
    setcolor(LIGHTGRAY);
    setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
    rectangle(0, 0, 45, 45); // 绘制返回按钮边框
 
    // 绘制返回箭头（"<" 形状）
    setcolor(BLUE);
    setlinestyle(SOLID_LINE, 0, THICK_WIDTH);
    line(30, 15, 15, 22);  // 右上角到箭头尖
    line(15, 22, 30, 30);  // 箭头尖到右下角
    // 绘制分隔线
    setcolor(LIGHTGRAY);
    setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
    for(i = 0; i <= numBlank; i++){
        line(0, lineStart_y + height * i, 640, lineStart_y + height * i);
    }
    
    // 界面标题和标签（不再显示时间、地点、天气、事故类型）
    puthz(5, lineStart_y - 29, "对方信息", 24, 24, BROWN);
    puthz(5, lineStart_y + height - 29, "身份证号", 24, 24, GREEN);
    puthz(5, lineStart_y + height * 2 - 29, "手机号", 24, 24, GREEN);
    puthz(5, lineStart_y + height * 3 - 29, "车辆类型", 24, 24, GREEN);
    puthz(325, lineStart_y + height * 3 - 29, "车牌号", 24, 24, GREEN);
    puthz(5, lineStart_y + height * 4 - 29, "显著受损部位", 24, 24, GREEN);
    
    // 在第二人信息下方添加责任信息
    puthz(5, lineStart_y + height * 6 - 29, "处理状态", 24, 24, BLUE);
    puthz(5, lineStart_y + height * 7 - 29, "审理单位", 24, 24, BLUE);
    puthz(5, lineStart_y + height * 8 - 29, "肇事者责任", 24, 24, BLUE);
    line(300,lineStart_y+height*7,300,lineStart_y+height*8);
    puthz(305, lineStart_y + height * 8 - 29, "被害者责任", 24, 24, BLUE);
    puthz(5,lineStart_y + height * 9 - 29,"当事人信息",24,24,BLUE);
    
    puthz(280, 5, "报案记录", 32, 32, RED);
    
    // 信息输入
    settextstyle(1, 0, 3);
    // 当事人信息
    outtextxy(100, lineStart_y  + 10, x->per2_idcard);   // 身份证号
    outtextxy(100, lineStart_y + height * 1 + 10, x->per2_phone);      // 手机号
    puthz(120, lineStart_y + height * 2 + 10, x->per2_car.type, 24, 24, LIGHTGRAY); // 车辆类型
    puthz(410, lineStart_y + height * 2 + 10, x->per2_car.province, 24, 24, LIGHTGRAY);
    outtextxy(430, lineStart_y + height * 2 + 10, x->per2_car.plate);    // 车牌号
    puthz(120,lineStart_y+height*6+10,x->judge.final_log,24,24,BROWN);//审理单位
    puthz(160, lineStart_y + height * 3 + 10, x->per2_destroied_part, 24, 24, LIGHTGRAY); // 显著受损部位
    puthz(140,lineStart_y+height*7+10,x->judge.final_per1duty,24,24,BROWN);//甲方责任
    puthz(140+300,lineStart_y+height*7+10,x->judge.final_per2duty,24,24,BROWN);//乙方责任
    // 责任信息（显示在第二人信息下方）
    if(x->processed_status == '0'){
        puthz(120, lineStart_y + height * 5 + 10,"未处理",24,24,RED); 
    } else {
        puthz(120, lineStart_y + height * 5 + 10,"已处理",24,24,GREEN);
    }// 处理状态
    if(flag != '\0'&&x->processed_status!='1'){
        setcolor(LIGHTCYAN);
        setlinestyle(SOLID_LINE, 0, THICK_WIDTH);
        rectangle(295,lineStart_y + height * 9+7,405,lineStart_y + height * 9+38);
        puthz(300,lineStart_y + height * 9+10,"进入取证",24,24,BLUE);
    }
    while (1)
    {
        mou_pos(&MouseX,&MouseY,&press);

        if(mouse_press(595,0,640,45)==1){//退出
            closegraph();//关闭画图
            delay(1000);
            exit(0);//退出程序
         }

        if(mouse_press(0,lineStart_y+height*8,640,lineStart_y+height*9)==1){
            page =1;
            break;
        }

        if(mouse_press(0, 0, 45, 45)==1){
            page =1;
            delay(100);
            break;
        }
        if(mouse_press(295,lineStart_y + height * 9+7,405,lineStart_y + height * 9+38)==1 && flag !='\0'&&x->processed_status!='1'){
            page = 3;
            delay(100);
            break;
        }
        

    }
    return page;
}


void warning_screen(){
    clock_t start,current;
    clrmous(MouseX,MouseY);
    cleardevice();
    setbkcolor(WHITE);
    puthz(170,100,"请先补充个人信息",32,32,RED);
    current = start = clock();
    while((current - start)/CLK_TCK < 3){
        mou_pos(&MouseX,&MouseY,&press);
        current = clock();
    }
}
