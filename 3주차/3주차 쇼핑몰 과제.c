#include <stdio.h>

#define MAX_PRODUCTS 5



void inputStock(int *stock, int count);
void inputSales(int *stock, int *sales, int count);
void displayProductStatus(int *stock, int *sales, int count);
void inputIndividualStock(int *stock, int count);
void inputIndividualSales(int *stock, int *sales, int count);

int main() {
    int stock[MAX_PRODUCTS] = {0, 0, 0, 0, 0};
    int sales[MAX_PRODUCTS] = {0, 0, 0, 0, 0};
    int choice;

    


    while (1) {
        printf("\n[쇼핑몰 관리 프로그램]\n");
        printf("원하는 메뉴를 선택하세요.(1. 입고, 2. 판매, 3. 상품현황, 4. 종료): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                inputStock(stock, MAX_PRODUCTS);
                break;
            case 2:
                inputSales(stock, sales, MAX_PRODUCTS);
                break;
            case 3:
                displayStatus(stock, sales, MAX_PRODUCTS);
                break;
            case 4:
                printf("프로그램을 종료합니다.\n");
                return 0;
            default:
                printf("잘못된 선택입니다. 다시 선택해주세요.\n");
        }
    }

    return 0;
}


void inputStock(int *stock, int count) {
    int choice;
    printf("입고수량 입력 : 전체 상품 입고수량 입력 1, 개별 상품 입력 2를 선택: ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("전체 상품의 입고수량을 입력하세요: ");
        for (int i = 0; i < count; i++) {
            int quantity;
            scanf("%d", &quantity);
            *(stock + i) += quantity;
        }
    } else if (choice == 2) {
        inputIndividualStock(stock, count);
    } else {
        printf("잘못된 선택입니다.\n");
    }
}

void inputIndividualStock(int *stock, int count) {
    int id, quantity;
    printf("상품ID: ");
    scanf("%d", &id);
    if (id < 1 || id > count) {
        printf("잘못된 상품 ID입니다.\n");
        return;
    }
    printf("입고수량: ");
    scanf("%d", &quantity);
    *(stock + id - 1) += quantity;
}

void inputSales(int *stock, int *sales, int count) {
    int choice;
    printf("판매수량 입력 : 전체 상품 판매수량 입력 1, 개별 상품 입력 2를 선택: ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("전체 상품의 판매수량을 입력하세요: ");
        for (int i = 0; i < count; i++) {
            int quantity;
            scanf("%d", &quantity);
            if (quantity <= *(stock + i)) {
                *(stock + i) -= quantity;
                *(sales + i) += quantity;
            } else {
                printf("상품 ID %d의 재고가 부족합니다.\n", i + 1);
            }
        }
    } else if (choice == 2) {
        inputIndividualSales(stock, sales, count);
    } else {
        printf("잘못된 선택입니다.\n");
    }
}

void inputIndividualSales(int *stock, int *sales, int count) {
    int id, quantity;
    printf("상품ID: ");
    scanf("%d", &id);
    if (id < 1 || id > count) {
        printf("잘못된 상품 ID입니다.\n");
        return;
    }
    printf("판매수량: ");
    scanf("%d", &quantity);
    if (quantity <= *(stock + id - 1)) {
        *(stock + id - 1) -= quantity;
        *(sales + id - 1) += quantity;
    } else {
        printf("재고가 부족합니다.\n");
    }
}

void displayProductStatus(int *stock, int *sales, int count) {
    int total_sales = 0;
    int total_stock = 0;
    int max_sales = 0, min_sales = *sales;
    int max_id = 0, min_id = 0;

    printf("재고수량 : ");
    for (int i = 0; i < count; i++) {
        printf("%d ", *(stock + i));
        total_sales += *(sales + i);
        total_stock += *(stock + i) + *(sales + i);

        if (*(sales + i) > max_sales) {
            max_sales = *(sales + i);
            max_id = i + 1;
        }
        if (*(sales + i) < min_sales) {
            min_sales = *(sales + i);
            min_id = i + 1;
        }
    }

    double sales_ratio = (double)total_sales / total_stock * 100;
    printf("\n총 판매량 : %d (판매율 %.2f%%)\n", total_sales, sales_ratio);
    printf("가장 많이 판매된 상품 : ID %d, 판매량 %d\n", max_id, max_sales);
    printf("가장 적게 판매된 상품 : ID %d, 판매량 %d\n", min_id, min_sales);

    for (int i = 0; i < count; i++) {
        if (*(stock + i) <= 2) {
            printf("상품 ID %d : 재고부족(%d)\n", i + 1, *(stock + i));
        }
    }
}