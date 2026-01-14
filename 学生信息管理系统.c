#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<Windows.h>

#include "studentManager.h"


int main() {

	List list = { 0 };
	memset(&list, 0, sizeof(list));
	while (true) {
		switch (menu()) {
		case Quit:
			printf("Quit\n");
			return 0;
		case Entry:
			EntryStudent(&list);
			break;
		case Print:
			PrintStudent(&list);
			break;
		case Save:
			break;
		case Read:
			break;
		case Modify:
			break;
		case Add:
			break;
		case Delete:
			break;
		case Find:
			break;
		case Statistics:
			break;
		case Sort:
			break;
		default:
			printf("无效选择!!!\n");
			break;
	}
	

		system("pause");
	}

	return 0;
}