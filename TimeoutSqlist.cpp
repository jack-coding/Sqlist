#include"webSever.h"
#include<iostream>

using namespace std;

bool ini_list(TimeoutSqlist &L) {//��ʼ��˳���
	cout << "list��ʼ��......\n" << endl;
	L.elem = new ConnTime_out[MAX_SIZE];
	if (!L.elem) {
		cout << "list��ʼ��ʧ��!" << endl;
		return false;
	}
	else {
		L.length = 0;
		L.size = MAX_SIZE;
		cout << "list��ʼ���ɹ�!" << endl;
		return true;
	}
}
bool Append_list(TimeoutSqlist &L,ConnTime_out add_elem) {//˳�����������
	if (!L.elem) {
		cout << "\nlistδ���г�ʼ��,list��������ʧ��!\n";
		return false;
	}
	if (L.length == L.size) {
		cout << "\nlist����!�������ʧ��!\n";
		return false;
	}
	L.elem[L.length] = add_elem;
	L.length++;
	return true;
}
bool List_Delete(TimeoutSqlist &L, int pos) {
	if (!L.elem) {
		cout << "\nlistδ���г�ʼ��,listɾ���ڵ�ʧ��!\n";
		return false;
	}
	if (pos < 0 || pos >= L.length) {
		cout << "\nɾ������ʧ��!��ɾ���ڵ�λ����0~" << L.length - 1 << endl;
		return false;
	}
	if (L.length == 0) {
		cout << "\nlistΪ��!\n";
		return false;
	}
	for (int j = pos; j < L.length - 1; j++) {
		L.elem[j] = L.elem[j + 1];
	}
	L.length--;
	return true;
}
bool destroy_list(TimeoutSqlist &L) {//ɾ��˳���
	if (!L.elem) {
		cout << "\nlistδ���г�ʼ��,listɾ��ʧ��!\n";
		return false;
	}
	delete[]L.elem;
	L.length = 0;
	L.size = 0;
	cout << "\n\nlistɾ���ɹ�!\n";
	return true;
}
bool print_list(TimeoutSqlist &L) {//��ӡ˳���
	if (!L.elem) {
		cout << "\nlistδ���г�ʼ��,list��ӡʧ��!\n";
		return false;
	}
	if (L.length <= 0) {
		cout << "\nlistΪ��,�����ӡ!\n";
		return false;
	}
	cout << "\n��ǰ:����" << L.size << "  �Ѵ��Ԫ�ظ���:" << L.length<<"\n\n";
	for (int i = 0; i < L.length; i++) {
		cout << "fd:" << L.elem[i].fd << "   time_out:" << L.elem[i].time_out<<"\n\n";
	}
	return true;
}