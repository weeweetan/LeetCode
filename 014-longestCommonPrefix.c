//
// Created by 11135 on 2018/5/27.
//
#include <stdlib.h>
#include <string.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    size_t length = 0;
    if (strsSize > 0) {
        length = strlen(strs[0]);
        for (int i = 1; i < strsSize && length > 0; ++i) {
            size_t matched = 0;
            while (matched < length && strs[i][matched] != '\0' &&
                   strs[i][matched] == strs[0][matched]) {
                ++matched;
            }
            length = matched;
        }
    }

    char *result = malloc(length + 1);
    if (result == NULL) return NULL;
    if (length > 0) memcpy(result, strs[0], length);
    result[length] = '\0';
    return result;
}
