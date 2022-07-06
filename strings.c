#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#define array_length(array) sizeof(array)/sizeof((array)[0])
size_t string_length(char* input_str) {
    size_t length = 0;
    char *cursor = input_str;
    while (*cursor != '\0') {
        length += 1;
        cursor += 1;
    }
    return length;
}
char buffer[256];
char *hstr;
int main (int argc, char *argv[]) {
    // char array
    // Explicit null terminator added manually.
    char str[] = { 'A', 'b', 'r', 'a', 'h', 'a', 'm', '\0' }; 
    size_t len = array_length(str) - 1;
    printf("string: %s of length: %zu.\n", str, array_length(str));
    for (int strCount = 0; strCount < len; ++strCount) {
        str[strCount] += 1;
    }
    printf("string: %s of length: %zu.\n", str, array_length(str));
    // char literal
    // Implicit null terminator added by the C compiler.
    char *cstr = "Abraham"; 
    size_t clen = string_length(cstr) + 1;
    printf("string: %s of length: %zu.\n", cstr, clen);
    memcpy(buffer, cstr, clen);
    for (int strCount = 0; strCount < clen; ++strCount) {
        buffer[strCount] += 1;
    }
    buffer[clen - 1] = '\0';
    cstr = buffer;
    printf("string: %s of length: %zu.\n", cstr, clen);
    // char heap array
    // Heap malloc & mutate
    char *string = "Abraham"; 
    size_t stringlen = string_length(string) + 1;
    printf("string: %s of length: %zu.\n", string, stringlen);
    hstr = malloc(clen * sizeof(char));
    memcpy(hstr, string, stringlen);
    for (int strCount = 0; strCount < stringlen; ++strCount) {
        hstr[strCount] += 1;
    }
    hstr[clen - 1] = '\0';
    string = hstr;
    printf("string: %s of length: %zu.\n", string, stringlen);
    free(hstr);
    return 0;
}
