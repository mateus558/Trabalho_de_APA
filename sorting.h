#ifndef SORTING_H_INCLUDED
#define SORTING_H_INCLUDED

#include <string>

struct Node{
	int key;
	std::string info;
};

/*!
	Sorting sub functions.
*/
void swap(Node v[], int a, int b);
void mergePart(int v[], int a, int b);
void mergeJoin(int v[], int a, int b);
int partition(Node v[], int low, int high);

/*!
	Sorting main functions.
*/
void bubble_sort(Node v[], int n);
void selection_sort(Node v[], int n);
void insertion_sort(Node v[], int n);
void merge_sort(int v[], int n);
void quick_sort(Node v[], int low, int high);

#endif
