#include"common.h"
#include<ctype.h>
/*
fincion:验证字符串长度是否符合规定。
合规时返回1，不合规返回-1
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

// 验证手机号是否符合要求（11位数字）
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

// 验证身份证号是否符合要求（18位数字）
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

// 验证密码是否符合要求（至少8位，包括数字、大写字母、小写字母和符号中的三种）
int validate_password(const char *password) {
    int has_digit ;
    int has_lower;
    int has_upper;
    int has_special ;
    int type_count;
    int len,i;
    len = strlen(password);
    if (len < 8) {
        return -1; // 密码长度至少 8 位
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
        } else if (ispunct(password[i])) {  // 判断符号
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