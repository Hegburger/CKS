#include"common.h"
#include"mouse.h"
#include"IMAGE.h"
#include"verify.h"

/*
���ܣ����û�ѡ��֤�ˣ����ҽ�֤�˴��浽ָ������
��� 
*/
void input_evidence(char *save_evidence)
{
	char evidence_options[5][7]={
		"����","����","����","����","����"
	};
	char evidence_current[7];
	int num_evidence=5;//һ��5��ѡ��
	int max_per_column=1;//ÿ��һ��ѡ��
    int width = 200;        // ��ť���
    int height = 30;        // ��ť�߶�
    int start_x = 250;      // ��ʼ������
    int start_y = 100;      // ��ʼ������
    int x, y, row, i;
    int press_num;
    void *background;
    unsigned int image_size;
    
    // �洢����
    image_size = imagesize(start_x, start_y, start_x + (width), start_y + ((num_evidence / max_per_column + 1) * (height)));
    background = malloc(image_size);
    if (background == NULL) {
        printf("malloc error!");
        return;
    }
    getimage(start_x, start_y, start_x + (width), start_y + ((num_evidence / max_per_column + 1) * (height)), background);

    // ���ư�ť
    for (i = 0; i < num_evidence; i++) {
        row = i / max_per_column;  // ���㵱ǰ�ص�ѡ�����ڵ���
        y = start_y + row * (height); // ���㰴ť��������
        x = start_x + (i % max_per_column) * width; // ���㰴ť�ĺ�����

        strcpy(evidence_current, evidence_options[i]);
        
        setfillstyle(SOLID_FILL, LIGHTGRAY);
        bar(x, y, x + width, y + height); // ���ư�ť����
        setcolor(BLACK);
        rectangle(x, y, x + width, y + height); // ���ư�ť�߿�
        puthz(x + (width - textwidth(evidence_current)) / 2, y + (height - textheight(evidence_current)) / 2, evidence_current, 16, 16, BLACK); // ��ʾ�ص�ѡ��
    }

    // ѡ��ص�
    while (1) {
        mou_pos(&MouseX, &MouseY, &press);

        // �ж��Ƿ�����������
        if (mouse_press(start_x, start_y, start_x + (max_per_column * width), start_y + ((num_evidence / max_per_column + 1) * height)) == 1) {
            // ������λ���������е�λ��
            press_num = (MouseY - start_y) / height;
            if (press_num < num_evidence) {
                strcpy(save_evidence, evidence_options[press_num]); // �洢ѡ�е�����
                putimage(start_x, start_y, background, COPY_PUT); // ��ԭ����
                free(background); // �ͷ��ڴ�
                exit_input();
                break;
            }
        }
    }
}

