//Cho số tự nhiên n. 
//Hãy in ra tất cả các số nhị phân từ 1 đến n.
//Input
//2
//2
//5
//Output
//1 10
//1 10 11 100 101
#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		queue<string> q;
		vector<string> v;
		int cnt=1;
		string s="1";
		v.push_back(s);
		q.push(s);
		while(cnt<=n){
			s=q.front();
			q.push(s+"0");
			q.push(s+"1");
			q.pop();
			v.push_back(q.front());
			++cnt;
		}
		for(int i=0;i<n;i++){
			cout << v[i] << " ";
		}
		cout << endl;
	}
}