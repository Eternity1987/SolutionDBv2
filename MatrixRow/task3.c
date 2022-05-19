#include "task.h"
#include <string.h>

/* task2�Ľ��������a��ֵ�ֶζ���������ɵģ�
 * task3�ڴ˻����ϸ���b��ֵ���й鲢����
 */

//����bֵ���кϲ�
static void merge(Row* arr, int left, int mid, int right) {
    Row* tmp = (Row*)malloc(sizeof(Row) * (mid - left + 1));
    if (NULL == tmp) {
        printf("malloc error\n");
        return;
    }
    memset(tmp, 0, sizeof(Row) * (mid - left + 1));

    for (int i = left; i <= mid; i++) {
        (tmp + i - left)->a = (arr + i)->a;
        (tmp + i - left)->b = (arr + i)->b;
    }

    for (int i = 0, k = left, j = mid + 1; i < mid - left+1;) {
        if (j > right || (tmp + i)->b < (arr + j)->b) {
            (arr + k)->a = (tmp + i)->a;
            (arr + k)->b = (tmp + i)->b;
            k++;
            i++;
        }
        else {
            (arr + k)->a = (arr + j)->a;
            (arr + k)->b = (arr + j)->b;
            k++;
            j++;
        }
    }

    if (tmp) {
        free(tmp);
        tmp = NULL;
    }
}

//�鲢����
static void mergeSort(Row* arr, int left, int right) {
    if (left >= right) return;
    int mid = (left + right) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

//���ҷ���������ֵ��target��ʾ����������aֵ,��������������ֵ������result��
static void search(const Row* rows, int nrows, int target, Row **res, int *cnt) {
    int pos_a_left = 0;
    int pos_a_right = 0;
    int pos_b_left = 0;
    int pos_b_right = 0;

    //����aֵ����С��Χ
    pos_a_left = SearchByValuea(rows, 0, nrows - 1, target - 1);
    pos_a_right = SearchByValuea(rows, 0, nrows - 1, target + 1);

    //�ҵ�aֵ����targetֵ�������
    while ((rows + pos_a_left)->a != target) {
        pos_a_left++;
    }

    //�ҵ�aֵ����targetֵ�����յ�
    while ((rows + pos_a_right)->a != target) {
        pos_a_right--;
    }

    //����aֵȷ���ķ�Χ�ڣ��ٸ���bֵ��һ����С����
    pos_b_left = SearchByValueb(rows, pos_a_left, pos_a_right, 9);
    pos_b_right = SearchByValueb(rows, pos_a_left, pos_a_right, 50);

    //����������������ֵ�洢��result��
    for (int i = pos_b_left; i < pos_b_right; i++) {
        //printf("%d, %d\n", (rows + i)->a, (rows + i)->b);
        (*cnt) += 1;
        *res = (Row*)realloc(*res, (*cnt) * sizeof(Row));
        if (NULL == *res) {
            printf("realloc error\n");
            return;
        }
        (*res + *cnt - 1)->a = (rows + i)->a;
        (*res + *cnt - 1)->b = (rows + i)->b;
    }
}

void task3(const Row* rows, int nrows) {
    Row* res = (Row*)malloc(sizeof(Row));
    if (NULL == res) {
        printf("malloc error\n");
        return;
    }
    memset(res, 0, sizeof(Row));
    int cnt = 0;
    search(rows, nrows, 1000, &res, &cnt);
    search(rows, nrows, 2000, &res, &cnt);
    search(rows, nrows, 3000, &res, &cnt);

    //�鲢����
    mergeSort(res, 0, cnt - 1);
    for (int i = 0; i < cnt; i++) {
        printf("%d, %d\n", (res + i)->a, (res + i)->b);
    }

    if (res) {
        free(res);
        res = NULL;
    }
}