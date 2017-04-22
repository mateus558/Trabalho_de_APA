#ifndef SORTING_H_INCLUDED
#define SORTING_H_INCLUDED

#include <string>

extern int comp;
extern int atrib;

struct Node{
	int key;
	std::string info;
};

/*!
	Sorting sub functions.
*/
void swap(Node v[], int a, int b);
void mergePart(Node v[], int a, int b);
void mergeJoin(Node v[], int a, int b);
int partition(Node v[], int low, int high);
void max_heapify(Node a[], int i, int n);
void build_max_heap(Node a[], int n);

/*!
	Sorting main functions.
*/
void bubble_sort(Node v[], int n);
void selection_sort(Node v[], int n);
void insertion_sort(Node v[], int n);
void merge_sort(Node v[], int n);
void quick_sort(Node v[], int low, int high);
void heap_sort(Node a[], int n);

#endif
