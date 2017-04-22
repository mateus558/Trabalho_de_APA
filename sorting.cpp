/**
*  Sorting algorithms, sorting.cpp
* Purpose: Implement algorithms to sort arrays of integers.
*
* @author Mateus Coutinho Marim	(mateus.marim@ice.ufjf.br)
* @author Mattheus Soares Santos
* @author Rafael Souza
* @author Aleksander Yacovenco
* @version 1.0 23/03/17
*/

#include "sorting.h"
#include <iostream>
#include <stdlib.h>

int comp = 0;	//Number of comparisons
int atrib = 0;	//Number of attributions

using namespace std;

/*!
	Swaps two elements in a vector.

	@param v is an c-like array.
	@param a is the position of the first element to be swaped.
	@param b is the position of the second element to be swaped.
	@return there is no return.
*/

void swap(Node v[], int a, int b){
	Node aux = v[a];
	v[a] = v[b];
	v[b] = aux;
	atrib += 3;
}

/*!
	Partition step of quick sort algorithm.

	@param v is an c-like array.
	@param low is the lowest position of the subarray.
	@param high is the highest position of the subarray.
	@return the pivot's position of the subarray.
*/

int partition(Node v[], int low, int high){
	int i, j;
	Node pivot = v[low];

	i = low;
	j = high;
	while(i < j){
		comp++;
		while(v[i].key <=pivot.key){
			comp++;
			atrib++;
			i++;
		}
		while(v[j].key >pivot.key){
			comp++;
			atrib++;
			j--;
		}
		if(i<j){
	 		comp++;
	 		swap(v, i, j);
	 	}

	}
	v[low] = v[j];
	v[j] = pivot;
	atrib += 5;
	return j;
}


/*!	Implementation of the quick sort algorithm

	@param v is an c-like array.
	@param low is the lowest position of the subarray.
	@param high is the highest position of the subarray.
	@return there is no return.
*/

void quick_sort(Node v[], int low, int high){
	if(low<high){
		comp++;
		atrib++;
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

void merge_sort(Node v[], int n)
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

void mergePart(Node v[], int a, int b)
{
	if (b - a > 1)
	{
		comp++;
		mergePart(v, a, a + (b - a) / 2 - 1);
		mergePart(v, a + (b - a) / 2, b);
		mergeJoin(v, a, b);
	}
	else if (v[a].key > v[b].key){
		swap(v, a, b);
		comp++;
	}
}

/*!
	Merge step of merge sort algorithm.

	@param v is a c-like array.
	@param a is the lowest position of the subarray.
	@param b is the highest position of the subarray.
	@return there is no return.
*/

void mergeJoin(Node v[], int a, int b)
{
	int i = a + (b - a + 1) / 2;
	int n = i, j;
	atrib += 2;
	while (a < n)
	{
		if (v[a].key > v[i].key){
			comp++;
			swap(v, a, i);
		}
		j = i;
		while (j < b && v[j].key > v[j + 1].key)
		{
			comp += 2;
			atrib++;
			swap(v, j, (j + 1));
			j++;
		}
		a++;
		comp++;
		atrib += 2;
	}
}

/*!	Implementation of the bubble sort algorithm

	@param v is an c-like array.
	@param n is the size of the array v.
	@return there is no return.
*/

void bubble_sort(Node v[], int n){
	int i, j, swaps;

	for(i = 0; ; ++i){
		swaps = 0;
		for(j = 0; j < n-1; ++j){			
			if(v[j].key > v[j + 1].key){
				comp++;
				swap(v, j + 1, j);
				swaps++;
			}
			comp++;
			atrib++;
		}
		atrib++;
		if(!swaps) return;
	}
}

/*!	Implementation of the selection sort algorithm

	@param v is an c-like array.
	@param n is the size of the array v.
	@return there is no return.
*/
void selection_sort(Node v[], int n){
	int i, j, min, pos_min;

	for(i = 0; i < n-1; i++){
		for(j = i + 1, min = v[i].key, pos_min = i; j < n; j++){
			atrib++;
			comp++;
			if(v[j].key < min){
				comp++;
				min = v[j].key;
				pos_min = j;
				atrib += 2;
			}
		}
		v[pos_min] = v[i];
		v[i].key = min;
		atrib += 5;
		comp++;
	}
}

/*! Implementation of the insertion sort algorithm.

	@param v is an c-like array.
	@param n is the size of the array v.
	@return there is no return.
*/
void insertion_sort(Node v[], int n){
	int i, j, x;

	for(i = 1; i < n; i++){
		x = v[i].key;
		atrib += 2;
		comp++;
		
		for(j = i - 1; j >= 0 && v[j].key > x; --j){
			v[j + 1] = v[j];
			v[j].key = x;
			atrib += 3;
			comp += 2;
		}
	}
}



/*! Implementation of the heapsort algorithm.

	@param a is an c-like array.
	@param n is the size of the array v.
	@return there is no return.
*/



void MAX_HEAPIFY(Node a[], int i, int n) /// transforma o vetor que receber em um maxheap
{
    int l,r,largest,loc;
    l=2*i;
    atrib++;
    r=(2*i+1);
    atrib++;
    if((l<=n)&&a[l].key>a[i].key)
        comp++;
	largest=l;
	atrib++;
    else
	comp++;
        largest=i;
	atrib++;
    if((r<=n)&&(a[r].key>a[largest].key))
	comp++;    
        largest=r;
	atrib++;
    if(largest!=i)
    {
	comp++;    
        loc=a[i].key;
	atrib++;
        a[i].key=a[largest].key;
	atrib++;    
        a[largest].key=loc;
	atrib++;    
        MAX_HEAPIFY(a, largest,n);
    }
}
void BUILD_MAX_HEAP(Node a[], int n) /// cria um maxheap
{
    for(int k = n/2; k >= 1; k--)
    {
	comp++;
        MAX_HEAPIFY(a, k, n);
    }
}
void HEAPSORT(Node a[], int n) /// recebe um vetor desordenado e aplica o heapsort nele
{

    BUILD_MAX_HEAP(a,n);
    int i, temp;
    for (i = n; i >= 2; i--)
    {
	comp++;
        temp = a[i].key;
	atrib++;    
        a[i].key = a[1].key;
	atrib++    
        a[1].key = temp;
	atrib++    
        MAX_HEAPIFY(a, 1, i - 1);
    }
}
