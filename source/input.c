#include"common.h"
#include"mouse.h"
/****
function:��������ַ�����ʾ����Ļ��
�����������ݴ洢��ָ���ص�
(based on outtextxy)
author:Chengkai Huang
*****/
#include <graphics.h>
#include <conio.h>
#include <time.h>
#include <string.h>
#include <stdio.h>
void input_str(int x, int y, char *save_str, int font, int size, int num_max) {
    char tepStr[21];        // �洢�����ַ����Ļ�����
    char kip;               // ��ǰ�����ַ�
    int num = 0;            // ��ǰ�ַ���
    int cursor_on = 1;       // �����ʾ״̬
    int need_redraw = 0;
    clock_t last_toggle ;// ����ʱ��
    
    // ͼ����ر���
    int text_width = textwidth("W") * num_max;
    int text_height = textheight("W") + 10;
    void *background;
    int max_x = getmaxx();
    int max_y = getmaxy();
    int right_x = (x + text_width) > max_x ? max_x : (x + text_width);
    int bottom_y = (y + text_height) > max_y ? max_y : (y + text_height);
    last_toggle = clock();
    // ��ʼ���ַ���
    strcpy(tepStr, save_str);
    num = strlen(tepStr);
    settextstyle(font, 0, size);
    clrmous(MouseX,MouseY);
    // ���ݱ���
    background = malloc(imagesize(x, y, right_x, bottom_y));
    getimage(x, y, right_x, bottom_y, background);
    outtextxy(x, y, tepStr);

    // ������ѭ��
    while (1) {
        need_redraw = 0;
        
        // �����������
        if (kbhit()) {
            kip = getch(); // ʹ���޻��Ե�getch
            
            if (kip == 13) { // �س�ȷ��
                break;
            } else if (kip == 8 && num > 0) { // �˸�ɾ��
                tepStr[--num] = '\0';
                need_redraw = 1;
            } else if (num < num_max && kip >= 32 && kip <= 126) { // �ɴ�ӡ�ַ�
                tepStr[num++] = kip;
                tepStr[num] = '\0';
                need_redraw = 1;
            }
            
            cursor_on = 1; // ��������ù��״̬
            last_toggle = clock();
        }

        // ��������˸
        if ((clock() - last_toggle) * 1000.0 / CLOCKS_PER_SEC > 500) {
            cursor_on = !cursor_on;
            last_toggle = clock();
            need_redraw = 1;
        }

        // �ػ����
        if (need_redraw) {
            putimage(x, y, background, COPY_PUT); // �ָ�����
            outtextxy(x, y, tepStr);              // �����ı�
            
            // ���ƹ��
            if (cursor_on&&num>0) {
                int text_w = textwidth(tepStr);
                line(x + text_w-2, y, x + text_w-2, y + textheight("W"));
            }
        }
        
        delay(10); // ����CPUռ��
    }

    // ������������

    strcpy(save_str, tepStr);
    putimage(x, y, background, COPY_PUT);
    outtextxy(x, y, tepStr);
    exit_input();
    free(background);
}
//void input_str(int x, int y, char *save_str, int font, int size, int num_max) {
//    char tepStr[21];        // �洢�����ַ����Ļ�����
//    char kip;               // ��ǰ�����ַ�
//    int num = 0;            // ��ǰ�ַ���
//    int cursor_on = 1;       // �����ʾ״̬
//    int need_redraw = 0;
////    clock_t last_toggle ;// ����ʱ��
//    
//    // ͼ����ر���
//    int text_width = textwidth("W") * num_max;
//    int text_height = textheight("W") + 10;
//    void *background;
//    int max_x = getmaxx();
//    int max_y = getmaxy();
//    int right_x = (x + text_width) > max_x ? max_x : (x + text_width);
//    int bottom_y = (y + text_height) > max_y ? max_y : (y + text_height);
////    last_toggle = clock();
//    // ��ʼ���ַ���
//    strcpy(tepStr, save_str);
//    num = strlen(tepStr);
//    settextstyle(font, 0, size);
//
//    // ���ݱ���
//    background = malloc(imagesize(x, y, right_x, bottom_y));
//    getimage(x, y, right_x, bottom_y, background);
//    outtextxy(x, y, tepStr);
//
//    // ������ѭ��
//    while (1) {
//        need_redraw = 0;
//        
//        // �����������
//        if (kbhit()) {
//            kip = getch(); // ʹ���޻��Ե�getch
//            
//            if (kip == 13) { // �س�ȷ��
//                break;
//            } else if (kip == 8 && num > 0) { // �˸�ɾ��
//                tepStr[--num] = '\0';
//                need_redraw = 1;
//            } else if (num < num_max && kip >= 32 && kip <= 126) { // �ɴ�ӡ�ַ�
//                tepStr[num++] = kip;
//                tepStr[num] = '\0';
//                need_redraw = 1;
//            }
////            
//            cursor_on = 1; // ��������ù��״̬
////            last_toggle = clock();
//        }
//
//        // ��������˸
//        if ((clock() - last_toggle) * 1000.0 / CLOCKS_PER_SEC > 500) {
//            cursor_on = !cursor_on;
//            last_toggle = clock();
//            need_redraw = 1;
//        }
//
//        // �ػ����
//        if (need_redraw) {
//            putimage(x, y, background, COPY_PUT); // �ָ�����
//            outtextxy(x, y, tepStr);              // �����ı�
//            
//            // ���ƹ��
//            if (cursor_on&&num>0) {
//                int text_w = textwidth(tepStr);
//                line(x + text_w-2, y, x + text_w-2, y + textheight("W"));
//            }
//        }
//        
//        delay(10); // ����CPUռ��
//    }
//
//    // ������������
//    strcpy(save_str, tepStr);
//    putimage(x, y, background, COPY_PUT);
//    outtextxy(x, y, tepStr);
//    free(background);
//}
// void input_str(int x, int y, char *save_str, int font ,int size,int num_max) {
//     char tepStr[21];   // ���ڴ洢��ǰ������ַ���
//     char kip;          // ��ǰ����ֵ
//     int num = 0;       // ������ַ�����
//         // �ı�����Ŀ�Ⱥ͸߶�
//     int text_width ;
//     int text_height;
//     int max_x,max_y,right_x,bottom_y;
//     unsigned int malloc_size;
//     void *background;
//     strcpy(tepStr,save_str);
//     num = strlen(tepStr);  // ��ʼ���ַ���
//     max_x = getmaxx();
//     max_y = getmaxy();
//     // �����ı���ʽ����������û�������������С
//     settextstyle(font, 0, size);  // ָ����������ʽ�ʹ�С
//     text_width = textwidth("W") * 20;  // Ϊ�˱��ⳬ���߽磬�����㹻���
//     text_height = textheight("W")+10;
    
