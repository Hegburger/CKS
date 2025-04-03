#include"common.h"
#include<ctype.h>
/*
fincion:楠岃瘉瀛楃涓查暱搴︽槸鍚︾鍚堣瀹氥�?
鍚堣鏃惰繑鍥?1锛屼笉鍚堣杩斿洖-1
author:CHENGKAI HUANG
*/

int len_verify(const char *s,int len_min,int len_max){
    int len = strlen(s);
    if(len >= len_min && len <=len_max){
        return 1;
    }else{
        return -1;
    }
}

// 楠岃瘉鎵嬫満鍙锋槸鍚︾鍚堣姹傦紙11浣嶆暟瀛楋級author:CHENGKAI HUANG
int validate_phone(const char *phone) {
    int i;
    if (strlen(phone) != 11) {
        return -1;
    }
    for (i = 0; i < 11; i++) {
        if (!isdigit(phone[i])) {
            return -1;
        }
    }
    return 1;
}

// 楠岃瘉韬唤璇佸彿鏄惁绗﹀悎瑕佹眰锛?18浣嶆暟瀛楋級author:CHENGKAI HUANG
int validate_idcard(const char *idcard) {
    int i;
    if (strlen(idcard) != 18) {
        return -1;
    }
    for (i = 0; i < 18; i++) {
        if (!isdigit(idcard[i])) {
            return -1;
        }
    }
    return 1;
}

// 楠岃瘉瀵嗙爜鏄惁绗﹀悎瑕佹眰锛堣嚦灏?8浣嶏紝鍖呮嫭鏁板瓧銆佸ぇ鍐欏瓧姣嶃�佸皬鍐欏瓧姣嶅拰绗﹀彿涓殑涓夌锛?
//author:CHENGKAI HUANG
int validate_password(const char *password) {
    int has_digit ;
    int has_lower;
    int has_upper;
    int has_special ;
    int type_count;
    int len,i;
    len = strlen(password);
    if (len < 8) {
        return -1; // 瀵嗙爜闀垮害鑷冲皯 8 浣?
    }

    has_digit = 0;
    has_lower = 0;
    has_upper = 0;
    has_special = 0;

    for (i = 0; i < len; i++) {
        if (isdigit(password[i])) {
            has_digit = 1;
        } else if (islower(password[i])) {
            has_lower = 1;
        } else if (isupper(password[i])) {
            has_upper = 1;
        } else if (ispunct(password[i])) {  // 鍒ゆ柇绗﹀彿
            has_special = 1;
        }
    }
    type_count = has_digit + has_lower + has_upper + has_special;
    if(type_count>=3){
        return 1;
    }else{
        return -1;
    }
}

//author:CHENGKAI HUANG
int validate_licence_car(const char *plate) {
    int i;

    // 车牌号长度应该为6
    if (strlen(plate) != 6) {
        return -1;
    }
    // 第一个字符是字母
    if ((!isupper(plate[0]))&&(!islower(plate[0]))) {
        return -1;
    }
    // 后面的五个字符可以是字母或数字
    for (i = 1; i < 6; i++) {
        if (!isalnum(plate[i])) {
            return -1;
        }
    }
    return 1; // 验证通过
}


//验证学号是否符合要求（一共10位，第一位是U）author:Peng Jian
int validate_student_id(const char *student_id)
{
    int len,i;
    len=strlen(student_id);
    if(len!=10)
    {
        return -1;//学号必须10位 
    }
    if(student_id[0]!='U')
    {
        return -1;//首位必须是U 
    }
    for(i=1;i<10;i++)
    {
        if(!isdigit(student_id[i]))
        {
            return -1;//后面的都要是数字 
        }
    } 
    return 1;
}