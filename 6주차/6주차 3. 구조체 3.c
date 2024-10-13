#include <stdio.h>
#include <math.h>

typedef struct point {
    int x;
    int y;
} POINT;

typedef struct {
    POINT center;
    double radius;
} CIRCLE;

typedef struct rect {
    POINT lb; 
    POINT rt; 
} RECT;


double dist(POINT p1, POINT p2) {
    return sqrt(pow((p2.x - p1.x), 2) + pow((p2.y - p1.y), 2));
}

// 예시로 사용할 메인 함수
int main() {
    POINT p1 = {0, 0};
    POINT p2 = {3, 4};
    
    printf("두 점 사이의 거리: %f\n", dist(p1, p2));
    return 0;
}
