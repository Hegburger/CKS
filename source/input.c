#include"common.h"
#include"mouse.h"
/****
function:将输入的字符串显示在屏幕，
并将输入内容存储到指定地点
(based on outtextxy)
author:Chengkai Huang
*****/
#include <graphics.h>
#include <conio.h>
#include <time.h>
#include <string.h>
#include <stdio.h>
void input_str(int x, int y, char *save_str, int font, int size, int num_max) {
    char tepStr[21];        // 存储输入字符串的缓冲区
    char kip;               // 当前按键字符
    int num = 0;            // 当前字符数
    int cursor_on = 1;       // 光标显示状态
    int need_redraw = 0;
    clock_t last_toggle ;// 光标计时器
    
    // 图形相关变量
    int text_width = textwidth("W") * num_max;
    int text_height = textheight("W") + 10;
    void *background;
    int max_x = getmaxx();
    int max_y = getmaxy();
    int right_x = (x + text_width) > max_x ? max_x : (x + text_width);
    int bottom_y = (y + text_height) > max_y ? max_y : (y + text_height);
    last_toggle = clock();
    // 初始化字符串
    strcpy(tepStr, save_str);
    num = strlen(tepStr);
    settextstyle(font, 0, size);
    clrmous(MouseX,MouseY);
    // 备份背景
    background = malloc(imagesize(x, y, right_x, bottom_y));
    getimage(x, y, right_x, bottom_y, background);
    outtextxy(x, y, tepStr);

    // 主输入循环
    while (1) {
        need_redraw = 0;
        
        // 处理键盘输入
        if (kbhit()) {
            kip = getch(); // 使用无回显的getch
            
            if (kip == 13) { // 回车确认
                break;
            } else if (kip == 8 && num > 0) { // 退格删除
                tepStr[--num] = '\0';
                need_redraw = 1;
            } else if (num < num_max && kip >= 32 && kip <= 126) { // 可打印字符
                tepStr[num++] = kip;
                tepStr[num] = '\0';
                need_redraw = 1;
            }
            
            cursor_on = 1; // 输入后重置光标状态
            last_toggle = clock();
        }

        // 处理光标闪烁
        if ((clock() - last_toggle) * 1000.0 / CLOCKS_PER_SEC > 500) {
            cursor_on = !cursor_on;
            last_toggle = clock();
            need_redraw = 1;
        }

        // 重绘界面
        if (need_redraw) {
            putimage(x, y, background, COPY_PUT); // 恢复背景
            outtextxy(x, y, tepStr);              // 绘制文本
            
            // 绘制光标
            if (cursor_on&&num>0) {
                int text_w = textwidth(tepStr);
                line(x + text_w-2, y, x + text_w-2, y + textheight("W"));
            }
        }
        
        delay(10); // 降低CPU占用
    }

    // 保存结果并清理

    strcpy(save_str, tepStr);
    putimage(x, y, background, COPY_PUT);
    outtextxy(x, y, tepStr);
    exit_input();
    free(background);
}
//void input_str(int x, int y, char *save_str, int font, int size, int num_max) {
//    char tepStr[21];        // 存储输入字符串的缓冲区
//    char kip;               // 当前按键字符
//    int num = 0;            // 当前字符数
//    int cursor_on = 1;       // 光标显示状态
//    int need_redraw = 0;
////    clock_t last_toggle ;// 光标计时器
//    
//    // 图形相关变量
//    int text_width = textwidth("W") * num_max;
//    int text_height = textheight("W") + 10;
//    void *background;
//    int max_x = getmaxx();
//    int max_y = getmaxy();
//    int right_x = (x + text_width) > max_x ? max_x : (x + text_width);
//    int bottom_y = (y + text_height) > max_y ? max_y : (y + text_height);
////    last_toggle = clock();
//    // 初始化字符串
//    strcpy(tepStr, save_str);
//    num = strlen(tepStr);
//    settextstyle(font, 0, size);
//
//    // 备份背景
//    background = malloc(imagesize(x, y, right_x, bottom_y));
//    getimage(x, y, right_x, bottom_y, background);
//    outtextxy(x, y, tepStr);
//
//    // 主输入循环
//    while (1) {
//        need_redraw = 0;
//        
//        // 处理键盘输入
//        if (kbhit()) {
//            kip = getch(); // 使用无回显的getch
//            
//            if (kip == 13) { // 回车确认
//                break;
//            } else if (kip == 8 && num > 0) { // 退格删除
//                tepStr[--num] = '\0';
//                need_redraw = 1;
//            } else if (num < num_max && kip >= 32 && kip <= 126) { // 可打印字符
//                tepStr[num++] = kip;
//                tepStr[num] = '\0';
//                need_redraw = 1;
//            }
////            
//            cursor_on = 1; // 输入后重置光标状态
////            last_toggle = clock();
//        }
//
//        // 处理光标闪烁
//        if ((clock() - last_toggle) * 1000.0 / CLOCKS_PER_SEC > 500) {
//            cursor_on = !cursor_on;
//            last_toggle = clock();
//            need_redraw = 1;
//        }
//
//        // 重绘界面
//        if (need_redraw) {
//            putimage(x, y, background, COPY_PUT); // 恢复背景
//            outtextxy(x, y, tepStr);              // 绘制文本
//            
//            // 绘制光标
//            if (cursor_on&&num>0) {
//                int text_w = textwidth(tepStr);
//                line(x + text_w-2, y, x + text_w-2, y + textheight("W"));
//            }
//        }
//        
//        delay(10); // 降低CPU占用
//    }
//
//    // 保存结果并清理
//    strcpy(save_str, tepStr);
//    putimage(x, y, background, COPY_PUT);
//    outtextxy(x, y, tepStr);
//    free(background);
//}
// void input_str(int x, int y, char *save_str, int font ,int size,int num_max) {
//     char tepStr[21];   // 用于存储当前输入的字符串
//     char kip;          // 当前键入值
//     int num = 0;       // 键入的字符个数
//         // 文本区域的宽度和高度
//     int text_width ;
//     int text_height;
//     int max_x,max_y,right_x,bottom_y;
//     unsigned int malloc_size;
//     void *background;
//     strcpy(tepStr,save_str);
//     num = strlen(tepStr);  // 初始化字符串
//     max_x = getmaxx();
//     max_y = getmaxy();
//     // 设置文本样式，允许根据用户输入调整字体大小
//     settextstyle(font, 0, size);  // 指定的字体样式和大小
//     text_width = textwidth("W") * 20;  // 为了避免超出边界，给定足够宽度
//     text_height = textheight("W")+10;
    
