#include <bits/stdc++.h>
using namespace std;

/**
 * Function pointer and callbacks
*/

/**
 * callback function should compare two integers, should return:
 *  1 if first > second
 *  0 if first = second 
 *  -1 if first < second 
*/

int compare(int a, int b) {
    if(a > b) return 1;
    else return -1;
}

bool compare_sort(int a, int b) {
    if(a > b) return true;
    else return false;
}

void bubbleSort(int *a, int n, int(*compare)(int , int)) {
    int i, j, temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n ; j++) {
            if(compare(a[i], a[j]) > 0) {
                temp = a[i];
                a[i] = a[j];
                a[j]  = temp;
            }
        }
    }
}

void printArray(int a[], int n) {
    for (int i = 0; i < n ; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() { 
    int i;
    int n = 6;
    int a[] = {3, 2, 1, 5, 4, 6} ;
    // bubbleSort(a, n, compare);
    printArray(a, n);
    // using quick sort in lib
    cout << "sort asc using stl" << endl;
    sort(a, a + n);
    printArray(a, n);
    cout << "sort desc using stl" << endl;
    sort(a, a + n, greater<int>());
    printArray(a, n);

    // using custom compare in sort
    cout << "sort asc using custom compare" << endl;
    sort(a, a + n, [](int e1, int e2) {
        return e1 < e2;
    });
    printArray(a, n);

    cout << "sort desc using custom compare" << endl;
    sort(a, a + n, [&](int e1, int e2) {
        return e1 > e2;
    });
    printArray(a, n);

    return 0;
}
