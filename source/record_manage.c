#include"common.h"
#include"verify.h"
#include"input.h"
#include"file.h"
void initial_screen();
int record_manage();
int list(AccidentInfo *p, const char *date_filter, char type_filter, char status_filter,const char *id_card,int current_page);
int record_manage(){
    AccidentInfo x;
    char date_filter [17];
    char idcard_filter[21];
    char status_filter,type_filter;
    int current_num;
    int page_current = 0;//当前页数，从0开始
    int perpage_max = 6;
    int pagenum_max;

    status_filter = type_filter = date_filter[0]=idcard_filter[0]='\0';
    
    cleardevice();
    initial_screen();
    current_num = list(&x,date_filter,type_filter,status_filter,idcard_filter,page_current);
    pagenum_max = (current_num + perpage_max - 1) / perpage_max;
    while(1){
        mou_pos(&MouseX,&MouseY,&press);
        
        if (mouse_press(600, 0, 640, 30) == 1) {
            closegraph();
            delay(1000);
            exit(0);
        }//exit
        if(mouse_press(600,30,640,90)==1){
            status_filter = type_filter = date_filter[0]=idcard_filter[0]='\0';
            setfillstyle(SOLID_FILL,WHITE);
            bar(60,31,318,59);//clear date
            bar(430,32,599,59);//clear type
            bar(100,61,219,89);//clear status
            bar(320,61,599,89);//clear idcard
            //clear all
            current_num = list(&x,date_filter,type_filter,status_filter,idcard_filter,page_current);
            pagenum_max = (current_num + perpage_max - 1) / perpage_max;//更新最大页数
            page_current = 0;
        }
        if(mouse_press(0,30,320,60) == 1){//date
            bar(60,31,318,59);
            input_time(60,30,date_filter,1,3);
            current_num = list(&x,date_filter,type_filter,status_filter,idcard_filter,page_current);
            pagenum_max = (current_num + perpage_max - 1) / perpage_max;
            page_current = 0;
        }
        if(mouse_press(320,30,600,60)==1){
            bar(430,32,599,59);
            input_accident_type(&type_filter);
            put_accident_type(type_filter,430,32,24,24,DARKGRAY);
            current_num = list(&x,date_filter,type_filter,status_filter,idcard_filter,page_current);
            pagenum_max = (current_num + perpage_max - 1) / perpage_max;
            page_current = 0;
            //accident type
        }

        if(mouse_press(0,60,220,90)==1){
            bar(100,61,219,89);
            //status
        }
        if(mouse_press(220,60,600,90)==1){
            //idcard
            bar(320,61,599,89);
            input_str(320,60,idcard_filter,1,3,18);
            current_num = list(&x,date_filter,type_filter,status_filter,idcard_filter,page_current);
            pagenum_max = (current_num + perpage_max - 1) / perpage_max;
            page_current = 0;
        }
        if(mouse_press(30,430,120,460)==1&&page_current>0){
            page_current--;
            current_num = list(&x,date_filter,type_filter,status_filter,idcard_filter,page_current);
            delay(100);
            //点击上一页
        }
        if(mouse_press(540,430,620,460)==1&&page_current<pagenum_max-1){
            page_current++;
            current_num = list(&x,date_filter,type_filter,status_filter,idcard_filter,page_current);
            delay(100);
            //下一页
        }
        if(record_click(&x,page_current,date_filter,type_filter,status_filter,idcard_filter)==1){
            initial_screen();
            current_num = list(&x,date_filter,type_filter,status_filter,idcard_filter,page_current);
            pagenum_max = (current_num + perpage_max - 1) / perpage_max;
            page_current = 0;
        }

        
        
    }
}


void initial_screen(){
    cleardevice();
    setbkcolor(WHITE);
    // 退出按键
    setcolor(LIGHTGRAY);
    rectangle(600, 0, 640, 30);
    line(600, 0, 640, 30);
    line(640, 0, 600, 30);


    puthz(275,3,"记录与检索",24,24,BLUE);
    setcolor(DARKGRAY);
    rectangle(0,30,320,60);
    rectangle(320,30,600,60);
    rectangle(0,60,220,90);
    rectangle(220,60,600,90);
    line(600,90,640,90);

    rectangle(30,430,120,460);
    puthz(30+5,430+2,"上一页",24,24,LIGHTBLUE);
    rectangle(540,430,620,460);
    puthz(540+5,430+2,"下一页",24,24,LIGHTBLUE);
    
    puthz(0,30+4,"日期",24,24,BROWN);
    puthz(320,30+4,"事故类型",24,24,BROWN);
    puthz(0,60+4,"处理状况",24,24,BROWN);
    puthz(220,60+4,"身份证号",24,24,BROWN);
    puthz(610,33,"清",24,24,RED);
    puthz(610,63,"空",24,24,RED);
    
}

