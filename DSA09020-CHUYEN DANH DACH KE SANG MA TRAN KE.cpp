//Cho đơn đồ thị vô hướng có n đỉnh dưới dạng danh sách kề.
//Hãy biểu diễn đồ thị bằng ma trận kề.
//Input
//3
//2 3
//1 3
//1 2
//Output
//0 1 1
//1 0 1
//1 1 0
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    cin.ignore();
    int a[n+1][n+1], b[n+1], c[n+1];
    memset(a,0,sizeof(a));
    for(int i=1;i<=n;i++){
    	string s; getline(cin,s);
    	string w;
    	stringstream ss(s);
    	while(ss >> w){
    		a[i][stoi(w)]=1;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}