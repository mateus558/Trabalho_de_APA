void merge_sort(Node v[], int n)
{
	mergePart(v, 0, n / 2 - 1);
	mergePart(v, n / 2, n - 1);
	merge(v, 0, n - 1);
}

void mergePart(Node v[], int a, int b)
{
	comp++;
	if (b - a > 1)
	{
		mergePart(v, a, (a + b) / 2);
		mergePart(v, (a + b) / 2 + 1, b);
		merge(v, a, b);
	}
	else if (v[a].key > v[b].key)
	{
		comp++;
		swap(v, a, b);
	}
}
void merge(Node v[], int a, int b)
{
	int tam = b - a + 1;
	int m = (a + b) / 2;
	int j = a;
	int k = m + 1;
	int vetAux[tam];
	atrib += 5;
	for (int i = 0; i < tam; i++)
	{
		if (v[j].key < v[k].key && j <= m)
			vetAux[i] = v[j++].key;
		else
			vetAux[i] = v[k++].key;
		atrib++;
		comp += 3;
	}
	for (int i = 0; i < tam; i++)
	{
		v[a+i].key = vetAux[i];
		comp++;
		atrib++;
	}
}
