//Cho đồ thị có hướng liên thông yếu G=<V, E> được biểu diễn dưới dạng danh sách cạnh. 
//Hãy kiểm tra xem đồ thị có chu trình Euler hay không?
//Input
//2
//6  10  
//1 2 2 4 2 5 3 1 3 2 4 3 4 5 5 3 5 6 6 4
//3 3
//1 2 2 3 1 3
//Output
//1
//0
#include <bits/stdc++.h> 
using namespace std;
int main(){
    int t; cin >> t;
    while(t--){
    	int n, k; cin >> n >> k;
    	int b[k+1], c[k+1];
    	for(int i=1;i<=k;i++){
    		cin >> b[i] >> c[i];
		}
		vector<int> a[n+1], v[n+1];
		for(int i=1;i<=k;i++){
			a[b[i]].push_back(c[i]);
			v[c[i]].push_back(b[i]);
		}
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(a[i].size()!=v[i].size()){
				++cnt;
				break;
			}
		}
		if(cnt==0) cout << "1";
		else cout << "0";
		cout << endl;
	}	
}