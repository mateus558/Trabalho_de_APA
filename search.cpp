/**
*  Searching algorithms, search.cpp
* Purpose: Implement algorithms to search an element in a structure.
*
* @author Mateus Coutinho Marim
* @version 1.0 29/03/17 
*/

#include <math.h>
#include "search.h"

/*!	Implementation of the linear sort algorithm

	@param v is an c-like array.
	@param n is the size of the array v.
	@param x is the the element being searched.
	@return returns a boolean telling if the element was found or not.
*/
bool linear_search(int v[], int n, int x){
	int i;
	
	for(i = 0; i < n; i++){
		if(v[i] == x) return true;
	}
	
	return false;
}

/*!	Implementation of the binary search algorithm

	@param v is an c-like array.
	@param n is the size of the array v.
	@param x is the the element being searched.
	@return returns a boolean telling if the element was found or not.
*/
bool binary_search(int v[], int n, int x){
	int li = 0, ls = n-1, m = (li + ls) / 2, i;
	
	while(v[m] != x && li < ls){
		if(v[m] < x){
			li = m+1;
		}else{
			ls = m-1;
		}
		
		m = ceil(li + ls) / 2;
	}
	
	return (v[m] == x);
}

/*!	binary_search - Implementation of the recursive binary search algorithm

	@param v is an c-like array.
	@param li is the inferior limit of the subarray 	*	being searched.
	@param ls is the superior limit of the subarray 	*	being searched.
	@param x is the the element being searched.
	@return returns a boolean telling if the element was found or not.
*/
bool recursive_binary_search(int v[], int li, int ls, int x){
	if(li <= ls){
		int m = ceil(li + ls)/2;

		if(x > v[m]){
			return recursive_binary_search(v, m+1, ls, x);
		}else if(x < v[m]){
			return recursive_binary_search(v, li, m-1, x);
		} 
		return true;		
	}
	return false;
}
