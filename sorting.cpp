/**
*  Sorting algorithms, sorting.cpp
* Purpose: Implement algorithms to sort arrays of integers
*
* @author Mateus Coutinho Marim
* @version 1.0 23/03/17
*/

#include "sorting.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

/*!
	Swaps two elements in a vector.

	@param v is an c-like array.
	@param a is the position of the first element to be swaped.
	@param b is the position of the second element to be swaped.
	@return there is no return.
*/

void swap(int v[], int a, int b){
	int aux = v[a];
	v[a] = v[b];
	v[b] = aux;
}

/*!
	Partition step of quick sort algorithm.

	@param v is an c-like array.
	@param low is the lowest position of the subarray.
	@param high is the highest position of the subarray.
	@return the pivot's position of the subarray.
*/

int partition(int v[], int low, int high){
	int pivot, i, j;
	pivot = v[low];
	i = low;
	j = high;
	while(i < j){
		while(v[i] <=pivot)
		i++;
		while(v[j]>pivot)
		j--;
		if(i<j)
		swap(v, i, j);

	}
	v[low] = v[j];
	v[j] = pivot;
	return j;
}


/*!	Implementation of the quick sort algorithm

	@param v is an c-like array.
	@param low is the lowest position of the subarray.
	@param high is the highest position of the subarray.
	@return there is no return.
*/

void quick_sort(int v[], int low, int high){
	if(low<high){
		int pivot = partition(v, low, high);
		quick_sort(v, low, (pivot-1));
		quick_sort(v, (pivot+1), high);
	}
}

/*!	Implementation of the merge sort algorithm

	@param v is a c-like array.
	@param n is the size of the array v.
	@return there is no return.
*/

void merge_sort(int v[], int n)
{
	mergePart(v, 0, n / 2 - 1);
	mergePart(v, n / 2, n - 1);
	mergeJoin(v, 0, n - 1);
}

/*!
	Partition step of merge sort algorithm.

	@param v is a c-like array.
	@param a is the lowest position of the subarray.
	@param b is the highest position of the subarray.
	@return there is no return.
*/

void mergePart(int v[], int a, int b)
{
	if (b - a > 1)
	{
		mergePart(v, a, a + (b - a) / 2 - 1);
		mergePart(v, a + (b - a) / 2, b);
		mergeJoin(v, a, b);
	}
	else if (v[a] > v[b])
		swap(v, a, b);
}

/*!
	Merge step of merge sort algorithm.

	@param v is a c-like array.
	@param a is the lowest position of the subarray.
	@param b is the highest position of the subarray.
	@return there is no return.
*/

void mergeJoin(int v[], int a, int b)
{
	int i = a + (b - a + 1) / 2;
	int n = i;
	while (a < n)
	{
		if (v[a] > v[i])
			swap(v, a, i);
		int j = i;
		while (j < b && v[j] > v[j + 1])
		{
			swap(v, j, j + 1);
			j++;
		}
		a++;
	}
}

/*!	Implementation of the bubble sort algorithm

	@param v is an c-like array.
	@param n is the size of the array v.
	@return there is no return.
*/

void bubble_sort(int v[], int n){
	int i, j, swaps;

	for(i = 0; ; ++i){
		swaps = 0;
		for(j = 0; j < n-1; ++j){
			if(v[j] > v[j + 1]){
				swap(v, j + 1, j);
				swaps++;
			}
		}
		if(!swaps) return;
	}
}

/*!	Implementation of the selection sort algorithm

	@param v is an c-like array.
	@param n is the size of the array v.
	@return there is no return.
*/
void selection_sort(int v[], int n){
	int i, j, min, pos_min;

	for(i = 0; i < n-1; i++){
		for(j = i + 1, min = v[i], pos_min = i; j < n; j++){
			if(v[j] < min){
				min = v[j];
				pos_min = j;
			}
		}
		v[pos_min] = v[i];
		v[i] = min;
	}
}

/*! Implementation of the insertion sort algorithm.

	@param v is an c-like array.
	@param n is the size of the array v.
	@return there is no return.
*/
void insertion_sort(int v[], int n){
	int i, j, x;

	for(i = 1; i < n; i++){
		x = v[i];

		for(j = i - 1; j >= 0 && v[j] > x; --j){
			v[j + 1] = v[j];
			v[j] = x;
		}
	}
}