/*
���ܣ����û�ѡ��֤�ʵ�һ�Σ����ҽ�֤�ʴ��浽ָ������
��� 
*/
void input_description1(char *save_description)
{
	char description_options[5][22]={
		"�綯�����˳�Ա��",
		"��װ�����ƣ�",
		"�������ڳ��أ�",
		"����Դ�������ˣ�",
		"���Ը��쳵�ߣ�"
	};
	char description_current[22];
	int num_description=5;//һ��5��ѡ��
	int max_per_column=1;//ÿ��һ��ѡ��
    int width = 200;        // ��ť���
    int height = 30;        // ��ť�߶�
    int start_x = 250;      // ��ʼ������
    int start_y = 100;      // ��ʼ������
    int x, y, row, i;
    int press_num;
    void *background;
    unsigned int image_size;
    
    // �洢����
    image_size = imagesize(start_x, start_y, start_x + (width), start_y + ((num_description / max_per_column + 1) * (height)));
    background = malloc(image_size);
    if (background == NULL) {
        printf("malloc error!");
        return;
    }
    getimage(start_x, start_y, start_x + (width), start_y + ((num_description / max_per_column + 1) * (height)), background);

    // ���ư�ť
    for (i = 0; i < num_description; i++) {
        row = i / max_per_column;  // ���㵱ǰ�ص�ѡ�����ڵ���
        y = start_y + row * (height); // ���㰴ť��������
        x = start_x + (i % max_per_column) * width; // ���㰴ť�ĺ�����

        strcpy(description_current, description_options[i]);
        
        setfillstyle(SOLID_FILL, LIGHTGRAY);
        bar(x, y, x + width, y + height); // ���ư�ť����
        setcolor(BLACK);
        rectangle(x, y, x + width, y + height); // ���ư�ť�߿�
        puthz(x + (width - textwidth(description_current)) / 2, y + (height - textheight(description_current)) / 2, description_current, 16, 16, BLACK); // ��ʾ�ص�ѡ��
    }

    // ѡ��ص�
    while (1) {
        mou_pos(&MouseX, &MouseY, &press);

        // �ж��Ƿ�����������
        if (mouse_press(start_x, start_y, start_x + (max_per_column * width), start_y + ((num_description / max_per_column + 1) * height)) == 1) {
            // ������λ���������е�λ��
            press_num = (MouseY - start_y) / height;
            if (press_num < num_description) {
                strcpy(save_description, description_options[press_num]); // �洢ѡ�е�����
                putimage(start_x, start_y, background, COPY_PUT); // ��ԭ����
                free(background); // �ͷ��ڴ�
                exit_input();
                break;
            }
        }
    }
}
/*
���ܣ����û�ѡ��֤�ʵڶ��Σ����ҽ�֤�ʴ��浽ָ������
��� 
*/
void input_description2(char *save_description)
{
	char description_options[5][19]={
		"�Ƽݺ������꣬",
		"���ݼ�����ԣ�",
		"��������δ��",
		"���������ֻ���",
		"��֤��ʻ������"
	};
	char description_current[19];
	int num_description=5;//һ��5��ѡ��
	int max_per_column=1;//ÿ��һ��ѡ��
    int width = 200;        // ��ť���
    int height = 30;        // ��ť�߶�
    int start_x = 250;      // ��ʼ������
    int start_y = 100;      // ��ʼ������
    int x, y, row, i;
    int press_num;
    void *background;
    unsigned int image_size;
    
    // �洢����
    image_size = imagesize(start_x, start_y, start_x + (width), start_y + ((num_description / max_per_column + 1) * (height)));
    background = malloc(image_size);
    if (background == NULL) {
        printf("malloc error!");
        return;
    }
    getimage(start_x, start_y, start_x + (width), start_y + ((num_description / max_per_column + 1) * (height)), background);

    // ���ư�ť
    for (i = 0; i < num_description; i++) {
        row = i / max_per_column;  // ���㵱ǰ�ص�ѡ�����ڵ���
        y = start_y + row * (height); // ���㰴ť��������
        x = start_x + (i % max_per_column) * width; // ���㰴ť�ĺ�����

        strcpy(description_current, description_options[i]);
        
        setfillstyle(SOLID_FILL, LIGHTGRAY);
        bar(x, y, x + width, y + height); // ���ư�ť����
        setcolor(BLACK);
        rectangle(x, y, x + width, y + height); // ���ư�ť�߿�
        puthz(x + (width - textwidth(description_current)) / 2, y + (height - textheight(description_current)) / 2, description_current, 16, 16, BLACK); // ��ʾ�ص�ѡ��
    }

    // ѡ��ص�
    while (1) {
        mou_pos(&MouseX, &MouseY, &press);

        // �ж��Ƿ�����������
        if (mouse_press(start_x, start_y, start_x + (max_per_column * width), start_y + ((num_description / max_per_column + 1) * height)) == 1) {
            // ������λ���������е�λ��
            press_num = (MouseY - start_y) / height;
            if (press_num < num_description) {
                strcpy(save_description, description_options[press_num]); // �洢ѡ�е�����
                putimage(start_x, start_y, background, COPY_PUT); // ��ԭ����
                free(background); // �ͷ��ڴ�
                exit_input();
                break;
            }
        }
    }
}
/*
���ܣ����û�ѡ��֤�ʵ����Σ����ҽ�֤�ʴ��浽ָ������
��� 
*/
void input_description3(char *save_description)
{
	char description_options[5][19]={
		"�ǻ����������У�",
		"ʵ�߱��׷β��",
		"���ռӦ������",
		"���д������ߣ�",
		"��������������"
	};
	char description_current[19];
	int num_description=5;//һ��5��ѡ��
	int max_per_column=1;//ÿ��һ��ѡ��
    int width = 200;        // ��ť���
    int height = 30;        // ��ť�߶�
    int start_x = 250;      // ��ʼ������
    int start_y = 100;      // ��ʼ������
    int x, y, row, i;
    int press_num;
    void *background;
    unsigned int image_size;
    
    // �洢����
    image_size = imagesize(start_x, start_y, start_x + (width), start_y + ((num_description / max_per_column + 1) * (height)));
    background = malloc(image_size);
    if (background == NULL) {
        printf("malloc error!");
        return;
    }
    getimage(start_x, start_y, start_x + (width), start_y + ((num_description / max_per_column + 1) * (height)), background);

    // ���ư�ť
    for (i = 0; i < num_description; i++) {
        row = i / max_per_column;  // ���㵱ǰ�ص�ѡ�����ڵ���
        y = start_y + row * (height); // ���㰴ť��������
        x = start_x + (i % max_per_column) * width; // ���㰴ť�ĺ�����

        strcpy(description_current, description_options[i]);
        
        setfillstyle(SOLID_FILL, LIGHTGRAY);
        bar(x, y, x + width, y + height); // ���ư�ť����
        setcolor(BLACK);
        rectangle(x, y, x + width, y + height); // ���ư�ť�߿�
        puthz(x + (width - textwidth(description_current)) / 2, y + (height - textheight(description_current)) / 2, description_current, 16, 16, BLACK); // ��ʾ�ص�ѡ��
    }

    // ѡ��ص�
    while (1) {
        mou_pos(&MouseX, &MouseY, &press);

        // �ж��Ƿ�����������
        if (mouse_press(start_x, start_y, start_x + (max_per_column * width), start_y + ((num_description / max_per_column + 1) * height)) == 1) {
            // ������λ���������е�λ��
            press_num = (MouseY - start_y) / height;
            if (press_num < num_description) {
                strcpy(save_description, description_options[press_num]); // �洢ѡ�е�����
                putimage(start_x, start_y, background, COPY_PUT); // ��ԭ����
                free(background); // �ͷ��ڴ�
                exit_input();
                break;
            }
        }
    }
}
/*
���ܣ����û�ѡ��֤�ʵ��ĶΣ����ҽ�֤�ʴ��浽ָ������
��� 
*/
void input_description4(char *save_description)
{
	char description_options[5][19]={
		"��������¼�켣��",
		"���¼��ײ˲�䡣",
		"����ͷץΥ������",
		"���ڲ�Υ��֤�ݡ�",
		"У԰���¼�ơ�"
	};
	char description_current[19];
	int num_description=5;//һ��5��ѡ��
	int max_per_column=1;//ÿ��һ��ѡ��
    int width = 200;        // ��ť���
    int height = 30;        // ��ť�߶�
    int start_x = 250;      // ��ʼ������
    int start_y = 100;      // ��ʼ������
    int x, y, row, i;
    int press_num;
    void *background;
    unsigned int image_size;
    
    // �洢����
    image_size = imagesize(start_x, start_y, start_x + (width), start_y + ((num_description / max_per_column + 1) * (height)));
    background = malloc(image_size);
    if (background == NULL) {
        printf("malloc error!");
        return;
    }
    getimage(start_x, start_y, start_x + (width), start_y + ((num_description / max_per_column + 1) * (height)), background);

    // ���ư�ť
    for (i = 0; i < num_description; i++) {
        row = i / max_per_column;  // ���㵱ǰ�ص�ѡ�����ڵ���
        y = start_y + row * (height); // ���㰴ť��������
        x = start_x + (i % max_per_column) * width; // ���㰴ť�ĺ�����

        strcpy(description_current, description_options[i]);
        
        setfillstyle(SOLID_FILL, LIGHTGRAY);
        bar(x, y, x + width, y + height); // ���ư�ť����
        setcolor(BLACK);
        rectangle(x, y, x + width, y + height); // ���ư�ť�߿�
        puthz(x + (width - textwidth(description_current)) / 2, y + (height - textheight(description_current)) / 2, description_current, 16, 16, BLACK); // ��ʾ�ص�ѡ��
    }

    // ѡ��ص�
    while (1) {
        mou_pos(&MouseX, &MouseY, &press);

        // �ж��Ƿ�����������
        if (mouse_press(start_x, start_y, start_x + (max_per_column * width), start_y + ((num_description / max_per_column + 1) * height)) == 1) {
            // ������λ���������е�λ��
            press_num = (MouseY - start_y) / height;
            if (press_num < num_description) {
                strcpy(save_description, description_options[press_num]); // �洢ѡ�е�����
                putimage(start_x, start_y, background, COPY_PUT); // ��ԭ����
                free(background); // �ͷ��ڴ�
                exit_input();
                break;
            }
        }
    }
}
/*
���ܣ������û�ѡ��ͼƬ�������
��� 
*/
void input_image(int bmp_x,int bmp_y,char photo)
{
		char description_options[6][10]={
				"ͼƬһ",
				"ͼƬ��",
				"ͼƬ��",
				"ͼƬ��",
				"ͼƬ��",
				"ͼƬ��"
			};
			char description_current[10];
			int num_description=6;//һ��5��ѡ��
			int max_per_column=1;//ÿ��һ��ѡ��
		    int width = 200;        // ��ť���
		    int height = 30;        // ��ť�߶�
		    int start_x = 250;      // ��ʼ������
		    int start_y = 10;      // ��ʼ������
		    int x, y, row, i;
		    int press_num;
		    void *background;
		    unsigned int image_size;
		    
		    // �洢����
		    image_size = imagesize(start_x, start_y, start_x + (width), start_y + ((num_description / max_per_column + 1) * (height)));
		    background = malloc(image_size);
		    if (background == NULL) {
		        printf("malloc error!");
		        return;
		    }
		    getimage(start_x, start_y, start_x + (width), start_y + ((num_description / max_per_column + 1) * (height)), background);
		
		    // ���ư�ť
		    for (i = 0; i < num_description; i++) {
		        row = i / max_per_column;  // ���㵱ǰ�ص�ѡ�����ڵ���
		        y = start_y + row * (height); // ���㰴ť��������
		        x = start_x + (i % max_per_column) * width; // ���㰴ť�ĺ�����
		
		        strcpy(description_current, description_options[i]);
		        
		        setfillstyle(SOLID_FILL, LIGHTGRAY);
		        bar(x, y, x + width, y + height); // ���ư�ť����
		        setcolor(BLACK);
		        rectangle(x, y, x + width, y + height); // ���ư�ť�߿�
		        puthz(x + (width - textwidth(description_current)) / 2, y + (height - textheight(description_current)) / 2, description_current, 16, 16, BLACK); // ��ʾ�ص�ѡ��
		    }
		
		    // ѡ��ص�
		    while (1) {
		        mou_pos(&MouseX, &MouseY, &press);
		
		        // �ж��Ƿ�����������
		        if (mouse_press(start_x, start_y, start_x + (max_per_column * width), start_y + ((num_description / max_per_column + 1) * height)) == 1) {
		            // ������λ���������е�λ��
		            press_num = (MouseY - start_y) / height+1;
		            if (press_num < num_description+1) {
		            	if(press_num==1)
		            	{
		            		photo=1;
		            		bmp_convert("C:\\PROJECT\\photo\\TU1.bmp","C:\\PROJECT\\photo\\TU1.dbm");
							show_dbm(bmp_x,bmp_y,"C:\\PROJECT\\photo\\TU1.dbm",0);
    		                putimage(start_x, start_y, background, COPY_PUT); // ��ԭ����
			                free(background); // �ͷ��ڴ�
			                exit_input();
			                break;
						}
		            	if(press_num==2)
		            	{
		            		photo=2;
		            		bmp_convert("C:\\PROJECT\\photo\\TU2.bmp","C:\\PROJECT\\photo\\TU2.dbm");
							show_dbm(bmp_x,bmp_y,"C:\\PROJECT\\photo\\TU2.dbm",0);
    		                putimage(start_x, start_y, background, COPY_PUT); // ��ԭ����
			                free(background); // �ͷ��ڴ�
			                exit_input();
			                break;
						}
		            	if(press_num==3)
		            	{
		            		photo=3;
		            		bmp_convert("C:\\PROJECT\\photo\\TU3.bmp","C:\\PROJECT\\photo\\TU3.dbm");
							show_dbm(bmp_x,bmp_y,"C:\\PROJECT\\photo\\TU3.dbm",0);
    		                putimage(start_x, start_y, background, COPY_PUT); // ��ԭ����
			                free(background); // �ͷ��ڴ�
			                exit_input();
			                break;
						}
		               if(press_num==4)
		            	{
		            		photo=4;
		            		bmp_convert("C:\\PROJECT\\photo\\TU4.bmp","C:\\PROJECT\\photo\\TU4.dbm");
							show_dbm(bmp_x,bmp_y,"C:\\PROJECT\\photo\\TU4.dbm",0);
    		                putimage(start_x, start_y, background, COPY_PUT); // ��ԭ����
			                free(background); // �ͷ��ڴ�
			                exit_input();
			                break;
						}
		            	if(press_num==5)
		            	{
		            		photo=5;
		            		bmp_convert("C:\\PROJECT\\photo\\TU5.bmp","C:\\PROJECT\\photo\\TU5.dbm");
							show_dbm(bmp_x,bmp_y,"C:\\PROJECT\\photo\\TU5.dbm",0);
    		                putimage(start_x, start_y, background, COPY_PUT); // ��ԭ����
			                free(background); // �ͷ��ڴ�
			                exit_input();
			                break;
						}
		            	if(press_num==6)
		            	{
		            		photo=6;
		            		bmp_convert("C:\\PROJECT\\photo\\TU6.bmp","C:\\PROJECT\\photo\\TU6.dbm");
							show_dbm(bmp_x,bmp_y,"C:\\PROJECT\\photo\\TU6.dbm",0);
    		                putimage(start_x, start_y, background, COPY_PUT); // ��ԭ����
			                free(background); // �ͷ��ڴ�
			                exit_input();
			                break;
						}
		            }
		        }
		    }
} 
/*
�ù���Աѡ������������1��
���
*/
void input_judge_des1(char *save_description)
{
	char description_options[5][19]={
		"����һ��",
		"��������",
		"��������",
		"�����ģ�",
		"�����壬"
	};
	char description_current[19];
	int num_description=5;//һ��5��ѡ��
	int max_per_column=1;//ÿ��һ��ѡ��
    int width = 200;        // ��ť���
    int height = 30;        // ��ť�߶�
    int start_x = 250;      // ��ʼ������
    int start_y = 100;      // ��ʼ������
    int x, y, row, i;
    int press_num;
    void *background;
    unsigned int image_size;
    
    // �洢����
    image_size = imagesize(start_x, start_y, start_x + (width), start_y + ((num_description / max_per_column + 1) * (height)));
    background = malloc(image_size);
    if (background == NULL) {
        printf("malloc error!");
        return;
    }
    getimage(start_x, start_y, start_x + (width), start_y + ((num_description / max_per_column + 1) * (height)), background);

    // ���ư�ť
    for (i = 0; i < num_description; i++) {
        row = i / max_per_column;  // ���㵱ǰ�ص�ѡ�����ڵ���
        y = start_y + row * (height); // ���㰴ť��������
        x = start_x + (i % max_per_column) * width; // ���㰴ť�ĺ�����

        strcpy(description_current, description_options[i]);
        
        setfillstyle(SOLID_FILL, LIGHTGRAY);
        bar(x, y, x + width, y + height); // ���ư�ť����
        setcolor(BLACK);
        rectangle(x, y, x + width, y + height); // ���ư�ť�߿�
        puthz(x + (width - textwidth(description_current)) / 2, y + (height - textheight(description_current)) / 2, description_current, 16, 16, BLACK); // ��ʾ�ص�ѡ��
    }

    // ѡ��ص�
    while (1) {
        mou_pos(&MouseX, &MouseY, &press);

        // �ж��Ƿ�����������
        if (mouse_press(start_x, start_y, start_x + (max_per_column * width), start_y + ((num_description / max_per_column + 1) * height)) == 1) {
            // ������λ���������е�λ��
            press_num = (MouseY - start_y) / height;
            if (press_num < num_description) {
                strcpy(save_description, description_options[press_num]); // �洢ѡ�е�����
                putimage(start_x, start_y, background, COPY_PUT); // ��ԭ����
                free(background); // �ͷ��ڴ�
                exit_input();
                break;
            }
        }
    }
}
/*
�ù���Աѡ�������ڶ���
���
*/
void input_judge_des2(char *save_description)
{
	char description_options[5][19]={
		"����һ��",
		"��������",
		"��������",
		"�����ģ�",
		"�����壬"
	};
	char description_current[19];
	int num_description=5;//һ��5��ѡ��
	int max_per_column=1;//ÿ��һ��ѡ��
    int width = 200;        // ��ť���
    int height = 30;        // ��ť�߶�
    int start_x = 250;      // ��ʼ������
    int start_y = 100;      // ��ʼ������
    int x, y, row, i;
    int press_num;
    void *background;
    unsigned int image_size;
    
    // �洢����
    image_size = imagesize(start_x, start_y, start_x + (width), start_y + ((num_description / max_per_column + 1) * (height)));
    background = malloc(image_size);
    if (background == NULL) {
        printf("malloc error!");
        return;
    }
    getimage(start_x, start_y, start_x + (width), start_y + ((num_description / max_per_column + 1) * (height)), background);

    // ���ư�ť
    for (i = 0; i < num_description; i++) {
        row = i / max_per_column;  // ���㵱ǰ�ص�ѡ�����ڵ���
        y = start_y + row * (height); // ���㰴ť��������
        x = start_x + (i % max_per_column) * width; // ���㰴ť�ĺ�����

        strcpy(description_current, description_options[i]);
        
        setfillstyle(SOLID_FILL, LIGHTGRAY);
        bar(x, y, x + width, y + height); // ���ư�ť����
        setcolor(BLACK);
        rectangle(x, y, x + width, y + height); // ���ư�ť�߿�
        puthz(x + (width - textwidth(description_current)) / 2, y + (height - textheight(description_current)) / 2, description_current, 16, 16, BLACK); // ��ʾ�ص�ѡ��
    }

    // ѡ��ص�
    while (1) {
        mou_pos(&MouseX, &MouseY, &press);

        // �ж��Ƿ�����������
        if (mouse_press(start_x, start_y, start_x + (max_per_column * width), start_y + ((num_description / max_per_column + 1) * height)) == 1) {
            // ������λ���������е�λ��
            press_num = (MouseY - start_y) / height;
            if (press_num < num_description) {
                strcpy(save_description, description_options[press_num]); // �洢ѡ�е�����
                putimage(start_x, start_y, background, COPY_PUT); // ��ԭ����
                free(background); // �ͷ��ڴ�
                exit_input();
                break;
            }
        }
    }
}
/*
�ù���Աѡ��������3��
���
*/
void input_judge_des3(char *save_description)
{
	char description_options[5][19]={
		"����һ��",
		"��������",
		"��������",
		"�����ģ�",
		"�����壬"
	};
	char description_current[19];
	int num_description=5;//һ��5��ѡ��
	int max_per_column=1;//ÿ��һ��ѡ��
    int width = 200;        // ��ť���
    int height = 30;        // ��ť�߶�
    int start_x = 250;      // ��ʼ������
    int start_y = 100;      // ��ʼ������
    int x, y, row, i;
    int press_num;
    void *background;
    unsigned int image_size;
    
    // �洢����
    image_size = imagesize(start_x, start_y, start_x + (width), start_y + ((num_description / max_per_column + 1) * (height)));
    background = malloc(image_size);
    if (background == NULL) {
        printf("malloc error!");
        return;
    }
    getimage(start_x, start_y, start_x + (width), start_y + ((num_description / max_per_column + 1) * (height)), background);

    // ���ư�ť
    for (i = 0; i < num_description; i++) {
        row = i / max_per_column;  // ���㵱ǰ�ص�ѡ�����ڵ���
        y = start_y + row * (height); // ���㰴ť��������
        x = start_x + (i % max_per_column) * width; // ���㰴ť�ĺ�����

        strcpy(description_current, description_options[i]);
        
        setfillstyle(SOLID_FILL, LIGHTGRAY);
        bar(x, y, x + width, y + height); // ���ư�ť����
        setcolor(BLACK);
        rectangle(x, y, x + width, y + height); // ���ư�ť�߿�
        puthz(x + (width - textwidth(description_current)) / 2, y + (height - textheight(description_current)) / 2, description_current, 16, 16, BLACK); // ��ʾ�ص�ѡ��
    }

    // ѡ��ص�
    while (1) {
        mou_pos(&MouseX, &MouseY, &press);

        // �ж��Ƿ�����������
        if (mouse_press(start_x, start_y, start_x + (max_per_column * width), start_y + ((num_description / max_per_column + 1) * height)) == 1) {
            // ������λ���������е�λ��
            press_num = (MouseY - start_y) / height;
            if (press_num < num_description) {
                strcpy(save_description, description_options[press_num]); // �洢ѡ�е�����
                putimage(start_x, start_y, background, COPY_PUT); // ��ԭ����
                free(background); // �ͷ��ڴ�
                exit_input();
                break;
            }
        }
    }
}
/*
�ù���Աѡ��������4��
���
*/
void input_judge_des4(char *save_description)
{
	char description_options[5][19]={
		"����һ��",
		"��������",
		"��������",
		"�����ģ�",
		"�����壬"
	};
	char description_current[19];
	int num_description=5;//һ��5��ѡ��
	int max_per_column=1;//ÿ��һ��ѡ��
    int width = 200;        // ��ť���
    int height = 30;        // ��ť�߶�
    int start_x = 250;      // ��ʼ������
    int start_y = 100;      // ��ʼ������
    int x, y, row, i;
    int press_num;
    void *background;
    unsigned int image_size;
    
    // �洢����
    image_size = imagesize(start_x, start_y, start_x + (width), start_y + ((num_description / max_per_column + 1) * (height)));
    background = malloc(image_size);
    if (background == NULL) {
        printf("malloc error!");
        return;
    }
    getimage(start_x, start_y, start_x + (width), start_y + ((num_description / max_per_column + 1) * (height)), background);

    // ���ư�ť
    for (i = 0; i < num_description; i++) {
        row = i / max_per_column;  // ���㵱ǰ�ص�ѡ�����ڵ���
        y = start_y + row * (height); // ���㰴ť��������
        x = start_x + (i % max_per_column) * width; // ���㰴ť�ĺ�����

        strcpy(description_current, description_options[i]);
        
        setfillstyle(SOLID_FILL, LIGHTGRAY);
        bar(x, y, x + width, y + height); // ���ư�ť����
        setcolor(BLACK);
        rectangle(x, y, x + width, y + height); // ���ư�ť�߿�
        puthz(x + (width - textwidth(description_current)) / 2, y + (height - textheight(description_current)) / 2, description_current, 16, 16, BLACK); // ��ʾ�ص�ѡ��
    }

    // ѡ��ص�
    while (1) {
        mou_pos(&MouseX, &MouseY, &press);

        // �ж��Ƿ�����������
        if (mouse_press(start_x, start_y, start_x + (max_per_column * width), start_y + ((num_description / max_per_column + 1) * height)) == 1) {
            // ������λ���������е�λ��
            press_num = (MouseY - start_y) / height;
            if (press_num < num_description) {
                strcpy(save_description, description_options[press_num]); // �洢ѡ�е�����
                putimage(start_x, start_y, background, COPY_PUT); // ��ԭ����
                free(background); // �ͷ��ڴ�
                exit_input();
                break;
            }
        }
    }
}
/*
�ù���Աѡ��Ӱ������
���
*/
void input_judge_infect(char *save_description)
{
	char description_options[5][19]={
		"����һ��",
		"���ض���",
		"��������",
		"�����ģ�",
		"�����壬"
	};
	char description_current[19];
	int num_description=5;//һ��5��ѡ��
	int max_per_column=1;//ÿ��һ��ѡ��
    int width = 200;        // ��ť���
    int height = 30;        // ��ť�߶�
    int start_x = 250;      // ��ʼ������
    int start_y = 100;      // ��ʼ������
    int x, y, row, i;
    int press_num;
    void *background;
    unsigned int image_size;
    
    // �洢����
    image_size = imagesize(start_x, start_y, start_x + (width), start_y + ((num_description / max_per_column + 1) * (height)));
    background = malloc(image_size);
    if (background == NULL) {
        printf("malloc error!");
        return;
    }
    getimage(start_x, start_y, start_x + (width), start_y + ((num_description / max_per_column + 1) * (height)), background);

    // ���ư�ť
    for (i = 0; i < num_description; i++) {
        row = i / max_per_column;  // ���㵱ǰ�ص�ѡ�����ڵ���
        y = start_y + row * (height); // ���㰴ť��������
        x = start_x + (i % max_per_column) * width; // ���㰴ť�ĺ�����

        strcpy(description_current, description_options[i]);
        
        setfillstyle(SOLID_FILL, LIGHTGRAY);
        bar(x, y, x + width, y + height); // ���ư�ť����
        setcolor(BLACK);
        rectangle(x, y, x + width, y + height); // ���ư�ť�߿�
        puthz(x + (width - textwidth(description_current)) / 2, y + (height - textheight(description_current)) / 2, description_current, 16, 16, BLACK); // ��ʾ�ص�ѡ��
    }

    // ѡ��ص�
    while (1) {
        mou_pos(&MouseX, &MouseY, &press);

        // �ж��Ƿ�����������
        if (mouse_press(start_x, start_y, start_x + (max_per_column * width), start_y + ((num_description / max_per_column + 1) * height)) == 1) {
            // ������λ���������е�λ��
            press_num = (MouseY - start_y) / height;
            if (press_num < num_description) {
                strcpy(save_description, description_options[press_num]); // �洢ѡ�е�����
                putimage(start_x, start_y, background, COPY_PUT); // ��ԭ����
                free(background); // �ͷ��ڴ�
                exit_input();
                break;
            }
        }
    }
}
/*
�ù���Աѡ������
���
*/
void input_judge_duty(char *save_description)
{
	char description_options[5][19]={
		"����������",
		"��ȫ������",
		"����Ҫ����",
		"����Ҫ����",
		"��������"
	};
	char description_current[19];
	int num_description=5;//һ��5��ѡ��
	int max_per_column=1;//ÿ��һ��ѡ��
    int width = 200;        // ��ť���
    int height = 30;        // ��ť�߶�
    int start_x = 250;      // ��ʼ������
    int start_y = 100;      // ��ʼ������
    int x, y, row, i;
    int press_num;
    void *background;
    unsigned int image_size;
    
    // �洢����
    image_size = imagesize(start_x, start_y, start_x + (width), start_y + ((num_description / max_per_column + 1) * (height)));
    background = malloc(image_size);
    if (background == NULL) {
        printf("malloc error!");
        return;
    }
    getimage(start_x, start_y, start_x + (width), start_y + ((num_description / max_per_column + 1) * (height)), background);

    // ���ư�ť
    for (i = 0; i < num_description; i++) {
        row = i / max_per_column;  // ���㵱ǰ�ص�ѡ�����ڵ���
        y = start_y + row * (height); // ���㰴ť��������
        x = start_x + (i % max_per_column) * width; // ���㰴ť�ĺ�����

        strcpy(description_current, description_options[i]);
        
        setfillstyle(SOLID_FILL, LIGHTGRAY);
        bar(x, y, x + width, y + height); // ���ư�ť����
        setcolor(BLACK);
        rectangle(x, y, x + width, y + height); // ���ư�ť�߿�
        puthz(x + (width - textwidth(description_current)) / 2, y + (height - textheight(description_current)) / 2, description_current, 16, 16, BLACK); // ��ʾ�ص�ѡ��
    }

    // ѡ��ص�
    while (1) {
        mou_pos(&MouseX, &MouseY, &press);

        // �ж��Ƿ�����������
        if (mouse_press(start_x, start_y, start_x + (max_per_column * width), start_y + ((num_description / max_per_column + 1) * height)) == 1) {
            // ������λ���������е�λ��
            press_num = (MouseY - start_y) / height;
            if (press_num < num_description) {
                strcpy(save_description, description_options[press_num]); // �洢ѡ�е�����
                putimage(start_x, start_y, background, COPY_PUT); // ��ԭ����
                free(background); // �ͷ��ڴ�
                exit_input();
                break;
            }
        }
    }
}
/*
�ù���Աѡ��ͷ����
���
*/
void input_judge_money(char *save_description)
{
	char description_options[5][19]={
		"�����⳥",
		"��ǧԪ����",
		"��ǧ��һ��Ԫ",
		"һ��ʮ��Ԫ",
		"ʮ��Ԫ����"
	};
	char description_current[19];
	int num_description=5;//һ��5��ѡ��
	int max_per_column=1;//ÿ��һ��ѡ��
    int width = 200;        // ��ť���
    int height = 30;        // ��ť�߶�
    int start_x = 250;      // ��ʼ������
    int start_y = 100;      // ��ʼ������
    int x, y, row, i;
    int press_num;
    void *background;
    unsigned int image_size;
    
    // �洢����
    image_size = imagesize(start_x, start_y, start_x + (width), start_y + ((num_description / max_per_column + 1) * (height)));
    background = malloc(image_size);
    if (background == NULL) {
        printf("malloc error!");
        return;
    }
    getimage(start_x, start_y, start_x + (width), start_y + ((num_description / max_per_column + 1) * (height)), background);

    // ���ư�ť
    for (i = 0; i < num_description; i++) {
        row = i / max_per_column;  // ���㵱ǰ�ص�ѡ�����ڵ���
        y = start_y + row * (height); // ���㰴ť��������
        x = start_x + (i % max_per_column) * width; // ���㰴ť�ĺ�����

        strcpy(description_current, description_options[i]);
        
        setfillstyle(SOLID_FILL, LIGHTGRAY);
        bar(x, y, x + width, y + height); // ���ư�ť����
        setcolor(BLACK);
        rectangle(x, y, x + width, y + height); // ���ư�ť�߿�
        puthz(x + (width - textwidth(description_current)) / 2, y + (height - textheight(description_current)) / 2, description_current, 16, 16, BLACK); // ��ʾ�ص�ѡ��
    }

    // ѡ��ص�
    while (1) {
        mou_pos(&MouseX, &MouseY, &press);

        // �ж��Ƿ�����������
        if (mouse_press(start_x, start_y, start_x + (max_per_column * width), start_y + ((num_description / max_per_column + 1) * height)) == 1) {
            // ������λ���������е�λ��
            press_num = (MouseY - start_y) / height;
            if (press_num < num_description) {
                strcpy(save_description, description_options[press_num]); // �洢ѡ�е�����
                putimage(start_x, start_y, background, COPY_PUT); // ��ԭ����
                free(background); // �ͷ��ڴ�
                exit_input();
                break;
            }
        }
    }
}
/*
�ù���Աѡ��ͷ�����
���
*/
void input_judge_punish(char *save_description)
{
	char description_options[5][19]={
		"�������ɳͷ�",
		"��ͷ����",
		"��������",
		"���¾���",
		"����"
	};
	char description_current[19];
	int num_description=5;//һ��5��ѡ��
	int max_per_column=1;//ÿ��һ��ѡ��
    int width = 200;        // ��ť���
    int height = 30;        // ��ť�߶�
    int start_x = 250;      // ��ʼ������
    int start_y = 100;      // ��ʼ������
    int x, y, row, i;
    int press_num;
    void *background;
    unsigned int image_size;
    
    // �洢����
    image_size = imagesize(start_x, start_y, start_x + (width), start_y + ((num_description / max_per_column + 1) * (height)));
    background = malloc(image_size);
    if (background == NULL) {
        printf("malloc error!");
        return;
    }
    getimage(start_x, start_y, start_x + (width), start_y + ((num_description / max_per_column + 1) * (height)), background);

    // ���ư�ť
    for (i = 0; i < num_description; i++) {
        row = i / max_per_column;  // ���㵱ǰ�ص�ѡ�����ڵ���
        y = start_y + row * (height); // ���㰴ť��������
        x = start_x + (i % max_per_column) * width; // ���㰴ť�ĺ�����

        strcpy(description_current, description_options[i]);
        
        setfillstyle(SOLID_FILL, LIGHTGRAY);
        bar(x, y, x + width, y + height); // ���ư�ť����
        setcolor(BLACK);
        rectangle(x, y, x + width, y + height); // ���ư�ť�߿�
        puthz(x + (width - textwidth(description_current)) / 2, y + (height - textheight(description_current)) / 2, description_current, 16, 16, BLACK); // ��ʾ�ص�ѡ��
    }

    // ѡ��ص�
    while (1) {
        mou_pos(&MouseX, &MouseY, &press);

        // �ж��Ƿ�����������
        if (mouse_press(start_x, start_y, start_x + (max_per_column * width), start_y + ((num_description / max_per_column + 1) * height)) == 1) {
            // ������λ���������е�λ��
            press_num = (MouseY - start_y) / height;
            if (press_num < num_description) {
                strcpy(save_description, description_options[press_num]); // �洢ѡ�е�����
                putimage(start_x, start_y, background, COPY_PUT); // ��ԭ����
                free(background); // �ͷ��ڴ�
                break;
                exit_input();
            }
        }
    }
}
/*
�ù���Աѡ��ͷ�ʱ��
���
*/
void input_judge_time(char *save_description)
{
	char description_options[5][19]={
		"�޳ͷ�ʱ��",
		"������",
		"һ������",
		"һ����",
		"����ͽ��"
	};
	char description_current[19];
	int num_description=5;//һ��5��ѡ��
	int max_per_column=1;//ÿ��һ��ѡ��
    int width = 200;        // ��ť���
    int height = 30;        // ��ť�߶�
    int start_x = 250;      // ��ʼ������
    int start_y = 100;      // ��ʼ������
    int x, y, row, i;
    int press_num;
    void *background;
    unsigned int image_size;
    
    // �洢����
    image_size = imagesize(start_x, start_y, start_x + (width), start_y + ((num_description / max_per_column + 1) * (height)));
    background = malloc(image_size);
    if (background == NULL) {
        printf("malloc error!");
        return;
    }
    getimage(start_x, start_y, start_x + (width), start_y + ((num_description / max_per_column + 1) * (height)), background);

    // ���ư�ť
    for (i = 0; i < num_description; i++) {
        row = i / max_per_column;  // ���㵱ǰ�ص�ѡ�����ڵ���
        y = start_y + row * (height); // ���㰴ť��������
        x = start_x + (i % max_per_column) * width; // ���㰴ť�ĺ�����

        strcpy(description_current, description_options[i]);
        
        setfillstyle(SOLID_FILL, LIGHTGRAY);
        bar(x, y, x + width, y + height); // ���ư�ť����
        setcolor(BLACK);
        rectangle(x, y, x + width, y + height); // ���ư�ť�߿�
        puthz(x + (width - textwidth(description_current)) / 2, y + (height - textheight(description_current)) / 2, description_current, 16, 16, BLACK); // ��ʾ�ص�ѡ��
    }

    // ѡ��ص�
    while (1) {
        mou_pos(&MouseX, &MouseY, &press);

        // �ж��Ƿ�����������
        if (mouse_press(start_x, start_y, start_x + (max_per_column * width), start_y + ((num_description / max_per_column + 1) * height)) == 1) {
            // ������λ���������е�λ��
            press_num = (MouseY - start_y) / height;
            if (press_num < num_description) {
                strcpy(save_description, description_options[press_num]); // �洢ѡ�е�����
                putimage(start_x, start_y, background, COPY_PUT); // ��ԭ����
                free(background); // �ͷ��ڴ�
                exit_input();
                break;
            }
        }
    }
}
/*
�ù���Աѡ������λ
���
*/
void input_judge_log(char *save_description)
{
	char description_options[5][19]={
		"У������",
		"��������",
		"��������Ժ",
		"�з�Ժ",
		"�й�����"
	};
	char description_current[19];
	int num_description=5;//һ��5��ѡ��
	int max_per_column=1;//ÿ��һ��ѡ��
    int width = 200;        // ��ť���
    int height = 30;        // ��ť�߶�
    int start_x = 250;      // ��ʼ������
    int start_y = 100;      // ��ʼ������
    int x, y, row, i;
    int press_num;
    void *background;
    unsigned int image_size;
    
    // �洢����
    image_size = imagesize(start_x, start_y, start_x + (width), start_y + ((num_description / max_per_column + 1) * (height)));
    background = malloc(image_size);
    if (background == NULL) {
        printf("malloc error!");
        return;
    }
    getimage(start_x, start_y, start_x + (width), start_y + ((num_description / max_per_column + 1) * (height)), background);

    // ���ư�ť
    for (i = 0; i < num_description; i++) {
        row = i / max_per_column;  // ���㵱ǰ�ص�ѡ�����ڵ���
        y = start_y + row * (height); // ���㰴ť��������
        x = start_x + (i % max_per_column) * width; // ���㰴ť�ĺ�����

        strcpy(description_current, description_options[i]);
        
        setfillstyle(SOLID_FILL, LIGHTGRAY);
        bar(x, y, x + width, y + height); // ���ư�ť����
        setcolor(BLACK);
        rectangle(x, y, x + width, y + height); // ���ư�ť�߿�
        puthz(x + (width - textwidth(description_current)) / 2, y + (height - textheight(description_current)) / 2, description_current, 16, 16, BLACK); // ��ʾ�ص�ѡ��
    }

    // ѡ��ص�
    while (1) {
        mou_pos(&MouseX, &MouseY, &press);

        // �ж��Ƿ�����������
        if (mouse_press(start_x, start_y, start_x + (max_per_column * width), start_y + ((num_description / max_per_column + 1) * height)) == 1) {
            // ������λ���������е�λ��
            press_num = (MouseY - start_y) / height;
            if (press_num < num_description) {
                strcpy(save_description, description_options[press_num]); // �洢ѡ�е�����
                putimage(start_x, start_y, background, COPY_PUT); // ��ԭ����
                free(background); // �ͷ��ڴ�
                exit_input();
                break;
            }
        }
    }
}

