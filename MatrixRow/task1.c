#include "task.h"

void task1(const Row* rows, int nrows) {
    for (int i = 0; i < nrows; i++) {
        if (((rows + i)->b >= 10 && (rows + i)->b < 50) &&
          ((rows + i)->a == 1000|| (rows + i)->a == 2000 || (rows + i)->a == 3000)) {
            printf("%d, %d\n", (rows + i)->a, (rows + i)->b);
        }
    }
}