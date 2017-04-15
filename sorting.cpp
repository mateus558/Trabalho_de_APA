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
	@return the pivot of the subarray.
*/

int partition(int v[], int low, int high){
  
}

/*!	Implementation of the quick sort algorithm

	@param v is an c-like array.
	@param low is the lowest position of the subarray.
	@param high is the highest position of the subarray.
	@return there is no return.
*/

void quick_sort(int v[], int low, int high){
	
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
