#include <iostream>
#include <vector>
using namespace std;
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
void bubbleSort(vector<int>& a) {
    for (int i = 1; i < a.size(); i++) {
        for (int j = a.size() - 1; j >= i; j--) {
            if (a[j - 1] > a[j]) {
                swap(a[j - 1], a[j]);
            }
        }
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
    bubbleSort(vec);
    for (int num : vec) {
        cout << num << " ";
    }
    return 0;
}