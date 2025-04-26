#include"common.h"
#include"verify.h"
#include"input.h"
#include"file.h"

void pagefresh(int current, int max);
void initial_screen();
int record_manage(char status);
int list(AccidentInfo *p, const char *date_filter, char type_filter, char status_filter,const char *id_card,int current_page);
int record_manage(char status){
    AccidentInfo x;
    char date_filter [17];
    char idcard_filter[21];
    char status_filter,type_filter;
    int current_num;// ������������
    int page_current = 0;//��ǰҳ������0��ʼ
    int perpage_max = 6;
    int pagenum_max;
    int flag = 0;//�Ƿ����ȡ֤

    status_filter = type_filter = date_filter[0]=idcard_filter[0]='\0';
    status_filter = status;
    cleardevice();
    initial_screen();
    current_num = list(&x,date_filter,type_filter,status_filter,idcard_filter,page_current);
    pagenum_max = (current_num + perpage_max - 1) / perpage_max;
    pagefresh(page_current,pagenum_max);
    if(status_filter == '0'){
        //δ����
        puthz(100,61,"δ����",24,24,DARKGRAY);
    }else if(status_filter == '1'){
        //�Ѵ���
        puthz(100,61,"�Ѵ���",24,24,DARKGRAY);
    }
    while(1){
        mou_pos(&MouseX,&MouseY,&press);
        if(mouse_press(0, 0, 45, 30)==1){
            return 11;//���ع����
        }
        if (mouse_press(600, 0, 640, 30) == 1) {
            closegraph();
            delay(1000);
            exit(0);
            continue;
        }//exit
        if(mouse_press(600,30,640,90)==1){
            clrmous(MouseX, MouseY);
		    delay(100);
		    save_bk_mou(MouseX,MouseY);
            status_filter = type_filter = date_filter[0]=idcard_filter[0]='\0';
            setfillstyle(SOLID_FILL,WHITE);
            bar(60,31+2,318,59-2);//clear date
            bar(430,32+1,599,59-1);//clear type
            bar(100,61+2,219,89-2);//clear status
            bar(320,61+2,599,89-2);//clear idcard
            clrmous(MouseX, MouseY);
		    delay(100);
		    save_bk_mou(MouseX,MouseY);
            //clear all
            current_num = list(&x,date_filter,type_filter,status_filter,idcard_filter,page_current);
            pagenum_max = (current_num + perpage_max - 1) / perpage_max;//�������ҳ��
            page_current = 0;
            pagefresh(page_current,pagenum_max);
            continue;
        }
        if(mouse_press(0,30,320,60) == 1){//date
            clrmous(MouseX, MouseY);
		    delay(100);
		    save_bk_mou(MouseX,MouseY);
            bar(60,31+2,318,59-2);
            input_time(60,30,date_filter,1,3);
            clrmous(MouseX, MouseY);
		    delay(100);
		    save_bk_mou(MouseX,MouseY);
            current_num = list(&x,date_filter,type_filter,status_filter,idcard_filter,page_current);
            pagenum_max = (current_num + perpage_max - 1) / perpage_max;
            page_current = 0;
            pagefresh(page_current,pagenum_max);
            continue;
        }
        if(mouse_press(320,30,600,60)==1){
            clrmous(MouseX, MouseY);
		    delay(100);
		    save_bk_mou(MouseX,MouseY);
            bar(430,32+1,599,59-2);
            input_accident_type(&type_filter);
            clrmous(MouseX, MouseY);
		    delay(100);
		    save_bk_mou(MouseX,MouseY);
            put_accident_type(type_filter,430,32,24,24,DARKGRAY);
            current_num = list(&x,date_filter,type_filter,status_filter,idcard_filter,page_current);
            pagenum_max = (current_num + perpage_max - 1) / perpage_max;
            page_current = 0;
            pagefresh(page_current,pagenum_max);
            continue;
            //accident type
        }

        if(mouse_press(0,60,220,90)==1){
            clrmous(MouseX, MouseY);
		    delay(100);
		    save_bk_mou(MouseX,MouseY);
            bar(100,61+2,219,89-2);
            input_status(&status_filter);
            clrmous(MouseX, MouseY);
		    delay(100);
		    save_bk_mou(MouseX,MouseY);
            if(status_filter == '0'){
                //δ����
                puthz(100,61,"δ����",24,24,DARKGRAY);
            }else if(status_filter == '1'){
                //�Ѵ���
                puthz(100,61,"�Ѵ���",24,24,DARKGRAY);
            }
            current_num = list(&x,date_filter,type_filter,status_filter,idcard_filter,page_current);
            pagenum_max = (current_num + perpage_max - 1) / perpage_max;
            page_current = 0;
            pagefresh(page_current,pagenum_max);
            clrmous(MouseX,MouseY);
            delay(100);
            continue;
            //status
        }
        if(mouse_press(220,60,600,90)==1){
            //idcard
            clrmous(MouseX, MouseY);
		    delay(100);
		    save_bk_mou(MouseX,MouseY);
            bar(320,61+2,599,89-2);
            input_str(320,60,idcard_filter,1,3,18);
            current_num = list(&x,date_filter,type_filter,status_filter,idcard_filter,page_current);
            pagenum_max = (current_num + perpage_max - 1) / perpage_max;
            page_current = 0;
            pagefresh(page_current,pagenum_max);
            clrmous(MouseX, MouseY);
		    delay(100);
		    save_bk_mou(MouseX,MouseY);
        }
        if(mouse_press(30,430,120,460)==1&&page_current>0){
            page_current--;
            current_num = list(&x,date_filter,type_filter,status_filter,idcard_filter,page_current);
            pagefresh(page_current,pagenum_max);
            delay(100);
            //�����һҳ
        }
        if(mouse_press(540,430,620,460)==1&&page_current<pagenum_max-1){
            page_current++;
            current_num = list(&x,date_filter,type_filter,status_filter,idcard_filter,page_current);
            pagefresh(page_current,pagenum_max);
            delay(100);
            //��һҳ
        }

        flag = record_click(&x,page_current,date_filter,type_filter,status_filter,idcard_filter,1);

        if(flag == 1){
            clrmous(MouseX,MouseY);
            initial_screen();
            current_num = list(&x,date_filter,type_filter,status_filter,idcard_filter,page_current);
            pagenum_max = (current_num + perpage_max - 1) / perpage_max;
            page_current = 0;
            pagefresh(page_current,pagenum_max);
        }else if(flag == 11){
            return 11;
        }

        
        
    }
}


