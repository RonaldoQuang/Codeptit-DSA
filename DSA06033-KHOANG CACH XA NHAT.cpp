//Cho dãy số A[] gồm có N phần tử. 
//Bạn cần tìm 2 vị trí i, j sao cho j-i lớn nhất và A[j] > A[i].
//Input
//3
//9
//34 8 10 3 2 80 30 33 1
//6
//1 2 3 4 5 6
//6
//6 5 4 3 2 1
//Output
//6
//5
//-1
#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while(t--){
    	int n; cin >> n;
    	int a[n];
    	multimap<int,int> mp;
    	for(int i=0;i<n;i++){
    		cin >> a[i];
    		mp.insert({a[i],i});
		}
		int min1=-1, m, k;
		for(auto x:mp){
			m=x.second;
			k=x.first;
			break;
		}
		for(auto x:mp){
			if(x.first>k) min1=max(min1,x.second-m);
			if(x.second<m){
				m=x.second;
				k=x.first;
			}
		}
	    cout << min1 << endl;
	}
}