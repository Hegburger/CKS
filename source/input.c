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

