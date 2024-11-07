#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTS 5
#define FILENAME "products.dat"

struct Product {
    int id;
    char name[100];
    int price;
    int stock;
    int sales;
    int totalSales;
};

void inputStock(struct Product products[], int count);
void inputSales(struct Product products[], int count);
void displayIndividualStatus(struct Product products[], int count);
void displayAllStatus(struct Product products[], int count);
void saveProducts(struct Product products[], int count);
void loadProducts(struct Product products[], int count);

int main() {
    struct Product products[MAX_PRODUCTS] = {0};
    int choice;

    // 프로그램 시작 시 파일에서 데이터 로드
    loadProducts(products, MAX_PRODUCTS);

    while (1) {
        printf("\n[쇼핑몰 관리 프로그램]\n");
        printf("원하는 메뉴를 선택하세요.(1. 입고, 2. 판매, 3. 개별현황, 4. 전체현황, 5. 저장, 6. 불러오기, 7. 종료): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                inputStock(products, MAX_PRODUCTS);
                break;
            case 2:
                inputSales(products, MAX_PRODUCTS);
                break;
            case 3:
                displayIndividualStatus(products, MAX_PRODUCTS);
                break;
            case 4:
                displayAllStatus(products, MAX_PRODUCTS);
                break;
            case 5:
                saveProducts(products, MAX_PRODUCTS);
                break;
            case 6:
                loadProducts(products, MAX_PRODUCTS);
                break;
            case 7:
                printf("프로그램을 종료합니다.\n");
                return 0;
            default:
                printf("잘못된 선택입니다. 다시 선택해주세요.\n");
        }
    }

    return 0;
}

// 기존 함수들은 동일하게 유지...

void saveProducts(struct Product products[], int count) {
    FILE *file = fopen(FILENAME, "wb");
    if (file == NULL) {
        printf("파일을 저장할 수 없습니다.\n");
        return;
    }

    fwrite(products, sizeof(struct Product), count, file);
    fclose(file);
    printf("상품 정보가 성공적으로 저장되었습니다.\n");
}

void loadProducts(struct Product products[], int count) {
    FILE *file = fopen(FILENAME, "rb");
    if (file == NULL) {
        printf("저장된 파일이 없습니다.\n");
        return;
    }

    fread(products, sizeof(struct Product), count, file);
    fclose(file);
    printf("상품 정보를 성공적으로 불러왔습니다.\n");
}

void inputStock(struct Product products[], int count) {
    int id;
    printf("상품ID: ");
    scanf("%d", &id);

    if (id < 1 || id > count) {
        printf("잘못된 상품 ID입니다.\n");
        return;
    }

    id--; // 배열 인덱스로 변환

    if (products[id].id == 0) {
        products[id].id = id + 1;
        printf("상품명: ");
        scanf("%s", products[id].name);
        printf("판매가격: ");
        scanf("%d", &products[id].price);
    }

    printf("입고량: ");
    scanf("%d", &products[id].stock);
    
    printf("입고가 완료되었습니다.\n");
}

void inputSales(struct Product products[], int count) {
    int id, quantity;
    printf("상품ID: ");
    scanf("%d", &id);

    if (id < 1 || id > count || products[id-1].id == 0) {
        printf("잘못된 상품 ID입니다.\n");
        return;
    }

    id--; // 배열 인덱스로 변환

    printf("판매량: ");
    scanf("%d", &quantity);

    if (quantity > products[id].stock) {
        printf("재고가 부족합니다.\n");
        return;
    }

    products[id].stock -= quantity;
    products[id].sales += quantity;
    products[id].totalSales += quantity * products[id].price;
    printf("판매가 완료되었습니다.\n");
}

void displayIndividualStatus(struct Product products[], int count) {
    int id;
    printf("상품ID: ");
    scanf("%d", &id);

    if (id < 1 || id > count || products[id-1].id == 0) {
        printf("잘못된 상품 ID입니다.\n");
        return;
    }

    id--; // 배열 인덱스로 변환

    printf("상품ID: %d\n", products[id].id);
    printf("상품명: %s\n", products[id].name);
    printf("가격: %d\n", products[id].price);
    printf("재고: %d\n", products[id].stock);
    printf("판매량: %d\n", products[id].sales);
    printf("총 판매금액: %d\n", products[id].totalSales);
}

void displayAllStatus(struct Product products[], int count) {
    int total_sales = 0;
    int total_stock = 0;
    int max_sales = 0, min_sales = -1;
    int max_id = 0, min_id = 0;

    printf("전체 상품 현황:\n");
    printf("ID\t상품명\t가격\t재고\t판매량\t총 판매금액\n");

    for (int i = 0; i < count; i++) {
        if (products[i].id != 0) {
            printf("%d\t%s\t%d\t%d\t%d\t%d\n", 
                products[i].id, products[i].name, products[i].price, 
                products[i].stock, products[i].sales, products[i].totalSales);

            total_sales += products[i].sales;
            total_stock += products[i].stock + products[i].sales;

            if (products[i].sales > max_sales) {
                max_sales = products[i].sales;
                max_id = i;
            }
            if (min_sales == -1 || products[i].sales < min_sales) {
                min_sales = products[i].sales;
                min_id = i;
            }
        }
    }

    if (total_stock > 0) {
        double sales_ratio = (double)total_sales / total_stock * 100;
        printf("\n총 판매량 : %d (판매율 %.2f%%)\n", total_sales, sales_ratio);
        printf("가장 많이 판매된 상품 : ID %d, 상품명 : %s, 판매량 %d\n", products[max_id].id, products[max_id].name, max_sales);
        printf("가장 적게 판매된 상품 : ID %d, 상품명 : %s, 판매량 %d\n", products[min_id].id, products[min_id].name, min_sales);

        for (int i = 0; i < count; i++) {
            if (products[i].id != 0 && products[i].stock <= 2) {
                printf("상품 ID : %d, 상품명 : %s : 재고부족(%d)\n", products[i].id, products[i].name, products[i].stock);
            }
        }
    } else {
        printf("\n등록된 상품이 없습니다.\n");
    }
}