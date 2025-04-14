#include"common.h"
#include"mouse.h"
#include"IMAGE.h"
#include"verify.h"

/*
功能：让用户选择证人，并且将证人储存到指定类型
彭减 
*/
void input_evidence(char *save_evidence)
{
	char evidence_options[5][7]={
		"张三","李四","王五","赵六","周七"
	};
	char evidence_current[7];
	int num_evidence=5;//一共5个选项
	int max_per_column=1;//每行一个选项
    int width = 200;        // 按钮宽度
    int height = 30;        // 按钮高度
    int start_x = 250;      // 起始横坐标
    int start_y = 100;      // 起始纵坐标
    int x, y, row, i;
    int press_num;
    void *background;
    unsigned int image_size;
    
    // 存储画面
    image_size = imagesize(start_x, start_y, start_x + (width), start_y + ((num_evidence / max_per_column + 1) * (height)));
    background = malloc(image_size);
    if (background == NULL) {
        printf("malloc error!");
        return;
    }
    getimage(start_x, start_y, start_x + (width), start_y + ((num_evidence / max_per_column + 1) * (height)), background);

    // 绘制按钮
    for (i = 0; i < num_evidence; i++) {
        row = i / max_per_column;  // 计算当前地点选项所在的行
        y = start_y + row * (height); // 计算按钮的纵坐标
        x = start_x + (i % max_per_column) * width; // 计算按钮的横坐标

        strcpy(evidence_current, evidence_options[i]);
        
        setfillstyle(SOLID_FILL, LIGHTGRAY);
        bar(x, y, x + width, y + height); // 绘制按钮背景
        setcolor(BLACK);
        rectangle(x, y, x + width, y + height); // 绘制按钮边框
        puthz(x + (width - textwidth(evidence_current)) / 2, y + (height - textheight(evidence_current)) / 2, evidence_current, 16, 16, BLACK); // 显示地点选项
    }

    // 选择地点
    while (1) {
        mou_pos(&MouseX, &MouseY, &press);

        // 判断是否点击类型区域
        if (mouse_press(start_x, start_y, start_x + (max_per_column * width), start_y + ((num_evidence / max_per_column + 1) * height)) == 1) {
            // 计算点击位置在数组中的位置
            press_num = (MouseY - start_y) / height;
            if (press_num < num_evidence) {
                strcpy(save_evidence, evidence_options[press_num]); // 存储选中的类型
                putimage(start_x, start_y, background, COPY_PUT); // 还原画面
                free(background); // 释放内存
                exit_input();
                break;
            }
        }
    }
}

