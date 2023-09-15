#ifndef SORTS_H_INCLUDED
#define SORTS_H_INCLUDED

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <TXLib.h>

void SortBubbleArray(char** string_array, const size_t string_number,
                     int (*comp)(const char*, const char*));

int StrcmpRightLeft(const char* str1, const char* str2);
int StrcmpLeftRight(const char* str1, const char* str2);

void QuickSortArray(char** string_array, const size_t string_number, size_t left, size_t right);
size_t Partition(char** string_array, const size_t string_number, size_t left, size_t right);
void Swap(char** string_array, const size_t left, const size_t right);

void SortingByQsort(char **line_array, int line_num);
int Compare(const void * str1, const void * str2);

#endif // SORTS_H_INCLUDED
