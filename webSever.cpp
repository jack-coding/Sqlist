#include<iostream>
#include<Windows.h>
#include"webSever.h"

using namespace std;

static void Cheak_timeout(TimeoutSqlist &L, time_t pos);
int main(void) {
	time_t now,end,last_timeout;
	TimeoutSqlist list;

	time(&now);
	end = now + 35;
	last_timeout = now;
	ini_list(list);
	for (int i = 0; i < num; i++) {
		ConnTime_out temp;
		temp.fd = i;
		temp.time_out = now + 5 + 2 * i;
		Append_list(list, temp);
	}
	print_list(list);

	do {
		if (last_timeout + time_interval < now) {
			Cheak_timeout(list, now);
			last_timeout = now;
		}
		Sleep(10);
		time(&now);
	} while (now<end);
	destroy_list(list);
	system("pause");
	return 0;
}
static void Cheak_timeout(TimeoutSqlist &L, time_t now) {
	cout << "检测超时fd......\n";
	for (int i = 0; i < L.length; i++) {
		if (L.elem[i].time_out > now) {
			continue;
		}
		cout << "连接fd=[" << L.elem[i].fd << "]超时,关闭连接!\n";
		List_Delete(L, i);
		i--;
	}
}