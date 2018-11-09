#include "string_tools.h"

int read_line(char buffer[], int bufferLen) {
    
    int i = 0;
    for (; i < bufferLen; i++) {
        scanf("%c", &buffer[i]);
        if (buffer[i] == '\"') i -= 1;
        if (buffer[i] == '\n') {
            buffer[i] = '\0';
            break;
        }
    }
    return i;
}
int read_file_line(FILE*f,char buffer[], int bufferLen) {
    int i = 0;
    for (; i < bufferLen; i++) {
        if (fscanf(f, "%c", &buffer[i]) == EOF) return EOF;
        if (buffer[i] == '\"') i -= 1;
        if (buffer[i] == '\n') {
            buffer[i] = '\0';
            break;
        }
    }
    return i;
}