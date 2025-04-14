#ifndef _VERIFY_
#define _VERIFY_
#include "manage.h"
// ������Ϣ�ṹ�壺һ����������һ������
typedef struct {
    char province[3];    // ����ʡ�ݴ��루���� 'a' ��ʾ������
    char plate[7];   // ʣ��ĳ��ƺ��루�� "A12345"��
    char type[7];        // ��������(��С�γ�,����)
} CarInfo;

// �綯����Ϣ�ṹ�壺һ����������һ���綯����Ҫ��ͬʱ��¼���ֳ���
typedef struct {
    char campus_plate[11]; // У԰���ƣ����Ƴ�������A26 075038)
    char wuhan_plate[10];  // �人�綯���ƣ����� D 7931)
} EBikeInfo;

// ������Ϣ�ṹ�壺�洢���˻�����Ϣ�ͳ�����Ϣ
typedef struct {
    char username[21];               // �û���
    char phone[12];                   //�ֻ���
    char password[21];               //����
    char idcard[21];                 // ���֤�ţ�18λ����+��������
    char student_id[21];             // ѧ��
    char driver_license_type[13];    // ��ʻ֤���ͣ��� "C1"��"B2" ��
    char driver_license_validity[21];// ��ʻ֤��Ч�ڣ����� "2025��12��31"
    CarInfo car;                     // ������Ϣ������һ����
    EBikeInfo ebike;                 // �綯����Ϣ������һ����
} User;

typedef struct {
    char account[20];
    char password[20];
    // �����������Ϣ������Ҫ��
} Admin;


// �¹���Ϣ�ṹ�壺���������¹������Ϣ
typedef struct {
    char per1_idcard[21];
    char per2_idcard[21];
    char per1_phone[12];
    char per2_phone[12];
    CarInfo per1_car;
    CarInfo per2_car;
    EBikeInfo per1_ebike;
    EBikeInfo per2_ebike;
    char location[17];           // �¹ʷ����ص�
    char weather[7];             // �¹ʷ���ʱ������
    char time[17];                // �¹ʷ���ʱ�䣬��ȷ�����ӣ����磺"2025��05��10 14:30"
    char accident_type;           // �¹����ʹ��루���� 'A' ��ʾ "�ˡ����¹�"��'B' ��ʾ "�������¹�"��
    char per1_destroied_part [9];
    char per2_destroied_part[9];      //����λ
    //char description[255];       (��������֤�����¹�˵������Ϣ)
    char processed_status;       // ����״̬��'0' ��ʾδ����'1' ��ʾ�Ѵ���
    char liability_result[20];   // �����϶�������� "����", "����", "ͬ��", "����"
    char liability_ratio[10];      // ���α��������� "80/20" �� "50%"
    char description1[10];       //֤�ʵ�һ��
    char description2[10];       //֤�ʵڶ���
    char description3[10];       //֤�ʵ�����
    char description4[10];       //֤�ʵ��Ķ�
    char evidence_per1[7];		//֤��1 
    char evidence_per2[7];		//֤��2 
    char photo1;//֤��ͼƬ1
    char photo2;
    char photo3;
    char photo4;
    Judge judge;
} AccidentInfo;
// ӳ���¹�������ĸ��ʵ������
/*const char accident_type_desc[5][20] = {
    "�ˡ��綯���¹�", // 'A'
    "�ˡ������¹�", // 'B'
    "�綯�����綯���¹�", // 'C'
    "�綯��������" // 'D' 
    "����������"//'E'��(��������չ���迼�ǡ��ˡ������С����������Ƿ�Գ�)
};
const char accident_type_char[5] = {
    'A','B','C','D','E'
    }
*/

int len_verify(char *s,int min,int max);//��֤�ַ��������Ƿ���Ϲ涨���Ϲ�ʱ����1�����Ϲ淵��-1
// ��֤�ֻ����Ƿ����Ҫ��11λ���֣�
int validate_phone(const char *phone);
// ��֤���֤���Ƿ����Ҫ��18λ���֣�
int validate_idcard(const char *idcard);
// ��֤�����Ƿ����Ҫ������8λ���������֡���д��ĸ��Сд��ĸ�ͷ����е����֣�
int validate_password(const char *password);
//��֤�����Ƿ����Ҫ��
int validate_licence_car(const char *plate);
#endif