//     right_x = (x + text_width) > max_x ? max_x : (x + text_width);
//     bottom_y = (y + text_height) > max_y ? max_y : (y + text_height);

//     clrmous(MouseX,MouseY);
//     malloc_size = imagesize(x,y,right_x,bottom_y);
//     background = malloc(malloc_size);
//     if (background == NULL){
//         printf("malloc error!");
//         return;
//     }             // 分配足够的内存

//     // 暂存当前输入区域的背景图像
//     getimage(x, y, right_x, bottom_y, background);
//     outtextxy(x,y,tepStr);
//     // 持续获取键盘输入
//     while (1) {
//         if (kbhit()) {
//             kip = getche();  // 获取用户输入的字符并显示

//             if (kip == 13) {  // 如果按下回车键，结束输入
//                 save_bk_mou(MouseX,MouseY);
//                 drawmous(MouseX,MouseY);
//                 break;
//             } else if (kip == 8 && num > 0) {  // 如果按下删除键
//                 // 清除当前输入区域（通过恢复背景图像）
//                 putimage(x, y, background, COPY_PUT);  // 恢复背景图像

//                 // 删除最后一个字符
//                 tepStr[--num] = '\0';

//                 // 重新绘制更新后的文本
//                 outtextxy(x, y, tepStr);  // 显示更新后的文本
//             } else if (num < num_max&&kip != 8) {  // 如果输入的字符未超过限制
//                 tepStr[num++] = kip;  // 添加新字符
//                 tepStr[num] = '\0';   // 保证字符串结束符正确

