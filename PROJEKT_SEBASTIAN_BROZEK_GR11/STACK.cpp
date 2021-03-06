// STACK.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>
#include "my_interface.h"
#include "my_stack.h"
#include "my_mess.h"
#include "my_student.h"

#pragma warning (disable : 4996)

int _tmain(int argc, _TCHAR* argv[])
{
	MY_STACK_Init(MY_STUDENT_Free);

	size_t op = 0;
	while (op >= INTERF_PUSH && op < INTERF_TOT)
	{
		menu();

		int ret = scanf("%d", &op);
		if (ret != 1)
		{
			printf("Wrong input\n");

			char c;

			while ((c = getchar()) != '\n' && c != EOF) {}

			continue;
		}

		switch (op)
		{
		case INTERF_PUSH: push();
			break;

		case INTERF_POP: pop();
			break;

		case INTERF_CLEAR: clear();
			break;

		case INTERF_FIND_LASTNAME: find_lastname();
			break;

		case INTERF_STOP: clear();
			return 0;

		case INTERF_SAVE_TO_FILE: save_to_file();
			break;

		case INTERF_LOAD: load();
			break;

		default:
			printf("blad\n");
		};
	}

	return 0;
}

