#include <iostream>
#include <malloc.h>

using namespace std;

const int MaxSize = 50;
typedef char ElemType;

typedef struct {
    ElemType data[MaxSize];
    int length;
} Sqlist;       // define the type of sequence list

void createList(Sqlist * &L, ElemType a[], int n) { // create the sequence list wholly
    L = (Sqlist * ) malloc (sizeof(Sqlist));
    for (int i = 0; i < n; i ++) {
        L->data[i] = a[i];
    }
    L->length = n;
}

void initList(Sqlist * &L) {
    L = (Sqlist *) malloc (sizeof(Sqlist));
    L->length = 0;
}

void destroyList(Sqlist * &L) {
    free(L);
}

bool listEmpty(Sqlist * L) {
    return (L->length == 0);
}

int listLength(Sqlist * L) {
    return (L->length);
}

void dispList(Sqlist * L) {
    for (int i = 0; i < L->length; i ++) {
        cout << L->data[i] << " ";
    }
    cout << endl;
}

bool getElem(Sqlist * L, int i, ElemType &e) {
    if (i < 1 || i > L->length) 
        return false;
    e = L->data[i - 1];
    return true;
}

int locateElem(Sqlist* L, ElemType e) {
    int i = 0;
    while (i < L->length && L->data[i] != e) 
        i ++;
    if (i >= L->length) 
        return 0;
    else 
        return i + 1;
}

bool listInsert(Sqlist * &L, int i, ElemType e) {
	if (i < 1 || i > L->length + 1 || L->length == MaxSize) 
		return false;
	i --;
	for (int j = L->length; j > i; j --) 
		L->data[j] = L->data[j - 1];
    L->data[i] = e;
    L->length ++;
    return true;
}

bool listDelete(Sqlist * &L, int i, ElemType &e) {
    if (i < 1 || i > L->length) 
        return false;
    i --;
    e = L->data[i];
    for (int j = i; j < L->length - 1; j ++) {
        L->data[j] = L->data[j + 1];
    }
    L->length --;
    return true;
}
