#include <stdio.h>

//
// Created by 11135 on 2019/9/21.
//
int numJewelsInStones(char * J, char * S){

    int amount = 0;
    while (*J != '\0')
    {
        char *temp = S;
        while (*temp != '\0')
        {
            if (*temp == *J) {
                amount++;
            }
            temp++;
        }
        J++;
    }
    return amount;
}


int main(int argc, char **argv)
{
    char J[] = {"z"};
    char S[] = {"ZZ"};

    int ret = numJewelsInStones(J, S);
    printf("%d\n", ret);
}