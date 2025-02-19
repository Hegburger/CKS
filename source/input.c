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

/****
function:让用户鼠标选中省份，并将省份存储到指定位置
author:Chengkai Huang
finished time:2025/2/19
*****/
void input_province(char *save_province){
    char provinces[33][3] = {
        "京", "津", "冀", "晋", "蒙", "辽", "吉", "黑", "沪", "苏",
        "浙", "皖", "闽", "赣", "鲁", "豫", "鄂", "湘", "粤", "桂",
        "琼", "川", "贵", "云", "陕", "甘", "青", "宁", "新", "藏",
        "港", "澳", "台"
    };
    char province_current[3];
    int num_provinces = 33;
    int max_per_row = 10;  // 每行最多显示10个省份
    int width = 50;
    int height = 50;
  

    // 按钮排列的起始坐标
    int start_x = 100;
    int start_y = 100;
    int x,y,row,col,i;
    int press_num;
    void *background;
    unsigned int image_size;
    //存储画面
    image_size = imagesize(start_x, start_y, start_x + (max_per_row * (width)), start_y + ((num_provinces / max_per_row + 1) * (height)));
    background = malloc(image_size);
    if (background == NULL){
        printf("malloc error!");
        return;
    }
    getimage(start_x, start_y, start_x + (max_per_row * (width)), start_y + ((num_provinces / max_per_row + 1) * (height)),background);
    
    // 绘制按钮
    for (i = 0; i < num_provinces; i++) {
        row = i / max_per_row;  // 计算当前省份所在的行
        col = i % max_per_row;  // 计算当前省份所在的列
        strcpy(province_current,provinces[i]);
        x = start_x + col * (width); // 计算按钮的横坐标
        y = start_y + row * (height); // 计算按钮的纵坐标
        setfillstyle(SOLID_FILL, LIGHTGRAY);
        bar(x, y, x + width, y + height); // 绘制按钮背景
        setcolor(BROWN);
        rectangle(x, y, x + width, y + height); // 绘制按钮边框
        puthz(x + 15, y + 15, province_current, 16, 16, BROWN);  // 显示省份简称
    }
    
    //选择省份
    while(1){
        mou_pos(&MouseX,&MouseY,&press);
        //判断是否点击省份区域
        if(mouse_press(start_x, start_y, start_x + (max_per_row * (width)), start_y + ((num_provinces / max_per_row + 1) * (height)))==1
        &&mouse_press(start_x+(num_provinces%max_per_row)*width,start_y+(num_provinces/max_per_row)*height,start_x+(max_per_row)*width,start_y+(num_provinces/max_per_row+1)*height)!=1){
            //计算点击身份在数组中的位置
            press_num = (MouseX-start_x)/width+((MouseY-start_y)/height)*max_per_row;
            strcpy(save_province,provinces[press_num]);//存储选中省份
            putimage(start_x,start_y,background,COPY_PUT);
            free(background);//释放内存
            break;
        }
        
    }

    
}
