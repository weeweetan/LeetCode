#include <stddef.h>
#include <stdbool.h>
//
// Created by 11135 on 2018/5/9.
//
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


bool allUnique(char *s, int start, int end)
{
    const int length = end - start;
    char temp[length];
    memset(temp, 0, length);
    int i = 0, j = 0;
    for (i = start; i < end; i++) {
        if (strchr(temp, s[i])) {
            return false;
        }
        temp[j] = s[i];
        j++;
    }
    return true;
}

int lengthOfLongestSubstring(char* s) {
    int n = strlen(s);
    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j <= n; j++)
            if (allUnique(s, i, j)) ans = ans > (j-i) ? ans:(j-i);
    return ans;
}

int main(int argc, char *argv[])
{
//    char temp[] = "abcabcbb";
//    char temp[] = "bbbbb";
    char temp[] = "pwwkew";
    int result = lengthOfLongestSubstring(temp);
    printf("result:%d\n", result);
}