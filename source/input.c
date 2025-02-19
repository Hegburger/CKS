#include"common.h"
#include"mouse.h"
/****
function:��������ַ�����ʾ����Ļ��
�����������ݴ洢��ָ���ص�
(based on outtextxy)
author:Chengkai Huang
*****/

void input_str(int x, int y, char *save_str, int font ,int size) {
    char tepStr[20];   // ���ڴ洢��ǰ������ַ���
    char kip;          // ��ǰ����ֵ
    int num = 0;       // ������ַ�����
        // �ı�����Ŀ�Ⱥ͸߶�
    int text_width ;
    int text_height;
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
                tepStr[--num] = '\0';

                // ���»��Ƹ��º���ı�
                outtextxy(x, y, tepStr);  // ��ʾ���º���ı�
            } else if (num < 20&&kip != 8) {  // ���������ַ�δ��������
                tepStr[num++] = kip;  // ������ַ�
                tepStr[num] = '\0';   // ��֤�ַ�����������ȷ

                // ���»����ַ�
                outtextxy(x, y, tepStr);  // ��ʾ�µ��ı�
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
    char provinces[33][3] = {
        "��", "��", "��", "��", "��", "��", "��", "��", "��", "��",
        "��", "��", "��", "��", "³", "ԥ", "��", "��", "��", "��",
        "��", "��", "��", "��", "��", "��", "��", "��", "��", "��",
        "��", "��", "̨"
    };
    char province_current[3];
    int num_provinces = 33;
    int max_per_row = 10;  // ÿ�������ʾ10��ʡ��
    int width = 50;
    int height = 50;
  

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
            free(background);//�ͷ��ڴ�
            break;
        }
        
    }

    
}
