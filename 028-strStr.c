//
// Created by 11135 on 2019/2/28.
//

#include <memory.h>
#include <stdio.h>

int strStr(char* haystack, char* needle) {

    if (haystack == NULL || needle == NULL) {
        return -1;
    }

    size_t needleLen = strlen(needle);
    size_t haystackLen = strlen(haystack);

    if (needleLen == 0) {
        return 0;
    }
    if (haystackLen < needleLen) {
        return -1;
    }
    int count = -1;
    int innerCount = -1;
    while (*haystack != '\0')
    {
        if (*(haystack) == *(needle)) {
            innerCount++;
            if (!strncmp(haystack, needle, needleLen)) {
                break;
            } else {
                innerCount = -1;
                count++;
            }
        } else {
            count++;
        }
        haystack++;
    }
    return innerCount==-1?-1:count+1;
}



int main(int argc, char *argv[])
{
    //"mississippi" "issipi"
    char *str1 = "mississippi";
    char *str2 = "issipi";
    int result = strStr(str1, str2);
    printf("%d", result);
}
