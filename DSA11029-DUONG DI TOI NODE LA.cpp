//Cho một cây có N node, gốc tại 1. 
//Với mỗi node lá, bạn hãy in ra đường đi từ node gốc tới nó.
//Input:
//Dòng đầu tiên là số lượng bộ test T( T≤ 20).
//Mỗi test bắt đầu bằng số nguyên N (1 ≤ N ≤ 1000).
//N-1 dòng tiếp theo, mỗi dòng gồm 2 số nguyên u, v cho biết node u nối với node v.
//Output: 
//Với mỗi test, in ra K dòng, trong đó K là số lượng node lá. 
//Mỗi dòng là đường đi từ node gốc tới node lá X. 
//Node lá nào có nhãn nhỏ hơn, in ra trước.
//Input
//2
//5
//1 2
//1 3
//2 4
//2 5
//4
//1 2
//2 3
//3 4
//Ouput
//1 3
//1 2 4
//1 2 5
//1 2 3 4
#include <bits/stdc++.h>
using namespace std;
void dfs(vector<int> a[], int truoc[], int y){
	vector<int> v;
	int x=truoc[y];
	v.push_back(y);
	while(x!=0){
		y=x;
		x=truoc[y];
		v.push_back(y);
	}
	for(int i=v.size()-1;i>=0;i--){
		cout << v[i] << " ";
	}
	cout << endl;
}
int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<int> a[n+1];
		int truoc[n+1]={};
		for(int i=1;i<=n-1;i++){
			int x, y; cin >> x >> y;
			a[x].push_back(y);
			truoc[y]=x;
		}
		for(int i=2;i<=n;i++){
			if(a[i].empty()){
				dfs(a,truoc,i);
			}
		}
	}
}