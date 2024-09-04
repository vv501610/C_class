#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int number[10];
    srand(time(NULL));
    
    for(int i = 0; i < 10; i++) {
        number[i] = (rand() % 100) + 1; // rand() 함수 사용
    }

    for(int i = 0; i < 10; i++) {
        printf("number[%d] = %d\n", i, number[i]);
    }

    return 0;
}