//     right_x = (x + text_width) > max_x ? max_x : (x + text_width);
//     bottom_y = (y + text_height) > max_y ? max_y : (y + text_height);

//     clrmous(MouseX,MouseY);
//     malloc_size = imagesize(x,y,right_x,bottom_y);
//     background = malloc(malloc_size);
//     if (background == NULL){
//         printf("malloc error!");
//         return;
//     }             // �����㹻���ڴ�

//     // �ݴ浱ǰ��������ı���ͼ��
//     getimage(x, y, right_x, bottom_y, background);
//     outtextxy(x,y,tepStr);
//     // ������ȡ��������
//     while (1) {
//         if (kbhit()) {
//             kip = getche();  // ��ȡ�û�������ַ�����ʾ

//             if (kip == 13) {  // ������»س�������������
//                 save_bk_mou(MouseX,MouseY);
//                 drawmous(MouseX,MouseY);
//                 break;
//             } else if (kip == 8 && num > 0) {  // �������ɾ����
//                 // �����ǰ��������ͨ���ָ�����ͼ��
//                 putimage(x, y, background, COPY_PUT);  // �ָ�����ͼ��

//                 // ɾ�����һ���ַ�
//                 tepStr[--num] = '\0';

//                 // ���»��Ƹ��º���ı�
//                 outtextxy(x, y, tepStr);  // ��ʾ���º���ı�
//             } else if (num < num_max&&kip != 8) {  // ���������ַ�δ��������
//                 tepStr[num++] = kip;  // ������ַ�
//                 tepStr[num] = '\0';   // ��֤�ַ�����������ȷ

//                 // ���»����ַ�
//                 outtextxy(x, y, tepStr);  // ��ʾ�µ��ı�
//             }
//         }
//     }

