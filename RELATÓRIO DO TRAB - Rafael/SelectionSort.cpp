void selection_sort(Node v[], int n){
	int i, j, min, pos_min;
	for(i = 0; i < n-1; i++){
		for(j = i + 1, min = v[i].key, pos_min = i; j < n; j++){
			atrib++;
			comp++;
			if(v[j].key < min){
				min = v[j].key;
				pos_min = j;
				atrib += 2;
			}
		}
		v[pos_min] = v[i];
		v[i].key = min;
		atrib += 4;
	}
}
