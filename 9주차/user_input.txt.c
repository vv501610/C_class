#include <stdio.h>

int getLine(char* line, int maxLength) {
    int ch;
    int i = 0;
    while ((ch = getchar()) != '\n' && i < maxLength - 1) {
        line[i++] = ch;
    }
    line[i] = '\0';
    return i;
}

int main() {
    char input[100];
    FILE* fp;

    if ((fp = fopen("output.txt", "w")) == NULL) {
        printf("error...");
        return 1; // 오류 발생 시 1 반환
    }

    for (int i = 0; i < 5; i++) {
        getLine(input, sizeof(input)); // 입력 길이 제한
        fputs(input, fp);
        fputs("\n", fp);
    }

    fclose(fp);
    return 0;
}
