#include"webSever.h"
#include<iostream>

using namespace std;

bool ini_list(TimeoutSqlist &L) {//初始化顺序表
	cout << "list初始化......\n" << endl;
	L.elem = new ConnTime_out[MAX_SIZE];
	if (!L.elem) {
		cout << "list初始化失败!" << endl;
		return false;
	}
	else {
		L.length = 0;
		L.size = MAX_SIZE;
		cout << "list初始化成功!" << endl;
		return true;
	}
}

bool Append_list(TimeoutSqlist &L,ConnTime_out add_elem) {//顺序表数据输入
	if (!L.elem) {
		cout << "\nlist未进行初始化,list数据输入失败!\n";
		return false;
	}
	if (L.length == L.size) {
		cout << "\nlist已满!添加数据失败!\n";
		return false;
	}
	L.elem[L.length] = add_elem;
	L.length++;
	return true;
}

bool List_Delete(TimeoutSqlist &L, int pos) {
	if (!L.elem) {
		cout << "\nlist未进行初始化,list删除节点失败!\n";
		return false;
	}
	if (pos < 0 || pos >= L.length) {
		cout << "\n删除数据失败!可删除节点位置在0~" << L.length - 1 << endl;
		return false;
	}
	if (L.length == 0) {
		cout << "\nlist为空!\n";
		return false;
	}
	for (int j = pos; j < L.length - 1; j++) {
		L.elem[j] = L.elem[j + 1];
	}
	L.length--;
	return true;
}

bool destroy_list(TimeoutSqlist &L) {//删除顺序表
	if (!L.elem) {
		cout << "\nlist未进行初始化,list删除失败!\n";
		return false;
	}
	delete[]L.elem;
	L.length = 0;
	L.size = 0;
	cout << "\n\nlist删除成功!\n";
	return true;
}

bool print_list(TimeoutSqlist &L) {//打印顺序表
	if (!L.elem) {
		cout << "\nlist未进行初始化,list打印失败!\n";
		return false;
	}
	if (L.length <= 0) {
		cout << "\nlist为空,无需打印!\n";
		return false;
	}
	cout << "\n当前:容量" << L.size << "  已存的元素个数:" << L.length<<"\n\n";
	for (int i = 0; i < L.length; i++) {
		cout << "fd:" << L.elem[i].fd << "   time_out:" << L.elem[i].time_out<<"\n\n";
	}
	return true;
}
