//
// Created by 11135 on 2020/5/8.
//

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char * removeOuterParentheses(char * S) {
    size_t len = strlen(S);
    int level = 0, j = 0;
    char *temp = malloc(len);

    for (int i = 0; i < len; i++) {
        if (S[i] == ')') --level;
        if (level >= 1) {
            temp[j] = S[i];
            j++;
        }
        if (S[i] == '(') ++level;
    }

    return temp;
}

int main(int argc, char **argv)
{
    char S[] = {"(()())(())"};
    printf("%s\n", removeOuterParentheses(S));
}