#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

int main(int argc, char* argv[]) {
    time_t calendar_s = time(NULL);
    clock_t cpu_s = clock();
    struct tm *time_data;

    time_data = localtime(&calendar_s);
    printf("Day: %d\nWeekday: %d\n%d:%d\n", time_data->tm_mday, time_data->tm_wday, time_data->tm_hour, time_data->tm_min);

    printf("Initial cpu time = %lld\nInitial calendar time = %lld\n", (long long)cpu_s, (long long)calendar_s);
    char *str = NULL;
    system("ls -lah .");
    assert((str = getenv("HOME")) != NULL);
    printf("%s\n", str);

    clock_t cpu_e = clock();
    time_t calendar_e = time(NULL);
    printf("Final cpu time: %lld\nFinal Calendar time: %lld\n", (long long)cpu_e, (long long)calendar_e);
    return 0;
}
