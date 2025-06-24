//Cho mảng A[] gồm N phần tử chỉ bao gồm các số 0 và 1. Các số 0 được đặt trước các số 1. 
//Hãy đếm các số 0 với thời gian log(N).
//Input
//3
//12
//0 0 0 0 0 0 0 0 0 1 1 1 
//5
//0 0 0 0 0
//6
//1 1 1 1 1 1
//Output
//9
//5
//0
#include <bits/stdc++.h> 
using namespace std; 
int main(){ 
    int t; cin >> t; 
	while(t--){ 
	    int n, x; cin >> n;
	    int a[n+1];
	    for(int i=1;i<=n;i++){
	    	cin >> a[i];
	    	if(a[i]==1&&a[i-1]==0) x=i-1;
	    	else if(a[n]==0) x=n;
	    	else if(a[1]==1) x=0;
		}
	    cout << x << endl;
	}
}