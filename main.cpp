#include <iostream>
#include "search.h"
#include "utils.h"
#include "sorting.h"

#define N 5

using namespace std;

int main(){
	Node *v2 = NULL;
	string path("ListNoR.txt");
	int v[] = {6, 5, 4, 3, 2, 1, -1, -2, 0};
	int v1[] = {3,1,2, -1};
	int i, n;
	
	n = load_list(path, &v2);
	cout << v2[0].info << endl;
	if(!v2) cout << "cu" << endl;
	cout << "original: ";
	print_nodes(v2, n);
	cout << endl;
	/*bubble_sort(v, 9);
	cout << "ordenado: ";
	for(i = 0; i < N; ++i) cout << v[i] << " ";
	cout << endl;*/
	bubble_sort(v2, n);
	cout << "quick_sort" << endl;
	print_nodes(v2, n);
	cout << endl;

}
