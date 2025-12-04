#include <bits/stdc++.h>
using namespace std;
using ll =long long;


//vector<kieu du lieu> ten_vector
//pair <datatype1 , datatype2> v;
//make_pair (a,b)
//push_back()
//size(): kich thuoc vector
//vector<int> v
//vector<int> v(n)
//vector<int> v(n, value)
 int main (){

    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    cout<< v.size()<<endl;
    cout <<"Phan tu dau tien trong vector :"<<v[0] <<endl;
    cout <<"Phan tu cuoi cung trong vector :"<< v[v.size()-1]<<endl;
   // cout <<"Phan tu cuoi cung trong vector :"<<v.back()<<endl;

   // duyet thong qua index 
   //duyet qua for each 
   //duyet qua interator
   for (int i=0 ; i<v.size(); i++){
    cout << v[i]<<endl;
   }
   /*for (int x: v){
    cout << x<<endl;
   }
   */

   for (vector<int>::iterator it =v.begin(); it!=v.end(); ++it){
    cout <<*it <<endl;
   }
   for (auto it=v.begin(); it!=v.end(); ++it){
    cout << *it<< endl;
   }
   return 0;


 }