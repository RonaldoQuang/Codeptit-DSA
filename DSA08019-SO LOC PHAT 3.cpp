//Một số được gọi là lộc phát nếu chỉ có 2 chữ số 6 và 8. 
//Cho số tự nhiên N. 
//Hãy liệt kê các số lộc phát có không quá N chữ số.
//Input
//2
//2
//3
//Output
//6
//88 86 68 66 8 6
//14
//888 886 868 866 688 686 668 666 88 86 68 66 8 6
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
		for(int i=v.size()-1;i>=0;i--){
			cout << v[i] << " ";
		}
		cout << endl;
	}
}