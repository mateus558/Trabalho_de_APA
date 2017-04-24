void swap(Node v[], int a, int b){
	Node aux = v[a];
	v[a] = v[b];
	v[b] = aux;
	atrib += 3;
}