void initial_screen(){
    cleardevice();
    setbkcolor(WHITE);
    // �˳�����
    setcolor(LIGHTGRAY);
    rectangle(600, 0, 640, 30);
    line(600, 0, 640, 30);
    line(640, 0, 600, 30);

     // ���ذ��������Ͻǣ�
    // ���Ʒ��ؼ�ͷ��"<" ��״��
    setcolor(BLUE);
    setlinestyle(SOLID_LINE, 0, THICK_WIDTH);
    line(30, 15, 15, 22);  // ���Ͻǵ���ͷ��
    line(15, 22, 30, 30);  // ��ͷ�⵽���½�
    puthz(275,3,"��¼�����",24,24,BLUE);
    setcolor(DARKGRAY);
    rectangle(0,30,320,60);
    rectangle(320,30,600,60);
    rectangle(0,60,220,90);
    rectangle(220,60,600,90);
    line(600,90,640,90);

    rectangle(30,430,120,460);
    puthz(30+5,430+2,"��һҳ",24,24,LIGHTBLUE);
    rectangle(540,430,620,460);
    puthz(540+5,430+2,"��һҳ",24,24,LIGHTBLUE);
    
    puthz(0,30+4,"����",24,24,BROWN);
    puthz(320,30+4,"�¹�����",24,24,BROWN);
    puthz(0,60+4,"����״��",24,24,BROWN);
    puthz(220,60+4,"���֤��",24,24,BROWN);
    puthz(610,33,"��",24,24,RED);
    puthz(610,63,"��",24,24,RED);
    
}

