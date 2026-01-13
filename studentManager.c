#define _CRT_SECURE_NO_WARNINGS
#include "studentManager.h"
#include<stdio.h>

int menu() {
	system("cls");
	printf("************************************\n");
	printf("*   欢迎使用高校学生信息管理系统   *\n");
	printf("************************************\n");
	printf("*            请选择功能            *\n");
	printf("************************************\n");
	printf("*         1.录入学生信息           *\n");
	printf("*         2.存储学生信息           *\n");
	printf("*         3.读取学生信息           *\n");
	printf("*         4.修改学生信息           *\n");
	printf("*         5.插入学生信息           *\n");
	printf("*         6.删除学生信息           *\n");
	printf("*         7.查询学生信息           *\n");
	printf("*         8.统计学生信息           *\n");
	printf("*         9.排序学生信息           *\n");
	printf("*         0.退出系统               *\n");
	printf("************************************\n");
	printf("请选择功能(0-9): ");
	int select = -1;
	scanf("%d", &select);
	return select;
}