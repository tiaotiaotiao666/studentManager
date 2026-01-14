#define _CRT_SECURE_NO_WARNINGS
#include "studentManager.h"
#include<stdio.h>
#include<stdlib.h>

int menu() {
	system("cls");
	printf("************************************\n");
	printf("*   欢迎使用高校学生信息管理系统   *\n");
	printf("************************************\n");
	printf("*            请选择功能            *\n");
	printf("************************************\n");
	printf("*         1.录入学生信息           *\n");
	printf("*         2.打印学生信息           *\n");
	printf("*         3.存储学生信息           *\n");
	printf("*         4.读取学生信息           *\n");
	printf("*         5.修改学生信息           *\n");
	printf("*         6.插入学生信息           *\n");
	printf("*         7.删除学生信息           *\n");
	printf("*         8.查询学生信息           *\n");
	printf("*         9.统计学生信息           *\n");
	printf("*         10.排序学生信息           *\n");
	printf("*         0.退出系统               *\n");
	printf("************************************\n");
	printf("请选择功能(0-10): ");
	int select = -1;
	scanf("%d", &select);
	return select;
}

void EntryStudent(List* list){
	Node* node = malloc(sizeof(Node));
	if (!node) {
		printf("malloc failed\n");
		return;
	}
	node->next = NULL;
	printf("请输入学生学号>");
	scanf("%llu", &node->stu.id);

	printf("请输入学生姓名>");
	scanf("%s", node->stu.name);

	printf("请输入学生性别>");
	scanf(" %c", &node->stu.sex);

	printf("请输入语文成绩>");
	scanf("%f", &node->stu.chinese);

	printf("请输入数学成绩>");
	scanf("%f", &node->stu.math);

	printf("请输入英语成绩>");
	scanf("%f", &node->stu.english);

	node->stu.total = node->stu.chinese + node->stu.math + node->stu.english;
	if (list->front == NULL) {
		list->front = node;
	}
	else {
		list->last->next = node;
	}
	list->last = node;
	list->size++;
}

void PrintStudent(List* list){

}
