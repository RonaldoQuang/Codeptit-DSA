//Cho số tự nhiên N. 
//Hãy tìm số nguyên dương X nhỏ nhất được tạo bởi số 9 và số 0 chia hết cho N. 
//Ví dụ với N = 5 ta sẽ tìm ra  X = 90.
//Input
//2
//5
//7
//Output
//90
//9009
#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		queue<string> q;
		vector<string> v;
		string s="9";
		v.push_back(s);
		q.push(s);
		while(1){
			s=q.front();
			if(s.size()==11) break;
			q.push(s+"0");
			q.push(s+"9");
			q.pop();
			v.push_back(q.front());
		}
		for(int i=0;i<v.size();i++){
			if(stoll(v[i])%n==0){
				cout << v[i] << endl;
				break;
			}
		}
		
	}
}