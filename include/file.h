#include"verify.h"
#ifndef _FILE_PROCESS_
#define _FILE_PROCESS_

int save_accident_info(AccidentInfo *incident);
int match(AccidentInfo *rec, const char *date_filter, char type_filter, char status_filter,const char *id_card);
int match_user(char *phone_number, User *x);
int addInfo_user(char *phone_number, User *add);
#endif