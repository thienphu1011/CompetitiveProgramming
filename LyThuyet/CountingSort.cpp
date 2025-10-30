#include <bits/stdc++.h>
using namespace std;

void countingSort(vector<int> &a) {
    int maxVal = *max_element(a.begin(), a.end());
    vector<int> count(maxVal+1, 0);

    for (int x : a) count[x]++; // đếm số lần xuất hiện

    int idx = 0;
    for (int i = 0; i <= maxVal; i++) {
        while (count[i]--) {
            a[idx++] = i;
        }
    }
}

int main() {
    vector<int> arr = {4, 2, 2, 8, 3, 3, 1};
    countingSort(arr);

    cout << "Counting Sort: ";
    for (int x : arr) cout << x << " ";
    cout << endl;
}
