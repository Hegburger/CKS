#ifndef _VERIFY_
#define _VERIFY_
// 汽车信息结构体：一个人至多有一辆汽车
typedef struct {
    char province[3];    // 车牌省份代码（例如 'a' 表示北京）
    char plate[7];   // 剩余的车牌号码（如 "A12345"）
    char type[7];        // 汽车类型(如小轿车,卡车)
} CarInfo;

// 电动车信息结构体：一个人至多有一辆电动车，要求同时记录两种车牌
typedef struct {
    char campus_plate[11]; // 校园车牌（华科车牌例子A26 075038)
    char wuhan_plate[10];  // 武汉电动车牌（例子 D 7931)
} EBikeInfo;

// 个人信息结构体：存储个人基本信息和车辆信息
typedef struct {
    char username[21];               // 用户名
    char phone[21];                   //手机号
    char password[21];               //密码
    char idcard[21];                 // 身份证号（18位数字+结束符）
    char student_id[21];             // 学号
    char driver_license_type[13];    // 驾驶证类型，如 "C1"、"B2" 等
    char driver_license_validity[21];// 驾驶证有效期，例如 "2025—12—31"
    CarInfo car;                     // 汽车信息（至多一辆）
    EBikeInfo ebike;                 // 电动车信息（至多一辆）
} User;


// 事故信息结构体：包含所有事故相关信息
typedef struct {
    User per1;            // 事故的第一方（可能是人、汽车或电动车）
    User per2;            // 事故的第二方（可能是人、汽车或电动车）
    char location[17];           // 事故发生地点
    char weather[7];             // 事故发生时的天气
    char time[21];                // 事故发生时间，精确到分钟，例如："2025—05—10 14:30"
    char accident_type;           // 事故类型代码（例如 'A' 表示 "人—车事故"，'B' 表示 "车—车事故"）
    //char description[255];       (后续考虑证词与事故说明等信息)
} AccidentInfo;

// 映射事故类型字母和实际描述
/*const char accident_type_desc[5][20] = {
    "人—电动车事故", // 'A'
    "人—汽车事故", // 'B'
    "电动车—电动车事故", // 'C'
    "电动车—汽车" // 'D' 
    "汽车—汽车"//'E'等(后续可拓展，需考虑“人—车”中“—”两边是否对称)
};
const char accident_type_char[5] = {
    'A','B','C','D','E'
    }
*/

int len_verify(char *s,int min,int max);//验证字符串长度是否符合规定。合规时返回1，不合规返回-1
// 验证手机号是否符合要求（11位数字）
int validate_phone(const char *phone);
// 验证身份证号是否符合要求（18位数字）
int validate_idcard(const char *idcard);
// 验证密码是否符合要求（至少8位，包括数字、大写字母、小写字母和符号中的三种）
int validate_password(const char *password);

#endif