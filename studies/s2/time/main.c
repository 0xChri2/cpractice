#include <stdio.h>
#include <time.h>

char* getcurrenttime(void){
    time_t now;
    time(&now);
    struct tm *local_time = localtime(&now);
    static char buf[80];
    strftime(buf, sizeof(buf), "%d.%m.%Y", local_time);
    return buf;
};

int main() {
    char* time;
    time = getcurrenttime();
    printf("Time: %s", time);
}


