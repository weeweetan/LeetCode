//
// Created by 11135 on 2018/5/27.
//
#include <string.h>
#include <stdlib.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    int i = 0, j = 0, count = 0;
    char *s = NULL;
    s = *(strs+0);
    size_t length = strlen(s);
    char *result = (char *)malloc(length);
    for (j = 0; j < length; j++) {
        for (i = 1; i < strsSize; i++) {
            if (s[j] == (*(strs+i))[j]) {
                continue;
            }
            else {
                goto out;
            }
        }
        result[j] = s[j];
        count++;
    }
    out:
    if (count == 0) {
        strcpy(result, "");
    } else{
        result[count] = '\0';
    }
    return result;
}
