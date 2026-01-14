#define _CRT_SECURE_NO_WARNINGS
#include "studentManager.h"
#include<stdio.h>
#include<stdlib.h>

static Node* CreatNode() {
	Node* node = malloc(sizeof(Node));
	if (!node) {
		printf("malloc failed\n");
		return NULL;
	}
	node->next = NULL;
	return node;
}

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
	Node* node = CreatNode();

	printf("请输入学生学号>");
	scanf("%llu", &node->stu.id);
	while (getchar() != '\n');
	printf("请输入学生姓名>");
	scanf("%s", node->stu.name);
	while (getchar() != '\n');
	printf("请输入学生性别>");
	scanf("%s", node->stu.sex);
	while (getchar() != '\n');
	printf("请输入语文成绩>");
	scanf("%f", &node->stu.chinese);
	while (getchar() != '\n');
	printf("请输入数学成绩>");
	scanf("%f", &node->stu.math);
	while (getchar() != '\n');
	printf("请输入英语成绩>");
	scanf("%f", &node->stu.english);
	while (getchar() != '\n');
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
	printf("\n");
	printf("*****************************************************\n");
	printf("*             欢迎使用高校学生信息管理系统          *\n");
	printf("*****************************************************\n");
	printf("*学号\t姓名\t性别\t语文\t数学\t英语\t总分*\n");
	printf("*****************************************************\n");
	Node* curr = list->front;
	while (curr != NULL) {
		printf("%llu\t%s\t%s\t%.2f\t%.2f\t%.2f\t%.2f\n", curr->stu.id, curr->stu.name, curr->stu.sex, curr->stu.chinese, curr->stu.math, curr->stu.english, curr->stu.total);
		curr = curr->next;
	}
}

void SaveStudent(List* list){
	FILE* fp = fopen("students.data", "wb");
	if (!fp) {
		perror("file open failed");
		return;
	}
	Node* curNode = list->front;
	while (curNode != NULL) {
		fwrite(&curNode->stu, sizeof(Student), 1, fp);
		curNode = curNode->next;
	}

	fclose(fp);
}

void ReadStudent(List* list){
	FILE* fp = fopen("students.data", "rb");
	if (!fp) {
		perror("file open failed");
		return;
	}
	while (!feof(fp)) {
		Node* node = CreatNode();
		size_t len = fread(&node->stu, sizeof(Student), 1, fp);
		if (len == 0) {
			free(node);
			break;
		}
		
		if (list->front == NULL) {
			list->front = node;
		}
		else {
			list->last->next = node;
		}
		list->last = node;
		list->size++;
	}

	fclose(fp);
}
