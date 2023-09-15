#ifndef ONEGIN1_H_INCLUDED
#define ONEGIN1_H_INCLUDED

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#include "sorts.h"

void ReadBuffer(char* buffer, const size_t buf_size, FILE* file_ptr);
size_t FillLineArray(char** line_array, char* buffer, const size_t buf_size, const size_t line_num);
void PrintLineArray(const char* filename, char** line_array, const size_t line_num);
void BubbleSortRightToLeft(char** line_array, const size_t line_num);
void QsortLeftToRight(char** line_array, const size_t line_num);
void PrintOriginalText(char* buffer, const size_t buf_size);
void FreeText(char** line_array, char*  buffer);

#endif // ONEGIN1_H_INCLUDED
