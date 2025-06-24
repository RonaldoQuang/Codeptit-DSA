//Cho dãy số A gồm N phần tử là các số nguyên. 
//Hãy tính tích lớn nhất của 2 hoặc 3 phần tử trong dãy.
//Input
//6
//5 10 -2 3 5 2
//Output
//250

#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    int a[n];
    for(int i=0;i<n;i++){
    	cin >> a[i];
	}
	sort(a,a+n);
	cout << max({a[0]*a[1],a[n-1]*a[n-2],a[0]*a[1]*a[n-1],a[n-1]*a[n-2]*a[n-3]});
}