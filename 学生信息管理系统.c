#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<Windows.h>

#include "studentManager.h"


int main() {
	int need = 0;
	List list = { 0 };
	memset(&list, 0, sizeof(list));
	ReadStudent(&list);
	while (true) {
		switch (menu()) {
		case Quit:
			if (need) {
				printf("刚进行了信息修改还未保存，是否保存?(1 / 0)\n");
				printf(">");
				int c;
				scanf("%d", &c);
				if (c == 1) {
					SaveStudent(&list);
					printf("保存成功!\n");
				}
			}
			printf("Quit!\n");
			return 0;
		case Entry:
			EntryStudent(&list);
			printf("录入成功!");
			need = 1;
			break;
		case Print:
			PrintStudent(&list);
			break;
		case Save:
			SaveStudent(&list);
			printf("保存成功!\n");
			need = 0;
			break;
		case Read:
			ReadStudent(&list);
			printf("读取成功!\n");
			break;
		case Modify:
			ModifyStudent(&list);
			need = 1;
			break;
		case Add:
			break;
		case Delete:
			DeleteStudent(&list);
			need = 1;
			break;
		case Find:
		{
			Node* node = FindStudent(&list);
			if (!node)printf("没有找到要查询的学生\n");
			else {
				printf("学号>%llu\n",node->stu.id);
				printf("姓名>%s\n", node->stu.name);
				printf("姓别>%s\n", node->stu.sex);
				printf("语文成绩>%.2f\n", node->stu.chinese);
				printf("数学成绩>%.2f\n", node->stu.math);
				printf("英语成绩>%.2f\n", node->stu.english);
				printf("总分>%.2f\n", node->stu.total);
			}
			break;
		}
		case Statistics:
			StatisticsStudent(&list);
			break;
		case Sort:
			SortStudent(&list);
			need = 1;
			break;
		default:
			printf("无效选择!!!\n");
			break;
		}
		while (getchar() != '\n');
		system("pause");
	}

	return 0;
}