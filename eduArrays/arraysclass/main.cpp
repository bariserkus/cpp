#include <iostream>

using namespace std;

class ArrayList {
    int *arr;
    int num_elements;
    int capacity;

public:
    ArrayList(int size) {
        arr = new int[size];
        num_elements = 0;
        capacity = size;
    }
    void insert(int val) {
        if(num_elements < capacity) {
            arr[num_elements]=val;
            num_elements++;
        } else {
            resize();
            arr[num_elements]=val;
            num_elements++;
        }
    }

    int getAt(int index){
        return arr[index];
    }

    void resize() {
        int* tempArr=new int[capacity*2];
        capacity*=2;

        for(int i=0; i<num_elements; i++) {
            tempArr[i]=arr[i];
        }

        delete [] arr;
        arr=tempArr;
    }

    int length() {

        return num_elements;
    }

    void print() {
        for(int i=0; i<num_elements; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

};

int main() {
    ArrayList arr(1);
    cout << "Arr length : " << arr.length() << endl;
    arr.insert(1);
    arr.insert(2);
    arr.insert(3);
    arr.insert(4);
    arr.insert(5);
    arr.insert(6);
    arr.insert(7);
    arr.insert(8);
    cout <<  "Arr length : " << arr.length() << endl;
    cout << "Array : ";
    arr.print();
    cout << "Element at index 5 is " << arr.getAt(4) << endl;
}