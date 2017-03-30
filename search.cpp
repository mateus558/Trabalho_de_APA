#include <iostream>
#include <math.h>
#include "search.h"

bool linear_search(int v[], int n, int x){
	int i;
	
	for(i = 0; i < n; i++){
		if(v[i] == x) return true;
	}
	
	return false;
}

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

bool recursive_binary_search(int v[], int li, int ls, int x){
	if(li <= ls){
		int m = (li + ls)/2;

		if(x > v[m]){
			return recursive_binary_search(v, m+1, ls, x);
		}else if(x < v[m]){
			return recursive_binary_search(v, li, m-1, x);
		} 
		return true;
		
	}
	return false;
}
