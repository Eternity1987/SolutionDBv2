#pragma once
#include <stdlib.h>
#include <stdio.h>

typedef struct Row {
    int a;
    int b;
} Row;

void task1(const Row* rows, int nrows);
void task2(const Row* rows, int nrows);
void task3(const Row* rows, int nrows);
//void task4(const Row* rows, int nrows);

int SearchByValuea(const Row* rows, int left, int right, int target);
int SearchByValueb(const Row* rows, int left, int right, int target);
