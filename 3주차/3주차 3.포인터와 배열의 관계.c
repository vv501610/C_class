#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 100

void InputRandomArray(int* array, int size) {
    for(int i = 0; i < size; i++) {
        *(array+i) = rand() % 100;
    }
}

void PrintArray(int * array, int size) {

    for(int i = 0; i<SIZE; i++) {
        printf("%3d\t", array[i]);
        if((i+1) % 10 == 0 ) printf("\n");
    }


}

int main() {
    int number[SIZE];

    srand(time(NULL));
    InputRandomArray(number, SIZE);

    PrintArray(number, SIZE);


    return 0;
}