#include <stdio.h>
#define MAX_PRODUCTS 100

int main() {
    int count;
    int stock[MAX_PRODUCTS];
    int sales[MAX_PRODUCTS];
    int i, total_sales = 0;
    int max_sales = 0, min_sales = 0, max_id = 0, min_id = 0;

    double total_stock = 0, sales_ratio;

    // 상품 개수 입력
    do {
        printf("상품 개수를 입력하세요 (1~100): ");
        scanf("%d", &count);
    } while (count < 1 || count > MAX_PRODUCTS);

    // 상품별 입고 수량 입력
    printf("상품별 입고 수량을 입력하세요:\n");
    for (i = 0; i < count; i++) {
        scanf("%d", &stock[i]);
        total_stock += stock[i];
    }

    // 상품별 판매 수량 입력
    printf("상품별 판매 수량을 입력하세요:\n");
    for (i = 0; i < count; i++) {
        scanf("%d", &sales[i]);
        stock[i] -= sales[i];
        total_sales += sales[i];

        // 최대/최소 판매량 계산
        if (sales[i] > max_sales) {
            max_sales = sales[i];
            max_id = i + 1;
        }
        if (sales[i] < min_sales) {
            min_sales = sales[i];
            min_id = i + 1;
        }
    }

    // 결과 출력
    printf("\n재고수량 : ");
    for (i = 0; i < count; i++) {
        printf("%d ", stock[i]);
    }

    sales_ratio = (total_sales / total_stock) * 100;
    printf("\n총 판매량: %d (판매율 %.2lf%%)\n", total_sales, sales_ratio);

    printf("가장 많이 판매된 상품 : ID %d, 판매량 %d\n", max_id, max_sales);
    printf("가장 적게 판매된 상품 : ID %d, 판매량 %d\n", min_id, min_sales);

    // 재고 부족 경고
    for (i = 0; i < count; i++) {
        if (stock[i] <= 2) {
            printf("상품 ID %d : 재고부족(%d)\n", i + 1, stock[i]);
        }
    }

    return 0;
}