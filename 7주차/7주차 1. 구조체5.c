#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 100

typedef struct point {
    int x;
    int y;
    
}POINT;

int main() {
    
    POINT point[SIZE] = {0};
    POINT temp = {0, 0};
    int min_address;
    
    srand(time(NULL));
    
    for (int i = 0; i < SIZE; i++) {
        point[i].x = rand()%101; //0~101까지의 난수
        point[i].y = rand()%101;
    }
    
    for (int i = 0; i < SIZE; i++) {
           printf("point[%d] = (%d, %d)\n", i, point[i].x, point[i].y);
    }
    
    for (int i = 0; i < SIZE - 1; i++) {
        min_address = i;
        for (int j = i + 1; j < SIZE; j++) {
            if (point[min_address].x > point[j].x) {
                min_address = j;
            }
            else if (point[min_address].x == point[j].x && point[min_address].y > point[j].y) {
                min_address = j;
            }
        }
            temp = point[min_address];
            point[min_address] = point[i];
            point[i] = temp;
    }
    
    printf("Array Sort ------------------->\n");
    for (int i = 0; i < SIZE; i++) {
           printf("point[%d] = (%d, %d)\n", i, point[i].x, point[i].y);
    }

    return 0;
}