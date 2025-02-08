#ifndef _VERIFY_
#define _VERIFY_
typedef struct 
{
    char phone[20];
    char id[20];
    char name[20];
    char password[20];
}user;

int len_verify(char *s,int min,int max);//验证字符串长度是否符合规定。合规时返回1，不合规返回-1
// 验证手机号是否符合要求（11位数字）
int validate_phone(const char *phone);
// 验证身份证号是否符合要求（18位数字）
int validate_idcard(const char *idcard);
// 验证密码是否符合要求（至少8位，包括数字、大写字母、小写字母和符号中的三种）
int validate_password(const char *password);

#endif