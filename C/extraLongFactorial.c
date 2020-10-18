/**
 * Program to calculate extra long factorials
 * using the naive multiplication method.
 */
#include<stdio.h>
#define MAX 500

/**
 * Maintains an array to store the result after
 * each step of multiplication. The digits are
 * stored in reverse order, i.e. 0th index is 
 * the rightmost digit and size-1 is the left 
 * most digit.
 */
void factorial(int n) {
    int ans[MAX] = {0};
    int size = 1;
    ans[0] = 1;
    for (int m = 2; m <= n; ++m) {
        int carry = 0;
        for (int i = 0; i < size; ++i) {
            int product = (ans[i] * m) + carry;
            ans[i] = product % 10;
            carry = product / 10;
        }
        while (carry) {
            ans[size++] = carry % 10;
            carry /= 10;
        }
    }
    for (int i = size - 1; i >= 0; --i) {
        printf("%d", ans[i]);
    }
    printf("\n");
}

int main() {
    factorial(100);
    return 0;
}