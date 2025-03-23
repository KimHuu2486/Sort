#include <iostream>
#include <vector>
using namespace std;
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
void Merge(vector<int>& a, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int>L1(n1), L2(n2);
    for (int i = 0; i < n1; i++) {
        L1[i] = a[i + left];
    }
    for (int i = 0; i < n2; i++) {
        L2[i] = a[i + mid + 1];
    }
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L1[i] < L2[j]) {
            a[k] = L1[i];
            i++;
        }
        else {
            a[k] = L2[j];
            j++;
        }
        k++;
    }
    while (i<n1){
        a[k] = L1[i];
        k++;
        i++;
    }
    while (j < n2) {
        a[k] = L2[j];
        k++;
        j++;
    }
}
void MergeSort(vector<int>& a, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        MergeSort(a, left, mid);
        MergeSort(a, mid + 1, right);
        Merge(a, left, mid, right);
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
    MergeSort(vec, 0, n - 1);
    for (int num : vec) {
        cout << num << " ";
    }
    return 0;
}