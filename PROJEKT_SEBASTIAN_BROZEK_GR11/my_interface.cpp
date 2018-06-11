//////////////////////////////////////////////////////////////////////
//  my_interface.cpp

#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "my_stack.h"
#include "my_interface.h"
#include "my_student.h"

#pragma warning (disable : 4996)

static char *strtab[] =
{
	"0 - push",
	"1 - pop",
	"2 - clear",
	"3 - find lastname",
	"4 - finish",
	"5 - save_to_file",
	"6 - load"
};

void menu()
{
	size_t it;

	for (it = 0; it<INTERF_TOT; ++it) {
		printf("%s\n", strtab[it]);
	}
}

void push()
{
	char lastname[512];

	size_t year;
	COURSE course;
	printf("lastname, year, degree (press 0 for MATHS; press 1 for IT)\n");

	scanf("%s", lastname);
	scanf("%d", &year);
	scanf("%d", &course);

	if (course >= COURSE_TOTAL)
	{
		printf("Wrong degree\n");
		return;
	}

	void *pdat = MY_STUDENT_Init(lastname, year, course);

	if (!MY_STACK_Push(pdat))
		printf("push error\n");
}

void pop()
{
	MY_STACK tmp = MY_STACK_Pop();

	if (tmp.pData)
	{
		MY_STUDENT_Print(tmp.pData);
		MY_STUDENT_Free(tmp.pData);
	}
}

void find_lastname()
{
	char str[512];

	printf("input lastname\n");
	scanf_s("%s", str, sizeof(str));

	MY_STUDENT serachDat;

	memset(&serachDat, 0, sizeof(MY_STUDENT));
	serachDat.lastname = str;

	void * pDat = MY_STACK_Search(&serachDat, MY_STUDENT_Search_Lastname, 1);

	if (pDat)
	{
		printf("found : \n");
		MY_STUDENT_Print(pDat);
	}

	while (pDat) {
		pDat = MY_STACK_Search(&serachDat, MY_STUDENT_Search_Lastname, 0);
		if (pDat)
		{
			printf("found : \n");
			MY_STUDENT_Print(pDat);
		}
	}
}

void clear()
{
	MY_STACK_Free();
}


void save_to_file()
{
	char str[512];

	printf("input filename\n");
	scanf_s("%s", str, sizeof(str));

	MY_STACK_Save(str, MY_STUDENT_Save);

	printf("File saved.\n");
}

void load()
{
	char str[512];

	printf("input filename\n");
	scanf_s("%s", str, sizeof(str));

	MY_STACK_Load(str, MY_STUDENT_Load);

	printf("Stack Loaded.\n");
}