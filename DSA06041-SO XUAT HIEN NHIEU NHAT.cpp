//Cho dãy số A[] gồm có N phần tử. 
//Nhiệm vụ của bạn là hãy tìm một số có tần số xuất hiện nhiều nhất, yêu cầu lớn hơn N/2 lần xuất hiện trong dãy số.
//Input
//2
//9
//3 3 4 2 4 4 2 4 4
//8
//3 3 4 2 4 4 2 4
//Output
//4
//NO
#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		int a[n+1];
		map<int,int> mp;
		for(int i=1;i<=n;i++){
			cin >> a[i];
			mp[a[i]]++;
		}
		int r=0;
		for(auto x:mp){
			if(x.second>(n/2)) r=x.first;
		}
		if(r>0) cout << r << endl;
		else cout << "NO" << endl;
	}
}