#include"verify.h"
#ifndef BAOAN_1
#define BAOAN_1
int baoan();
void baoan_1_screen();
void draw_triangle(int x,int y,int blank_width);
void baoan_1_click(AccidentInfo *p,int *page);
void baoan_2_click(AccidentInfo *p,int *page);
void baoan_2_screen();
int verify_baoan_1(AccidentInfo *p);
int verify_baoan_2(AccidentInfo *p);
#endif