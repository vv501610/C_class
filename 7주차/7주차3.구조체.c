#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 100

typedef struct point {
    int x;
    int y;
    
}POINT;

void print_point_array(POINT p[], int size) {
    for (int i = 0; i < size; i++) {
          printf("p[%d] = (%d, %d)\n", i, p[i].x, p[i].y);
    }
}

void input_random_array(POINT* p, int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        (p + i) -> x = rand()%101; //0~101까지의 난수
        (p + i) -> y = rand()%101;
    }
}

void swap_point(POINT* p1, POINT* p2) {
    POINT temp;
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

void selection_sort(POINT* point, int size) {
    int min_address;
    
    for (int i = 0; i < SIZE - 1; i++) {
        min_address = i;
        for (int j = i + 1; j < SIZE; j++) {
            if ((point + min_address)->x > (point + j)->x) {
                min_address = j;
            }
            else if ((point + min_address)->x == point[j].x && (point + min_address)->y > (point + j)->y) {
                min_address = j;
            }
        }
        swap_point(point + i, point + min_address);
    }
}


int main() {
    
    POINT point[SIZE] = {0};
    POINT temp = {0, 0};
    
    input_random_array(point, SIZE);
    print_point_array(point, SIZE);
    selection_sort(point, SIZE);

    
    printf("Array Sort ------------------->\n");
    print_point_array(point, SIZE);

    return 0;
}