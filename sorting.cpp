/**
*  Sorting algorithms, sorting.cpp
* Purpose: Implement algorithms to sort arrays of integers
*
* @author Mateus Coutinho Marim
* @version 1.0 23/03/17 
*/

#include "sorting.h"

/**	bubble_sort - Implementation of the bubble sort    	  *	algorithm
*
*	@param v is an c-like array.
*	@param n is the size of the array v.
*	@return there is no return.
*/
void bubble_sort(int v[], int n){
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

/** Implementation of the insertion sort algorithm.
*
*	@param v is an c-like array.
*	@param n is the size of the array v.
*	@return there is no return.
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
