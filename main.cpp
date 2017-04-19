#include <iostream>
#include "search.h"
#include "sorting.h"

#define N 9

using namespace std;

int main(){
	int v[] = {6, 5, 4, 3, 2, 1, -1, -2, 0};
	int v1[] = {3,1,2, -1};
	int i;

	cout << "original: ";
	for(i = 0; i < N; ++i) cout << v[i] << " ";
	cout << endl;
	/*bubble_sort(v, 9);
	cout << "ordenado: ";
	for(i = 0; i < N; ++i) cout << v[i] << " ";
	cout << endl;*/
	quick_sort(v,0, 9);
	cout << "quick_sort" << endl;
	for(i = 0; i< 9; i++) cout << v[i] << " ";
	cout << endl;

}
