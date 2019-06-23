#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

//
// Created by 11135 on 2019/6/23.
//
char * toLowerCase(char * str) {
    size_t str_len = strlen(str);
    for (; *str != '\0'; str++)
    {
        if (*str >= 65 && *str <= 90)
        {
            *str = *str + 32;
        }
    }
    return str - str_len;
}


int main(int argc, char **argv)
{
    char temp[] = {"Hello"};
    char *o_str = toLowerCase(temp);
    printf("%s\n", o_str);
}