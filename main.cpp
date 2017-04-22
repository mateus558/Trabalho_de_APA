#include <iostream>
#include <time.h>
#include "search.h"
#include "utils.h"
#include "sorting.h"
#define N 5

using namespace std;

int main(int argc, char * argv []){
	clock_t timeBeginning, timeEnd;
	double timeWasted = 0.0;
	Node *v2 = NULL;
	if(argc!=2)
		return -1;
	else{
		string path(argv[1]);
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
		//bubble_sort(v2, n);
		timeBeginning = clock();
		quick_sort(v2, 0, n-1);
		timeEnd = clock();
		cout << "quick_sort" << endl;
		print_nodes(v2, n);
		cout << endl;
		timeWasted =((timeEnd-timeBeginning)/(double)CLOCKS_PER_SEC);
		cout << "Time wasted: " << timeWasted*1000  << "ms."<< endl;
	}
}
