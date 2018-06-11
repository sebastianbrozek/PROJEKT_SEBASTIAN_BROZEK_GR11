
#include "stdafx.h"
#include <stdlib.h>
#include <string.h>
#include "my_mess.h"

static char *my_message_str_tab[] =
{
	"E memory allocation error",
	"W zly numer wiersza",
	"W mem alloc fault",
	"W File I/O error",
	"W Wrong format"
};

static dealloc p_dealloc_fun = NULL;


void my_mess_dealloc_set(dealloc dealloc_fun)
{
	p_dealloc_fun = dealloc_fun;
}

void my_mess_fun(enum MY_MESSAGES mess)
{

	puts(my_message_str_tab[mess] + 1);

	if (my_message_str_tab[mess][0] == 'E')
	{

		if (p_dealloc_fun != NULL)
			p_dealloc_fun();

		system("pause");
		exit(1);
	}
}