/*
功能：让用户选择证词第一段，并且将证词储存到指定类型
彭减 
*/
void input_description1(char *save_description)
{
	char description_options[5][22]={
		"电动车载人超员，",
		"改装氙气大灯，",
		"车辆存在超载，",
		"新能源车不让人，",
		"擅自改造车具，"
	};
	char description_current[22];
	int num_description=5;//一共5个选项
	int max_per_column=1;//每行一个选项
    int width = 200;        // 按钮宽度
    int height = 30;        // 按钮高度
    int start_x = 250;      // 起始横坐标
    int start_y = 100;      // 起始纵坐标
    int x, y, row, i;
    int press_num;
    void *background;
    unsigned int image_size;
    
    // 存储画面
    image_size = imagesize(start_x, start_y, start_x + (width), start_y + ((num_description / max_per_column + 1) * (height)));
    background = malloc(image_size);
    if (background == NULL) {
        printf("malloc error!");
        return;
    }
    getimage(start_x, start_y, start_x + (width), start_y + ((num_description / max_per_column + 1) * (height)), background);

    // 绘制按钮
    for (i = 0; i < num_description; i++) {
        row = i / max_per_column;  // 计算当前地点选项所在的行
        y = start_y + row * (height); // 计算按钮的纵坐标
        x = start_x + (i % max_per_column) * width; // 计算按钮的横坐标

        strcpy(description_current, description_options[i]);
        
        setfillstyle(SOLID_FILL, LIGHTGRAY);
        bar(x, y, x + width, y + height); // 绘制按钮背景
        setcolor(BLACK);
        rectangle(x, y, x + width, y + height); // 绘制按钮边框
        puthz(x + (width - textwidth(description_current)) / 2, y + (height - textheight(description_current)) / 2, description_current, 16, 16, BLACK); // 显示地点选项
    }

    // 选择地点
    while (1) {
        mou_pos(&MouseX, &MouseY, &press);

        // 判断是否点击类型区域
        if (mouse_press(start_x, start_y, start_x + (max_per_column * width), start_y + ((num_description / max_per_column + 1) * height)) == 1) {
            // 计算点击位置在数组中的位置
            press_num = (MouseY - start_y) / height;
            if (press_num < num_description) {
                strcpy(save_description, description_options[press_num]); // 存储选中的类型
                putimage(start_x, start_y, background, COPY_PUT); // 还原画面
                free(background); // 释放内存
                exit_input();
                break;
            }
        }
    }
}
/*
功能：让用户选择证词第二段，并且将证词储存到指定类型
彭减 
*/
void input_description2(char *save_description)
{
	char description_options[5][19]={
		"酒驾呼气超标，",
		"毒驾检测阳性，",
		"驾照逾期未审，",
		"开车操作手机，",
		"无证驾驶车辆，"
	};
	char description_current[19];
	int num_description=5;//一共5个选项
	int max_per_column=1;//每行一个选项
    int width = 200;        // 按钮宽度
    int height = 30;        // 按钮高度
    int start_x = 250;      // 起始横坐标
    int start_y = 100;      // 起始纵坐标
    int x, y, row, i;
    int press_num;
    void *background;
    unsigned int image_size;
    
    // 存储画面
    image_size = imagesize(start_x, start_y, start_x + (width), start_y + ((num_description / max_per_column + 1) * (height)));
    background = malloc(image_size);
    if (background == NULL) {
        printf("malloc error!");
        return;
    }
    getimage(start_x, start_y, start_x + (width), start_y + ((num_description / max_per_column + 1) * (height)), background);

    // 绘制按钮
    for (i = 0; i < num_description; i++) {
        row = i / max_per_column;  // 计算当前地点选项所在的行
        y = start_y + row * (height); // 计算按钮的纵坐标
        x = start_x + (i % max_per_column) * width; // 计算按钮的横坐标

        strcpy(description_current, description_options[i]);
        
        setfillstyle(SOLID_FILL, LIGHTGRAY);
        bar(x, y, x + width, y + height); // 绘制按钮背景
        setcolor(BLACK);
        rectangle(x, y, x + width, y + height); // 绘制按钮边框
        puthz(x + (width - textwidth(description_current)) / 2, y + (height - textheight(description_current)) / 2, description_current, 16, 16, BLACK); // 显示地点选项
    }

    // 选择地点
    while (1) {
        mou_pos(&MouseX, &MouseY, &press);

        // 判断是否点击类型区域
        if (mouse_press(start_x, start_y, start_x + (max_per_column * width), start_y + ((num_description / max_per_column + 1) * height)) == 1) {
            // 计算点击位置在数组中的位置
            press_num = (MouseY - start_y) / height;
            if (press_num < num_description) {
                strcpy(save_description, description_options[press_num]); // 存储选中的类型
                putimage(start_x, start_y, background, COPY_PUT); // 还原画面
                free(background); // 释放内存
                exit_input();
                break;
            }
        }
    }
}
/*
功能：让用户选择证词第三段，并且将证词储存到指定类型
彭减 
*/
void input_description3(char *save_description)
{
	char description_options[5][19]={
		"非机动车道逆行，",
		"实线变道追尾，",
		"隧道占应急道，",
		"逆行闯单行线，",
		"禁鸣区鸣笛扰民，"
	};
	char description_current[19];
	int num_description=5;//一共5个选项
	int max_per_column=1;//每行一个选项
    int width = 200;        // 按钮宽度
    int height = 30;        // 按钮高度
    int start_x = 250;      // 起始横坐标
    int start_y = 100;      // 起始纵坐标
    int x, y, row, i;
    int press_num;
    void *background;
    unsigned int image_size;
    
    // 存储画面
    image_size = imagesize(start_x, start_y, start_x + (width), start_y + ((num_description / max_per_column + 1) * (height)));
    background = malloc(image_size);
    if (background == NULL) {
        printf("malloc error!");
        return;
    }
    getimage(start_x, start_y, start_x + (width), start_y + ((num_description / max_per_column + 1) * (height)), background);

    // 绘制按钮
    for (i = 0; i < num_description; i++) {
        row = i / max_per_column;  // 计算当前地点选项所在的行
        y = start_y + row * (height); // 计算按钮的纵坐标
        x = start_x + (i % max_per_column) * width; // 计算按钮的横坐标

        strcpy(description_current, description_options[i]);
        
        setfillstyle(SOLID_FILL, LIGHTGRAY);
        bar(x, y, x + width, y + height); // 绘制按钮背景
        setcolor(BLACK);
        rectangle(x, y, x + width, y + height); // 绘制按钮边框
        puthz(x + (width - textwidth(description_current)) / 2, y + (height - textheight(description_current)) / 2, description_current, 16, 16, BLACK); // 显示地点选项
    }

    // 选择地点
    while (1) {
        mou_pos(&MouseX, &MouseY, &press);

        // 判断是否点击类型区域
        if (mouse_press(start_x, start_y, start_x + (max_per_column * width), start_y + ((num_description / max_per_column + 1) * height)) == 1) {
            // 计算点击位置在数组中的位置
            press_num = (MouseY - start_y) / height;
            if (press_num < num_description) {
                strcpy(save_description, description_options[press_num]); // 存储选中的类型
                putimage(start_x, start_y, background, COPY_PUT); // 还原画面
                free(background); // 释放内存
                exit_input();
                break;
            }
        }
    }
}
/*
功能：让用户选择证词第四段，并且将证词储存到指定类型
彭减 
*/
void input_description4(char *save_description)
{
	char description_options[5][19]={
		"电子眼摄录轨迹。",
		"监控录碰撞瞬间。",
		"摄像头抓违特征。",
		"卡口采违法证据。",
		"校园监控录制。"
	};
	char description_current[19];
	int num_description=5;//一共5个选项
	int max_per_column=1;//每行一个选项
    int width = 200;        // 按钮宽度
    int height = 30;        // 按钮高度
    int start_x = 250;      // 起始横坐标
    int start_y = 100;      // 起始纵坐标
    int x, y, row, i;
    int press_num;
    void *background;
    unsigned int image_size;
    
    // 存储画面
    image_size = imagesize(start_x, start_y, start_x + (width), start_y + ((num_description / max_per_column + 1) * (height)));
    background = malloc(image_size);
    if (background == NULL) {
        printf("malloc error!");
        return;
    }
    getimage(start_x, start_y, start_x + (width), start_y + ((num_description / max_per_column + 1) * (height)), background);

    // 绘制按钮
    for (i = 0; i < num_description; i++) {
        row = i / max_per_column;  // 计算当前地点选项所在的行
        y = start_y + row * (height); // 计算按钮的纵坐标
        x = start_x + (i % max_per_column) * width; // 计算按钮的横坐标

        strcpy(description_current, description_options[i]);
        
        setfillstyle(SOLID_FILL, LIGHTGRAY);
        bar(x, y, x + width, y + height); // 绘制按钮背景
        setcolor(BLACK);
        rectangle(x, y, x + width, y + height); // 绘制按钮边框
        puthz(x + (width - textwidth(description_current)) / 2, y + (height - textheight(description_current)) / 2, description_current, 16, 16, BLACK); // 显示地点选项
    }

    // 选择地点
    while (1) {
        mou_pos(&MouseX, &MouseY, &press);

        // 判断是否点击类型区域
        if (mouse_press(start_x, start_y, start_x + (max_per_column * width), start_y + ((num_description / max_per_column + 1) * height)) == 1) {
            // 计算点击位置在数组中的位置
            press_num = (MouseY - start_y) / height;
            if (press_num < num_description) {
                strcpy(save_description, description_options[press_num]); // 存储选中的类型
                putimage(start_x, start_y, background, COPY_PUT); // 还原画面
                free(background); // 释放内存
                exit_input();
                break;
            }
        }
    }
}
/*
功能：允许用户选择图片并且输出
彭减 
*/
void input_image(int bmp_x,int bmp_y,char photo)
{
		char description_options[6][10]={
				"图片一",
				"图片二",
				"图片三",
				"图片四",
				"图片五",
				"图片六"
			};
			char description_current[10];
			int num_description=6;//一共5个选项
			int max_per_column=1;//每行一个选项
		    int width = 200;        // 按钮宽度
		    int height = 30;        // 按钮高度
		    int start_x = 250;      // 起始横坐标
		    int start_y = 10;      // 起始纵坐标
		    int x, y, row, i;
		    int press_num;
		    void *background;
		    unsigned int image_size;
		    
		    // 存储画面
		    image_size = imagesize(start_x, start_y, start_x + (width), start_y + ((num_description / max_per_column + 1) * (height)));
		    background = malloc(image_size);
		    if (background == NULL) {
		        printf("malloc error!");
		        return;
		    }
		    getimage(start_x, start_y, start_x + (width), start_y + ((num_description / max_per_column + 1) * (height)), background);
		
		    // 绘制按钮
		    for (i = 0; i < num_description; i++) {
		        row = i / max_per_column;  // 计算当前地点选项所在的行
		        y = start_y + row * (height); // 计算按钮的纵坐标
		        x = start_x + (i % max_per_column) * width; // 计算按钮的横坐标
		
		        strcpy(description_current, description_options[i]);
		        
		        setfillstyle(SOLID_FILL, LIGHTGRAY);
		        bar(x, y, x + width, y + height); // 绘制按钮背景
		        setcolor(BLACK);
		        rectangle(x, y, x + width, y + height); // 绘制按钮边框
		        puthz(x + (width - textwidth(description_current)) / 2, y + (height - textheight(description_current)) / 2, description_current, 16, 16, BLACK); // 显示地点选项
		    }
		
		    // 选择地点
		    while (1) {
		        mou_pos(&MouseX, &MouseY, &press);
		
		        // 判断是否点击类型区域
		        if (mouse_press(start_x, start_y, start_x + (max_per_column * width), start_y + ((num_description / max_per_column + 1) * height)) == 1) {
		            // 计算点击位置在数组中的位置
		            press_num = (MouseY - start_y) / height+1;
		            if (press_num < num_description+1) {
		            	if(press_num==1)
		            	{
		            		photo=1;
		            		bmp_convert("C:\\PROJECT\\photo\\TU1.bmp","C:\\PROJECT\\photo\\TU1.dbm");
							show_dbm(bmp_x,bmp_y,"C:\\PROJECT\\photo\\TU1.dbm",0);
    		                putimage(start_x, start_y, background, COPY_PUT); // 还原画面
			                free(background); // 释放内存
			                exit_input();
			                break;
						}
		            	if(press_num==2)
		            	{
		            		photo=2;
		            		bmp_convert("C:\\PROJECT\\photo\\TU2.bmp","C:\\PROJECT\\photo\\TU2.dbm");
							show_dbm(bmp_x,bmp_y,"C:\\PROJECT\\photo\\TU2.dbm",0);
    		                putimage(start_x, start_y, background, COPY_PUT); // 还原画面
			                free(background); // 释放内存
			                exit_input();
			                break;
						}
		            	if(press_num==3)
		            	{
		            		photo=3;
		            		bmp_convert("C:\\PROJECT\\photo\\TU3.bmp","C:\\PROJECT\\photo\\TU3.dbm");
							show_dbm(bmp_x,bmp_y,"C:\\PROJECT\\photo\\TU3.dbm",0);
    		                putimage(start_x, start_y, background, COPY_PUT); // 还原画面
			                free(background); // 释放内存
			                exit_input();
			                break;
						}
		               if(press_num==4)
		            	{
		            		photo=4;
		            		bmp_convert("C:\\PROJECT\\photo\\TU4.bmp","C:\\PROJECT\\photo\\TU4.dbm");
							show_dbm(bmp_x,bmp_y,"C:\\PROJECT\\photo\\TU4.dbm",0);
    		                putimage(start_x, start_y, background, COPY_PUT); // 还原画面
			                free(background); // 释放内存
			                exit_input();
			                break;
						}
		            	if(press_num==5)
		            	{
		            		photo=5;
		            		bmp_convert("C:\\PROJECT\\photo\\TU5.bmp","C:\\PROJECT\\photo\\TU5.dbm");
							show_dbm(bmp_x,bmp_y,"C:\\PROJECT\\photo\\TU5.dbm",0);
    		                putimage(start_x, start_y, background, COPY_PUT); // 还原画面
			                free(background); // 释放内存
			                exit_input();
			                break;
						}
		            	if(press_num==6)
		            	{
		            		photo=6;
		            		bmp_convert("C:\\PROJECT\\photo\\TU6.bmp","C:\\PROJECT\\photo\\TU6.dbm");
							show_dbm(bmp_x,bmp_y,"C:\\PROJECT\\photo\\TU6.dbm",0);
    		                putimage(start_x, start_y, background, COPY_PUT); // 还原画面
			                free(background); // 释放内存
			                exit_input();
			                break;
						}
		            }
		        }
		    }
} 
/*
让管理员选择责任评估第1段
彭减
*/
void input_judge_des1(char *save_description)
{
	char description_options[5][19]={
		"评估一，",
		"评估二，",
		"评估三，",
		"评估四，",
		"评估五，"
	};
	char description_current[19];
	int num_description=5;//一共5个选项
	int max_per_column=1;//每行一个选项
    int width = 200;        // 按钮宽度
    int height = 30;        // 按钮高度
    int start_x = 250;      // 起始横坐标
    int start_y = 100;      // 起始纵坐标
    int x, y, row, i;
    int press_num;
    void *background;
    unsigned int image_size;
    
    // 存储画面
    image_size = imagesize(start_x, start_y, start_x + (width), start_y + ((num_description / max_per_column + 1) * (height)));
    background = malloc(image_size);
    if (background == NULL) {
        printf("malloc error!");
        return;
    }
    getimage(start_x, start_y, start_x + (width), start_y + ((num_description / max_per_column + 1) * (height)), background);

    // 绘制按钮
    for (i = 0; i < num_description; i++) {
        row = i / max_per_column;  // 计算当前地点选项所在的行
        y = start_y + row * (height); // 计算按钮的纵坐标
        x = start_x + (i % max_per_column) * width; // 计算按钮的横坐标

        strcpy(description_current, description_options[i]);
        
        setfillstyle(SOLID_FILL, LIGHTGRAY);
        bar(x, y, x + width, y + height); // 绘制按钮背景
        setcolor(BLACK);
        rectangle(x, y, x + width, y + height); // 绘制按钮边框
        puthz(x + (width - textwidth(description_current)) / 2, y + (height - textheight(description_current)) / 2, description_current, 16, 16, BLACK); // 显示地点选项
    }

    // 选择地点
    while (1) {
        mou_pos(&MouseX, &MouseY, &press);

        // 判断是否点击类型区域
        if (mouse_press(start_x, start_y, start_x + (max_per_column * width), start_y + ((num_description / max_per_column + 1) * height)) == 1) {
            // 计算点击位置在数组中的位置
            press_num = (MouseY - start_y) / height;
            if (press_num < num_description) {
                strcpy(save_description, description_options[press_num]); // 存储选中的类型
                putimage(start_x, start_y, background, COPY_PUT); // 还原画面
                free(background); // 释放内存
                exit_input();
                break;
            }
        }
    }
}
/*
让管理员选择评估第二段
彭减
*/
void input_judge_des2(char *save_description)
{
	char description_options[5][19]={
		"评估一，",
		"评估二，",
		"评估三，",
		"评估四，",
		"评估五，"
	};
	char description_current[19];
	int num_description=5;//一共5个选项
	int max_per_column=1;//每行一个选项
    int width = 200;        // 按钮宽度
    int height = 30;        // 按钮高度
    int start_x = 250;      // 起始横坐标
    int start_y = 100;      // 起始纵坐标
    int x, y, row, i;
    int press_num;
    void *background;
    unsigned int image_size;
    
    // 存储画面
    image_size = imagesize(start_x, start_y, start_x + (width), start_y + ((num_description / max_per_column + 1) * (height)));
    background = malloc(image_size);
    if (background == NULL) {
        printf("malloc error!");
        return;
    }
    getimage(start_x, start_y, start_x + (width), start_y + ((num_description / max_per_column + 1) * (height)), background);

    // 绘制按钮
    for (i = 0; i < num_description; i++) {
        row = i / max_per_column;  // 计算当前地点选项所在的行
        y = start_y + row * (height); // 计算按钮的纵坐标
        x = start_x + (i % max_per_column) * width; // 计算按钮的横坐标

        strcpy(description_current, description_options[i]);
        
        setfillstyle(SOLID_FILL, LIGHTGRAY);
        bar(x, y, x + width, y + height); // 绘制按钮背景
        setcolor(BLACK);
        rectangle(x, y, x + width, y + height); // 绘制按钮边框
        puthz(x + (width - textwidth(description_current)) / 2, y + (height - textheight(description_current)) / 2, description_current, 16, 16, BLACK); // 显示地点选项
    }

    // 选择地点
    while (1) {
        mou_pos(&MouseX, &MouseY, &press);

        // 判断是否点击类型区域
        if (mouse_press(start_x, start_y, start_x + (max_per_column * width), start_y + ((num_description / max_per_column + 1) * height)) == 1) {
            // 计算点击位置在数组中的位置
            press_num = (MouseY - start_y) / height;
            if (press_num < num_description) {
                strcpy(save_description, description_options[press_num]); // 存储选中的类型
                putimage(start_x, start_y, background, COPY_PUT); // 还原画面
                free(background); // 释放内存
                exit_input();
                break;
            }
        }
    }
}
/*
让管理员选择评估第3段
彭减
*/
void input_judge_des3(char *save_description)
{
	char description_options[5][19]={
		"评估一，",
		"评估二，",
		"评估三，",
		"评估四，",
		"评估五，"
	};
	char description_current[19];
	int num_description=5;//一共5个选项
	int max_per_column=1;//每行一个选项
    int width = 200;        // 按钮宽度
    int height = 30;        // 按钮高度
    int start_x = 250;      // 起始横坐标
    int start_y = 100;      // 起始纵坐标
    int x, y, row, i;
    int press_num;
    void *background;
    unsigned int image_size;
    
    // 存储画面
    image_size = imagesize(start_x, start_y, start_x + (width), start_y + ((num_description / max_per_column + 1) * (height)));
    background = malloc(image_size);
    if (background == NULL) {
        printf("malloc error!");
        return;
    }
    getimage(start_x, start_y, start_x + (width), start_y + ((num_description / max_per_column + 1) * (height)), background);

    // 绘制按钮
    for (i = 0; i < num_description; i++) {
        row = i / max_per_column;  // 计算当前地点选项所在的行
        y = start_y + row * (height); // 计算按钮的纵坐标
        x = start_x + (i % max_per_column) * width; // 计算按钮的横坐标

        strcpy(description_current, description_options[i]);
        
        setfillstyle(SOLID_FILL, LIGHTGRAY);
        bar(x, y, x + width, y + height); // 绘制按钮背景
        setcolor(BLACK);
        rectangle(x, y, x + width, y + height); // 绘制按钮边框
        puthz(x + (width - textwidth(description_current)) / 2, y + (height - textheight(description_current)) / 2, description_current, 16, 16, BLACK); // 显示地点选项
    }

    // 选择地点
    while (1) {
        mou_pos(&MouseX, &MouseY, &press);

        // 判断是否点击类型区域
        if (mouse_press(start_x, start_y, start_x + (max_per_column * width), start_y + ((num_description / max_per_column + 1) * height)) == 1) {
            // 计算点击位置在数组中的位置
            press_num = (MouseY - start_y) / height;
            if (press_num < num_description) {
                strcpy(save_description, description_options[press_num]); // 存储选中的类型
                putimage(start_x, start_y, background, COPY_PUT); // 还原画面
                free(background); // 释放内存
                exit_input();
                break;
            }
        }
    }
}
/*
让管理员选择评估第4段
彭减
*/
void input_judge_des4(char *save_description)
{
	char description_options[5][19]={
		"评估一，",
		"评估二，",
		"评估三，",
		"评估四，",
		"评估五，"
	};
	char description_current[19];
	int num_description=5;//一共5个选项
	int max_per_column=1;//每行一个选项
    int width = 200;        // 按钮宽度
    int height = 30;        // 按钮高度
    int start_x = 250;      // 起始横坐标
    int start_y = 100;      // 起始纵坐标
    int x, y, row, i;
    int press_num;
    void *background;
    unsigned int image_size;
    
    // 存储画面
    image_size = imagesize(start_x, start_y, start_x + (width), start_y + ((num_description / max_per_column + 1) * (height)));
    background = malloc(image_size);
    if (background == NULL) {
        printf("malloc error!");
        return;
    }
    getimage(start_x, start_y, start_x + (width), start_y + ((num_description / max_per_column + 1) * (height)), background);

    // 绘制按钮
    for (i = 0; i < num_description; i++) {
        row = i / max_per_column;  // 计算当前地点选项所在的行
        y = start_y + row * (height); // 计算按钮的纵坐标
        x = start_x + (i % max_per_column) * width; // 计算按钮的横坐标

        strcpy(description_current, description_options[i]);
        
        setfillstyle(SOLID_FILL, LIGHTGRAY);
        bar(x, y, x + width, y + height); // 绘制按钮背景
        setcolor(BLACK);
        rectangle(x, y, x + width, y + height); // 绘制按钮边框
        puthz(x + (width - textwidth(description_current)) / 2, y + (height - textheight(description_current)) / 2, description_current, 16, 16, BLACK); // 显示地点选项
    }

    // 选择地点
    while (1) {
        mou_pos(&MouseX, &MouseY, &press);

        // 判断是否点击类型区域
        if (mouse_press(start_x, start_y, start_x + (max_per_column * width), start_y + ((num_description / max_per_column + 1) * height)) == 1) {
            // 计算点击位置在数组中的位置
            press_num = (MouseY - start_y) / height;
            if (press_num < num_description) {
                strcpy(save_description, description_options[press_num]); // 存储选中的类型
                putimage(start_x, start_y, background, COPY_PUT); // 还原画面
                free(background); // 释放内存
                exit_input();
                break;
            }
        }
    }
}
/*
让管理员选择影响因素
彭减
*/
void input_judge_infect(char *save_description)
{
	char description_options[5][19]={
		"因素一，",
		"因素二，",
		"因素三，",
		"因素四，",
		"因素五，"
	};
	char description_current[19];
	int num_description=5;//一共5个选项
	int max_per_column=1;//每行一个选项
    int width = 200;        // 按钮宽度
    int height = 30;        // 按钮高度
    int start_x = 250;      // 起始横坐标
    int start_y = 100;      // 起始纵坐标
    int x, y, row, i;
    int press_num;
    void *background;
    unsigned int image_size;
    
    // 存储画面
    image_size = imagesize(start_x, start_y, start_x + (width), start_y + ((num_description / max_per_column + 1) * (height)));
    background = malloc(image_size);
    if (background == NULL) {
        printf("malloc error!");
        return;
    }
    getimage(start_x, start_y, start_x + (width), start_y + ((num_description / max_per_column + 1) * (height)), background);

    // 绘制按钮
    for (i = 0; i < num_description; i++) {
        row = i / max_per_column;  // 计算当前地点选项所在的行
        y = start_y + row * (height); // 计算按钮的纵坐标
        x = start_x + (i % max_per_column) * width; // 计算按钮的横坐标

        strcpy(description_current, description_options[i]);
        
        setfillstyle(SOLID_FILL, LIGHTGRAY);
        bar(x, y, x + width, y + height); // 绘制按钮背景
        setcolor(BLACK);
        rectangle(x, y, x + width, y + height); // 绘制按钮边框
        puthz(x + (width - textwidth(description_current)) / 2, y + (height - textheight(description_current)) / 2, description_current, 16, 16, BLACK); // 显示地点选项
    }

    // 选择地点
    while (1) {
        mou_pos(&MouseX, &MouseY, &press);

        // 判断是否点击类型区域
        if (mouse_press(start_x, start_y, start_x + (max_per_column * width), start_y + ((num_description / max_per_column + 1) * height)) == 1) {
            // 计算点击位置在数组中的位置
            press_num = (MouseY - start_y) / height;
            if (press_num < num_description) {
                strcpy(save_description, description_options[press_num]); // 存储选中的类型
                putimage(start_x, start_y, background, COPY_PUT); // 还原画面
                free(background); // 释放内存
                exit_input();
                break;
            }
        }
    }
}
/*
让管理员选择责任
彭减
*/
void input_judge_duty(char *save_description)
{
	char description_options[5][19]={
		"负部分责任",
		"负全部责任",
		"负主要责任",
		"负次要责任",
		"不负责任"
	};
	char description_current[19];
	int num_description=5;//一共5个选项
	int max_per_column=1;//每行一个选项
    int width = 200;        // 按钮宽度
    int height = 30;        // 按钮高度
    int start_x = 250;      // 起始横坐标
    int start_y = 100;      // 起始纵坐标
    int x, y, row, i;
    int press_num;
    void *background;
    unsigned int image_size;
    
    // 存储画面
    image_size = imagesize(start_x, start_y, start_x + (width), start_y + ((num_description / max_per_column + 1) * (height)));
    background = malloc(image_size);
    if (background == NULL) {
        printf("malloc error!");
        return;
    }
    getimage(start_x, start_y, start_x + (width), start_y + ((num_description / max_per_column + 1) * (height)), background);

    // 绘制按钮
    for (i = 0; i < num_description; i++) {
        row = i / max_per_column;  // 计算当前地点选项所在的行
        y = start_y + row * (height); // 计算按钮的纵坐标
        x = start_x + (i % max_per_column) * width; // 计算按钮的横坐标

        strcpy(description_current, description_options[i]);
        
        setfillstyle(SOLID_FILL, LIGHTGRAY);
        bar(x, y, x + width, y + height); // 绘制按钮背景
        setcolor(BLACK);
        rectangle(x, y, x + width, y + height); // 绘制按钮边框
        puthz(x + (width - textwidth(description_current)) / 2, y + (height - textheight(description_current)) / 2, description_current, 16, 16, BLACK); // 显示地点选项
    }

    // 选择地点
    while (1) {
        mou_pos(&MouseX, &MouseY, &press);

        // 判断是否点击类型区域
        if (mouse_press(start_x, start_y, start_x + (max_per_column * width), start_y + ((num_description / max_per_column + 1) * height)) == 1) {
            // 计算点击位置在数组中的位置
            press_num = (MouseY - start_y) / height;
            if (press_num < num_description) {
                strcpy(save_description, description_options[press_num]); // 存储选中的类型
                putimage(start_x, start_y, background, COPY_PUT); // 还原画面
                free(background); // 释放内存
                exit_input();
                break;
            }
        }
    }
}
/*
让管理员选择惩罚金额
彭减
*/
void input_judge_money(char *save_description)
{
	char description_options[5][19]={
		"不处赔偿",
		"三千元以下",
		"三千到一万元",
		"一万到十万元",
		"十万元以上"
	};
	char description_current[19];
	int num_description=5;//一共5个选项
	int max_per_column=1;//每行一个选项
    int width = 200;        // 按钮宽度
    int height = 30;        // 按钮高度
    int start_x = 250;      // 起始横坐标
    int start_y = 100;      // 起始纵坐标
    int x, y, row, i;
    int press_num;
    void *background;
    unsigned int image_size;
    
    // 存储画面
    image_size = imagesize(start_x, start_y, start_x + (width), start_y + ((num_description / max_per_column + 1) * (height)));
    background = malloc(image_size);
    if (background == NULL) {
        printf("malloc error!");
        return;
    }
    getimage(start_x, start_y, start_x + (width), start_y + ((num_description / max_per_column + 1) * (height)), background);

    // 绘制按钮
    for (i = 0; i < num_description; i++) {
        row = i / max_per_column;  // 计算当前地点选项所在的行
        y = start_y + row * (height); // 计算按钮的纵坐标
        x = start_x + (i % max_per_column) * width; // 计算按钮的横坐标

        strcpy(description_current, description_options[i]);
        
        setfillstyle(SOLID_FILL, LIGHTGRAY);
        bar(x, y, x + width, y + height); // 绘制按钮背景
        setcolor(BLACK);
        rectangle(x, y, x + width, y + height); // 绘制按钮边框
        puthz(x + (width - textwidth(description_current)) / 2, y + (height - textheight(description_current)) / 2, description_current, 16, 16, BLACK); // 显示地点选项
    }

    // 选择地点
    while (1) {
        mou_pos(&MouseX, &MouseY, &press);

        // 判断是否点击类型区域
        if (mouse_press(start_x, start_y, start_x + (max_per_column * width), start_y + ((num_description / max_per_column + 1) * height)) == 1) {
            // 计算点击位置在数组中的位置
            press_num = (MouseY - start_y) / height;
            if (press_num < num_description) {
                strcpy(save_description, description_options[press_num]); // 存储选中的类型
                putimage(start_x, start_y, background, COPY_PUT); // 还原画面
                free(background); // 释放内存
                exit_input();
                break;
            }
        }
    }
}
/*
让管理员选择惩罚类型
彭减
*/
void input_judge_punish(char *save_description)
{
	char description_options[5][19]={
		"不处法律惩罚",
		"口头教育",
		"行政拘留",
		"刑事拘留",
		"坐牢"
	};
	char description_current[19];
	int num_description=5;//一共5个选项
	int max_per_column=1;//每行一个选项
    int width = 200;        // 按钮宽度
    int height = 30;        // 按钮高度
    int start_x = 250;      // 起始横坐标
    int start_y = 100;      // 起始纵坐标
    int x, y, row, i;
    int press_num;
    void *background;
    unsigned int image_size;
    
    // 存储画面
    image_size = imagesize(start_x, start_y, start_x + (width), start_y + ((num_description / max_per_column + 1) * (height)));
    background = malloc(image_size);
    if (background == NULL) {
        printf("malloc error!");
        return;
    }
    getimage(start_x, start_y, start_x + (width), start_y + ((num_description / max_per_column + 1) * (height)), background);

    // 绘制按钮
    for (i = 0; i < num_description; i++) {
        row = i / max_per_column;  // 计算当前地点选项所在的行
        y = start_y + row * (height); // 计算按钮的纵坐标
        x = start_x + (i % max_per_column) * width; // 计算按钮的横坐标

        strcpy(description_current, description_options[i]);
        
        setfillstyle(SOLID_FILL, LIGHTGRAY);
        bar(x, y, x + width, y + height); // 绘制按钮背景
        setcolor(BLACK);
        rectangle(x, y, x + width, y + height); // 绘制按钮边框
        puthz(x + (width - textwidth(description_current)) / 2, y + (height - textheight(description_current)) / 2, description_current, 16, 16, BLACK); // 显示地点选项
    }

    // 选择地点
    while (1) {
        mou_pos(&MouseX, &MouseY, &press);

        // 判断是否点击类型区域
        if (mouse_press(start_x, start_y, start_x + (max_per_column * width), start_y + ((num_description / max_per_column + 1) * height)) == 1) {
            // 计算点击位置在数组中的位置
            press_num = (MouseY - start_y) / height;
            if (press_num < num_description) {
                strcpy(save_description, description_options[press_num]); // 存储选中的类型
                putimage(start_x, start_y, background, COPY_PUT); // 还原画面
                free(background); // 释放内存
                break;
                exit_input();
            }
        }
    }
}
/*
让管理员选择惩罚时间
彭减
*/
void input_judge_time(char *save_description)
{
	char description_options[5][19]={
		"无惩罚时间",
		"七日内",
		"一个月内",
		"一年内",
		"无期徒刑"
	};
	char description_current[19];
	int num_description=5;//一共5个选项
	int max_per_column=1;//每行一个选项
    int width = 200;        // 按钮宽度
    int height = 30;        // 按钮高度
    int start_x = 250;      // 起始横坐标
    int start_y = 100;      // 起始纵坐标
    int x, y, row, i;
    int press_num;
    void *background;
    unsigned int image_size;
    
    // 存储画面
    image_size = imagesize(start_x, start_y, start_x + (width), start_y + ((num_description / max_per_column + 1) * (height)));
    background = malloc(image_size);
    if (background == NULL) {
        printf("malloc error!");
        return;
    }
    getimage(start_x, start_y, start_x + (width), start_y + ((num_description / max_per_column + 1) * (height)), background);

    // 绘制按钮
    for (i = 0; i < num_description; i++) {
        row = i / max_per_column;  // 计算当前地点选项所在的行
        y = start_y + row * (height); // 计算按钮的纵坐标
        x = start_x + (i % max_per_column) * width; // 计算按钮的横坐标

        strcpy(description_current, description_options[i]);
        
        setfillstyle(SOLID_FILL, LIGHTGRAY);
        bar(x, y, x + width, y + height); // 绘制按钮背景
        setcolor(BLACK);
        rectangle(x, y, x + width, y + height); // 绘制按钮边框
        puthz(x + (width - textwidth(description_current)) / 2, y + (height - textheight(description_current)) / 2, description_current, 16, 16, BLACK); // 显示地点选项
    }

    // 选择地点
    while (1) {
        mou_pos(&MouseX, &MouseY, &press);

        // 判断是否点击类型区域
        if (mouse_press(start_x, start_y, start_x + (max_per_column * width), start_y + ((num_description / max_per_column + 1) * height)) == 1) {
            // 计算点击位置在数组中的位置
            press_num = (MouseY - start_y) / height;
            if (press_num < num_description) {
                strcpy(save_description, description_options[press_num]); // 存储选中的类型
                putimage(start_x, start_y, background, COPY_PUT); // 还原画面
                free(background); // 释放内存
                exit_input();
                break;
            }
        }
    }
}
/*
让管理员选择审理单位
彭减
*/
void input_judge_log(char *save_description)
{
	char description_options[5][19]={
		"校保卫处",
		"区公安所",
		"市人民检察院",
		"市法院",
		"市公安所"
	};
	char description_current[19];
	int num_description=5;//一共5个选项
	int max_per_column=1;//每行一个选项
    int width = 200;        // 按钮宽度
    int height = 30;        // 按钮高度
    int start_x = 250;      // 起始横坐标
    int start_y = 100;      // 起始纵坐标
    int x, y, row, i;
    int press_num;
    void *background;
    unsigned int image_size;
    
    // 存储画面
    image_size = imagesize(start_x, start_y, start_x + (width), start_y + ((num_description / max_per_column + 1) * (height)));
    background = malloc(image_size);
    if (background == NULL) {
        printf("malloc error!");
        return;
    }
    getimage(start_x, start_y, start_x + (width), start_y + ((num_description / max_per_column + 1) * (height)), background);

    // 绘制按钮
    for (i = 0; i < num_description; i++) {
        row = i / max_per_column;  // 计算当前地点选项所在的行
        y = start_y + row * (height); // 计算按钮的纵坐标
        x = start_x + (i % max_per_column) * width; // 计算按钮的横坐标

        strcpy(description_current, description_options[i]);
        
        setfillstyle(SOLID_FILL, LIGHTGRAY);
        bar(x, y, x + width, y + height); // 绘制按钮背景
        setcolor(BLACK);
        rectangle(x, y, x + width, y + height); // 绘制按钮边框
        puthz(x + (width - textwidth(description_current)) / 2, y + (height - textheight(description_current)) / 2, description_current, 16, 16, BLACK); // 显示地点选项
    }

    // 选择地点
    while (1) {
        mou_pos(&MouseX, &MouseY, &press);

        // 判断是否点击类型区域
        if (mouse_press(start_x, start_y, start_x + (max_per_column * width), start_y + ((num_description / max_per_column + 1) * height)) == 1) {
            // 计算点击位置在数组中的位置
            press_num = (MouseY - start_y) / height;
            if (press_num < num_description) {
                strcpy(save_description, description_options[press_num]); // 存储选中的类型
                putimage(start_x, start_y, background, COPY_PUT); // 还原画面
                free(background); // 释放内存
                exit_input();
                break;
            }
        }
    }
}

