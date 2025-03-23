#include <iostream>
#include <vector>
using namespace std;
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
void shellSort(vector<int>& vec) {
    for (int gap = vec.size() / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < vec.size(); i++) {
            int temp = vec[i];
            int j = i;
            while (j >= gap && vec[j - gap] > vec[j]) {
                vec[j] = vec[j - gap];
                j -= gap;
            }
            vec[j] = temp;
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
    shellSort(vec);
    for (int num : vec) {
        cout << num << " ";
    }
    return 0;
}