//     // ����ǰ������ַ������浽ָ����λ��
//     strcpy(save_str, tepStr);
//     // �ͷ��ݴ�ı���ͼ���ڴ�
//     free(background);
//     background = NULL;
// }
void input_password(int x, int y, char *save_str, int font ,int size,int num_max) {
    char tepStr[21];   // ���ڴ洢��ǰ������ַ���
    char passShow[21];
    char kip;          // ��ǰ����ֵ
    int num = 0,i;       // ������ַ�����
        // �ı�����Ŀ�Ⱥ͸߶�
    int text_width ;
    int text_height;
    int max_x,max_y,right_x,bottom_y;
    unsigned int malloc_size;
    void *background;
    strcpy(tepStr,save_str);
    num = strlen(tepStr);  // ��ʼ���ַ���
    for(i = 0;i<num;i++){
        passShow[i] = '*';
    }
    passShow[num] = '\0';
    max_x = getmaxx();
    max_y = getmaxy();
    // �����ı���ʽ����������û�������������С
    settextstyle(font, 0, size);  // ָ����������ʽ�ʹ�С
    text_width = textwidth("W") * 20;  // Ϊ�˱��ⳬ���߽磬�����㹻���
    text_height = textheight("W")+10;
    
    right_x = (x + text_width) > max_x ? max_x : (x + text_width);
    bottom_y = (y + text_height) > max_y ? max_y : (y + text_height);

    clrmous(MouseX,MouseY);
    malloc_size = imagesize(x,y,right_x,bottom_y);
    background = malloc(malloc_size);
    if (background == NULL){
        printf("malloc error!");
        return;
    }             // �����㹻���ڴ�

    // �ݴ浱ǰ��������ı���ͼ��
    getimage(x, y, right_x, bottom_y, background);
    outtextxy(x,y,passShow);
    // ������ȡ��������
    while (1) {
        if (kbhit()) {
            kip = getche();  // ��ȡ�û�������ַ�����ʾ

            if (kip == 13) {  // ������»س�������������
                save_bk_mou(MouseX,MouseY);
                drawmous(MouseX,MouseY);
                break;
            } else if (kip == 8 && num > 0) {  // �������ɾ����
                // �����ǰ��������ͨ���ָ�����ͼ��
                putimage(x, y, background, COPY_PUT);  // �ָ�����ͼ��
                // ɾ�����һ���ַ�
                num--;
                tepStr[num] = '\0';
                passShow[num] = '\0';

                // ���»��Ƹ��º���ı�
                outtextxy(x, y, passShow);  // ��ʾ���º���ı�
            } else if (num < num_max&&kip != 8) {  // ���������ַ�δ��������
                tepStr[num] = kip;  // ������ַ�
                passShow[num] = '*';
                num++;
                tepStr[num] = '\0';   // ��֤�ַ�����������ȷ
                passShow[num] = '\0';
                // ���»����ַ�
                outtextxy(x, y, passShow);  // ��ʾ�µ��ı�
            }
        }
    }

    // ����ǰ������ַ������浽ָ����λ��
    strcpy(save_str, tepStr);

    // �ͷ��ݴ�ı���ͼ���ڴ�
    free(background);
}