/*
功能：让用户选择反馈第1段，并且将反馈储存到指定类型
彭减 
*/
void input_feedback1(char *save_description)
{
	char description_options[5][19]={
		"反馈一",
		"反馈二",
		"反馈三",
		"反馈四",
		"反馈五"
	};
	char description_current[19];
	int num_description=5;//一共5个选项
	int max_per_column=1;//每行一个选项
    int width = 200;        // 按钮宽度
    int height = 30;        // 按钮高度
    int start_x = 250;      // 起始横坐标
    int start_y = 100;      // 起始纵坐标
    int x, y, row, i;
    int press_num;
    void *background;
    unsigned int image_size;
    
    // 存储画面
    image_size = imagesize(start_x, start_y, start_x + (width), start_y + ((num_description / max_per_column + 1) * (height)));
    background = malloc(image_size);
    if (background == NULL) {
        printf("malloc error!");
        return;
    }
    getimage(start_x, start_y, start_x + (width), start_y + ((num_description / max_per_column + 1) * (height)), background);

    // 绘制按钮
    for (i = 0; i < num_description; i++) {
        row = i / max_per_column;  // 计算当前地点选项所在的行
        y = start_y + row * (height); // 计算按钮的纵坐标
        x = start_x + (i % max_per_column) * width; // 计算按钮的横坐标

        strcpy(description_current, description_options[i]);
        
        setfillstyle(SOLID_FILL, LIGHTGRAY);
        bar(x, y, x + width, y + height); // 绘制按钮背景
        setcolor(BLACK);
        rectangle(x, y, x + width, y + height); // 绘制按钮边框
        puthz(x + (width - textwidth(description_current)) / 2, y + (height - textheight(description_current)) / 2, description_current, 16, 16, BLACK); // 显示地点选项
    }

    // 选择地点
    while (1) {
        mou_pos(&MouseX, &MouseY, &press);

        // 判断是否点击类型区域
        if (mouse_press(start_x, start_y, start_x + (max_per_column * width), start_y + ((num_description / max_per_column + 1) * height)) == 1) {
            // 计算点击位置在数组中的位置
            press_num = (MouseY - start_y) / height;
            if (press_num < num_description) {
                strcpy(save_description, description_options[press_num]); // 存储选中的类型
                putimage(start_x, start_y, background, COPY_PUT); // 还原画面
                free(background); // 释放内存
                exit_input();
                break;
            }
        }
    }
}


