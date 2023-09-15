#include "Onegin1.h"

int main()
{
    FILE* file_ptr = fopen("OnEgIn.txt", "r");

    char* buffer = nullptr;
    size_t buf_size = 0;

    struct stat st;
    stat("OnEgIn.txt", &st);
    buf_size = st.st_size;
    buffer = (char*) calloc(buf_size, sizeof(char));

    ReadBuffer(buffer, buf_size, file_ptr);

    size_t line_num = (buf_size / 2) + 1;

    char** line_array = (char**) calloc(line_num, sizeof(char*));

    size_t count_of_lines = FillLineArray(line_array, buffer, buf_size, line_num);

    if (count_of_lines <= line_num) {
        line_num = count_of_lines;
    } else {
        printf("Error! count_of_lines > line_num\n");
        return 0;
    }

    BubbleSortRightToLeft(line_array, line_num);
    QsortLeftToRight(line_array, line_num);
    PrintOriginalText(buffer, buf_size);

    FreeText(line_array, buffer);

    return 0;
}