/*
���ܣ����û�ѡ������1�Σ����ҽ��������浽ָ������
��� 
*/
void input_feedback1(char *save_description)
{
	char description_options[5][19]={
		"����һ",
		"������",
		"������",
		"������",
		"������"
	};
	char description_current[19];
	int num_description=5;//һ��5��ѡ��
	int max_per_column=1;//ÿ��һ��ѡ��
    int width = 200;        // ��ť���
    int height = 30;        // ��ť�߶�
    int start_x = 250;      // ��ʼ������
    int start_y = 100;      // ��ʼ������
    int x, y, row, i;
    int press_num;
    void *background;
    unsigned int image_size;
    
    // �洢����
    image_size = imagesize(start_x, start_y, start_x + (width), start_y + ((num_description / max_per_column + 1) * (height)));
    background = malloc(image_size);
    if (background == NULL) {
        printf("malloc error!");
        return;
    }
    getimage(start_x, start_y, start_x + (width), start_y + ((num_description / max_per_column + 1) * (height)), background);

    // ���ư�ť
    for (i = 0; i < num_description; i++) {
        row = i / max_per_column;  // ���㵱ǰ�ص�ѡ�����ڵ���
        y = start_y + row * (height); // ���㰴ť��������
        x = start_x + (i % max_per_column) * width; // ���㰴ť�ĺ�����

        strcpy(description_current, description_options[i]);
        
        setfillstyle(SOLID_FILL, LIGHTGRAY);
        bar(x, y, x + width, y + height); // ���ư�ť����
        setcolor(BLACK);
        rectangle(x, y, x + width, y + height); // ���ư�ť�߿�
        puthz(x + (width - textwidth(description_current)) / 2, y + (height - textheight(description_current)) / 2, description_current, 16, 16, BLACK); // ��ʾ�ص�ѡ��
    }

    // ѡ��ص�
    while (1) {
        mou_pos(&MouseX, &MouseY, &press);

        // �ж��Ƿ�����������
        if (mouse_press(start_x, start_y, start_x + (max_per_column * width), start_y + ((num_description / max_per_column + 1) * height)) == 1) {
            // ������λ���������е�λ��
            press_num = (MouseY - start_y) / height;
            if (press_num < num_description) {
                strcpy(save_description, description_options[press_num]); // �洢ѡ�е�����
                putimage(start_x, start_y, background, COPY_PUT); // ��ԭ����
                free(background); // �ͷ��ڴ�
                exit_input();
                break;
            }
        }
    }
}


