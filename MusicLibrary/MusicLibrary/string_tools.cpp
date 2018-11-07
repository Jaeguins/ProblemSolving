#include "string_tools.h"

int read_line(char buffer[], int bufferLen) {
    int i = 0;
    for (; i < bufferLen; i++) {
        scanf_s("%c", &buffer[i]);
        if (buffer[i] == '\n') {
            buffer[i] = '\0';
            break;
        }
    }
    return i;
}