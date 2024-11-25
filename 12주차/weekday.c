#include <stdio.h>
#include <time.h>

int main(int argc, char* argv[]) {
    time_t current;
    struct tm* timeinfo;

    int year, month, day;
    char* WEEK[] = {"sun", "mon", "tue", "wed", "thu", "fri", "sat"};

    printf("Enter YYYY MM DD : ");
    scanf("%d %d %d", &year, &month, &day);

    current = time(NULL);
    timeinfo = localtime(&current);

    timeinfo->tm_year = year - 1900;
    timeinfo->tm_mon = month - 1;
    timeinfo->tm_mday = day;

    mktime(timeinfo); // mktime() 호출하여 tm 구조체를 업데이트합니다.

    printf("%d %d %d -> %s\n", year, month, day, WEEK[timeinfo->tm_wday]);
    return 0;
}
