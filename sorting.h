#ifndef SORTING_H_INCLUDED
#define SORTING_H_INCLUDED
private:
void swap(int v[], int a, int b);
int partition(int v[], int low, int high);
public:
void bubble_sort(int v[], int n);
void selection_sort(int v[], int n);
void insertion_sort(int v[], int n);
void quick_sort(int v[], int low, int high);

#endif
