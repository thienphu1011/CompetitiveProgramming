#include <bits/stdc++.h>
using namespace std;
using ll =long long;

//O(logn)
//insert
//size 
//find 
//count 
//Erase
//multiset 
int main (){
    int n;
    set<int> s;
    
    cout <<s.size()<<endl;
    for (int i=1 ;i<=10 ; i++){
        s.insert(i);
    }
    s.erase(5);
    cout <<s.size()<<endl;
    if (s.count(5) !=0){
        //if (s.find(5) != s.end()){
        cout <<"Found !\n";

    }
    else {
        cout <<"Not Found !\n";
    }
//duyet for each
for (int x :s){
    cout <<x<<" ";
}
cout <<endl;
cout <<*s.begin()<<endl;
cout <<s*.rbegin()<<endl;

//duyet auto 
for (int x :s){
    cout <<x<<" ";
}
for (auto x:s){
    cout <<x <<endl;
}
 // duyet iterator 
 for (set<int>::iterator it = s.begin(); it !=s.end(); +=it){
    cout <<*it<<" ";
 }

//ap dung 
int n; cin >>n;
set<sring> s ;
cin.ignore();
for (int i=0 ; i<=n ; i++){
    string str ;
    getline (cin,str);
    s.insert(str);
}
cout <<s.size()<<endl;
for (string x:s){
    cout <<x <<endl;
}
    return 0;


}
