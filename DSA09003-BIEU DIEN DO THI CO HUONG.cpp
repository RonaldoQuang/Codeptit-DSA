//Cho đồ thị có hướng G=<V, E> được biểu diễn dưới dạng danh sách cạnh. 
//Hãy viết chương trình thực hiện chuyển đổi biểu diễn đồ thị dưới dạng danh sách kề.
//Input
//1
//6  9
//1  2
//2  5
//3  1
//3  2
//3  5
//4  3
//5  4
//5  6
//6  4
//Output
//1: 2
//2: 5
//3: 1 2 5
//4: 3
//5: 4 6
//6: 4
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t; cin >> t;
    while(t--){
    	int n, k; cin >> n >> k;
    	int b[k+1], c[k+1];
    	for(int i=1;i<=k;i++){
    		cin >> b[i];
    		cin >> c[i];
		}
		vector<int> a[n+1];
		for(int i=1;i<=k;i++){
			a[b[i]].push_back(c[i]);
		}
		for(int i=1;i<=n;i++){
			cout << i << ": ";
			for(int j=0;j<a[i].size();j++){
				cout << a[i][j] << " ";
			}
			cout << endl;
		}	
	}
	
}