//Cho đồ thị vô hướng liên thông G=<V, E> được biểu diễn dưới dạng danh sách cạnh. 
//Hãy kiểm tra xem đồ thị có đường đi Euler hay chu trình Euler hay không?
//Đường đi Euler bắt đầu tại một đỉnh, và kết thúc tại một đỉnh khác.
//Chu trình Euler bắt đầu tại một đỉnh, và kết thúc chu trình tại chính đỉnh đó.
//Đưa ra 1, 2, 0 kết quả mỗi test theo từng dòng tương ứng với đồ thị có đường đi Euler, chu trình Euler và trường hợp không tồn tại.
//Input
//2
//6  10  
//1 2 1 3 2 3 2 4 2 5 3 4 3 5 4 5 4 6 5 6
//6 9  
//1  2 1  3 2  3 2  4 2  5 3  4 3  5 4  5 4  6
//Output
//2
//1
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
		vector<int> a[n+1];
		for(int i=1;i<=k;i++){
			a[b[i]].push_back(c[i]);
			a[c[i]].push_back(b[i]);
		}
		int cnt=0, dem=0;
		for(int i=1;i<=n;i++){
			if(a[i].size()){
				if(a[i].size()%2==0) ++cnt;
				else ++dem;
			}
		}
		if(cnt==n) cout << "2";
		else if(dem==2) cout << "1";
		else cout << "0";
		cout << endl;
	}	
}