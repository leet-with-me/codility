#include <stdio.h>


// LOOK For the bugs

 int main()
 {  
    int N = 100;
    int enable_print = N % 10;
    while (N > 0) {
        if (enable_print == 0 && N % 10 != 0) {
            enable_print = 1;
        }
        else if (enable_print == 1) {
            printf("%d", N % 10);
        }
        N = N / 10;
    }
 }