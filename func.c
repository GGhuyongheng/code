#include "Myheader.h"

// 最大子序列和
int maxSumOfSubset(int nums[], int numsSize) {
    int ans = nums[0], sum = 0;
    for(int i = 0; i < numsSize; i++) {
        sum += nums[i];
        ans = ans < sum ? sum : ans;
        if (sum <= 0)
            sum = 0;
    }

    return ans;
}

// Leetcode 209
int minSumOfSubarr(int nums[], int numsSize, int target) {
    int sum = 0;
    int Ans = __INT_MAX__;
    int start = 0;
    for (int i = start; i < numsSize; i++) {
        sum += nums[i];
        
        while (sum >= target) {
            Ans = fmin(Ans, i - start + 1);
            sum -= nums[start];
            start++;
        }
    }
    return Ans == __INT_MAX__? 0 : Ans;
}

// 寻找两数之和为target
int cmpInt(const void* a, const void* b) {
    return (*(int*)a) - (*(int*)b);
}
int twoSum(int nums[], int numsSize, int target) {
    int (*funcPtr)(const void *, const void *);
    funcPtr = cmpInt;
    qsort(nums, numsSize, sizeof(nums[0]), funcPtr);
    return 1;
}

// 分治算法
void mergeSort(int* arr, int left, int right) {
    int mid;
    
    if(left < right) {
        mid = left + (right - left)/2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);
        merge(arr, left, mid, right);
    }
}

void merge(int* arr, int left, int mid, int right) {
    int arrSize = right - left + 1;
    int temp1 = left, temp2 = mid + 1;
    int index = 0;
    int* arrCopy = (int* )malloc(sizeof(int)*arrSize);
    while(temp1 <=mid && temp2 <= right) {
        if(arr[temp1] <= arr[temp2])
            arrCopy[index++] = arr[temp1++];
        else arrCopy[index++] =arr[temp2++];
    }
    if(temp1 <= mid) {
        for(int i = temp1; i < mid + 1; i++)
            arrCopy[index++] = arr[i];
    }
    if(temp2 <= right) {
        for(int i = temp2; i < right + 1; i++)
            arrCopy[index++] = arr[i];
    }
    index = 0;
    for(int i = left; i < right + 1; i++)
        arr[i] = arrCopy[index++];
    free(arrCopy);
}

// Leetcode 542 01矩阵
const int dx[4] = {1, 0, 0, -1};
const int dy[4] = {0, 1, -1, 0};
int** updateMatrix(int** mat, int matSize, int* matColSize, int* returnSize, int** returnColumnSizes){
    //int** result;
    int n = matSize;
    int m = *matColSize;

    int** result;
    result = (int**)malloc(n *sizeof(int*));
    for (int i = 0; i < m ; i++)
        result[i] = (int*)malloc(m *sizeof(int));
    int seen[n][m];

    int Q[n * m][2];
    int first = 0, last = 0;

    *returnSize = n;
    *returnColumnSizes = (int*)malloc(n * sizeof(int));
    
    for (int i = 0; i < n; i++) {
        (*returnColumnSizes)[i] = m;
    }

    //result = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        //result[i] = (int*)malloc(m * sizeof(int));
        for (int j = 0; j < m; j++) {
            seen[i][j] = 0;
            result[i][j] = 0;
            if (mat[i][j] == 0) {
                Q[last][0] = i;
                Q[last++][1] = j;
                seen[i][j] = 1;
            }
        }
    }
    
    while (first < last) {
        int x = Q[first][0];
        int y = Q[first][1];
        first++;

        for (int i = 0; i < 4; i++) {
            int mx = x + dx[i], my = y + dy[i];
            if (mx >=0 && mx < n && my >= 0 && my < m && !seen[mx][my]) {
                result[mx][my] = result[x][y] + 1;
                seen[mx][my] = 1;
                Q[last][0] = mx;
                Q[last++][1] = my;
            }
        }
    }

    return result;
}

int test542(void) {
    int MatSize = 3;
    int A[3][3] = {
        {0,0,0},
        {0,1,0},
        {1,1,1}
    };
    int** mat;
    mat = (int**)malloc(MatSize * sizeof(int*));
    for (int i = 0; i < MatSize; i++) {
        mat[i] = A[i]; //这个比较关键，二维数组不能A直接赋值给int** mat:因为(mat + 1) 不等于(A + 1)，所以需要单独赋值
        // printf("%p %p %d\n", mat[i], A[i], mat[i][1]);
    }
    // getchar();
    int** result;
    int matSize = 3, matColSize = 3, returnSize, *returnColSize;
    
    result = updateMatrix(mat, matSize, &matColSize, &returnSize, &returnColSize);
    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j < returnColSize[i]; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    getchar();
    return 0;
}

//Leetcode 28.寻找模式串，经典KMP算法
void getNextArray(int *next, char *t) {
    int i, j = 0;
    next[0] = j;
    for (i = 1; i < strlen(t); i++) {
        while( j > 0 && t[i] != t[j])
            j = next[j - 1];
        if(t[i] == t[j]) {
            j++;
        }
        next[i] = j;
    }
}
int strStrKMP(char *s, char *t) {
    int next[100];
    getNextArray(next, t);
    int i, j = 0;
    for (i = 0; i < strlen(s); i++) {
        while(j > 0 && s[i] != t[j])
            j = next[j - 1];
        if(s[i] == t[j]){
            j++;
        }
        if(j == strlen(t))
            return (i - j + 1);
    }

    return -1;
}

void test28() {
    char *s = "aabaabaaf";
    char *t = "aabaaf";
    printf("%d\n", strStrKMP(s, t));
}

// 滑动窗口中的最大值 leetcode239
struct Stack;
typedef struct Stack* StackPtr;

struct Stack {
    int left;
    int right;
    int *arr;
};
int empty(StackPtr S) {
    return !((S->right >= 0) && (S->left <= S->right));
}

int Shead(StackPtr S) {
    return S->arr[S->left];
}
int Sback(StackPtr S) {
    return S->arr[S->right];
}

int pop(StackPtr S) {
    return S->arr[S->left++];
}

void push(StackPtr S, int value) {
    while(!empty(S) && (value > Sback(S)))
        S->right--;
    S->arr[++(S->right)] = value;
}
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize){
    int *result;
    *returnSize = 0;
    result = (int *)malloc((numsSize - k + 1) * sizeof(int));
    StackPtr S;
    S = (StackPtr)malloc(sizeof(struct Stack));
    S->arr = (int *)malloc(numsSize * sizeof(int) + 1);
    S->left = 0;
    S->right = -1;
    for (int i = 0 ; i < k; i++) {
        push(S, nums[i]);
    }
    result[(*returnSize)++] = Shead(S);

    for (int i = k; i < numsSize; i++) {
        if(nums[i - k] == Shead(S))
            pop(S);
        push(S, nums[i]);
        result[(*returnSize)++] = Shead(S);
    }
    return result;
}

void test239() {
    int A[11] = {1, 3, -1, -3, 5, 3, 6, 7, 3, 2, 1};
    int *nums = A;
    int returnSize;
    int *result = maxSlidingWindow(nums, 11, 3, &returnSize);
    for(int i = 0; i < 9; i++)
        printf("%d ", result[i]);
}