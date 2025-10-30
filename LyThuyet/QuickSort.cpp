#include <bits/stdc++.h>
using namespace std;

//Complexity o(nlog(n)), o(n^2)
int partition (vector<int> &a, int low , int high){
    int pivot =a[high];// chọn pivot là phần tử cuối 
    int i=low -1;
    for (int j=low ; j<high ; j++){
        if (a[j] <=pivot ){
            i++;
            swap(a[i] , a[j]);

        }
    }
    //đưa pivot (chốt) về giữa 
    swap (a[i+1], a[high]);
    return i+1; // vị trí 
}       

void quicksort(vector<int> &a,int low , int high){
    if (low<high){
        int pi=partition(a, low,high);
        quicksort (a,low,pi-1);
        quicksort(a,pi+1,high);
    }
}


int main (){
    vector <int>arr={3,6,8,10,1,2,1};
    quicksort(arr,0,arr.size()-1);
    cout << "Quick Sort"<<endl;
    for (int x :arr) cout << x<<" ";
    cout << endl;



    return 0;
}

