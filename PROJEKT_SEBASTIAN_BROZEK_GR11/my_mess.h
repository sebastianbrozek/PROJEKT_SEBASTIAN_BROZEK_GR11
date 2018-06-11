
#pragma once

enum MY_MESSAGES
{
	MY_MESS_MEM_ALOC_ERROR,
	MY_MESS_WRONG_INDEX_WARNING,
	MY_MESS_MEM_ALLOC_NOT_FATAL,
	MY_MESS_FILE_IO_WARNING,
	MY_MESS_WRONG_FORMAT,
	MY_MESS_TOTAL
};

typedef void(*dealloc)(void);

void my_mess_dealloc_set(dealloc dealloc_fun);

void my_mess_fun(enum MY_MESSAGES mess);