/****
function:���û����ѡ��ʡ�ݣ�����ʡ�ݴ洢��ָ��λ��
author:Chengkai Huang
finished time:2025/2/19
*****/
void input_province(char *save_province){
    char provinces[18][3] = {
        "��", "��", "��", "��", "��", "��", "��", "��", "��",
        "��", "��", "��", "³", "ԥ", "��", "��", "��", "��",
        
    };
    char province_current[3];
    int num_provinces = 18;
    int max_per_row = 7;  // ÿ�������ʾ10��ʡ��
    int width = 45;
    int height = 45;
    // ��ť���е���ʼ����
    int start_x = 100;
    int start_y = 100;
    int x,y,row,col,i;
    int press_num;
    void *background;
    unsigned int image_size;
    //�洢����
    image_size = imagesize(start_x, start_y, start_x + (max_per_row * (width)), start_y + ((num_provinces / max_per_row + 1) * (height)));
    background = malloc(image_size);
    if (background == NULL){
        printf("malloc error!");
        return;
    }
    getimage(start_x, start_y, start_x + (max_per_row * (width)), start_y + ((num_provinces / max_per_row + 1) * (height)),background);
    
    // ���ư�ť
    for (i = 0; i < num_provinces; i++) {
        row = i / max_per_row;  // ���㵱ǰʡ�����ڵ���
        col = i % max_per_row;  // ���㵱ǰʡ�����ڵ���
        strcpy(province_current,provinces[i]);
        x = start_x + col * (width); // ���㰴ť�ĺ�����
        y = start_y + row * (height); // ���㰴ť��������
        setfillstyle(SOLID_FILL, LIGHTGRAY);
        bar(x, y, x + width, y + height); // ���ư�ť����
        setcolor(BROWN);
        rectangle(x, y, x + width, y + height); // ���ư�ť�߿�
        puthz(x + 15, y + 15, province_current, 16, 16, BROWN);  // ��ʾʡ�ݼ��
    }
    delay(100);
    //ѡ��ʡ��
    while(1){
        mou_pos(&MouseX,&MouseY,&press);
        //�ж��Ƿ���ʡ������
        if(mouse_press(start_x, start_y, start_x + (max_per_row * (width)), start_y + ((num_provinces / max_per_row + 1) * (height)))==1
        &&mouse_press(start_x+(num_provinces%max_per_row)*width,start_y+(num_provinces/max_per_row)*height,start_x+(max_per_row)*width,start_y+(num_provinces/max_per_row+1)*height)!=1){
            //����������������е�λ��
            press_num = (MouseX-start_x)/width+((MouseY-start_y)/height)*max_per_row;
            strcpy(save_province,provinces[press_num]);//�洢ѡ��ʡ��
            
            putimage(start_x,start_y,background,COPY_PUT);
            break;
        }
        
    }
    free(background);//�ͷ��ڴ�
    exit_input();
}

/****
function:���û����ѡ�����������������洢��ָ��λ��
author:Chengkai Huang
finished time:2025/2/20
*****/
void input_weather(char *save_weather) {
    char weather_options[10][7] = {
        "��", "��", "����", "������", "С��", 
        "����", "����", "����", "����", "ѩ"
    };
    char weather_current[7];
    int num_accident_type = 10;
    int max_per_row = 1;  // ÿ�������ʾ1������ѡ��
    int width = 100;         // ��ť���
    int height = 25;         // ��ť�߶�
    int start_x = 250;       // ��ʼ������
    int start_y = 100;       // ��ʼ������
    int x, y, row, i;
    int press_num;
    void *background;
    unsigned int image_size;
    clrmous(MouseX,MouseY);
    // �洢����
    image_size = imagesize(start_x, start_y, start_x + (width), start_y + ((num_accident_type / max_per_row + 1) * (height)));
    background = malloc(image_size);
    if (background == NULL) {
        printf("malloc error!");
        return;
    }
    getimage(start_x, start_y, start_x + (width), start_y + ((num_accident_type / max_per_row + 1) * (height)), background);

    // ���ư�ť
    for (i = 0; i < num_accident_type; i++) {
        row = i / max_per_row;  // ���㵱ǰ����ѡ�����ڵ���
        y = start_y + row * (height); // ���㰴ť��������
        x = start_x+(i%max_per_row)*width;

        strcpy(weather_current, weather_options[i]);
        
        setfillstyle(SOLID_FILL, WHITE);
        bar(x, y, x + width, y + height); // ���ư�ť����
        setcolor(BLACK);
        rectangle(x, y, x + width, y + height); // ���ư�ť�߿�
        settextstyle(DEFAULT_FONT, HORIZ_DIR, 1); // ʹ�ý�С����
        puthz(x + (width - textwidth(weather_current)) / 2, y + (height - textheight(weather_current)) / 2, weather_current,16,16,BROWN); // ��ʾ����ѡ��
    }
    delay(100);
    // ѡ������
    while (1) {
        mou_pos(&MouseX, &MouseY, &press);

        // �ж��Ƿ�����������
        if(mouse_press(start_x, start_y, start_x + (max_per_row * (width)), start_y + ((num_accident_type / max_per_row + 1) * (height)))==1
        &&mouse_press(start_x+(num_accident_type%max_per_row)*width,start_y+(num_accident_type/max_per_row)*height,start_x+(max_per_row)*width,start_y+(num_accident_type/max_per_row+1)*height)!=1){
            // ������λ���������е�λ��
            press_num = (MouseY - start_y) / height;
            if (press_num < num_accident_type) {
                strcpy(save_weather, weather_options[press_num]); // �洢ѡ�е�����
                putimage(start_x, start_y, background, COPY_PUT); // ��ԭ����
                break;
            }
        }
    }
    free(background); // �ͷ��ڴ�
    exit_input();
}
/****
function:���û����ѡ���¹ʣ������¹����Ͷ�Ӧ���Ŵ洢��ָ��λ��
author:Chengkai Huang
finished time:2025/2/21
*****/

