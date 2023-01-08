#include "Myheader.h"
#include "uthash.h"

struct hash_table {
    int key;
    int val;
    UT_hash_handle hh;
};

typedef struct hash_table* hash_ptr;

struct pair {
    int first;
    int second;
};
struct pair* heap;
int heapSize;
int k;

bool comp(struct pair* a, struct pair* b) {
    return a->second < b->second;
}

int push(hash_ptr x) {
    if (heapSize < k) {
        heap[++heapSize].first = x->key;
        heap[heapSize].second = x->val;
        int p = heapSize, s;
        while (p > 1) {
            s = p >> 1;
            if (comp(heap + s, heap + p)) return;
            p = s;
        } 
    }
    else {
        int p = 10;
    }
    return 0;
}

int main(void) {
    
    int *nums;
    int numsSize;
    hash_ptr head = NULL;
    hash_ptr p = NULL, tmp = NULL;
    for (int i = 0; i < numsSize; i++) {
        HASH_FIND_INT(head, &nums[i], p);
        if (p == NULL) {
            p = (hash_ptr)malloc(sizeof(struct hash_table));
            p->key = nums[i];
            p->val = 1;
            HASH_ADD_INT(head, key, p);
        }
        else {
            p->val++;
        }
    }
    heap = malloc(sizeof(struct pair) * k);
    
    system("pause");
    return 0;
}