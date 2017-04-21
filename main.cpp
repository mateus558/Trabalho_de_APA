#include <iostream>
#include "search.h"
#include "sorting.h"

#define N 5

using namespace std;

int main(){
	Node v2[5];
	int v[] = {6, 5, 4, 3, 2, 1, -1, -2, 0};
	int v1[] = {3,1,2, -1};
	int i;
	v2[0].key = 5;
	v2[1].key = 4;
	v2[2].key = 3;
	v2[3].key = 2;
	v2[4].key = 1;
	cout << "original: ";
	for(i = 0; i < N; ++i) cout << v2[i].key << " ";
	cout << endl;
	/*bubble_sort(v, 9);
	cout << "ordenado: ";
	for(i = 0; i < N; ++i) cout << v[i] << " ";
	cout << endl;*/
	bubble_sort(v2, N);
	cout << "quick_sort" << endl;
	for(i = 0; i< N; i++) cout << v2[i].key << " ";
	cout << endl;

}
