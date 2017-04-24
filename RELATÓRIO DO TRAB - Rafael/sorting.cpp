#include "sorting.h"
#include <iostream>
#include <stdlib.h>
long long int comp = 0;		//Number of comparisons
long long int atrib = 0;	//Number of attributions
using namespace std;

void swap(Node v[], int a, int b){
	Node aux = v[a];
	v[a] = v[b];
	v[b] = aux;
	atrib += 3;
}
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
void merge_sort(Node v[], int n)
{
	mergePart(v, 0, n / 2 - 1);
	mergePart(v, n / 2, n - 1);
	merge(v, 0, n - 1);
}

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
void insertion_sort(Node v[], int n){
	int i, j;
	Node temp;
	for(i = 1;i <= n-1;i++){
        temp = v[i];
        j = i-1;
 	comp++;
        while((j >= 0) && (temp.key < v[j].key)){
            v[j+1] = v[j]; 
            j = j-1;
            comp++;
            atrib += 2;
        }
        v[j+1] = temp;
        atrib += 3;
    }
}
void max_heapify(Node a[], int i, int n)
{
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if (l < n && a[l].key > a[largest].key){
        largest = l;
    	atrib++;
    }
    if (r < n && a[r].key > a[largest].key){
        largest = r;
    	atrib++;
    }
    comp += 2;
    if (largest != i)
    {
    	comp++;
        swap(a, i, largest);
        max_heapify(a, largest, n);
    }
    return;
}
void heap_sort(Node a[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--){
        max_heapify(a, i, n);
    }

    for (int i=n-1; i>=0; i--)
    {
        swap(a, 0, i);

        max_heapify(a, 0, i);
    }
}