void input_accident_type(char *save_accident_type) {
    char accident_type_options[5][20] = {
        "�ˡ��綯��", "�ˡ�����", "�綯�����綯��", "�綯��������", "����������", 
    };
    const char accident_type_char[5] = {
        'A','B','C','D','E'
        };
    char weather_current[20];
    int num_accident_type = 5;
    int max_per_row = 1;  // ÿ��������
    int width = 130;         // ��ť���
    int height = 25;         // ��ť�߶�
    int start_x = 250;       // ��ʼ������
    int start_y = 100;       // ��ʼ������
    int x, y, row, i;
    int press_num;
    void *background;
    unsigned int image_size;
    clrmous(MouseX,MouseY);
    delay(100);
    // �洢����
    image_size = imagesize(start_x, start_y, start_x + (width), start_y + ((num_accident_type / max_per_row + 1) * (height)));
    background = malloc(image_size);
    if (background == NULL) {
        printf("malloc error!");
        return;
    }
    getimage(start_x, start_y, start_x + (width), start_y + ((num_accident_type / max_per_row + 1) * (height)), background);

    // ���ư�ť
    for (i = 0; i < num_accident_type; i++) {
        row = i / max_per_row;  // ���㵱ǰѡ�����ڵ���
        y = start_y + row * (height); // ���㰴ť��������
        x = start_x+(i%max_per_row)*width;

        strcpy(weather_current, accident_type_options[i]);
        
        setfillstyle(SOLID_FILL, WHITE);
        bar(x, y, x + width, y + height); // ���ư�ť����
        setcolor(BLACK);
        rectangle(x, y, x + width, y + height); // ���ư�ť�߿�
        settextstyle(DEFAULT_FONT, HORIZ_DIR, 1); // ʹ�ý�С����
        puthz(x + (width - textwidth(weather_current)) / 2, y + (height - textheight(weather_current)) / 2, weather_current,16,16,BROWN); 
    }
    delay(100);
    // ѡ������
    while (1) {
        mou_pos(&MouseX, &MouseY, &press);

        // �ж��Ƿ�������
        if(mouse_press(start_x, start_y, start_x + (max_per_row * (width)), start_y + ((num_accident_type / max_per_row + 1) * (height)))==1
        &&mouse_press(start_x+(num_accident_type%max_per_row)*width,start_y+(num_accident_type/max_per_row)*height,start_x+(max_per_row)*width,start_y+(num_accident_type/max_per_row+1)*height)!=1){
            // ������λ���������е�λ��
            press_num = (MouseY - start_y) / height;
            if (press_num < num_accident_type) {
                *save_accident_type = accident_type_char[press_num]; // �洢
                putimage(start_x, start_y, background, COPY_PUT); // ��ԭ����
                break;
            }
        }
    }
    free(background); // �ͷ��ڴ�
    exit_input();
}

/*���¹��ַ�ת��Ϊ���ֲ���ʾ��x,yΪ���Ͻ����꣬flagΪͼ���С��16��24��32��48����
partΪ���ּ����colorΪ��ɫ*/
void put_accident_type(char type,int x, int y, int flag, int part, int color){
    char accident_type_options[5][20] = {
        "�ˡ��綯��", "�ˡ�����", "�綯�����綯��", "�綯��������", "����������", 
    };
    puthz(x,y,accident_type_options[type-'A'],flag,part,color);
}
void accident_type_trans(char type,char *save_type){
    char accident_type_options[5][20] = {
        "�ˡ��綯��", "�ˡ�����", "�綯�����綯��", "�綯��������", "����������", 
    };
    strcpy(save_type,accident_type_options[type-'A']);
}

