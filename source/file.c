#include"common.h"
#include"verify.h"
/*
function:�洢�¹���Ϣ,�ɹ�����1�����򷵻�-1
author: CHENGKAI HUANG
time:2025/3/9
*/
int save_accident_info(AccidentInfo *incident) {
    FILE *fp = fopen("ACCIDENT.dat", "ab"); // ׷�Ӷ�����ģʽ���ļ�
    if (fp == NULL) {
        puthz(310,200,"���ݿ��ʧ��",16,16,RED); 
        return -1;
    }
    fwrite(incident, sizeof(AccidentInfo), 1, fp);
    fclose(fp);
    printf("�¹���Ϣ����ɹ���\n");
    return 1;
}
/*
function:���������ķ���1�����򷵻�0.����Ҫ��ѯ����NULL
author: CHENGKAI HUANG
time:2025/3/20
*/
int match(AccidentInfo *rec, const char *date_filter, char type_filter, char status_filter,const char *id_card) {
    // ���ڹ��ˣ���� date_filter �ǿգ����� rec->time ���Ƿ�����������ַ���
    if (date_filter[0] != '\0' && strstr(rec->time, date_filter) == NULL) {
        return 0;
    }
    // �¹����͹��ˣ���� type_filter ��Ϊnull����������
    if (type_filter != NULL && rec->accident_type != type_filter) {
        return 0;
    }
    // ����״̬���ˣ���� status_filter ��Ϊnull����������
    if (status_filter != NULL && rec->processed_status != status_filter) {
        return 0;
    }

    //idcard����
    if(id_card[0]!='\0' && strstr(rec->per1_idcard,id_card) ==NULL && strstr(rec->per2_idcard,id_card)==NULL){
        return 0;
    }
    return 1;
}
/*
function:�����ֻ���Ѱ���û����з��������ĸ���xΪ���û���Ϣ������1�����򷵻�-1
author: CHENGKAI HUANG
time:2025/3/30
*/
int match_user(char *phone_number, User *x){
    FILE *fp;
    int result = -1;
    if ((fp = fopen("list.dat", "rb")) == NULL) {
        puthz(310, 600, "���ݿ��ʧ��", 24, 24, RED);
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
function:�����ֻ���Ѱ���û�������add��user��Ϣ����ԭ�û���Ϣ(�޸����ݿ�),�ɹ�
�򷵻�1�������ݿ�ʧ�ܷ���-1��δƥ�䵽����0
author: CHENGKAI HUANG
time:2025/3/30
*/
int addInfo_user(char *phone_number, User *add){
    FILE *fp;
    int result = 0;
    User x;//  ���ڱ���
    int validation = 1;
    long size;
    size = (long)sizeof(User);
    if((fp = fopen("list.dat", "rb+"))==NULL){
        puthz(310, 600, "���ݿ��ʧ��", 24, 24, RED);
        result = -1;
    }else{
        while(fread(&x,sizeof(User),1,fp)){
            if(strcmp(phone_number,x.phone)==0){
                validation = fseek(fp,-size,SEEK_CUR);
                if(validation != 0){
                    puthz(300,400,"Ѱַ����",16,16,RED);
                    result = -1;
                    break;
                }
                result = 1;
                fwrite(add,sizeof(User),1,fp);//д��
                break;
            }
        }
    }
    fclose(fp);
    return result;
}