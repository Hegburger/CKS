#ifndef _INPUT_H_
#define _INPUT_H_

void input_str(int x, int y, char *save_str, int font ,int size,int num_max);

void input_province(char *save_province);

void input_weather(char *save_weather);

void input_accident_type(char *save_accident_type);

void put_accident_type(char type,int x, int y, int flag, int part, int color);

void input_location(char *save_location);

void input_car_type(char *save_car_type);

void input_time(int x, int y, char *save_str, int font ,int size);

void input_password(int x, int y, char *save_str, int font ,int size,int num_max);

void input_destroy_part(char *save_des_type);
#endif