//                 // 重新绘制字符
//                 outtextxy(x, y, tepStr);  // 显示新的文本
//             }
//         }
//     }

//     // 将当前输入的字符串保存到指定的位置
//     strcpy(save_str, tepStr);
//     // 释放暂存的背景图像内存
//     free(background);
//     background = NULL;
// }
void input_password(int x, int y, char *save_str, int font ,int size,int num_max) {
    char tepStr[21];   // 用于存储当前输入的字符串
    char passShow[21];
    char kip;          // 当前键入值
    int num = 0,i;       // 键入的字符个数
        // 文本区域的宽度和高度
    int text_width ;
    int text_height;
    int max_x,max_y,right_x,bottom_y;
    unsigned int malloc_size;
    void *background;
    strcpy(tepStr,save_str);
    num = strlen(tepStr);  // 初始化字符串
    for(i = 0;i<num;i++){
        passShow[i] = '*';
    }
    passShow[num] = '\0';
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
    outtextxy(x,y,passShow);
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
                num--;
                tepStr[num] = '\0';
                passShow[num] = '\0';

                // 重新绘制更新后的文本
                outtextxy(x, y, passShow);  // 显示更新后的文本
            } else if (num < num_max&&kip != 8) {  // 如果输入的字符未超过限制
                tepStr[num] = kip;  // 添加新字符
                passShow[num] = '*';
                num++;
                tepStr[num] = '\0';   // 保证字符串结束符正确
                passShow[num] = '\0';
                // 重新绘制字符
                outtextxy(x, y, passShow);  // 显示新的文本
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
    char provinces[18][3] = {
        "京", "津", "冀", "晋", "蒙", "吉", "黑", "沪", "苏",
        "浙", "闽", "赣", "鲁", "豫", "鄂", "湘", "粤", "桂",
        
    };
    char province_current[3];
    int num_provinces = 18;
    int max_per_row = 7;  // 每行最多显示10个省份
    int width = 45;
    int height = 45;
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
    delay(100);
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
            break;
        }
        
    }
    free(background);//释放内存
    exit_input();
}

/****
function:让用户鼠标选中天气，并将天气存储到指定位置
author:Chengkai Huang
finished time:2025/2/20
*****/
void input_weather(char *save_weather) {
    char weather_options[10][7] = {
        "晴", "阴", "多云", "雷阵雨", "小雨", 
        "中雨", "大雨", "暴雨", "雾霾", "雪"
    };
    char weather_current[7];
    int num_accident_type = 10;
    int max_per_row = 1;  // 每行最多显示1个天气选项
    int width = 100;         // 按钮宽度
    int height = 25;         // 按钮高度
    int start_x = 250;       // 起始横坐标
    int start_y = 100;       // 起始纵坐标
    int x, y, row, i;
    int press_num;
    void *background;
    unsigned int image_size;
    clrmous(MouseX,MouseY);
    // 存储画面
    image_size = imagesize(start_x, start_y, start_x + (width), start_y + ((num_accident_type / max_per_row + 1) * (height)));
    background = malloc(image_size);
    if (background == NULL) {
        printf("malloc error!");
        return;
    }
    getimage(start_x, start_y, start_x + (width), start_y + ((num_accident_type / max_per_row + 1) * (height)), background);

    // 绘制按钮
    for (i = 0; i < num_accident_type; i++) {
        row = i / max_per_row;  // 计算当前天气选项所在的行
        y = start_y + row * (height); // 计算按钮的纵坐标
        x = start_x+(i%max_per_row)*width;

        strcpy(weather_current, weather_options[i]);
        
        setfillstyle(SOLID_FILL, WHITE);
        bar(x, y, x + width, y + height); // 绘制按钮背景
        setcolor(BLACK);
        rectangle(x, y, x + width, y + height); // 绘制按钮边框
        settextstyle(DEFAULT_FONT, HORIZ_DIR, 1); // 使用较小字体
        puthz(x + (width - textwidth(weather_current)) / 2, y + (height - textheight(weather_current)) / 2, weather_current,16,16,BROWN); // 显示天气选项
    }
    delay(100);
    // 选择天气
    while (1) {
        mou_pos(&MouseX, &MouseY, &press);

        // 判断是否点击天气区域
        if(mouse_press(start_x, start_y, start_x + (max_per_row * (width)), start_y + ((num_accident_type / max_per_row + 1) * (height)))==1
        &&mouse_press(start_x+(num_accident_type%max_per_row)*width,start_y+(num_accident_type/max_per_row)*height,start_x+(max_per_row)*width,start_y+(num_accident_type/max_per_row+1)*height)!=1){
            // 计算点击位置在数组中的位置
            press_num = (MouseY - start_y) / height;
            if (press_num < num_accident_type) {
                strcpy(save_weather, weather_options[press_num]); // 存储选中的天气
                putimage(start_x, start_y, background, COPY_PUT); // 还原画面
                break;
            }
        }
    }
    free(background); // 释放内存
    exit_input();
}
/****
function:让用户鼠标选中事故，并将事故类型对应代号存储到指定位置
author:Chengkai Huang
finished time:2025/2/21
*****/

