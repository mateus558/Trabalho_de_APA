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
	double timeWasted = 0.0;
	Node *v2 = NULL;
	string path(argv[1]);
	int n, o;
	
	o = atoi(argv[2]);
	n = load_list(path, &v2);

	if(n <= 100){
		cout << "original: ";
		print_nodes(v2, n);
		cout << endl;
	}
	
	cout << "\nSize: " << n << endl;
	cout << endl;
	
	timeBeginning = clock();
	switch(o){
		case BUBBLE:
			cout << "Bubble sort." << endl;
			bubble_sort(v2, n);
			break;
		case SELECTION:
			cout << "Selection sort." << endl;
			selection_sort(v2, n);
			break;
		case INSERTION:
			cout << "Insertion sort." << endl;
			insertion_sort(v2, n);
			break;
		case MERGE:
			cout << "Merge sort." << endl;
			merge_sort(v2, n);
			break;
		case QUICK:
			cout << "Quick sort." << endl;
			quick_sort(v2, 0, n);
			break;
		case HEAP:
			cout << "Heap sort." << endl;
			heap_sort(v2, n+1);
			break;
	}		
	timeEnd = clock();
	timeWasted = double(timeEnd - timeBeginning) / CLOCKS_PER_SEC;
	
	if(n <= 100){
		cout << "\nSorted: " << endl;
		print_nodes(v2, n);
		cout << endl;
	}
	cout << "Number of comparisons: " << comp << endl;
	cout << "Number of attributions: " << atrib << endl;
	cout << "Time wasted: " << timeWasted  << "s."<< endl;
}
