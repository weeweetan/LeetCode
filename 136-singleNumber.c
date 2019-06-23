//
// Created by 11135 on 2019/4/3.
//
//思路
/*标签：位运算
        本题根据题意，线性时间复杂度O(n)，很容易想到使用Hash映射来进行计算，遍历一次后结束得到结果，但是在空间复杂度上会达到O(n)，需要使用较多的额外空间
        既满足时间复杂度又满足空间复杂度，就要提到位运算中的异或运算XOR，主要因为异或运算有以下几个特点：
一个数和0做XOR运算等于本身：a⊕0 = a
        一个数和其本身做XOR运算等于0：a⊕a = 0
XOR运算满足交换律和结合律：a⊕b⊕a = (a⊕a)⊕b = 0⊕b = b
故而在以上的基础条件上，将所有数字按照顺序做抑或运算，最后剩下的结果即为唯一的数字
        时间复杂度：O(n)，空间复杂度：O(1)

作者：guanpengchn
        链接：https://leetcode-cn.com/problems/two-sum/solution/hua-jie-suan-fa-136-zhi-chu-xian-yi-ci-de-shu-zi-b/
        来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。*/
#include <stdio.h>

int singleNumber(int* nums, int numsSize) {
    int temp = 0;
    for (int i = 0; i < numsSize; ++i) {
        temp = temp ^ nums[i];
    }
    return temp;
}

int main(int argc, char **argv) {
    int temp[] = {4,1,2,1,2};
    int result = singleNumber(temp, 5);
    printf("%d", result);
}