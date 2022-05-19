#include "task.h"

//���������rows,����a��ֵ�����ֲ���Ŀ��ֵ���������
int SearchByValuea(const Row* rows, int left, int right, int target) {
    while (left < right) {
        int mid = (left + right) / 2;
        if ((rows + mid)->a >= target) {
            right = mid;    //���ڵ�ʱ�򣬿��ܻ������������һ��
        }
        else {
            left = mid + 1;
        }
    }

    return left;
}

//���������rows,����b��ֵ�����ֲ���Ŀ��ֵ���������
int SearchByValueb(const Row* rows, int left, int right, int target) {
    while (left < right) {
        int mid = (left + right) / 2;
        if ((rows + mid)->b >= target) {
            right = mid; //���ڵ�ʱ�򣬿��ܻ������������һ��
        }
        else {
            left = mid + 1;
        }
    }

    return left;
}

//���ҷ���������ֵ������ӡ����� target��ʾ����������aֵ
static void search(const Row* rows, int nrows, int target) {
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

    //����������������ֵ��ӡ
    for (int i = pos_b_left; i < pos_b_right; i++) {
            printf("%d, %d\n", (rows + i)->a, (rows + i)->b);
    }
}

void task2(const Row* rows, int nrows) {
    search(rows, nrows, 1000);
    search(rows, nrows, 2000);
    search(rows, nrows, 3000);
}