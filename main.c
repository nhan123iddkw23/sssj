#include "stdio.h"
#include "stdarg.h"
#include "math.h"

int check_integer(double n){
    int flag = 1;
    if (n != (int)n) flag = 0;
    return flag;
}


double tong(int sum, ...) {
    int flag = 0;
    double flag1 = 0;
    va_list ptr;
    va_start(ptr, sum);
    for (int i = 0; i < sum; i++) {
        double x = va_arg(ptr, double);
        if (check_integer(x) == 1) {
            flag += (int)x;
        }
        else {
            flag1 += x;
        }
    }
    va_end(ptr);
    return (double)flag + flag1;
}


int main() {
    double total = tong(3, 4.3, 5.2, 6.4);
    printf("tong la %lf", total);
    return 0;
}