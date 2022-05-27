#include <iostream>

using namespace std;

void swp(int* a, int* b);

int partarry (int a[], int low, int high)
{
    int pivot = a[low];
    int i = low;
    int j = high;

    while (i < j)
    {
        while (i <=high && a[i] <= pivot) ++i;
        while (a[j] > pivot) --j;
        if (i < j) swp(&a[i], &a[j]);
        cout << i << ' ' << j << endl;
    }
    swp(&a[j], &a[low]);
    return j;
}

void quick_sort_(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivot_index = partarry(arr, low, high);
        cout << "Pivot Index: " << pivot_index << endl;
        quick_sort_(arr, low, pivot_index - 1);
        quick_sort_(arr, pivot_index + 1, high);
    }

}

void quick_sort(int arr[], int n)
{
    quick_sort_(arr, 0, n - 1);
}

void swp(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}


int main()
{
    int a[] = {55, 23, 26, 2, 18, 78, 25, 9, 7, 3, 43, 28, 64, 93, 12, 4, 8, 5};
    int n = sizeof(a) / sizeof(a[0]);

    for (int i : a) cout << i << ", ";
    cout << endl;

    quick_sort(a, n);

    for (int i : a) cout << i << ", ";
    cout << endl;


    return 0;


}
