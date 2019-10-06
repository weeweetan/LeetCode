//
// Created by 11135 on 2019/10/6.
//
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

char * defangIPaddr(char * address){
    size_t len = strlen(address);
    char *result = (char *) malloc(len + 6);
    unsigned long temp = 0, total = 0;
    char *p = strchr(address, '.');
    while (p != NULL)
    {
        temp = p - address;
        memcpy(result + total, address, temp);
        total += temp;
        memcpy(result + total, "[.]", 3);
        total += 3;
        address = address + temp + 1;
        p = strchr(address, '.');
    }

    strcpy(result + total, address);

    return result;
}

int main(int argc, char **argv)
{
    char temp[] = {"1.1.1.1"};
    char *result = defangIPaddr(temp);
    printf("%s\n", result);
}