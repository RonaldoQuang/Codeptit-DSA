//Cho đồ thị vô hướng G=<V, E> được biểu diễn dưới dạng danh sách cạnh. 
//Hãy kiểm tra xem đồ thị có tồn tại chu trình hay không?
//Input
//2
//4
//1 2
//1 3
//2 4
//4
//1 2
//1 3
//2 3
//Output
//YES
//NO
#include<bits/stdc++.h>
using namespace std;
int main(){ 
    int t; cin >> t; 
	while(t--){ 
	    int n; cin >> n; 
		set<int> se; 
		for(int i=0;i<n-1;i++){ 
		    int x,y; cin >> x >> y; 
			se.insert(x); 
			se.insert(y); 
		} 
		if(se.size()!=n) cout << "NO" << endl;
		else cout << "YES" << endl;  
	} 
}