/****
function:���û����ѡ�еص㣬�����ص�洢��ָ��λ��
author:Chengkai Huang
finished time:2025/2/21
*****/
void input_location(char *save_location) {
    char location_options[9][17] = {
        "����¥��", "����¥ǰ·��", "��Էʳ��·��", "��԰���", 
        "������", "����·", "����·", "�Ͼ�·", "��ݿ·"
    };
    char location_current[17];
    int num_locations = 9;  // �ܹ�9���ص�ѡ��
    int max_per_column = 1; // ÿ�������ʾ1���ص�ѡ��
    int width = 160;        // ��ť���
    int height = 30;        // ��ť�߶�
    int start_x = 250;      // ��ʼ������
    int start_y = 100;      // ��ʼ������
    int x, y, row, i;
    int press_num;
    void *background;
    unsigned int image_size;
    clrmous(MouseX,MouseY);
    delay(100);
    // �洢����
    image_size = imagesize(start_x, start_y, start_x + (width), start_y + ((num_locations / max_per_column + 1) * (height)));
    background = malloc(image_size);
    if (background == NULL) {
        printf("malloc error!");
        return;
    }
    getimage(start_x, start_y, start_x + (width), start_y + ((num_locations / max_per_column + 1) * (height)), background);

    // ���ư�ť
    for (i = 0; i < num_locations; i++) {
        row = i / max_per_column;  // ���㵱ǰ�ص�ѡ�����ڵ���
        y = start_y + row * (height); // ���㰴ť��������
        x = start_x + (i % max_per_column) * width; // ���㰴ť�ĺ�����

        strcpy(location_current, location_options[i]);
        
        setfillstyle(SOLID_FILL, LIGHTGRAY);
        bar(x, y, x + width, y + height); // ���ư�ť����
        setcolor(BLACK);
        rectangle(x, y, x + width, y + height); // ���ư�ť�߿�
        puthz(x + (width - textwidth(location_current)) / 2, y + (height - textheight(location_current)) / 2, location_current, 16, 16, BLACK); // ��ʾ�ص�ѡ��
    }
    delay(100);
    // ѡ��ص�
    while (1) {
        mou_pos(&MouseX, &MouseY, &press);

        // �ж��Ƿ����ص�����
        if (mouse_press(start_x, start_y, start_x + (max_per_column * width), start_y + ((num_locations / max_per_column + 1) * height)) == 1) {
            // ������λ���������е�λ��
            press_num = (MouseY - start_y) / height;
            if (press_num < num_locations) {
                strcpy(save_location, location_options[press_num]); // �洢ѡ�еĵص�
                putimage(start_x, start_y, background, COPY_PUT); // ��ԭ����
                break;
            }
        }
    }
    free(background); // �ͷ��ڴ�
    exit_input();
}
/****
function:���û����ѡ�г������ͣ��������ʹ洢��ָ��λ��
author:Chengkai Huang
finished time:2025/2/24
*****/
void input_car_type(char *save_car_type) {
    char des_part_options[5][7] = {
        "С�γ�","�����","����","ԽҰ��","���"
    };
    char car_current[7];
    int num_locations = 5;  // �ܹ�9���ص�ѡ��
    int max_per_column = 1; // ÿ�������ʾ1���ص�ѡ��
    int width = 200;        // ��ť���
    int height = 30;        // ��ť�߶�
    int start_x = 250;      // ��ʼ������
    int start_y = 100;      // ��ʼ������
    int x, y, row, i;
    int press_num;
    void *background;
    unsigned int image_size;
    clrmous(MouseX,MouseY);
    delay(100);
    // �洢����
    image_size = imagesize(start_x, start_y, start_x + (width), start_y + ((num_locations / max_per_column + 1) * (height)));
    background = malloc(image_size);
    if (background == NULL) {
        printf("malloc error!");
        return;
    }
    getimage(start_x, start_y, start_x + (width), start_y + ((num_locations / max_per_column + 1) * (height)), background);

    // ���ư�ť
    for (i = 0; i < num_locations; i++) {
        row = i / max_per_column;  // ���㵱ǰ�ص�ѡ�����ڵ���
        y = start_y + row * (height); // ���㰴ť��������
        x = start_x + (i % max_per_column) * width; // ���㰴ť�ĺ�����

        strcpy(car_current, des_part_options[i]);
        
        setfillstyle(SOLID_FILL, LIGHTGRAY);
        bar(x, y, x + width, y + height); // ���ư�ť����
        setcolor(BLACK);
        rectangle(x, y, x + width, y + height); // ���ư�ť�߿�
        puthz(x + (width - textwidth(car_current)) / 2, y + (height - textheight(car_current)) / 2, car_current, 16, 16, BROWN); // ��ʾ�ص�ѡ��
    }
    delay(100);
    // ѡ��ص�
    while (1) {
        mou_pos(&MouseX, &MouseY, &press);

        // �ж��Ƿ�����������
        if (mouse_press(start_x, start_y, start_x + (max_per_column * width), start_y + ((num_locations / max_per_column + 1) * height)) == 1) {
            // ������λ���������е�λ��
            press_num = (MouseY - start_y) / height;
            if (press_num < num_locations) {
                strcpy(save_car_type, des_part_options[press_num]); // �洢ѡ�е�����
                putimage(start_x, start_y, background, COPY_PUT); // ��ԭ����
                break;
            }
        }
    }
    free(background); // �ͷ��ڴ�
    exit_input();
}
/****
function:����ʱ��
author:Chengkai Huang
finished time:2025/3/1
*****/

