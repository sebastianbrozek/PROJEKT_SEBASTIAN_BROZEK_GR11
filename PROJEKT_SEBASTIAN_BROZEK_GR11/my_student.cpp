/////////////////////////////////////////////////////////////////////////////////////
//    MY_STUDENT.cpp

#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>
#include "my_mess.h"
#include "string.h"
#include "my_student.h"

#pragma warning (disable : 4996)

static char *course_tab[COURSE_TOTAL] = {
	"MATHS",
	"IT",
};

void *MY_STUDENT_Init(char *llastname, size_t year, COURSE course)
{
	MY_STUDENT *pdat = (MY_STUDENT *)malloc(sizeof(MY_STUDENT));

	if (pdat)
	{
		pdat->lastname = (char *)malloc(strlen(llastname) + 1);
		if (pdat->lastname)
		{
			strcpy(pdat->lastname, llastname);
		}
		pdat->year = year;
		pdat->course = course;
	}
	else
	{
		my_mess_fun(MY_MESS_MEM_ALLOC_NOT_FATAL);
	}
	return (void *)(pdat);
}

void MY_STUDENT_Free(void *ptr)
{
	MY_STUDENT *pDat = (MY_STUDENT *)ptr;
	if (pDat)
	{
		if (pDat->lastname)
			free(pDat->lastname);

		pDat->lastname = NULL;

		free(pDat);
	}
}

void MY_STUDENT_Print(void *ptr)
{
	MY_STUDENT *p = (MY_STUDENT *)ptr;
	if (p && p->lastname)
	{
		printf("lastname:      %s\n", p->lastname);
		printf("year    :      %d\n", p->year);
		printf("degree course: %s\n", course_tab[p->course]);
	}
}

int MY_STUDENT_Search_Lastname(void *pCurData, void *pSearchData)
{
	MY_STUDENT *pcur = (MY_STUDENT *)pCurData;
	MY_STUDENT *psearch = (MY_STUDENT *)pSearchData;

	if (strcmp(pcur->lastname, psearch->lastname) == 0)
		return 1;

	return 0;
}

int MY_STUDENT_Save(FILE *fp, void * pel)
{
	MY_STUDENT *pdat = (MY_STUDENT *)pel;
	int lastname_len = strlen(pdat->lastname);

	fwrite(&lastname_len, sizeof(lastname_len), 1, fp);
	fwrite(pdat->lastname, 1, lastname_len, fp);
	fwrite(&pdat->year, sizeof(pdat->year), 1, fp);
	fwrite(&pdat->course, sizeof(pdat->course), 1, fp);

	return 0;
}

void * MY_STUDENT_Load(FILE *fp)
{
	char lastname[512];
	size_t year;
	COURSE course;
	int lastname_len;

	fread(&lastname_len, sizeof(lastname_len), 1, fp);
	lastname_len = fread(lastname, 1, lastname_len, fp);
	lastname[lastname_len] = '\0';
	fread(&year, sizeof(year), 1, fp);
	fread(&course, sizeof(course), 1, fp);

	return MY_STUDENT_Init(lastname, year, course);
}