#ifndef SORTS_H_INCLUDED
#define SORTS_H_INCLUDED

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

void SortBubbleArray(char** string_array, const size_t string_number,
                     int (*comp)(const char*, const char*));

int Compare(const void * str1, const void * str2);
int StrcmpRightLeft(const char* str1, const char* str2);
int StrcmpLeftRight(const char* str1, const char* str2);

void SortingByQsort(char **line_array, int line_num);

#endif // SORTS_H_INCLUDED