void input_accident_type(char *save_accident_type) {
    char accident_type_options[5][20] = {
        "人—电动车", "人—汽车", "电动车—电动车", "电动车—汽车", "汽车—汽车", 
    };
    const char accident_type_char[5] = {
        'A','B','C','D','E'
        };
    char weather_current[20];
    int num_accident_type = 5;
    int max_per_row = 1;  // 每行最多个数
    int width = 130;         // 按钮宽度
    int height = 25;         // 按钮高度
    int start_x = 250;       // 起始横坐标
    int start_y = 100;       // 起始纵坐标
    int x, y, row, i;
    int press_num;
    void *background;
    unsigned int image_size;
    clrmous(MouseX,MouseY);
    delay(100);
    // 存储画面
    image_size = imagesize(start_x, start_y, start_x + (width), start_y + ((num_accident_type / max_per_row + 1) * (height)));
    background = malloc(image_size);
    if (background == NULL) {
        printf("malloc error!");
        return;
    }
    getimage(start_x, start_y, start_x + (width), start_y + ((num_accident_type / max_per_row + 1) * (height)), background);

    // 绘制按钮
    for (i = 0; i < num_accident_type; i++) {
        row = i / max_per_row;  // 计算当前选项所在的行
        y = start_y + row * (height); // 计算按钮的纵坐标
        x = start_x+(i%max_per_row)*width;

        strcpy(weather_current, accident_type_options[i]);
        
        setfillstyle(SOLID_FILL, WHITE);
        bar(x, y, x + width, y + height); // 绘制按钮背景
        setcolor(BLACK);
        rectangle(x, y, x + width, y + height); // 绘制按钮边框
        settextstyle(DEFAULT_FONT, HORIZ_DIR, 1); // 使用较小字体
        puthz(x + (width - textwidth(weather_current)) / 2, y + (height - textheight(weather_current)) / 2, weather_current,16,16,BROWN); 
    }
    delay(100);
    // 选择天气
    while (1) {
        mou_pos(&MouseX, &MouseY, &press);

        // 判断是否点击区域
        if(mouse_press(start_x, start_y, start_x + (max_per_row * (width)), start_y + ((num_accident_type / max_per_row + 1) * (height)))==1
        &&mouse_press(start_x+(num_accident_type%max_per_row)*width,start_y+(num_accident_type/max_per_row)*height,start_x+(max_per_row)*width,start_y+(num_accident_type/max_per_row+1)*height)!=1){
            // 计算点击位置在数组中的位置
            press_num = (MouseY - start_y) / height;
            if (press_num < num_accident_type) {
                *save_accident_type = accident_type_char[press_num]; // 存储
                putimage(start_x, start_y, background, COPY_PUT); // 还原画面
                break;
            }
        }
    }
    free(background); // 释放内存
    exit_input();
}

