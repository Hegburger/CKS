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
                closegraph();//�رջ�ͼ
                delay(1000);
                exit(0);//�˳�����
        }
        if(mouse_press(0, 0, 45, 45)==1){
            return 3;//������ҳ��
        }

        if(mouse_press(30,430,120,460)==1&&page_current>0){
            page_current--;
            current_num =  list(&incident,date_filter,type_filter,status_filter,user_idcard,page_current);
            pagefresh(page_current,pagenum_max);
            delay(100);
            //�����һҳ
        }
        if(mouse_press(540,430,620,460)==1&&page_current<pagenum_max-1){
            page_current++;
            current_num =  list(&incident,date_filter,type_filter,status_filter,user_idcard,page_current);
            pagefresh(page_current,pagenum_max);
            delay(100);
            //��һҳ
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
        //     num_press = (MouseY-header_y-row_height)/row_height;//����Ľṹ�����ţ�0��ʼ��
        //     fp = fopen("ACCIDENT.dat", "rb");
        //     if (fp == NULL) {
        //         puthz(50, header_y + row_height, "����ʷ��¼��",16,16,RED);
        //         getch();
        //         closegraph();
        //         return;
        //     }
        //     fseek(fp,num_press*sizeof(AccidentInfo),SEEK_SET);//��ָ��ָ��ָ��λ��
        //     if(fread(&incident, sizeof(AccidentInfo), 1, fp) == 1){
        //         page =1;
        //         while(1){
        //             if(page == 0){
        //                 cleardevice();
        //                 num = his_indi_screen(user_idcard,&incident);
        //                 break;//�������
        //             }
        //             switch (page)
        //             {
        //             case 0 : //������ؼ�
                       
        //                 break;
        //             case 1://��һ����Ϣ
        //                 page=show_per1(&incident);
        //                 delay(100);
        //                 break;
                    
        //             case 2://�ڶ�����Ϣ
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
        //         puthz(50, header_y + row_height, "�ļ���ʧ��",16,16,RED);
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
    int col_time = 78;              // �¹�ʱ����ʾ��ʼ������
    int col_type = col_time + 180;    // �¹�������ʾ��ʼ������
    int col_status = col_type + 180;  // ����״̬��ʾ��ʼ������
    int current_row = 0;
    int display_y;
    char accident_type[20];
    clrmous(MouseX,MouseY);
    cleardevice();
    setbkcolor(WHITE);
    setcolor(DARKGRAY);
    puthz(50, 10, "��ʷ������¼",24,24,BLUE);

    // ���Ʊ�ͷ
    puthz(col_time, header_y, "�¹�ʱ��",16,16,BROWN);
    puthz(col_type, header_y, "�¹�����",16,16,BROWN);
    puthz(col_status, header_y, "����״̬",16,16,BROWN);
    // ���Ʒ��ؼ�ͷ��"<" ��״��
    setcolor(BLUE);
    setlinestyle(SOLID_LINE, 0, THICK_WIDTH);
    line(30, 15, 15, 22);  // ���Ͻǵ���ͷ��
    line(15, 22, 30, 30);  // ��ͷ�⵽���½�
     //�˳�����
     setcolor(LIGHTGRAY);
     setlinestyle(DOTTED_LINE,0,NORM_WIDTH);
     rectangle(595,0,640,45);
     setlinestyle(SOLID_LINE,0,THICK_WIDTH);
     line(595,0,640,45);
     line(640,0,595,45);
     rectangle(30,430,120,460);
     puthz(30+5,430+2,"��һҳ",24,24,LIGHTBLUE);
     rectangle(540,430,620,460);
     puthz(540+5,430+2,"��һҳ",24,24,LIGHTBLUE);
    // // �򿪶������¹������ļ�
    // fp = fopen("ACCIDENT.dat", "rb");
    // if (fp == NULL) {
    //     puthz(50, header_y + row_height, "����ʷ��¼��",16,16,RED);
    //     getch();
    //     closegraph();
    //     return 0;
    // }


    // // �����ļ��е������¹ʼ�¼
    // while (fread(p, sizeof(AccidentInfo), 1, fp) == 1) {
    //     // ����Ƿ�Ϊ���û��ļ�¼��ƥ�����֤��
    //     if (strcmp(p->per1_idcard, user_idcard) == 0 ||
    //         strcmp(p->per2_idcard, user_idcard) == 0) {
    //         current_row++;
    //         display_y = header_y + current_row * row_height;
    //         // ��ʾ�¹ʷ���ʱ��
    //         settextstyle(COMPLEX_FONT, HORIZ_DIR, 1);
    //         setcolor(LIGHTGREEN);
    //         outtextxy(col_time-20, display_y, p->time);
    //         // ��ʾ�¹����ͣ�ת��Ϊ����������
    //         accident_type_trans(p->accident_type,accident_type);
    //         puthz(col_type, display_y,accident_type,24,24,DARKGRAY);
    //         // ��ʾ����״̬
    //         if(p->processed_status == '1'){
    //             puthz(col_status, display_y, "�Ѵ���",24,24,GREEN);
    //         }else if(p->processed_status == '0'){
    //             puthz(col_status, display_y, "δ����",24,24,RED);
    //         }
                
    //     }
    // }
    // fclose(fp);

    // // ���δ�ҵ��κμ�¼������ʾ��ʾ��Ϣ
    // if (current_row == 0) {
    //     puthz(50, header_y + row_height, "û���ҵ���ؼ�¼",24,24,GREEN);
    // }
    // return current_row;
}

