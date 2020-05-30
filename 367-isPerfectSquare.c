//
// Created by 11135 on 2020/5/26.
//
#include <stdbool.h>
#include <stdio.h>

bool isPerfectSquare(int num) {
    if (num < 2) {
        return true;
    }

    long left = 2, right = num / 2, x, guessSquared;
    while (left <= right) {
        x = left + (right - left) / 2;
        guessSquared = x * x;
        if (guessSquared == num) {
            return true;
        }
        if (guessSquared > num) {
            right = x - 1;
        } else {
            left = x + 1;
        }
    }
    return false;
}

int main(int argc, char **argv)
{
    printf("%d\n", isPerfectSquare(16));
}