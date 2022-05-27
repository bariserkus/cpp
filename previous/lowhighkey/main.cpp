#include <iostream>
#include <vector>

using namespace std;

int lowkey_vec(vector<int>& arr, int start, int end, int key)
{
    if (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == key && arr[mid-1] != key)
            return mid;
        else if(key > arr[mid])
            return lowkey_vec(arr, mid+1, end, key);
        else if(key <= arr[mid])
            return lowkey_vec(arr, start, mid-1, key);
    }
    return -1;
}

int highkey_vec(vector<int>& arr, int start, int end, int key)
{
    if (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == key && arr[mid+1] != key)
            return mid;
        else if(key >= arr[mid])
            return highkey_vec(arr, mid+1, end, key);
        else if(key < arr[mid])
            return highkey_vec(arr, start, mid-1, key);
    }
    return -1;

}


int main()
{
    vector<int> v1 = {1, 2, 2, 2, 2, 3, 3, 3, 3, 4, 5, 6, 7, 8, 9, 10};
    int len = v1.size();
    int key = 2;

    cout<<"Low Key = " << key << " found at: "<< lowkey_vec(v1, 0, len-1, key)<<endl;
    cout<<"High Key = " << key << " found at: "<< highkey_vec(v1, 0, len-1, key)<<endl;

}
