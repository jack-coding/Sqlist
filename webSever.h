#ifndef _webSever_H
#define _webSever_H

#define MAX_SIZE 100
#define num 10
#define time_interval 0.999
#include<time.h>

typedef struct {
	int fd;
	time_t time_out;
}ConnTime_out;

typedef struct {
	ConnTime_out *elem;
	int length;//˳���Ԫ�ظ���
	int size;//˳���ռ��С
}TimeoutSqlist;

bool ini_list(TimeoutSqlist &L);
bool Append_list(TimeoutSqlist &L, ConnTime_out add_elem);
bool List_Delete(TimeoutSqlist &L, int pos);
bool destroy_list(TimeoutSqlist &L);
bool print_list(TimeoutSqlist &L);

#endif 

