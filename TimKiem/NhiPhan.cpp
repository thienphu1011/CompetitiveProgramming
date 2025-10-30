#include <bits/stdc++.h>
using namespace std;
using ll =long long;
// tim kiem nhi phan bat buoc day so phai tang dan 
    
    bool bs (int a[], int l , int r ,int x ){
        while (l<=r){
            int m=(l+r)/2;
            if (a[m]==x){
                return true;
            }
            else if (a[m] < x){
                l=m+1 ;
            }
            else {
                r=m-1;
            }
        }
        return false;
    }

    int firstpos (int a[], int l , int r , int x ){
        int res =-1 ;
        while (l<=r) {
            int m=(l+r)/2;
            if (a[m]==x){
                res =m ;// ghi nhan lai ket qua 
                r=m-1;
            }
            else if (a[m]<x){
                l=m+1;
            
            }
            else {
                r=m-1;
            }

        }
        return res;
    }

    int lastpos (int a[], int l , int r , int x ){
        int res =-1 ;
        while (l<=r) {
            int m=(l+r)/2;
            if (a[m]==x){
                res =m ;// ghi nhan lai ket qua 
                l=m+1;
            }
            else if (a[m]<x){
                l=m+1;
            
            }
            else {
                r=m-1;
            }

        }
        return res;
    }


int main(){
    int a[]= {1,1,1,2,2,3,5,6,8,9};
    cout <<bs(a,0,9,9)<<endl;
}