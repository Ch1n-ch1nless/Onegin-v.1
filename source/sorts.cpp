#include "sorts.h"

void SortBubbleArray(char** string_array, const size_t string_number,
                     int (*comp)(const char*, const char*))
{
    assert(string_array);

    for (size_t i = 0; i < string_number; i++) {
        for (size_t j = i+1; j < string_number; j++) {

            if (string_array[j] == nullptr) break;

            int is_str1_smaller_str2 = (*comp)(*(string_array + i), *(string_array + j));

            if (is_str1_smaller_str2 > 0)
            {
                char* temp_pt = *(string_array + i);
                *(string_array + i) = *(string_array + j);
                *(string_array + j) = temp_pt;
            }
        }
        if (string_array[i] == nullptr) break;
    }
}

void SortingByQsort(char **line_array, int line_num)
{
    qsort((void *)line_array, line_num, sizeof(char*), Compare);
}

int Compare(const void * str1, const void * str2)
{
    return StrcmpLeftRight( * ( char** ) str1, * ( char** ) str2 );
}

int StrcmpRightLeft(const char* str1, const char* str2)
{
    size_t str1_len = strlen(str1);
    size_t str2_len = strlen(str2);

    size_t i = str1_len-1;
    size_t j = str2_len-1;

    while (true)
    {
        while (i > 0) {
            if ('a' <= str1[i] && str1[i] <= 'z') break;
            if ('A' <= str1[i] && str1[i] <= 'Z') break;
            //printf("Пропускаем элемент в строке str1: %c\n", str1[i]);
            i--;
        }
        //printf("Сравниваем последний буквенный элемент в строке str1: %c\n", str1[i]);

        while (j > 0) {
            if ('a' <= str2[j] && str2[j] <= 'z') break;
            if ('A' <= str2[j] && str2[j] <= 'Z') break;
            //printf("Пропускаем элемент в строке str2: %c\n", str2[j]);
            j--;
        }
        //printf("Сравниваем последний буквенный элемент в строке str2: %c\n", str2[j]);

        if (str1[i] > str2[j]) {
            return 1;
        } else if (str1[i] < str2[j]) {
            return -1;
        } else {
            i--;
            j--;
        }

        if (i >= str1_len || j >= str2_len) break;
    }

    if (i < str1_len && j < str2_len) {
        return str1[i] <= str2[j];
    } else if (i >= str1_len) {
        return -1;
    } else {
        return 1;
    }
}

int StrcmpLeftRight(const char* str1, const char* str2)
{
    size_t str1_len = strlen(str1);
    size_t str2_len = strlen(str2);

    size_t i = 0;
    size_t j = 0;

    while (true)
    {
        while (i < str1_len) {
            if ('a' <= str1[i] && str1[i] <= 'z') break;
            if ('A' <= str1[i] && str1[i] <= 'Z') break;
            //printf("Пропускаем элемент в строке str1: %c\n", str1[i]);
            i++;
        }
        //printf("Сравниваем последний буквенный элемент в строке str1: %c\n", str1[i]);

        while (j < str2_len) {
            if ('a' <= str2[j] && str2[j] <= 'z') break;
            if ('A' <= str2[j] && str2[j] <= 'Z') break;
            //printf("Пропускаем элемент в строке str2: %c\n", str2[j]);
            j++;
        }
        //printf("Сравниваем последний буквенный элемент в строке str2: %c\n", str2[j]);

        if (str1[i] > str2[j]) {
            return 1;
        } else if (str1[i] < str2[j]) {
            return -1;
        } else {
            i++;
            j++;
        }

        if (i >= str1_len || j >= str2_len) break;
    }

    if (i < str1_len && j < str2_len) {
        return str1[i] <= str2[j];
    } else if (i >= str1_len) {
        return -1;
    } else {
        return 1;
    }
}

