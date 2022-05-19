#include "task.h"

//对已排序的rows,根据a的值，二分查找目标值最近的索引
int SearchByValuea(const Row* rows, int left, int right, int target) {
    while (left < right) {
        int mid = (left + right) / 2;
        if ((rows + mid)->a >= target) {
            right = mid;    //等于的时候，可能还不是最近的那一个
        }
        else {
            left = mid + 1;
        }
    }

    return left;
}

//对已排序的rows,根据b的值，二分查找目标值最近的索引
int SearchByValueb(const Row* rows, int left, int right, int target) {
    while (left < right) {
        int mid = (left + right) / 2;
        if ((rows + mid)->b >= target) {
            right = mid; //等于的时候，可能还不是最近的那一个
        }
        else {
            left = mid + 1;
        }
    }

    return left;
}

//查找符合条件的值，并打印输出， target表示符合条件的a值
static void search(const Row* rows, int nrows, int target) {
    int pos_a_left = 0;
    int pos_a_right = 0;
    int pos_b_left = 0;
    int pos_b_right = 0;

    //根据a值先缩小范围
    pos_a_left = SearchByValuea(rows, 0, nrows - 1, target - 1);
    pos_a_right = SearchByValuea(rows, 0, nrows - 1, target + 1);

    //找到a值等于target值的左起点
    while ((rows + pos_a_left)->a != target) {
        pos_a_left++;
    }

    //找到a值等于target值的右终点
    while ((rows + pos_a_right)->a != target) {
        pos_a_right--;
    }

    //根据a值确定的范围内，再根据b值进一步缩小区间
    pos_b_left = SearchByValueb(rows, pos_a_left, pos_a_right, 9);
    pos_b_right = SearchByValueb(rows, pos_a_left, pos_a_right, 50);

    //将满足条件的区间值打印
    for (int i = pos_b_left; i < pos_b_right; i++) {
            printf("%d, %d\n", (rows + i)->a, (rows + i)->b);
    }
}

void task2(const Row* rows, int nrows) {
    search(rows, nrows, 1000);
    search(rows, nrows, 2000);
    search(rows, nrows, 3000);
}