/*
���ܣ����û�ѡ������2�Σ����ҽ��������浽ָ������
��� 
*/
void input_feedback2(char *save_description)
{
	char description_options[5][19]={
		"����һ",
		"������",
		"������",
		"������",
		"������"
	};
	char description_current[19];
	int num_description=5;//һ��5��ѡ��
	int max_per_column=1;//ÿ��һ��ѡ��
    int width = 200;        // ��ť���
    int height = 30;        // ��ť�߶�
    int start_x = 250;      // ��ʼ������
    int start_y = 100;      // ��ʼ������
    int x, y, row, i;
    int press_num;
    void *background;
    unsigned int image_size;
    
    // �洢����
    image_size = imagesize(start_x, start_y, start_x + (width), start_y + ((num_description / max_per_column + 1) * (height)));
    background = malloc(image_size);
    if (background == NULL) {
        printf("malloc error!");
        return;
    }
    getimage(start_x, start_y, start_x + (width), start_y + ((num_description / max_per_column + 1) * (height)), background);

    // ���ư�ť
    for (i = 0; i < num_description; i++) {
        row = i / max_per_column;  // ���㵱ǰ�ص�ѡ�����ڵ���
        y = start_y + row * (height); // ���㰴ť��������
        x = start_x + (i % max_per_column) * width; // ���㰴ť�ĺ�����

        strcpy(description_current, description_options[i]);
        
        setfillstyle(SOLID_FILL, LIGHTGRAY);
        bar(x, y, x + width, y + height); // ���ư�ť����
        setcolor(BLACK);
        rectangle(x, y, x + width, y + height); // ���ư�ť�߿�
        puthz(x + (width - textwidth(description_current)) / 2, y + (height - textheight(description_current)) / 2, description_current, 16, 16, BLACK); // ��ʾ�ص�ѡ��
    }

    // ѡ��ص�
    while (1) {
        mou_pos(&MouseX, &MouseY, &press);

        // �ж��Ƿ�����������
        if (mouse_press(start_x, start_y, start_x + (max_per_column * width), start_y + ((num_description / max_per_column + 1) * height)) == 1) {
            // ������λ���������е�λ��
            press_num = (MouseY - start_y) / height;
            if (press_num < num_description) {
                strcpy(save_description, description_options[press_num]); // �洢ѡ�е�����
                putimage(start_x, start_y, background, COPY_PUT); // ��ԭ����
                free(background); // �ͷ��ڴ�
                exit_input();
                break;
            }
        }
    }
}

