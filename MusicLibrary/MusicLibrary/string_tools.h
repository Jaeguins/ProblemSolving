#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int read_line(char buffer[], int bufferLen);
int read_file_line(FILE* f,char buffer[], int bufferLen);
char* compose_name();