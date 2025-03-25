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