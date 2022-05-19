#include "task.h"

Row rows[] = {
    {1000,31},
    {1000,72},
    {1500,12},
    {1500,34},
    {2000,22},
    {2000,33},
    {2000,51},
    {3000,31},
    {3000,21},
    {3000,19},
    {3000,50},
    {4000,31},
};

int main(int argc, char** argv) {
    printf("task1:\n");
    task1(rows,sizeof(rows)/sizeof(Row));
    printf("============\n\n");

    printf("task2:\n");
    task2(rows, sizeof(rows) / sizeof(Row));
    printf("============\n\n");

    printf("task3:\n");
    task3(rows, sizeof(rows) / sizeof(Row));
    printf("============\n\n");

    getchar();
    return 0;
}