void input_time(int x, int y, char *save_str, int font ,int size) {
    char tepStr[21];   // ���ڴ洢��ǰ������ַ���
    char kip;          // ��ǰ����ֵ
    int num = 0;       // ������ַ�����
        // �ı�����Ŀ�Ⱥ͸߶�
    int text_width ;
    int text_height;
    int cursor_on = 1;       // �����ʾ״̬
    int need_redraw = 0;
    clock_t last_toggle ;// ����ʱ��
    int max_x,max_y,right_x,bottom_y;
    unsigned int malloc_size;
    void *background;
    strcpy(tepStr,save_str);
    num = strlen(tepStr);  // ��ʼ���ַ���
    max_x = getmaxx();
    max_y = getmaxy();
    // �����ı���ʽ����������û�������������С
    settextstyle(font, 0, size);  // ָ����������ʽ�ʹ�С
    text_width = textwidth("W") * 20;  // Ϊ�˱��ⳬ���߽磬�����㹻���
    text_height = textheight("W")+10;
    
    right_x = (x + text_width) > max_x ? max_x : (x + text_width);
    bottom_y = (y + text_height) > max_y ? max_y : (y + text_height);

    clrmous(MouseX,MouseY);
    delay(100);
    malloc_size = imagesize(x,y,right_x,bottom_y);
    background = malloc(malloc_size);
    if (background == NULL){
        printf("malloc error!");
        return;
    }             // �����㹻���ڴ�

    // �ݴ浱ǰ��������ı���ͼ��
    getimage(x, y, right_x, bottom_y, background);
    outtextxy(x,y,tepStr);
    // ������ȡ��������
    while (1) {
        need_redraw = 0;
        if (kbhit()) {
            kip = getche();  // ��ȡ�û�������ַ�����ʾ

            if (kip == 13) {  // ������»س�������������
                save_bk_mou(MouseX,MouseY);
                drawmous(MouseX,MouseY);
                break;
            } else if (kip == 8 && num > 0) {  // �������ɾ����

                // ɾ�����һ���ַ�
                tepStr[--num] = '\0';
                need_redraw = 1;

            } else if (num < 16&&kip >=48&&kip<=57) {  // ���������ַ�δ��������
                tepStr[num++] = kip;  // ������ַ�
                if(num==4){
                    tepStr[num++] = '/';
                }else if(num==7){
                    tepStr[num++] = '/';
                }else if(num == 10){
                    tepStr[num++] = ' ';
                }else if(num == 13){
                    tepStr[num++] = ':';
                }
                tepStr[num] = '\0';   // ��֤�ַ�����������ȷ
                
                need_redraw = 1;
            }
            cursor_on = 1; // ��������ù��״̬
            last_toggle = clock();
        }
                // ��������˸
                if ((clock() - last_toggle) * 1000.0 / CLOCKS_PER_SEC > 500) {
                    cursor_on = !cursor_on;
                    last_toggle = clock();
                    need_redraw = 1;
                }

                // �ػ����
                if (need_redraw) {
                    putimage(x, y, background, COPY_PUT); // �ָ�����
                    outtextxy(x, y, tepStr);              // �����ı�
                    
                    // ���ƹ��
                    if (cursor_on&&num>0) {
                        int text_w = textwidth(tepStr);
                        line(x + text_w-5, y, x + text_w-5, y + textheight("W"));
                    }
                }
                delay(10);
                
    }
    // ������������
    strcpy(save_str, tepStr);
    putimage(x, y, background, COPY_PUT);
    outtextxy(x, y, tepStr);
    free(background);
}

