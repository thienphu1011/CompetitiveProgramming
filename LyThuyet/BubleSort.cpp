#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int> &a) {
    int n = a.size();
    for (int i = 0; i < n-1; i++) {
        bool swapped = false;
        for (int j = 0; j < n-i-1; j++) {
            if (a[j] > a[j+1]) {
                swap(a[j], a[j+1]);
                swapped = true;
            }
        }
        if (!swapped) break; // tối ưu: nếu không swap thì dừng
    }
}

int main() {
    vector<int> arr = {5, 1, 4, 2, 8};
    bubbleSort(arr);

    cout << "Bubble Sort: ";
    for (int x : arr) cout << x << " ";
    cout << endl;
}