/*
功能：让用户选择反馈第2段，并且将反馈储存到指定类型
彭减 
*/
void input_feedback2(char *save_description)
{
	char description_options[5][19]={
		"反馈一",
		"反馈二",
		"反馈三",
		"反馈四",
		"反馈五"
	};
	char description_current[19];
	int num_description=5;//一共5个选项
	int max_per_column=1;//每行一个选项
    int width = 200;        // 按钮宽度
    int height = 30;        // 按钮高度
    int start_x = 250;      // 起始横坐标
    int start_y = 100;      // 起始纵坐标
    int x, y, row, i;
    int press_num;
    void *background;
    unsigned int image_size;
    
    // 存储画面
    image_size = imagesize(start_x, start_y, start_x + (width), start_y + ((num_description / max_per_column + 1) * (height)));
    background = malloc(image_size);
    if (background == NULL) {
        printf("malloc error!");
        return;
    }
    getimage(start_x, start_y, start_x + (width), start_y + ((num_description / max_per_column + 1) * (height)), background);

    // 绘制按钮
    for (i = 0; i < num_description; i++) {
        row = i / max_per_column;  // 计算当前地点选项所在的行
        y = start_y + row * (height); // 计算按钮的纵坐标
        x = start_x + (i % max_per_column) * width; // 计算按钮的横坐标

        strcpy(description_current, description_options[i]);
        
        setfillstyle(SOLID_FILL, LIGHTGRAY);
        bar(x, y, x + width, y + height); // 绘制按钮背景
        setcolor(BLACK);
        rectangle(x, y, x + width, y + height); // 绘制按钮边框
        puthz(x + (width - textwidth(description_current)) / 2, y + (height - textheight(description_current)) / 2, description_current, 16, 16, BLACK); // 显示地点选项
    }

    // 选择地点
    while (1) {
        mou_pos(&MouseX, &MouseY, &press);

        // 判断是否点击类型区域
        if (mouse_press(start_x, start_y, start_x + (max_per_column * width), start_y + ((num_description / max_per_column + 1) * height)) == 1) {
            // 计算点击位置在数组中的位置
            press_num = (MouseY - start_y) / height;
            if (press_num < num_description) {
                strcpy(save_description, description_options[press_num]); // 存储选中的类型
                putimage(start_x, start_y, background, COPY_PUT); // 还原画面
                free(background); // 释放内存
                exit_input();
                break;
            }
        }
    }
}

