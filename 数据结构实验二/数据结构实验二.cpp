// 数据结构实验二.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#define MAX_LINE 20  //文件行数
using namespace std;

//定义结构体studentInfo
typedef struct studentInfo
{
	char name[10];
	int nanlysis;
	int algebra;
	int analGeo;
}student;

typedef struct 
{
	student *data;
	int length;
}gradeList;
void Create(gradeList &l,FILE *p)
{
	l.data = new studentInfo[MAX_LINE];
	int i = 0;
	if (p == NULL)//判断是否成功打开文档
		cout << "打开失败" << endl;
	//读取学生姓名
	fseek(p, 31, SEEK_SET);//文件指针移动到距文档开头l个偏移量
	while (fscanf_s(p, "%s%d%d%d",
		&l.data[i].name,
		&l.data[i].nanlysis,
		&l.data[i].algebra,
		&l.data[i].analGeo ) != EOF)//遍历文档读取学生姓名直到文档末尾
	{
		i++;
	}
	fclose(p);
	l.length = i;
}
void Insert(gradeList &l, student &st,int i)
{
	if (i >= MAX_LINE)
		cout << "错误，下标溢出" << endl;
	else
	{
		if (i < l.length)
		{
			for (int j = l.length; j > i - 1; j--)
			{
				strcpy_s(l.data[j].name, l.data[j - 1].name);
				l.data[j].nanlysis = l.data[j - 1].nanlysis;
				l.data[j].algebra = l.data[j - 1].algebra;
				l.data[j].analGeo = l.data[j - 1].analGeo;
			}
			strcpy_s(l.data[i - 1].name, st.name);
			l.data[i - 1].nanlysis = st.nanlysis;
			l.data[i - 1].algebra = st.algebra;
			l.data[i - 1].analGeo = st.analGeo;
			l.length++;
		}
		else if (i == l.length)
		{
			strcpy_s(l.data[i - 1].name, st.name);
			l.data[i - 1].nanlysis = st.nanlysis;
			l.data[i - 1].algebra = st.algebra;
			l.data[i - 1].analGeo = st.analGeo;
		}
		else
			cout << "下标错误，下标必须连续，不能跳跃" << endl;
	}
}
void SerachOfIndex(gradeList &l)
{
	int n;
	cout << "你想按下标搜索第几条记录：";
	while (true)
	{
		cin >> n;
		if (n < 0 || n >= l.length)
			cout << "下标错误，请重新输入：";
		else
			break;
	}
	cout << "第" << n << "条记录为：" 
		<< l.data[n - 1].name << " " 
		<< l.data[n - 1].nanlysis << " " 
		<< l.data[n - 1].algebra << " " 
		<< l.data[n - 1].analGeo << endl;
}
void Show(gradeList &l)
{
	for (int i = 0; i < l.length; i++)
	{
		cout << l.data[i].name << " " 
			<< l.data[i].nanlysis << " " 
			<< l.data[i].algebra << " " 
			<< l.data[i].analGeo << endl;
	}
}
void SerchOfName(gradeList &l)
{
	bool t =true;
	char str[10];
	cout << "你想搜索关于谁的记录:";
	while (t)
	{
		cin >> str;
		if (strcmp(str, "No") == 0)
			break;
		else
		{
			int i;
			for (i = 0; i < l.length; i++)
			{
				if (strcmp(l.data[i].name, str) == 0)
				{
					cout << str << "的记录为:" << l.data[i].name << " "
						<< l.data[i].nanlysis << " "
						<< l.data[i].algebra << " "
						<< l.data[i].analGeo << endl;
					break;
				}
			}
			if (i == l.length)
				cout << "无此人记录！" << endl;
		}
		cout << "你还想查询谁的记录，是则请输入名字，否请输入No" << endl;
	}
}
void Pop(gradeList &l)
{
	char str[10];
	cout << "你想删除谁的记录:";
	cin >> str;
	int i;
	bool key = false;
	for (i = 0; i < l.length; i++)
	{
		if (strcmp(l.data[i].name, str) == 0)
		{
			cout << "已找到此人记录，是否确认要删除？yes/no:";
			char s[4];
			cin >> s;
			if(strcmp(s,"yes")==0)
				key = true;
			break;
		}
	}
	if(!key&&i==l.length)
		cout << "不存在此人的记录，无需进行删除" << endl;
	if (key)
	{
		for (int j = i; j < l.length; j++)
		{
			strcpy_s(l.data[j].name, l.data[j + 1].name);
			l.data[j].nanlysis = l.data[j + 1].nanlysis;
			l.data[j].algebra = l.data[j + 1].algebra;
			l.data[j].analGeo = l.data[j + 1].analGeo;
		}
		l.length--;
	}
}
int main()
{
	FILE *fp1;
	//D:\\users\\lenovo\\source\\数据结构作业源代码\\数据结构作业1
	fp1 = fopen_s("scores.txt", "r");//创建文件句柄，打开用于读取数据
	gradeList l;
	Create(l, fp1);
	Show(l);
	studentInfo s1 = { "张兰", 85, 77,92 };
	studentInfo s2 = { "王平", 92, 83,79 };
	studentInfo s3 = { "冯文成",77,68,80 };
	Insert(l, s1, 7);
	Insert(l, s2, 2);
	Insert(l, s3, l.length);
	cout << "我是分割线=================" << endl;
	Show(l);
	SerachOfIndex(l);
	SerchOfName(l);
	Pop(l);
	Show(l);
	return 0;
}

