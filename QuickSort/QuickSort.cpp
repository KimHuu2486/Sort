#include <iostream>
#include <vector>
using namespace std;
void swap(int& a, int& b) {
    int temp = a;
    a = b; 
    b = temp;
}
int partition(vector<int>&vec, int low, int high) {
    int pivot = vec[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (vec[j] < pivot) {
            i++;
            swap(vec[i], vec[j]);
        }
    }
    swap(vec[i + 1], vec[high]);
    return i + 1;
}
void quickSort(vector<int>&vec, int low, int high) {
    if (low < high) {
        int pi = partition(vec, low, high);
        quickSort(vec, low, pi - 1);
        quickSort(vec, pi + 1, high);
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
    quickSort(vec, 0, n - 1);
    for (int num : vec) {
        cout << num << " ";
    }
    return 0;
}