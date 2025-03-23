#include <iostream>
#include <vector>
using namespace std;
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
void insertionSort(vector<int>& a) {
    for (int i = 1; i < a.size(); i++) {
        int temp = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > temp) {
            a[j+1] = a[j];
            j--;
        }
        a[j + 1] = temp;
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
    insertionSort(vec);
    for (int num : vec) {
        cout << num << " ";
    }
    return 0;
}