/*将事故字符转化为汉字并显示，x,y为左上角坐标，flag为图像大小（16，24，32，48），
part为汉字间隔，color为颜色*/
void put_accident_type(char type,int x, int y, int flag, int part, int color){
    char accident_type_options[5][20] = {
        "人—电动车", "人—汽车", "电动车—电动车", "电动车—汽车", "汽车—汽车", 
    };
    puthz(x,y,accident_type_options[type-'A'],flag,part,color);
}
void accident_type_trans(char type,char *save_type){
    char accident_type_options[5][20] = {
        "人—电动车", "人—汽车", "电动车—电动车", "电动车—汽车", "汽车—汽车", 
    };
    strcpy(save_type,accident_type_options[type-'A']);
}

/****
function:让用户鼠标选中地点，并将地点存储到指定位置
author:Chengkai Huang
finished time:2025/2/21
*****/
void input_location(char *save_location) {
    char location_options[9][17] = {
        "东九楼下", "东九楼前路口", "韵苑食堂路口", "喻园大道", 
        "绝望坡", "启明路", "华中路", "紫荆路", "紫菘路"
    };
    char location_current[17];
    int num_locations = 9;  // 总共9个地点选项
    int max_per_column = 1; // 每列最多显示1个地点选项
    int width = 160;        // 按钮宽度
    int height = 30;        // 按钮高度
    int start_x = 250;      // 起始横坐标
    int start_y = 100;      // 起始纵坐标
    int x, y, row, i;
    int press_num;
    void *background;
    unsigned int image_size;
    clrmous(MouseX,MouseY);
    delay(100);
    // 存储画面
    image_size = imagesize(start_x, start_y, start_x + (width), start_y + ((num_locations / max_per_column + 1) * (height)));
    background = malloc(image_size);
    if (background == NULL) {
        printf("malloc error!");
        return;
    }
    getimage(start_x, start_y, start_x + (width), start_y + ((num_locations / max_per_column + 1) * (height)), background);

    // 绘制按钮
    for (i = 0; i < num_locations; i++) {
        row = i / max_per_column;  // 计算当前地点选项所在的行
        y = start_y + row * (height); // 计算按钮的纵坐标
        x = start_x + (i % max_per_column) * width; // 计算按钮的横坐标

        strcpy(location_current, location_options[i]);
        
        setfillstyle(SOLID_FILL, LIGHTGRAY);
        bar(x, y, x + width, y + height); // 绘制按钮背景
        setcolor(BLACK);
        rectangle(x, y, x + width, y + height); // 绘制按钮边框
        puthz(x + (width - textwidth(location_current)) / 2, y + (height - textheight(location_current)) / 2, location_current, 16, 16, BLACK); // 显示地点选项
    }
    delay(100);
    // 选择地点
    while (1) {
        mou_pos(&MouseX, &MouseY, &press);

        // 判断是否点击地点区域
        if (mouse_press(start_x, start_y, start_x + (max_per_column * width), start_y + ((num_locations / max_per_column + 1) * height)) == 1) {
            // 计算点击位置在数组中的位置
            press_num = (MouseY - start_y) / height;
            if (press_num < num_locations) {
                strcpy(save_location, location_options[press_num]); // 存储选中的地点
                putimage(start_x, start_y, background, COPY_PUT); // 还原画面
                break;
            }
        }
    }
    free(background); // 释放内存
    exit_input();
}
/****
function:让用户鼠标选中车辆类型，并将类型存储到指定位置
author:Chengkai Huang
finished time:2025/2/24
*****/
void input_car_type(char *save_car_type) {
    char des_part_options[5][7] = {
        "小轿车","面包车","卡车","越野车","长款车"
    };
    char car_current[7];
    int num_locations = 5;  // 总共9个地点选项
    int max_per_column = 1; // 每列最多显示1个地点选项
    int width = 200;        // 按钮宽度
    int height = 30;        // 按钮高度
    int start_x = 250;      // 起始横坐标
    int start_y = 100;      // 起始纵坐标
    int x, y, row, i;
    int press_num;
    void *background;
    unsigned int image_size;
    clrmous(MouseX,MouseY);
    delay(100);
    // 存储画面
    image_size = imagesize(start_x, start_y, start_x + (width), start_y + ((num_locations / max_per_column + 1) * (height)));
    background = malloc(image_size);
    if (background == NULL) {
        printf("malloc error!");
        return;
    }
    getimage(start_x, start_y, start_x + (width), start_y + ((num_locations / max_per_column + 1) * (height)), background);

    // 绘制按钮
    for (i = 0; i < num_locations; i++) {
        row = i / max_per_column;  // 计算当前地点选项所在的行
        y = start_y + row * (height); // 计算按钮的纵坐标
        x = start_x + (i % max_per_column) * width; // 计算按钮的横坐标

        strcpy(car_current, des_part_options[i]);
        
        setfillstyle(SOLID_FILL, LIGHTGRAY);
        bar(x, y, x + width, y + height); // 绘制按钮背景
        setcolor(BLACK);
        rectangle(x, y, x + width, y + height); // 绘制按钮边框
        puthz(x + (width - textwidth(car_current)) / 2, y + (height - textheight(car_current)) / 2, car_current, 16, 16, BROWN); // 显示地点选项
    }
    delay(100);
    // 选择地点
    while (1) {
        mou_pos(&MouseX, &MouseY, &press);

        // 判断是否点击类型区域
        if (mouse_press(start_x, start_y, start_x + (max_per_column * width), start_y + ((num_locations / max_per_column + 1) * height)) == 1) {
            // 计算点击位置在数组中的位置
            press_num = (MouseY - start_y) / height;
            if (press_num < num_locations) {
                strcpy(save_car_type, des_part_options[press_num]); // 存储选中的类型
                putimage(start_x, start_y, background, COPY_PUT); // 还原画面
                break;
            }
        }
    }
    free(background); // 释放内存
    exit_input();
}
/****
function:输入时间
author:Chengkai Huang
finished time:2025/3/1
*****/

