#include"common.h"
#include"verify.h"
/*
function:存储事故信息,成功返回1，否则返回-1
author: CHENGKAI HUANG
time:2025/3/9
*/
int save_accident_info(AccidentInfo *incident) {
    FILE *fp = fopen("ACCIDENT.dat", "ab"); // 追加二进制模式打开文件
    if (fp == NULL) {
        puthz(310,200,"数据库打开失败",16,16,RED); 
        return -1;
    }
    fwrite(incident, sizeof(AccidentInfo), 1, fp);
    fclose(fp);
    printf("事故信息保存成功！\n");
    return 1;
}