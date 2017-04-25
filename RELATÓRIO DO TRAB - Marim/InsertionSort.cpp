void insertion_sort(Node v[], int n){
	int i, j;
	Node temp;
	for(i = 1;i <= n-1;i++){
        temp = v[i];
        j = i-1;
 	comp++;
        while((j >= 0) && (temp.key < v[j].key)){
            v[j+1] = v[j]; 
            j = j-1;
            comp++;
            atrib += 2;
        }
        v[j+1] = temp;
        atrib += 3;
    }
}