void input_time(int x, int y, char *save_str, int font ,int size) {
    char tepStr[21];   // 用于存储当前输入的字符串
    char kip;          // 当前键入值
    int num = 0;       // 键入的字符个数
        // 文本区域的宽度和高度
    int text_width ;
    int text_height;
    int cursor_on = 1;       // 光标显示状态
    int need_redraw = 0;
    clock_t last_toggle ;// 光标计时器
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
    delay(100);
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
        need_redraw = 0;
        if (kbhit()) {
            kip = getche();  // 获取用户输入的字符并显示

            if (kip == 13) {  // 如果按下回车键，结束输入
                save_bk_mou(MouseX,MouseY);
                drawmous(MouseX,MouseY);
                break;
            } else if (kip == 8 && num > 0) {  // 如果按下删除键

                // 删除最后一个字符
                tepStr[--num] = '\0';
                need_redraw = 1;

            } else if (num < 16&&kip >=48&&kip<=57) {  // 如果输入的字符未超过限制
                tepStr[num++] = kip;  // 添加新字符
                if(num==4){
                    tepStr[num++] = '/';
                }else if(num==7){
                    tepStr[num++] = '/';
                }else if(num == 10){
                    tepStr[num++] = ' ';
                }else if(num == 13){
                    tepStr[num++] = ':';
                }
                tepStr[num] = '\0';   // 保证字符串结束符正确
                
                need_redraw = 1;
            }
            cursor_on = 1; // 输入后重置光标状态
            last_toggle = clock();
        }
                // 处理光标闪烁
                if ((clock() - last_toggle) * 1000.0 / CLOCKS_PER_SEC > 500) {
                    cursor_on = !cursor_on;
                    last_toggle = clock();
                    need_redraw = 1;
                }

                // 重绘界面
                if (need_redraw) {
                    putimage(x, y, background, COPY_PUT); // 恢复背景
                    outtextxy(x, y, tepStr);              // 绘制文本
                    
                    // 绘制光标
                    if (cursor_on&&num>0) {
                        int text_w = textwidth(tepStr);
                        line(x + text_w-5, y, x + text_w-5, y + textheight("W"));
                    }
                }
                delay(10);
                
    }
    // 保存结果并清理
    strcpy(save_str, tepStr);
    putimage(x, y, background, COPY_PUT);
    outtextxy(x, y, tepStr);
    free(background);
}

