//Cho mảng đã được sắp xếp A[] gồm N phần tử không có hai phần tử giống nhau và số X. 
//Nhiệm vụ của bạn là tìm floor(X). 
//Trong đó, K=floor(X) là phần tử lớn nhất trong mảng A[] nhỏ hơn hoặc bằng X.
//Input
//3
//7 0
//1 2 8 10 11 12 19
//7 5
//1 2 8 10 11 12 19
//7 10
//1 2 8 10 11 12 19
//Output
//-1
//2
//4
#include<bits/stdc++.h> 
using namespace std; 
int main(){ 
    int t ; cin >> t; 
	while(t--){ 
	    int n, X; cin >> n >> X;
	    int a[n+1];
	    for(int i=1;i<=n;i++) cin >> a[i];
	    auto it=upper_bound(a+1,a+n+1,X)-a;
	    if(it>=2) cout << it-1;
	    else cout << "-1";
	    cout << endl;
	} 
}