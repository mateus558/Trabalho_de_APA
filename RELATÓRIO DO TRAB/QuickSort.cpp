void quick_sort(Node v[], int low, int high)
{
	int pivot, aux;
	int i, j;
	pivot = v[(low + high) / 2].key;
	i = low;
	j = high;
	atrib += 3;

	while(i <= j)
	{
		while(v[i].key < pivot)
		{
			comp++;
			i++;
		}
		while(v[j].key > pivot)
		{
			comp++;
			j--;
		}
		if(i <= j)
		{
			comp++;
			swap(v, i, j);
			i++;
			j--;
		}
	}

	if(j > low)
		quick_sort(v, low, j);

	if(i < high)
		quick_sort(v, j + 1, high);
}
