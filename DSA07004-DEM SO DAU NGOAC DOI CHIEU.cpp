//Cho một xâu chỉ gồm các kí tự ‘(‘, ‘) và có độ dài chẵn. 
//Hãy đếm số lượng dấu ngoặc cần phải đổi chiều ít nhất, sao cho xâu mới thu được là một dãy ngoặc đúng.
//Input
//4
//))((
//((((
//(((())
//)(())(((
//2
//2
//1
//3
#include <bits/stdc++.h>
using namespace std;
int main() {
	int t; cin >> t;
	while(t--){
		string s; cin >> s;
		int cnt=0;
		while(s.size()) {
			int x=s.find("()");
			if(x==-1) {
				if(s[0]==')'){
					s[0]='(';
					++cnt;
				}
				if(s[s.size()-1]=='('){
					s[s.size()-1]=')'; 
					++cnt;
				}
			}
			else{
				s.erase(x,2);
			}
		}
		cout << cnt << endl;
	}
}