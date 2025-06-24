//Một số được gọi là lộc phát nếu chỉ có 2 chữ số 6 và 8. 
//Cho số tự nhiên N. 
//Hãy liệt kê các số lộc phát có không quá N chữ số.
//Input
//2
//2
//3
//Output
//6
//6 8 66 68 86 88
//14
//6 8 66 68 86 88 666 668 686 688 866 868 886 888
#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		queue<string> q;
		vector<string> v;
		v.push_back("6");
		v.push_back("8");
		q.push("6");
		q.push("8");
		if(n>=2){
			while(1){
			    string s=q.front();
			    if(s.size()==n+1) break;
			    q.push(s+"6");
			    q.push(s+"8");
			    q.pop();
			    if(q.front().size()<=n&&q.front()!="8")v.push_back(q.front());
		    }
		}
		cout << v.size() << endl;
		for(int i=0;i<v.size();i++){
			cout << v[i] << " ";
		}
		cout << endl;
	}
}