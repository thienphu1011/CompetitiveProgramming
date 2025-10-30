#include <bits/stdc++.h>
using namespace std;

void selectionSort(vector<int> &a) {
    int n = a.size();
    for (int i = 0; i < n-1; i++) {
        int minIdx = i;
        for (int j = i+1; j < n; j++) {
            if (a[j] < a[minIdx]) minIdx = j;
        }
        swap(a[i], a[minIdx]);
    }
}

int main() {
    vector<int> arr = {64, 25, 12, 22, 11};
    selectionSort(arr);

    cout << "Selection Sort: ";
    for (int x : arr) cout << x << " ";
    cout << endl;
}
