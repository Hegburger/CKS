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