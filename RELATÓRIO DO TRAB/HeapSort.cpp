void max_heapify(Node a[], int i, int n)
{
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if (l < n && a[l].key > a[largest].key){
        largest = l;
    	atrib++;
    }
    if (r < n && a[r].key > a[largest].key){
        largest = r;
    	atrib++;
    }
    comp += 2;
    if (largest != i)
    {
    	comp++;
        swap(a, i, largest);
        max_heapify(a, largest, n);
    }
    return;
}
void heap_sort(Node a[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--){
        max_heapify(a, i, n);
    }

    for (int i=n-1; i>=0; i--)
    {
        swap(a, 0, i);

        max_heapify(a, 0, i);
    }
}
