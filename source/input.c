#include"common.h"
#include"mouse.h"
/****
function:将输入的字符串显示在屏幕，
并将输入内容存储到指定地点
(based on outtextxy)
author:Chengkai Huang
*****/

void input_str(int x, int y, char *save_str, int font ,int size) {
    char tepStr[20];   // 用于存储当前输入的字符串
    char kip;          // 当前键入值
    int num = 0;       // 键入的字符个数
        // 文本区域的宽度和高度
    int text_width ;
    int text_height;
    int max_x,max_y,right_x,bottom_y;
    unsigned int malloc_size;
    void *background;
    strcpy(tepStr,save_str);
    num = strlen(tepStr);  // 初始化字符串
    max_x = getmaxx();
    max_y = getmaxy();
    // 设置文本样式，允许根据用户输入调整字体大小
    settextstyle(font, 0, size);  // 指定的字体样式和大小
    text_width = textwidth("W") * 20;  // 为了避免超出边界，给定足够宽度
    text_height = textheight("W")+10;
    
    right_x = (x + text_width) > max_x ? max_x : (x + text_width);
    bottom_y = (y + text_height) > max_y ? max_y : (y + text_height);

    clrmous(MouseX,MouseY);
    malloc_size = imagesize(x,y,right_x,bottom_y);
    background = malloc(malloc_size);
    if (background == NULL){
        printf("malloc error!");
        return;
    }             // 分配足够的内存

    // 暂存当前输入区域的背景图像
    getimage(x, y, right_x, bottom_y, background);
    outtextxy(x,y,tepStr);
    // 持续获取键盘输入
    while (1) {
        if (kbhit()) {
            kip = getche();  // 获取用户输入的字符并显示

            if (kip == 13) {  // 如果按下回车键，结束输入
                save_bk_mou(MouseX,MouseY);
                drawmous(MouseX,MouseY);
                break;
            } else if (kip == 8 && num > 0) {  // 如果按下删除键
                // 清除当前输入区域（通过恢复背景图像）
                putimage(x, y, background, COPY_PUT);  // 恢复背景图像

                // 删除最后一个字符
                tepStr[--num] = '\0';

                // 重新绘制更新后的文本
                outtextxy(x, y, tepStr);  // 显示更新后的文本
            } else if (num < 20&&kip != 8) {  // 如果输入的字符未超过限制
                tepStr[num++] = kip;  // 添加新字符
                tepStr[num] = '\0';   // 保证字符串结束符正确

                // 重新绘制字符
                outtextxy(x, y, tepStr);  // 显示新的文本
            }
        }
    }

    // 将当前输入的字符串保存到指定的位置
    strcpy(save_str, tepStr);

    // 释放暂存的背景图像内存
    free(background);
}