void input_destroy_part(char *save_des_type) {
    char des_part_options[6][9] = {
        "��ͷ","������","��β","����֫","���ظ���","��ȫ��"
    };
    char car_current[9];
    int num_locations = 6;  // �ܹ�6��ѡ��
    int max_per_column = 1; // ÿ�������ʾ1��ѡ��
    int width = 200;        // ��ť���
    int height = 30;        // ��ť�߶�
    int start_x = 250;      // ��ʼ������
    int start_y = 100;      // ��ʼ������
    int x, y, row, i;
    int press_num;
    void *background;
    unsigned int image_size;
    clrmous(MouseX,MouseY);
    delay(100);
    // �洢����
    image_size = imagesize(start_x, start_y, start_x + (width), start_y + ((num_locations / max_per_column + 1) * (height)));
    background = malloc(image_size);
    if (background == NULL) {
        printf("malloc error!");
        return;
    }
    getimage(start_x, start_y, start_x + (width), start_y + ((num_locations / max_per_column + 1) * (height)), background);

    // ���ư�ť
    for (i = 0; i < num_locations; i++) {
        row = i / max_per_column;  // ���㵱ǰѡ�����ڵ���
        y = start_y + row * (height); // ���㰴ť��������
        x = start_x + (i % max_per_column) * width; // ���㰴ť�ĺ�����

        strcpy(car_current, des_part_options[i]);
        
        setfillstyle(SOLID_FILL, LIGHTGRAY);
        bar(x, y, x + width, y + height); // ���ư�ť����
        setcolor(BLACK);
        rectangle(x, y, x + width, y + height); // ���ư�ť�߿�
        puthz(x + (width - textwidth(car_current)) / 2, y + (height - textheight(car_current)) / 2, car_current, 16, 16, BROWN); // ��ʾ�ص�ѡ��
    }
    delay(100);
    // ѡ��ص�
    while (1) {
        mou_pos(&MouseX, &MouseY, &press);

        // �ж��Ƿ�����������
        if (mouse_press(start_x, start_y, start_x + (max_per_column * width), start_y + ((num_locations / max_per_column + 1) * height)) == 1) {
            // ������λ���������е�λ��
            press_num = (MouseY - start_y) / height;
            if (press_num < num_locations) {
                strcpy(save_des_type, des_part_options[press_num]); // �洢ѡ�е�����
                putimage(start_x, start_y, background, COPY_PUT); // ��ԭ����
                break;
            }
        }
    }
    free(background); // �ͷ��ڴ�
    exit_input();
}


/****
function: ���û����ѡ���¹ʴ���״̬������״̬���� processed_status
author: Chengkai Huang
finished time: 2025/4/6
*****/
void input_status(char *processed_status) {
    char *status_options[3] = { "δ����", "�Ѵ���", "��" };
    char status_values[3] = { '0', '1', '\0' };
    int num_status = 3;
    int width = 150;
    int height = 30;
    int start_x = 250;
    int start_y = 100;
    int i, x, y;
    int press_index;
    void *background;
    unsigned int image_size;

    clrmous(MouseX, MouseY);
    delay(100);

    // ���浱ǰ��Ļ����ͼ��
    image_size = imagesize(start_x, start_y, start_x + width, start_y + num_status * height);
    background = malloc(image_size);
    if (background == NULL) {
        printf("malloc error!");
        return;
    }
    getimage(start_x, start_y, start_x + width, start_y + num_status * height, background);

    // ����ѡ�ť
    for (i = 0; i < num_status; i++) {
        y = start_y + i * height;
        x = start_x;

        setfillstyle(SOLID_FILL, LIGHTGRAY);
        bar(x, y, x + width, y + height);
        setcolor(BLACK);
        rectangle(x, y, x + width, y + height);
        puthz(x + (width - textwidth(status_options[i])) / 2, y + (height - textheight(status_options[i])) / 2,
              status_options[i], 16, 16, BLACK);
    }

    delay(100);

    // �ȴ��û����
    while (1) {
        mou_pos(&MouseX, &MouseY, &press);
        if (mouse_press(start_x, start_y, start_x + width, start_y + num_status * height) == 1) {
            press_index = (MouseY - start_y) / height;
            if (press_index >= 0 && press_index < num_status) {
                *processed_status = status_values[press_index];
                putimage(start_x, start_y, background, COPY_PUT); // ��ԭ����
                break;
            }
        }
    }

    free(background);
    exit_input();
}
