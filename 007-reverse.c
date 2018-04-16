#include <stdio.h>
#include <limits.h>

//
// Created by 11135 on 2018/4/14.
//
int reverse(int x) {
    int result = 0;
    int mod;
    while (x != 0) {
        mod = x % 10;
        if (result > INT_MAX/10 || result < INT_MIN/10)
            return 0;
        result = result * 10 + mod;
        x /= 10;
    }
    return result;
}