/*
功能：让用户选择反馈第3段，并且将反馈储存到指定类型
彭减 
*/
void input_feedback3(char *save_description)
{
	char description_options[5][19]={
		"反馈一",
		"反馈二",
		"反馈三",
		"反馈四",
		"反馈五"
	};
	char description_current[19];
	int num_description=5;//一共5个选项
	int max_per_column=1;//每行一个选项
    int width = 200;        // 按钮宽度
    int height = 30;        // 按钮高度
    int start_x = 250;      // 起始横坐标
    int start_y = 100;      // 起始纵坐标
    int x, y, row, i;
    int press_num;
    void *background;
    unsigned int image_size;
    
    // 存储画面
    image_size = imagesize(start_x, start_y, start_x + (width), start_y + ((num_description / max_per_column + 1) * (height)));
    background = malloc(image_size);
    if (background == NULL) {
        printf("malloc error!");
        return;
    }
    getimage(start_x, start_y, start_x + (width), start_y + ((num_description / max_per_column + 1) * (height)), background);

    // 绘制按钮
    for (i = 0; i < num_description; i++) {
        row = i / max_per_column;  // 计算当前地点选项所在的行
        y = start_y + row * (height); // 计算按钮的纵坐标
        x = start_x + (i % max_per_column) * width; // 计算按钮的横坐标

        strcpy(description_current, description_options[i]);
        
        setfillstyle(SOLID_FILL, LIGHTGRAY);
        bar(x, y, x + width, y + height); // 绘制按钮背景
        setcolor(BLACK);
        rectangle(x, y, x + width, y + height); // 绘制按钮边框
        puthz(x + (width - textwidth(description_current)) / 2, y + (height - textheight(description_current)) / 2, description_current, 16, 16, BLACK); // 显示地点选项
    }

    // 选择地点
    while (1) {
        mou_pos(&MouseX, &MouseY, &press);

        // 判断是否点击类型区域
        if (mouse_press(start_x, start_y, start_x + (max_per_column * width), start_y + ((num_description / max_per_column + 1) * height)) == 1) {
            // 计算点击位置在数组中的位置
            press_num = (MouseY - start_y) / height;
            if (press_num < num_description) {
                strcpy(save_description, description_options[press_num]); // 存储选中的类型
                putimage(start_x, start_y, background, COPY_PUT); // 还原画面
                free(background); // 释放内存
                exit_input();
                break;
            }
        }
    }
}

