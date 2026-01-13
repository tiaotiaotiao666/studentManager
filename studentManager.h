#pragma once

typedef enum MenuOptions {
	Quit,		//退出系统
	Entry,		//录入学生信息
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