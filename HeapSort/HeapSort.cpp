#include <iostream>
#include <vector>
using namespace std;
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
void Heapify(vector<int>&a, int n, int i) {
    int saved = a[i];
    while (i < n / 2) {
        int child = 2 * i + 1;
        if (child + 1 < n) {
            if (a[child] < a[child + 1]) {
                child++;
            }
        }
        if (saved >= a[child]) {
            break;
        }
        a[i] = a[child];
        i = child;
    }
    a[i] = saved;
}
void buildHeap(vector<int>&a, int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        Heapify(a, n, i);
    }
}
void heapSort(vector<int>&a, int n) {
    buildHeap(a, n);
    for (int i = n - 1;i >= 0; i--) {
        swap(a[0], a[i]);
        Heapify(a, i, 0);
    }
}
int main()
{
    int n;
    cin >> n;
    vector<int>vec(n);
    for (int& num : vec) {
        cin >> num;
    }
    heapSort(vec, n);
    for (int num : vec) {
        cout << num << " ";
    }
    return 0;
}