#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX_STRING_SIZE 16

static double diff_in_msecond(struct timespec t1, struct timespec t2)
{
    struct timespec diff;
    if (t2.tv_nsec-t1.tv_nsec < 0) {
        diff.tv_sec  = t2.tv_sec - t1.tv_sec - 1;
        diff.tv_nsec = t2.tv_nsec - t1.tv_nsec + 1000000000;
    } else {
        diff.tv_sec  = t2.tv_sec - t1.tv_sec;
        diff.tv_nsec = t2.tv_nsec - t1.tv_nsec;
    }
    return (diff.tv_sec + diff.tv_nsec / 1000000.0);
}

char smallest_character(char str[], char c)
{
    int i = 0;
    while (str[i] <= c && str[i] != '\0')
        i++;
    if (str[i] == '\0')
        return str[0];
    return str[i];
}

int main()
{
    FILE *in;
    char str[MAX_STRING_SIZE];
    char c;
    int i = 0;
    int countLine = 0;
    struct timespec start, end;
    double total_run_time;

    in = fopen("input_test.txt", "r");
    if (in == NULL) {
        printf("File Fail.\n");
        return -1;
    }

    while (fgets(str, sizeof(str), in)) {
        while (str[i] != '\0')
            i++;
        str[i - 1] = '\0';
        i = 0;
        c = fgetc(in);

        clock_gettime(CLOCK_REALTIME, &start);
        smallest_character(str, c);
        clock_gettime(CLOCK_REALTIME, &end);
        total_run_time += diff_in_msecond(start, end);

        c = fgetc(in);
        countLine++;
    }
    fclose(in);
    printf("smallest_character() average run time: %lf msec\n",
           total_run_time / (float)countLine);
    return 0;
}