/*
功能：让用户选择反馈第4段，并且将反馈储存到指定类型
彭减 
*/
void input_feedback4(char *save_description)
{
	char description_options[5][19]={
		"反馈一",
		"反馈二",
		"反馈三",
		"反馈四",
		"反馈五"
	};
	char description_current[19];
	int num_description=5;//一共5个选项
	int max_per_column=1;//每行一个选项
    int width = 200;        // 按钮宽度
    int height = 30;        // 按钮高度
    int start_x = 250;      // 起始横坐标
    int start_y = 100;      // 起始纵坐标
    int x, y, row, i;
    int press_num;
    void *background;
    unsigned int image_size;
    
    // 存储画面
    image_size = imagesize(start_x, start_y, start_x + (width), start_y + ((num_description / max_per_column + 1) * (height)));
    background = malloc(image_size);
    if (background == NULL) {
        printf("malloc error!");
        return;
    }
    getimage(start_x, start_y, start_x + (width), start_y + ((num_description / max_per_column + 1) * (height)), background);

    // 绘制按钮
    for (i = 0; i < num_description; i++) {
        row = i / max_per_column;  // 计算当前地点选项所在的行
        y = start_y + row * (height); // 计算按钮的纵坐标
        x = start_x + (i % max_per_column) * width; // 计算按钮的横坐标

        strcpy(description_current, description_options[i]);
        
        setfillstyle(SOLID_FILL, LIGHTGRAY);
        bar(x, y, x + width, y + height); // 绘制按钮背景
        setcolor(BLACK);
        rectangle(x, y, x + width, y + height); // 绘制按钮边框
        puthz(x + (width - textwidth(description_current)) / 2, y + (height - textheight(description_current)) / 2, description_current, 16, 16, BLACK); // 显示地点选项
    }

    // 选择地点
    while (1) {
        mou_pos(&MouseX, &MouseY, &press);

        // 判断是否点击类型区域
        if (mouse_press(start_x, start_y, start_x + (max_per_column * width), start_y + ((num_description / max_per_column + 1) * height)) == 1) {
            // 计算点击位置在数组中的位置
            press_num = (MouseY - start_y) / height;
            if (press_num < num_description) {
                strcpy(save_description, description_options[press_num]); // 存储选中的类型
                putimage(start_x, start_y, background, COPY_PUT); // 还原画面
                free(background); // 释放内存
                exit_input();
                break;
            }
        }
    }
}



















