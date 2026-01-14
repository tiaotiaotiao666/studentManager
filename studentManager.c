#define _CRT_SECURE_NO_WARNINGS
#include "studentManager.h"
#include<stdio.h>
#include<stdlib.h>
#define MAX(a,b)(a > b ? a : b)
#define MIN(a,b)(a < b ? a : b)

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

void ModifyStudent(List* list){
	char buffer[32];
	printf("请输入要修改学生的姓名或学号>");
	scanf("%s", buffer);
	Node* curNode = list->front;
	while (curNode != NULL) {
		if (strcmp(curNode->stu.name, buffer) == 0)break;
		else if (atoi(buffer) == curNode->stu.id)break;
		curNode = curNode->next;
	}
	if (curNode != NULL) {
		printf("Find it!\n");
		printf("请输入修改后的学号>");
		scanf("%llu", &curNode->stu.id);
		while (getchar() != '\n');
		printf("请输入修改后的姓名>");
		scanf("%s", curNode->stu.name);
		while (getchar() != '\n');
		printf("请输入修改后的性别>");
		scanf("%s", curNode->stu.sex);
		while (getchar() != '\n');
		printf("请输入修改后的语文成绩>");
		scanf("%f", &curNode->stu.chinese);
		while (getchar() != '\n');
		printf("请输入修改后数学成绩>");
		scanf("%f", &curNode->stu.math);
		while (getchar() != '\n');
		printf("请输入修改后的英语成绩>");
		scanf("%f", &curNode->stu.english);
		curNode->stu.total = curNode->stu.chinese + curNode->stu.math + curNode->stu.english;
	}
	else printf("没找到目标学生~~\n");
	printf("修改成功!\n");
}

void AddStudent(List* list){

}

void DeleteStudent(List* list){
	char buffer[32];
	printf("请输入要删除的学生的姓名或学号>");
	scanf("%s", buffer);
	Node* dummy = (Node*)malloc(sizeof(Node));
	dummy->next = list->front;
	Node* curNode = dummy;
	while (curNode->next != NULL) {
		if (strcmp(curNode->next->stu.name, buffer) == 0)break;
		else if (atoi(buffer) == curNode->next->stu.id)break;
		curNode = curNode->next;
	}
	if(curNode->next == NULL)printf("没找到要删除的学生!\n");
	else {
		curNode->next = curNode->next->next;
	}
	list->front = dummy->next;
	free(dummy);
	printf("删除成功!\n");
}

Node* FindStudent(List* list){
	char buffer[32];
	printf("请输入要查找学生的姓名或学号>");
	scanf("%s", buffer);
	Node* curNode = list->front;
	while (curNode != NULL) {
		if (strcmp(curNode->stu.name, buffer) == 0) return curNode;
		else if (atoi(buffer) == curNode->stu.id)return curNode;
		curNode = curNode->next;
	}
	return NULL;
}

void StatisticsStudent(List* list) {
	Node* node = list->front;
	printf("共有%d名学生\n", list->size);
	if(list->size > 0){
	float chi = 0, ma = 0, eng = 0, all = 0;
	float chineseMax = 0, mathMax = 0, englishMax = 0,totalMax = 0;
	float chineseMin = 1000, mathMin = 1000, englishMin = 1000,totalMin = 1000;
	while (node != NULL) {
		chi += node->stu.chinese;
		ma += node->stu.math;
		eng += node->stu.english;
		all += node->stu.total;
		chineseMax = MAX(node->stu.chinese, chineseMax);
		chineseMin = MIN(node->stu.chinese, chineseMin);
		mathMax = MAX(node->stu.math, mathMax);
		mathMin = MIN(node->stu.math, mathMin);
		englishMax = MAX(node->stu.english, englishMax);
		englishMin = MIN(node->stu.english, englishMin);
		totalMax = MAX(node->stu.total, totalMax);
		totalMin = MIN(node->stu.total, totalMin);
		node = node->next;
	}
	chi /= list->size;
	ma /= list->size;
	eng /= list->size;
	all /= list->size;
	printf("总分平均分为>%.2f\n",all);
	printf("语文平均分为>%.2f\n",chi);
	printf("数学平均分为>%.2f\n",ma);
	printf("英语平均分为>%.2f\n",eng);
	printf("******************\n");
	printf("语文最高分为>%.2f\n",chineseMax);
	printf("数学最高分为>%.2f\n",mathMax);
	printf("英语最高分为>%.2f\n",englishMax);
	printf("总分最高分为>%.2f\n",totalMax);
	printf("******************\n");
	printf("语文最低分为>%.2f\n", chineseMin);
	printf("数学最低分为>%.2f\n", mathMin);
	printf("英语最低分为>%.2f\n", englishMin);
	printf("总分最低分为>%.2f\n", totalMin);
}
}

void SortStudent(List* list){
	Node* node = list->front;
	int choise;
	printf("************************************\n");
	printf("*           请选择排序             *\n");
	printf("************************************\n");
	printf("*          1.总分升序              *\n");
	printf("*          2.总分降序              *\n");
	printf("*          3.语文成绩升序          *\n");
	printf("*          4.语文成绩降序          *\n");
	printf("*          5.数学成绩升序          *\n");
	printf("*          6.数学成绩降序          *\n");
	printf("*          7.英语成绩升序          *\n");
	printf("*          8.英语成绩降序          *\n");
	printf("*          9.名字序升序            *\n");
	printf("*          10.名字序降序           *\n");
	printf("*          11.学号升序             *\n");
	printf("*          12.学号降序             *\n");
	printf("************************************\n");
	printf(">");
	scanf("%d", &choise);
	if (choise < 1 || choise > 12) {
		printf("无效选择!\n");
		return;
	}
	else {

	}
}
