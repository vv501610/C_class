#include <stdio.h>

// int getLine(char* line, int maxLength) {
//     int ch;
//     int i = 0;
//     while ((ch = getchar()) != '\n' && i < maxLength - 1) {
//         line[i++] = ch;
//     }
//     line[i] = '\0';
//     return i;
// }


int main() {
    char input[100];
    int num1, num2;
    FILE* fp_src;
    FILE* fp_dest;

    if ((fp_src = fopen("output.txt", "r")) == NULL) {
        printf("error...\n");
        return 0;
    }

    if ((fp_dest = fopen("output3.txt", "w")) == NULL) {
        printf("error...\n");
        fclose(fp_src);
        return 0;
    }

    while (!feof(fp_src)) {
        fscanf(fp_src, "%s %d %d\n", input, &num1, &num2);
        fprintf(fp_dest, "%s %d %d\n", input, num1, num2);
    }

    fclose(fp_src);
    fclose(fp_dest);
    return 0;
}
