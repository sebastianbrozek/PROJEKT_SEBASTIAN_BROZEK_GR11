#pragma once

#include<stdio.h>

#ifndef MY_STACK___H
#define MY_STACK___H

struct MY_STACK
{
	void *pData;
	MY_STACK *next;
};

typedef void(*FreeData)(void *pdat);
typedef int (CompData)(void * pcurData, void * pSearchData);
typedef int (SaveData)(FILE *fp, void * pel);
typedef void * (LoadData)(FILE *fp);

void MY_STACK_Init(FreeData pFreeDat);
void MY_STACK_Free();
MY_STACK * MY_STACK_Push(void *pdat);
MY_STACK MY_STACK_Pop();
void * MY_STACK_Search(void *pSearchDat, CompData ptr_comp_fun, int FirstEntry);
void MY_STACK_Save(char * name, SaveData el_save_fun);
void MY_STACK_Load(char * name, LoadData el_load_fun);

#endif