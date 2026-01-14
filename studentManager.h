#pragma once

typedef struct Student {
	unsigned long long id;	//学号
	char name[32];			//姓名
	char sex;				//性别
	float chinese;			//语文成绩
	float math;				//数学成绩
	float english;			//英语成绩
	float total;			//总成绩
}Student;

typedef struct Node {
	Student stu;
	struct Node* next;
}Node;

typedef struct List {
	Node* front;
	Node* last;
	int size;
}List;

typedef enum MenuOptions {
	Quit,		//退出系统
	Entry,		//录入学生信息
	Print,		//打印学生信息
	Save,		//保存学生信息
	Read,		//读取信息
	Modify,		//修改信息
	Add,		//插入信息
	Delete,		//删除信息
	Find,		//查询信息
	Statistics,	//统计信息
	Sort,		//排序信息
}MenuOptions;

//打印菜单
int menu();

void EntryStudent(List* list);

void PrintStudent(List* list);