//
// Created by tanwei on 2018/4/19.
//
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool isPalindrome(int x) {
    char str[32] = {0};
    unsigned int len = 0;
    unsigned int half = 0;
    int i = 0, j = 0;
    sprintf(str, "%d", x);
    len = (unsigned int)strlen(str);
    len = len -1;
    if (len%2 == 0) {
        half=len/2;
        for (i = 0, j = len; i < half, j > half; i++, j--) {
            if (str[i] != str[j]) {
                return false;
            }
        }
    }
    else {
        half=len/2;
        for (i = 0, j = len; i <= half, j >= half+1; i++, j--) {
            if (str[i] != str[j]) {
                return false;
            }
        }
    }
    return true;
}