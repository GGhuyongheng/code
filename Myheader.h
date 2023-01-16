#ifndef _MYHEADER_H
#define _MYHEADER_H
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <malloc.h>
#include <stdbool.h>
#include "uthash.h"


int maxSumOfSubset(int arr[], int arrSize);
int minSumOfSubarr(int arr[], int arrSize, int target);
void merge(int* arr, int left, int mid, int right);
void mergeSort(int* arr, int left, int right);
int** updateMatrix(int** mat, int matSize, int* matColSize, int* returnSize, int** returnColumnSizes);
int strStrKMP(char *s, char *t);
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize);
#endif