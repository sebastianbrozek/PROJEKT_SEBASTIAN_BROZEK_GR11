#pragma once
//   my_student.h

#ifndef MY_STUDENT_ADFGRETW__H
#define MY_STUDENT_ADFGRETW__H

enum COURSE
{
	MATHS,
	IT,
	COURSE_TOTAL
};

struct MY_STUDENT
{
	char *lastname;
	size_t year;
	COURSE course;
};

void *MY_STUDENT_Init(char *llastname, size_t year, COURSE course);
void MY_STUDENT_Free(void *ptr);
void MY_STUDENT_Print(void *ptr);
int MY_STUDENT_Search_Lastname(void *pCurData, void *pSearchData);
int MY_STUDENT_Save(FILE *fp, void * pel);
void * MY_STUDENT_Load(FILE *fp);
#endif