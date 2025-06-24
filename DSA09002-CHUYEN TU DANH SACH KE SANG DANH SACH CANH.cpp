//Cho đơn đồ thị G vô hướng liên thông được mô tả bởi danh sách kề. 
//Hãy in ra danh sách cạnh tương ứng của G.
//Input
//3
//1 2 3
//2 3
//Output
//1 2
//1 3
//2 3
#include<bits/stdc++.h>
using namespace std;
int main() {
	int n; cin >> n;
	cin.ignore();
	int a[1001][1001];
	memset(a,0,sizeof(a));
	for(int i=1;i<=n;i++) {
		string s; getline(cin,s);
		string w;
		stringstream ss(s);
		while(ss >> w) {
			a[i][stoi(w)]=1;
			a[stoi(w)][i]=1;
		}
	}
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) {
			if(a[i][j]==1) {
				cout << i << " " << j << endl;
				a[j][i]=0;
			}
		}
		
	}

}