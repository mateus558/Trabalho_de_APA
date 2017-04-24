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

long long int comp = 0;		//Number of comparisons
long long int atrib = 0;	//Number of attributions

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

/*!	Implementation of the quick sort algorithm

	@param v is an c-like array.
	@param low is the lowest position of the subarray.
	@param high is the highest position of the subarray.
	@return there is no return.
*/

void quick_sort(Node v[], int low, int high)
{
	int pivot, aux;
	int i, j;
	pivot = v[(low + high) / 2].key;
	i = low;
	j = high;
	atrib += 3;

	while(i <= j)
	{
		while(v[i].key < pivot)
		{
			comp++;
			i++;
		}
		while(v[j].key > pivot)
		{
			comp++;
			j--;
		}
		if(i <= j)
		{
			comp++;
			swap(v, i, j);
			i++;
			j--;
		}
	}

	if(j > low)
		quick_sort(v, low, j);

	if(i < high)
		quick_sort(v, j + 1, high);
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
	merge(v, 0, n - 1);
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
	comp++;
	if (b - a > 1)
	{
		mergePart(v, a, (a + b) / 2);
		mergePart(v, (a + b) / 2 + 1, b);
		merge(v, a, b);
	}
	else if (v[a].key > v[b].key)
	{
		comp++;
		swap(v, a, b);
	}
}

/*!
	Merge step of merge sort algorithm.

	@param v is a c-like array.
	@param a is the lowest position of the subarray.
	@param b is the highest position of the subarray.
	@return there is no return.
*/

void merge(Node v[], int a, int b)
{
	int tam = b - a + 1;
	int m = (a + b) / 2;
	int j = a;
	int k = m + 1;
	int vetAux[tam];
	atrib += 5;
	for (int i = 0; i < tam; i++)
	{
		if (v[j].key < v[k].key && j <= m)
			vetAux[i] = v[j++].key;
		else
			vetAux[i] = v[k++].key;
		atrib++;
		comp += 3;
	}
	for (int i = 0; i < tam; i++)
	{
		v[a+i].key = vetAux[i];
		comp++;
		atrib++;
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
			comp++;
			if(v[j].key > v[j + 1].key){
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
void selection_sort(Node v[], int n){
	int i, j, min, pos_min;

	for(i = 0; i < n-1; i++){
		for(j = i + 1, min = v[i].key, pos_min = i; j < n; j++){
			atrib++;
			comp++;
			if(v[j].key < min){
				min = v[j].key;
				pos_min = j;
				atrib += 2;
			}
		}
		v[pos_min] = v[i];
		v[i].key = min;
		atrib += 4;
	}
}

/*! Implementation of the insertion sort algorithm.

	@param v is an c-like array.
	@param n is the size of the array v.
	@return there is no return.
*/
void insertion_sort(Node v[], int n){
	int i, j;
	Node temp;

	for(i = 1;i <= n-1;i++){
        temp = v[i];
        j = i-1;

 		comp++;
        while((j >= 0) && (temp.key < v[j].key)){
            v[j+1] = v[j];    //moves element forward
            j = j-1;
            comp++;
            atrib += 2;
        }
        v[j+1] = temp;    //insert element in proper place
        atrib += 3;
    }
}



/*! Max heapify algorithm.

	Rearrange a heap to maintain the heap property.

	@param a is an c-like array.
	@param n is the size of the array v.
	@return there is no return.
*/
void max_heapify(Node a[], int i, int n) /// transforma o vetor que receber em um maxheap
{
    int largest = i;  // Initialize largest as root
    int l = 2*i + 1;  // left = 2*i + 1
    int r = 2*i + 2;  // right = 2*i + 2

    // If left child is larger than root
    if (l < n && a[l].key > a[largest].key){
        largest = l;
    	atrib++;
    }

    // If right child is larger than largest so far
    if (r < n && a[r].key > a[largest].key){
        largest = r;
    	atrib++;
    }

	comp += 2;

    // If largest is not root
    if (largest != i)
    {
    	comp++;
        swap(a, i, largest);

        // Recursively heapify the affected sub-tree
        max_heapify(a, largest, n);
    }
    return;
}

/*!	Heap sort algorithm implementation.

	@param a is an c-like array.
	@param n is the size of the array v.
	@return there is no return.
*/
void heap_sort(Node a[], int n) /// recebe um vetor desordenado e aplica o heapsort nele
{
	// Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--){
        max_heapify(a, i, n);
    }

    // One by one extract an element from heap
    for (int i=n-1; i>=0; i--)
    {
        // Move current root to end
        swap(a, 0, i);

        // call max heapify on the reduced heap
        max_heapify(a, 0, i);
    }
}