/*
���ܣ����û�ѡ������3�Σ����ҽ��������浽ָ������
��� 
*/
void input_feedback3(char *save_description)
{
	char description_options[5][19]={
		"����һ",
		"������",
		"������",
		"������",
		"������"
	};
	char description_current[19];
	int num_description=5;//һ��5��ѡ��
	int max_per_column=1;//ÿ��һ��ѡ��
    int width = 200;        // ��ť���
    int height = 30;        // ��ť�߶�
    int start_x = 250;      // ��ʼ������
    int start_y = 100;      // ��ʼ������
    int x, y, row, i;
    int press_num;
    void *background;
    unsigned int image_size;
    
    // �洢����
    image_size = imagesize(start_x, start_y, start_x + (width), start_y + ((num_description / max_per_column + 1) * (height)));
    background = malloc(image_size);
    if (background == NULL) {
        printf("malloc error!");
        return;
    }
    getimage(start_x, start_y, start_x + (width), start_y + ((num_description / max_per_column + 1) * (height)), background);

    // ���ư�ť
    for (i = 0; i < num_description; i++) {
        row = i / max_per_column;  // ���㵱ǰ�ص�ѡ�����ڵ���
        y = start_y + row * (height); // ���㰴ť��������
        x = start_x + (i % max_per_column) * width; // ���㰴ť�ĺ�����

        strcpy(description_current, description_options[i]);
        
        setfillstyle(SOLID_FILL, LIGHTGRAY);
        bar(x, y, x + width, y + height); // ���ư�ť����
        setcolor(BLACK);
        rectangle(x, y, x + width, y + height); // ���ư�ť�߿�
        puthz(x + (width - textwidth(description_current)) / 2, y + (height - textheight(description_current)) / 2, description_current, 16, 16, BLACK); // ��ʾ�ص�ѡ��
    }

    // ѡ��ص�
    while (1) {
        mou_pos(&MouseX, &MouseY, &press);

        // �ж��Ƿ�����������
        if (mouse_press(start_x, start_y, start_x + (max_per_column * width), start_y + ((num_description / max_per_column + 1) * height)) == 1) {
            // ������λ���������е�λ��
            press_num = (MouseY - start_y) / height;
            if (press_num < num_description) {
                strcpy(save_description, description_options[press_num]); // �洢ѡ�е�����
                putimage(start_x, start_y, background, COPY_PUT); // ��ԭ����
                free(background); // �ͷ��ڴ�
                exit_input();
                break;
            }
        }
    }
}