void input_destroy_part(char *save_des_type) {
    char des_part_options[6][9] = {
        "车头","车侧身","车尾","人四肢","人胸腹部","人全身"
    };
    char car_current[9];
    int num_locations = 6;  // 总共6个选项
    int max_per_column = 1; // 每列最多显示1个选项
    int width = 200;        // 按钮宽度
    int height = 30;        // 按钮高度
    int start_x = 250;      // 起始横坐标
    int start_y = 100;      // 起始纵坐标
    int x, y, row, i;
    int press_num;
    void *background;
    unsigned int image_size;
    clrmous(MouseX,MouseY);
    delay(100);
    // 存储画面
    image_size = imagesize(start_x, start_y, start_x + (width), start_y + ((num_locations / max_per_column + 1) * (height)));
    background = malloc(image_size);
    if (background == NULL) {
        printf("malloc error!");
        return;
    }
    getimage(start_x, start_y, start_x + (width), start_y + ((num_locations / max_per_column + 1) * (height)), background);

    // 绘制按钮
    for (i = 0; i < num_locations; i++) {
        row = i / max_per_column;  // 计算当前选项所在的行
        y = start_y + row * (height); // 计算按钮的纵坐标
        x = start_x + (i % max_per_column) * width; // 计算按钮的横坐标

        strcpy(car_current, des_part_options[i]);
        
        setfillstyle(SOLID_FILL, LIGHTGRAY);
        bar(x, y, x + width, y + height); // 绘制按钮背景
        setcolor(BLACK);
        rectangle(x, y, x + width, y + height); // 绘制按钮边框
        puthz(x + (width - textwidth(car_current)) / 2, y + (height - textheight(car_current)) / 2, car_current, 16, 16, BROWN); // 显示地点选项
    }
    delay(100);
    // 选择地点
    while (1) {
        mou_pos(&MouseX, &MouseY, &press);

        // 判断是否点击类型区域
        if (mouse_press(start_x, start_y, start_x + (max_per_column * width), start_y + ((num_locations / max_per_column + 1) * height)) == 1) {
            // 计算点击位置在数组中的位置
            press_num = (MouseY - start_y) / height;
            if (press_num < num_locations) {
                strcpy(save_des_type, des_part_options[press_num]); // 存储选中的类型
                putimage(start_x, start_y, background, COPY_PUT); // 还原画面
                break;
            }
        }
    }
    free(background); // 释放内存
    exit_input();
}


/****
function: 让用户鼠标选择事故处理状态，并将状态存入 processed_status
author: Chengkai Huang
finished time: 2025/4/6
*****/
void input_status(char *processed_status) {
    char *status_options[3] = { "未处理", "已处理", "空" };
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

    // 保存当前屏幕区域图像
    image_size = imagesize(start_x, start_y, start_x + width, start_y + num_status * height);
    background = malloc(image_size);
    if (background == NULL) {
        printf("malloc error!");
        return;
    }
    getimage(start_x, start_y, start_x + width, start_y + num_status * height, background);

    // 绘制选项按钮
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

    // 等待用户点击
    while (1) {
        mou_pos(&MouseX, &MouseY, &press);
        if (mouse_press(start_x, start_y, start_x + width, start_y + num_status * height) == 1) {
            press_index = (MouseY - start_y) / height;
            if (press_index >= 0 && press_index < num_status) {
                *processed_status = status_values[press_index];
                putimage(start_x, start_y, background, COPY_PUT); // 还原画面
                break;
            }
        }
    }

    free(background);
    exit_input();
}
