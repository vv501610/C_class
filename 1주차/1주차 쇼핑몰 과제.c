#include <stdio.h>
#define MAX_PRODUCTS 100

int main() {
    int count;
    int stock[MAX_PRODUCTS];
    int sales[MAX_PRODUCTS];
    int i, id;

    // 상품 개수 입력
    do {
        printf("상품 개수를 입력하세요 (1-100): \n");
        scanf("%d", &count);
    } while (count < 1 || count > MAX_PRODUCTS);

    // 상품별 입고 수량 입력
    printf("상품별 입고 수량을 입력하세요:\n");
    for (i = 0; i < count; i++) {
        scanf("%d", &stock[i]);
    }

    // 상품별 판매 수량 입력
    printf("상품별 판매 수량을 입력하세요:\n");
    for (i = 0; i < count; i++) {
        scanf("%d", &sales[i]);
        stock[i] -= sales[i];  
    }

    // ID 입력 및 재고 출력
    printf("조회할 상품의 ID를 입력하세요 (1-%d): ", count);
    scanf("%d", &id);

    if (id < 1 || id > count) {
        printf("잘못된 ID입니다.\n");
        return 1;
    }

    printf("%d\n", stock[id-1]);  

    // 전체 재고 수량 출력
    for (i = 0; i < count; i++) {
        printf("%d ", stock[i]);
    }

    return 0;
}