void bubble_sort(Node v[], int n){
	int i, j, swaps;

	for(i = 0; ; ++i){
		swaps = 0;
		for(j = 0; j < n-1; ++j){
			comp++;
			if(v[j].key > v[j + 1].key){
				swap(v, j + 1, j);
				swaps++;
			}
		}
		if(!swaps) return;
	}
}
