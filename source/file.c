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
/*
function:符合条件的返回1，否则返回0.不需要查询的用NULL
author: CHENGKAI HUANG
time:2025/3/20
*/
int match(AccidentInfo *rec, const char *date_filter, char type_filter, char status_filter,const char *id_card) {
    // 日期过滤：如果 date_filter 非空，则检查 rec->time 中是否包含该日期字符串
    if (date_filter[0] != '\0' && strstr(rec->time, date_filter) == NULL) {
        return 0;
    }
    // 事故类型过滤：如果 type_filter 不为null，则必须相等
    if (type_filter != NULL && rec->accident_type != type_filter) {
        return 0;
    }
    // 处理状态过滤：如果 status_filter 不为null，则必须相等
    if (status_filter != NULL && rec->processed_status != status_filter) {
        return 0;
    }

    //idcard过滤
    if(id_card[0]!='\0' && strstr(rec->per1_idcard,id_card) ==NULL && strstr(rec->per2_idcard,id_card)==NULL){
        return 0;
    }
    return 1;
}
/*
function:根据手机号寻找用户，有符合条件的更改x为该用户信息并返回1，否则返回-1
author: CHENGKAI HUANG
time:2025/3/30
*/
int match_user(char *phone_number, User *x){
    FILE *fp;
    int result = -1;
    if ((fp = fopen("list.dat", "rb")) == NULL) {
        puthz(310, 600, "数据库打开失败", 24, 24, RED);
    }else{
        while (fread(x, sizeof(User), 1, fp)) {
            if (strcmp(phone_number,x->phone) == 0){
                result = 1;
                break;
            }
        }
        fclose(fp);
    } 
    return result;
}
/*
function:根据手机号寻找用户，并将add中user信息覆盖原用户信息(修改数据库),成功
则返回1，打开数据库失败返回-1，未匹配到返回0
author: CHENGKAI HUANG
time:2025/3/30
*/
int addInfo_user(char *phone_number, User *add){
    FILE *fp;
    int result = 0;
    User x;//  用于遍历
    int validation = 1;
    long size;
    size = (long)sizeof(User);
    if((fp = fopen("list.dat", "rb+"))==NULL){
        puthz(310, 600, "数据库打开失败", 24, 24, RED);
        result = -1;
    }else{
        while(fread(&x,sizeof(User),1,fp)){
            if(strcmp(phone_number,x.phone)==0){
                validation = fseek(fp,-size,SEEK_CUR);
                if(validation != 0){
                    puthz(300,400,"寻址错误",16,16,RED);
                    result = -1;
                    break;
                }
                result = 1;
                fwrite(add,sizeof(User),1,fp);//写入
                break;
            }
        }
    }
    fclose(fp);
    return result;
}