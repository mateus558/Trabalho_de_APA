#include <iostream>
#include <time.h>
#include "search.h"
#include "utils.h"
#include "sorting.h"
#define N 5

enum Sort {BUBBLE = 0, SELECTION = 1, INSERTION = 2, MERGE = 3, QUICK = 4, HEAP = 5};

using namespace std;


int main(int argc, char * argv[]){
	clock_t timeBeginning, timeEnd;
	Node *v = NULL;
	string path(argv[1]), algo;
	Analysis to_save;
	double timeWasted = 0.0;
	int n, o, i = 0;
	
	o = atoi(argv[2]);
	n = load_list(path, &v);

	if(n <= 100){
		cout << "original: ";
		print_nodes(v, n);
		cout << endl;
	}
	
	cout << "\nSize: " << n << endl;
	cout << endl;
	
	timeBeginning = clock();
	
	switch(o){
		case BUBBLE:
			algo = "Bubble";
			cout << algo << endl;
			bubble_sort(v, n);
			break;
		case SELECTION:
			algo = "Selection";
			cout << algo << endl;
			selection_sort(v, n);
			break;
		case INSERTION:
			algo = "Insertion";
			cout << algo << endl;
			insertion_sort(v, n);
			break;
		case MERGE:
			algo = "Merge";
			cout << algo << endl;
			merge_sort(v, n);
			break;
		case QUICK:
			algo = "Quick";
			cout << algo << endl;
			quick_sort(v, 0, n);
			break;
		case HEAP:
			algo = "Heap";
			cout << algo << endl;
			heap_sort(v, n);
			break;
	}		
	
	while(path[i++] != '1');
	
	timeEnd = clock();
	timeWasted = double(timeEnd - timeBeginning) / CLOCKS_PER_SEC;
	to_save.list_type = path.substr(6, i - 7);
	to_save.comp = comp;
	to_save.atrib = atrib;
	to_save.time = timeWasted;
	to_save.size = n;
	algo = string("Experiments/") + algo + to_save.list_type;
	save_csv(algo, to_save);
	
	if(n <= 100){
		cout << "\nSorted: " << endl;
		print_nodes(v, n);
		cout << endl;
	}
	
	cout << "Number of comparisons: " << comp << endl;
	cout << "Number of attributions: " << atrib << endl;
	cout << "Time wasted: " << timeWasted  << "s."<< endl;
}
