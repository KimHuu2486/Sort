#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
int findDigit(int a) {
    int cnt = 0;
    while (a != 0) {
        a /= 10;
        cnt++;
    }
    return cnt;
}
void RadixSort(vector<int>& a, int n) {
    int max = *max_element(a.begin(), a.end());
    for (int i = 1; i <= findDigit(max); i++) {
        vector<vector<int>>bin(10);
        for (int num : a) {
            int digit = (num / (int)pow(10, i - 1)) % 10;
            bin[digit].push_back(num);
        }
        int idx = 0;
        for (int j = 0; j <= 9; j++) {
            while (!bin[j].empty()) {
                a[idx] = *bin[j].rbegin();
                bin[j].pop_back();
                idx++;
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
    RadixSort(vec, n);
    for (int num : vec) {
        cout << num << " ";
    }
    return 0;
}