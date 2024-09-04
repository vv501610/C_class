#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 100

int main(void){
    
    srand((unsigned int)time(NULL));
    
    int number[SIZE], total = 0, max, min;
    float avg = 0.0;
    
    for(int i = 0; i<SIZE; i++){
        number[i] = (rand()%100)+1;
    }
    
    for(int i = 0; i<SIZE; i++){
        printf("%3d\t\t", number[i]);
        if((i+1)%10==0) printf("\n");
    }
    
    for(int i = 0; i<SIZE; i++){
        total += number[i];
    }
    
    avg = (float)total / SIZE;
    
    
    max = 0;
    min = 0;

    for(int i = 1; i<SIZE; i++){
        if(number[max] < number[i]) max = i;
        if(number[min] > number[i]) min = i;
    }
    
    printf("avg = %f, max=%d, min = %d\n", avg, number[max], number[min]);
    
    
    return 0;
}