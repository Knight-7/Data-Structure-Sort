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
//’€∞Î≤Â»Î≈≈–Ú
void BInsetSort(SqList &L) {
	for (int i = 2; i < L.length; i++) {
		L.r[0] = L.r[i];
		int low = i, high = i - 1;
		while (low <= high) {
			int mid = (low + high) / 2;
			if (L.r[0] > L.r[mid]) low = mid + 1;
			else high = mid - 1;
		}
		for (int j = i - 1; j >= high + 1; j--) L.r[j + 1] = L.r[j];
		L.r[high] = L.r[0];
	}
}
//œ£∂˚≈≈–Ú
void ShellInsert(SqList &L, int dt[], int t) {
	for (int k = 0; k < t; k++) {
		for (int i = dt[k] + 1; i < L.length; i++) {
			if (L.r[i] < L.r[i - dt[k]]) {
				L.r[0] = L.r[i];
				int j;
				for (j = i - dt[k]; j > 0 && L.r[0] < L.r[j]; j -= dt[k])
					L.r[j + dt[k]] = L.r[j];
				L.r[j + dt[k]] = L.r[0];
			}
		}
	}
}
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

//…∏—°∑®µ˜’˚∂—
void HeapAdjust(SqList &L, int s, int m) {
	int rc = L.r[s];
	for (int j = s * 2; j <= m; j *= 2) {
		if (j < m&&L.r[j] < L.r[j + 1]) j++;
		if (rc > L.r[j]) break;
		L.r[s] = L.r[j];
		s = j;
	}
	L.r[s] = rc;
}
//¥¥Ω®∂—
void CreatHeap(SqList &L) {
	int n = L.length;
	for (int i = n / 2; i; i++) {
		HeapAdjust(L, i, n);
	}
}
//∂—≈≈–Ú
void HeapSort(SqList &L) {
	CreatHeap(L);
	for (int i = L.length; i > 1; i--) {
		int x = L.r[1];
		L.r[1] = L.r[i];
		L.r[i] = x;
		HeapAdjust(L, 1, i - 1);
	}
}
//πÈ≤¢≈≈–Ú
void Merge() {

}


#endif // !SORT_H_INCLUEDE