int list(AccidentInfo *p, const char *date_filter, char type_filter, char status_filter,const char *id_card,int current_page){
    FILE *fp;
    int header_y= 60;
    int row_height = 50;
    int col_time = 50;              // 事故时间显示起始横坐标
    int col_type = col_time + 200;    // 事故类型显示起始横坐标
    int col_status = col_type + 200;  // 处理状态显示起始横坐标
    int current_row = 0;
    int display_y;
    char accident_type[20];
    int row_max = 6;
    // 打开二进制事故数据文件
    fp = fopen("ACCIDENT.dat", "rb");
    if (fp == NULL) {
        puthz(50, header_y + row_height, "无历史记录！",16,16,RED);
        getch();
        closegraph();
        return 0;
    }
    //清空显示
    setfillstyle(SOLID_FILL,WHITE);
    bar(0,header_y+50,640,420);
    // 遍历文件中的所有事故记录
    fseek(fp,0,SEEK_SET);//将指针指在指定位置
    while (fread(p, sizeof(AccidentInfo), 1, fp) == 1) {
        if(match(p,date_filter,type_filter,status_filter,id_card)==1 ){
            current_row++;//符合条件加一
            if(current_row <= current_page*row_max + row_max&&current_row > current_page*row_max){
                display_y = header_y + (current_row-current_page*row_max) * row_height;
                // 显示事故发生时间
                settextstyle(COMPLEX_FONT, HORIZ_DIR, 1);
                setcolor(LIGHTGREEN);
                outtextxy(col_time-20, display_y, p->time);
                // 显示事故类型（转换为文字描述）
                accident_type_trans(p->accident_type,accident_type);
                puthz(col_type, display_y,accident_type,24,24,DARKGRAY);
                // 显示处理状态
                if(p->processed_status == 1){
                    puthz(col_status, display_y, "已处理",24,24,GREEN);
                }else if(p->processed_status == 0){
                    puthz(col_status, display_y, "未处理",24,24,RED);
                }    
            }
           
        }
        // 检查是否为该用户的记录
    }
    fclose(fp);
    return current_row;
}
//点击成功返回1,否则-1
int record_click(AccidentInfo *incident,int current_page,const char *date_filter, char type_filter, char status_filter,const char *id_card){
    FILE *fp;
    int header_y= 60;
    int row_height = 50;
    int end_y,num_press;
    int page_max = 6;
    int page;
    int num = 0;
    end_y = header_y + (page_max+1)*row_height;
    
    if(mouse_press(0,header_y+row_height,640,end_y)==1){
        num_press = (MouseY-header_y-row_height)/row_height+current_page*page_max+1;//点击的结构体的序号（1开始）
        fp = fopen("ACCIDENT.dat", "rb");
        if (fp == NULL) {
            puthz(50, header_y + row_height, "无历史记录！",16,16,RED);
            getch();
            closegraph();
            return;
        }else{
            fseek(fp,0,SEEK_SET);
        }
        while(fread(incident, sizeof(AccidentInfo), 1, fp) == 1){//将指针指在指定位置
           
            if(match(incident,date_filter,type_filter,status_filter,id_card)==1 ){
                num++;
                if(num == num_press){
                    page =1;
                while(1){
                    if(page == 0){
                        fclose(fp);
                        return 1;
                        break;//点击返回
                    }
                    switch (page)
                    {
                    case 0 : //点击返回键
                    fclose(fp);
                    return 1;
                        break;
                    case 1://第一人信息
                        page=show_per1(incident);
                        break;
                
                    case 2://第二人信息
                        page = show_per2(incident);
                        break;
                    default:
                        break;
                    }
                }
                }
            }
            
        
        }

    }
    if(fp==NULL){
        return -1 ;
    }
    fclose(fp);
    return -1;
}