/*
���ܣ����û�ѡ������4�Σ����ҽ��������浽ָ������
��� 
*/
void input_feedback4(char *save_description)
{
	char description_options[5][19]={
		"����һ",
		"������",
		"������",
		"������",
		"������"
	};
	char description_current[19];
	int num_description=5;//һ��5��ѡ��
	int max_per_column=1;//ÿ��һ��ѡ��
    int width = 200;        // ��ť���
    int height = 30;        // ��ť�߶�
    int start_x = 250;      // ��ʼ������
    int start_y = 100;      // ��ʼ������
    int x, y, row, i;
    int press_num;
    void *background;
    unsigned int image_size;
    
    // �洢����
    image_size = imagesize(start_x, start_y, start_x + (width), start_y + ((num_description / max_per_column + 1) * (height)));
    background = malloc(image_size);
    if (background == NULL) {
        printf("malloc error!");
        return;
    }
    getimage(start_x, start_y, start_x + (width), start_y + ((num_description / max_per_column + 1) * (height)), background);

    // ���ư�ť
    for (i = 0; i < num_description; i++) {
        row = i / max_per_column;  // ���㵱ǰ�ص�ѡ�����ڵ���
        y = start_y + row * (height); // ���㰴ť��������
        x = start_x + (i % max_per_column) * width; // ���㰴ť�ĺ�����

        strcpy(description_current, description_options[i]);
        
        setfillstyle(SOLID_FILL, LIGHTGRAY);
        bar(x, y, x + width, y + height); // ���ư�ť����
        setcolor(BLACK);
        rectangle(x, y, x + width, y + height); // ���ư�ť�߿�
        puthz(x + (width - textwidth(description_current)) / 2, y + (height - textheight(description_current)) / 2, description_current, 16, 16, BLACK); // ��ʾ�ص�ѡ��
    }

    // ѡ��ص�
    while (1) {
        mou_pos(&MouseX, &MouseY, &press);

        // �ж��Ƿ�����������
        if (mouse_press(start_x, start_y, start_x + (max_per_column * width), start_y + ((num_description / max_per_column + 1) * height)) == 1) {
            // ������λ���������е�λ��
            press_num = (MouseY - start_y) / height;
            if (press_num < num_description) {
                strcpy(save_description, description_options[press_num]); // �洢ѡ�е�����
                putimage(start_x, start_y, background, COPY_PUT); // ��ԭ����
                free(background); // �ͷ��ڴ�
                exit_input();
                break;
            }
        }
    }
}



