//չʾ��һ������Ϣ������2����ڶ�������Ϣ
int show_per1(AccidentInfo *x,char flag){
    int height = 40,i,page;
    int lineStart_y = 80,numBlank=9;
    int check=0;
    int random=0;
    clrmous(MouseX,MouseY);
    delay(100);
    cleardevice();
    setbkcolor(WHITE);
    //�˳�����
     setcolor(LIGHTGRAY);
     setlinestyle(DOTTED_LINE,0,NORM_WIDTH);
     rectangle(595,0,640,45);
     setlinestyle(SOLID_LINE,0,THICK_WIDTH);
     line(595,0,640,45);
     line(640,0,595,45);

     // ���ذ��������Ͻǣ�
    setcolor(LIGHTGRAY);
    setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
    rectangle(0, 0, 45, 45); // ���Ʒ��ذ�ť�߿�
    // ���Ʒ��ؼ�ͷ��"<" ��״��
    setcolor(BLUE);
    setlinestyle(SOLID_LINE, 0, THICK_WIDTH);
    line(30, 15, 15, 22);  // ���Ͻǵ���ͷ��
    line(15, 22, 30, 30);  // ��ͷ�⵽���½�
    
    //����
    setcolor(LIGHTGRAY);
    setlinestyle(SOLID_LINE,0,NORM_WIDTH);
    for(i = 0 ;i <= numBlank;i++){
        line(0,lineStart_y+height*i,640,lineStart_y+height*i);

    }
    //ԭҳ��
    puthz(5,lineStart_y-29,"�¹ʻ�����Ϣ",24,24,BROWN);
    puthz(5,lineStart_y+height-29,"ʱ��",24,24,GREEN);
    puthz(5,lineStart_y+height*2-29,"�ص�",24,24,GREEN);
    puthz(325,lineStart_y+height*2-29,"����",24,24,GREEN);
    puthz(5,lineStart_y+height*3-29,"�¹�����",24,24,GREEN);
    puthz(5,lineStart_y+height*4-29,"��������Ϣ",24,24,BROWN);
    puthz(5,lineStart_y+height*5-29,"���֤��",24,24,GREEN);
    puthz(5,lineStart_y+height*6-29,"�ֻ���",24,24,GREEN);
    puthz(5,lineStart_y+height*7-29,"��������",24,24,GREEN);
    puthz(325,lineStart_y+height*7-29,"���ƺ�",24,24,GREEN);
    puthz(5,lineStart_y+height*8-29,"��������λ",24,24,GREEN);
    puthz(5,lineStart_y+height*9-29,"�Է���Ϣ",24,24,BLUE);
    puthz(280,5,"������¼",32,32,RED);
    if(x->processed_status=='0'&&flag=='\0')
    {
	    puthz(5,lineStart_y+height*10-29,"��������һ�¹���Ա������ı���",24,24,LIGHTBLUE);
	    settextstyle(1,0,3);
	    setcolor(LIGHTBLUE);
	    outtextxy(410,lineStart_y+height*10-29-5,"\\(>w<)/");
	}

    //��Ϣ����
    settextstyle(1, 0, 3);  // ��Ӧ��������ʽ�ʹ�С
    outtextxy(60,lineStart_y+height*0+5,x->time);
    puthz(50,lineStart_y+height*1+10,x->location,24,24,LIGHTGRAY);
    puthz(400,lineStart_y+height*1+10,x->weather,24,24,LIGHTGRAY);
    put_accident_type(x->accident_type,100,lineStart_y+height*2+10,24,24,LIGHTGRAY);//type
    outtextxy(100,lineStart_y+height*4+10,x->per1_idcard);//idcard
    outtextxy(100,lineStart_y+height*5+10,x->per1_phone);//phone
    puthz(120,lineStart_y+height*6+10,x->per1_car.type,24,24,LIGHTGRAY);//car type
    puthz(410,lineStart_y+height*6+10,x->per1_car.province,24,24,LIGHTGRAY);
    outtextxy(430,lineStart_y+height*6+10,x->per1_car.plate);//plate
    puthz(160,lineStart_y+height*7+10,x->per1_destroied_part,24,24,LIGHTGRAY);//���� 
    setfillstyle(SOLID_FILL,WHITE);
	settextstyle(1,0,3);
    srand(time(NULL));
    //ѭ��
    while (1)
    {
        mou_pos(&MouseX,&MouseY,&press);

        if(mouse_press(595,0,640,45)==1){//�˳�
            closegraph();//�رջ�ͼ
            delay(1000);
            exit(0);//�˳�����
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
		            puthz(5,lineStart_y+height*10-29,"��������һ�¹���Ա������ı���",24,24,LIGHTCYAN);
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
		            puthz(5,lineStart_y+height*10-29,"��������һ�¹���Ա������ı���",24,24,LIGHTRED);
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
		            puthz(5,lineStart_y+height*10-29,"��������һ�¹���Ա������ı���",24,24,LIGHTGREEN);
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
		            puthz(5,lineStart_y+height*10-29,"��������һ�¹���Ա������ı���",24,24,BLUE);
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
		            puthz(5,lineStart_y+height*10-29,"��������һ�¹���Ա������ı���",24,24,LIGHTMAGENTA);
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
		            puthz(5,lineStart_y+height*10-29,"�����������ԱҪͷͺ��",24,24,BROWN);
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
// flag = 1 ��ʾ����ˣ����Խ���ȡ֤
int show_per2(AccidentInfo *x, char flag) {
    int height = 40, i,page;
    int lineStart_y = 80, numBlank = 9;
    clrmous(MouseX, MouseY);
    delay(100);
    cleardevice();
    setbkcolor(WHITE);
    
    // �˳�����
    setcolor(LIGHTGRAY);
    setlinestyle(DOTTED_LINE, 0, NORM_WIDTH);
    rectangle(595, 0, 640, 45);
    setlinestyle(SOLID_LINE, 0, THICK_WIDTH);
    line(595, 0, 640, 45);
    line(640, 0, 595, 45);
    
    // ���ذ��������Ͻǣ�
    setcolor(LIGHTGRAY);
    setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
    rectangle(0, 0, 45, 45); // ���Ʒ��ذ�ť�߿�
 
    // ���Ʒ��ؼ�ͷ��"<" ��״��
    setcolor(BLUE);
    setlinestyle(SOLID_LINE, 0, THICK_WIDTH);
    line(30, 15, 15, 22);  // ���Ͻǵ���ͷ��
    line(15, 22, 30, 30);  // ��ͷ�⵽���½�
    // ���Ʒָ���
    setcolor(LIGHTGRAY);
    setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
    for(i = 0; i <= numBlank; i++){
        line(0, lineStart_y + height * i, 640, lineStart_y + height * i);
    }
    
    // �������ͱ�ǩ��������ʾʱ�䡢�ص㡢�������¹����ͣ�
    puthz(5, lineStart_y - 29, "�Է���Ϣ", 24, 24, BROWN);
    puthz(5, lineStart_y + height - 29, "���֤��", 24, 24, GREEN);
    puthz(5, lineStart_y + height * 2 - 29, "�ֻ���", 24, 24, GREEN);
    puthz(5, lineStart_y + height * 3 - 29, "��������", 24, 24, GREEN);
    puthz(325, lineStart_y + height * 3 - 29, "���ƺ�", 24, 24, GREEN);
    puthz(5, lineStart_y + height * 4 - 29, "��������λ", 24, 24, GREEN);
    
    // �ڵڶ�����Ϣ�·����������Ϣ
    puthz(5, lineStart_y + height * 6 - 29, "����״̬", 24, 24, BLUE);
    puthz(5, lineStart_y + height * 7 - 29, "����λ", 24, 24, BLUE);
    puthz(5, lineStart_y + height * 8 - 29, "����������", 24, 24, BLUE);
    line(300,lineStart_y+height*7,300,lineStart_y+height*8);
    puthz(305, lineStart_y + height * 8 - 29, "����������", 24, 24, BLUE);
    puthz(5,lineStart_y + height * 9 - 29,"��������Ϣ",24,24,BLUE);
    
    puthz(280, 5, "������¼", 32, 32, RED);
    
    // ��Ϣ����
    settextstyle(1, 0, 3);
    // ��������Ϣ
    outtextxy(100, lineStart_y  + 10, x->per2_idcard);   // ���֤��
    outtextxy(100, lineStart_y + height * 1 + 10, x->per2_phone);      // �ֻ���
    puthz(120, lineStart_y + height * 2 + 10, x->per2_car.type, 24, 24, LIGHTGRAY); // ��������
    puthz(410, lineStart_y + height * 2 + 10, x->per2_car.province, 24, 24, LIGHTGRAY);
    outtextxy(430, lineStart_y + height * 2 + 10, x->per2_car.plate);    // ���ƺ�
    puthz(120,lineStart_y+height*6+10,x->judge.final_log,24,24,BROWN);//����λ
    puthz(160, lineStart_y + height * 3 + 10, x->per2_destroied_part, 24, 24, LIGHTGRAY); // ��������λ
    puthz(140,lineStart_y+height*7+10,x->judge.final_per1duty,24,24,BROWN);//�׷�����
    puthz(140+300,lineStart_y+height*7+10,x->judge.final_per2duty,24,24,BROWN);//�ҷ�����
    // ������Ϣ����ʾ�ڵڶ�����Ϣ�·���
    if(x->processed_status == '0'){
        puthz(120, lineStart_y + height * 5 + 10,"δ����",24,24,RED); 
    } else {
        puthz(120, lineStart_y + height * 5 + 10,"�Ѵ���",24,24,GREEN);
    }// ����״̬
    if(flag != '\0'&&x->processed_status!='1'){
        setcolor(LIGHTCYAN);
        setlinestyle(SOLID_LINE, 0, THICK_WIDTH);
        rectangle(295,lineStart_y + height * 9+7,405,lineStart_y + height * 9+38);
        puthz(300,lineStart_y + height * 9+10,"����ȡ֤",24,24,BLUE);
    }
    while (1)
    {
        mou_pos(&MouseX,&MouseY,&press);

        if(mouse_press(595,0,640,45)==1){//�˳�
            closegraph();//�رջ�ͼ
            delay(1000);
            exit(0);//�˳�����
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
    puthz(170,100,"���Ȳ��������Ϣ",32,32,RED);
    current = start = clock();
    while((current - start)/CLK_TCK < 3){
        mou_pos(&MouseX,&MouseY,&press);
        current = clock();
    }
}
