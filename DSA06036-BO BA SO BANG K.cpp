//Cho dãy số A[] gồm có N phần tử.
//Nhiệm vụ của bạn là hãy kiểm tra tồn tại bộ ba (i, j, k) mà A[i] + A[j] + A[k] = K cho trước hay không.
//Input
//2
//6 22
//1 4 15 6 10 8
//3 4
//1 1 1
//Output
//YES
//NO
#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin >> t;
	while(t--){
		int n, k; cin >> n >> k;
		vector<int> a(n);
		for(auto &x:a) cin >> x;
		int cnt=0;
		sort(a.begin(),a.end());
		for(int i=0;i<n;i++){
			if(a[i]>=k) break;
			for(int j=i+1;j<n;j++){
				if(binary_search(a.begin()+j+1,a.end(),k-a[i]-a[j])){
					++cnt;
					cout << "YES" << endl;
					break;
				}
			}
			if(cnt==1) break;
		}
		if(cnt==0) cout << "NO" << endl;
	}
}