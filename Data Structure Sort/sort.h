#pragma once
#ifndef SORT_H_INCLUDE
#define SORT_H_INCLUDE

#include<iostream>
#include<bits/stdc++.h>

#define maxn 20
typedef int KeyType;
typedef struct {
	KeyType r[maxn];
	int length;
}SqList;

//√∞≈›≈≈–Ú
void Bubble_sort(SqList &L){
	bool flag = true;
	int m = L.length;
	while (m&&flag) {
		flag = false;
		for (int i = 0; i <= m; i++) {
			if (L.r[i] > L.r[i + 1]) {
				int t = L.r[i];
				L.r[i] = L.r[i + 1];
				L.r[i + 1] = t;
				flag = true;
			}
			m--;
		}
	}
}
//øÏÀŸ≈≈–Ú(…˝–Ú)
void qsort(SqList&L, int l, int r) {
	if (l >= r) return;
	int left = l, right = r;
	int base = L.r[l];
	while (l < r) {
		while (l < r&&L.r[r] >= base) r--;
		if (l < r)
			L.r[l] = L.r[r];
		while (l < r&&L.r[l] <= base) l++;
		if (l < r)
			L.r[r] = L.r[l];
	}
	L.r[l] = base;
	qsort(L, left, l - 1);
	qsort(L, l + 1, right);
}
//ºÚµ•µƒ—°‘Ò≈≈–Ú
void SelectSort(SqList &L) {
	for (int i = 1; i < L.length; i++) {
		int k = i;
		for (int j = i + 1; j < L.length; j++) {
			if (L.r[k] < L.r[j]) k = j;
			if (i != k) {
				int t = L.r[i];
				L.r[i] = L.r[k];
				L.r[k] = t;
			}
		}
	}
}

#endif // !SORT_H_INCLUEDE