int list(AccidentInfo *p, const char *date_filter, char type_filter, char status_filter,const char *id_card,int current_page){
    FILE *fp;
    int header_y= 60;
    int row_height = 50;
    int col_time = 50;              // �¹�ʱ����ʾ��ʼ������
    int col_type = col_time + 200;    // �¹�������ʾ��ʼ������
    int col_status = col_type + 200;  // ����״̬��ʾ��ʼ������
    int current_row = 0;
    int display_y;
    char accident_type[20];
    int row_max = 6;
    // �򿪶������¹������ļ�
    fp = fopen("ACCIDENT.dat", "rb");
    if (fp == NULL) {
        puthz(50, header_y + row_height, "����ʷ��¼��",16,16,RED);
        getch();
        closegraph();
        return 0;
    }
    //�����ʾ
    setfillstyle(SOLID_FILL,WHITE);
    bar(0,header_y+50,640,420);
    // �����ļ��е������¹ʼ�¼
    fseek(fp,0,SEEK_SET);//��ָ��ָ��ָ��λ��
    while (fread(p, sizeof(AccidentInfo), 1, fp) == 1) {
        if(match(p,date_filter,type_filter,status_filter,id_card)==1 ){
            current_row++;//����������һ
            if(current_row <= current_page*row_max + row_max&&current_row > current_page*row_max){
                display_y = header_y + (current_row-current_page*row_max) * row_height;
                // ��ʾ�¹ʷ���ʱ��
                settextstyle(COMPLEX_FONT, HORIZ_DIR, 1);
                setcolor(LIGHTGREEN);
                outtextxy(col_time-20, display_y, p->time);
                // ��ʾ�¹����ͣ�ת��Ϊ����������
                accident_type_trans(p->accident_type,accident_type);
                puthz(col_type, display_y,accident_type,24,24,DARKGRAY);
                // ��ʾ����״̬
                if(p->processed_status == '1'){
                    puthz(col_status, display_y, "�Ѵ���",24,24,GREEN);
                }else if(p->processed_status == '0'){
                    puthz(col_status, display_y, "δ����",24,24,RED);
                }    
            }
           
        }
        // ����Ƿ�Ϊ���û��ļ�¼
    }
    fclose(fp);

    return current_row;
}
//����ɹ�����1,����-1
int record_click(AccidentInfo *incident,int current_page,const char *date_filter, char type_filter, char status_filter,const char *id_card,int flag){
    FILE *fp = NULL;
    int header_y= 60;
    int row_height = 50;
    int end_y,num_press;//ƥ��Ľṹ�����
    int page_max = 6;
    int page;
    int num = 0;
    int num_solid = 0;//��ʵ�Ľṹ�����
    end_y = header_y + (page_max+1)*row_height;
    
    if(mouse_press(0,header_y+row_height,640,end_y)==1){
        num_press = (MouseY-header_y-row_height)/row_height+current_page*page_max+1;//����Ľṹ�����ţ�1��ʼ��
        fp = fopen("ACCIDENT.dat", "rb");
        if (fp == NULL) {
            puthz(50, header_y + row_height, "����ʷ��¼��",16,16,RED);
            getch();
            closegraph();
            return;
        }else{
            fseek(fp,0,SEEK_SET);
        }
        while(fread(incident, sizeof(AccidentInfo), 1, fp) == 1){//��ָ��ָ��ָ��λ��
            num_solid++;
            if(match(incident,date_filter,type_filter,status_filter,id_card)==1 ){
                num++;
                if(num == num_press){
                    page =1;
                while(1){
                    if(page == 0){
                        fclose(fp);
                        return 1;
                        break;//�������
                    }
                    switch (page)
                    {
                    case 0 : //������ؼ�
                    fclose(fp);
                    return 1;
                        break;
                    case 1://��һ����Ϣ
                        page=show_per1(incident,flag);
                        delay(100);
                        break;

                    case 2://�ڶ�����Ϣ
                        page = show_per2(incident,flag);
                        delay(100);
                        break;
                    case 3://ȡ֤
                        fclose(fp);
                        page = page_evidence(num_solid,incident);
                        break;
                    case 4://ȡ֤չʾ
                        page = show_evidence(incident);
                        break;
                    case 5://�ж�չʾ
                        page = show_judge(incident);
                        break;
                    case 11://����
                        return 11;
                    case 17://�ж�
                        page = page_judge(incident,num_solid);
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

void pagefresh(int current, int max){
    char str[10];
    char current_s,max_s;
    setfillstyle(SOLID_FILL, WHITE);
    bar(270,430,400,470);
    settextstyle(0,0,3);
    current_s = current+'1';//start from 0
    max_s = max +'0';
    str[0]=current_s;
    str[1]='/';
    str[2] = max_s;
    str[3] = '\0';
    setcolor(GREEN);
    outtextxy(270,430,str);
    puthz(340,430,"ҳ",24,24,GREEN);
}
