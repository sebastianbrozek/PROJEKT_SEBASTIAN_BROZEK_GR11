#pragma once

//   my_interface.h

#ifndef MY_INTERFACE___H
#define MY_INTERFACE___H

enum MY_INTERF_EN
{
	INTERF_PUSH,
	INTERF_POP,
	INTERF_CLEAR,
	INTERF_FIND_LASTNAME,
	INTERF_STOP,
	INTERF_SAVE_TO_FILE,
	INTERF_LOAD,
	INTERF_TOT
};

void push();
void pop();
void clear();
void menu();
void find_lastname();
void save_to_file();
void load();

#endif