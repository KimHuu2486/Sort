#include <iostream>
#include <vector>
using namespace std;
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
void selectionSort(vector<int>& a) {
    for (int i = 0; i < a.size(); i++) {
        int pos = i;
        for (int j = i + 1; j < a.size(); j++) {
            if (a[pos] > a[j]) {
                pos = j;
            }
        }
        swap(a[i], a[pos]);
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
    selectionSort(vec);
    for (int num : vec) {
        cout << num << " ";
    }
    return 0;
}