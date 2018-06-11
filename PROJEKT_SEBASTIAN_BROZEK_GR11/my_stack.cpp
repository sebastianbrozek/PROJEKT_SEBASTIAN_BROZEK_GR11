#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>

#include "my_mess.h"

#include "my_stack.h"


static MY_STACK *first = NULL;
FreeData ptr_free_dat;

static FILE *fp = NULL;

#pragma warning (disable: 4996)

static void stack_dealloc(void)
{

	if (fp)
	{
		fclose(fp);
	}

	MY_STACK_Free();
}

void MY_STACK_Init(FreeData pFreeDat)
{
	first = NULL;
	ptr_free_dat = pFreeDat;
	my_mess_dealloc_set(stack_dealloc);
}


void MY_STACK_Free()
{
	MY_STACK *p = first;
	MY_STACK *ptmp = NULL;
	while (p)
	{
		(*ptr_free_dat)(p->pData);
		ptmp = p;
		p = p->next;

		free(ptmp);
	}

	first = NULL;
}

MY_STACK * MY_STACK_Push(void *pdat)
{

	MY_STACK *current = (MY_STACK *)malloc(sizeof(MY_STACK));

	if (!current)
	{
		my_mess_fun(MY_MESS_MEM_ALLOC_NOT_FATAL);
		return NULL;
	}

	current->next = first;
	current->pData = pdat;
	first = current;

	return current;
}

MY_STACK MY_STACK_Pop()
{
	MY_STACK rv;

	if (!first)
	{
		rv.pData = NULL;
		rv.next = NULL;
	}
	else
	{

		MY_STACK *next = first->next;
		rv.pData = first->pData;
		rv.next = NULL;
		free(first);
		first = next;
	}

	return rv;
}

void * MY_STACK_Search(void *pSearchDat, CompData ptr_comp_fun, int FirstEntry)
{
	static MY_STACK *p;

	MY_STACK *ptmp = NULL;

	if (FirstEntry)
	{
		p = first;
	}

	while (p)
	{
		if (!(*ptr_comp_fun)(p->pData, pSearchDat))
		{
			p = p->next;
		}
		else
		{
			ptmp = p;
			p = p->next;
			return ptmp->pData;
		}
	}

	return NULL;
}

void reverse()
{
	MY_STACK *previous, *current, *succ;
	current = previous = first;

	current = current->next;
	previous->next = NULL;

	while (current != NULL) {

		succ = current->next;
		current->next = previous;
		previous = current;
		current = succ;
	}
	first = previous;
}

void MY_STACK_Save(char * name, SaveData el_save_fun)
{
	MY_STACK *p = first;
	fp = fopen(name, "w");

	if (fp)
	{
		while (p)
		{
			el_save_fun(fp, p->pData);
			p = p->next;
		}

		fclose(fp);
		fp = NULL;
	}
	else
	{
		my_mess_fun(MY_MESS_FILE_IO_WARNING);
	}
}


void MY_STACK_Load(char * name, LoadData el_load_fun)
{
	size_t arrSize = 1;

	fp = fopen(name, "r");


	if (fp)
	{

		MY_STACK_Free();

		while (feof(fp) == 0)
		{
			MY_STACK_Push(el_load_fun(fp));
		}
		fclose(fp);
		fp = NULL;

		reverse();

	}
	else
	{
		my_mess_fun(MY_MESS_FILE_IO_WARNING);
	}
}

