//Cho xâu ký tự mã hóa str. 
//Hãy viết chương trình giải mã xâu ký tự str. 
//Xâu ký tự mã hóa được thực hiện theo số lần lặp các xâu con của str như sau:
//Xâu đầu vào: “abbbababbbababbbab ”
//Xâu mã hóa : "3[a3[b]1[ab]]"
//Input
//2
//1[b]
//3[b2[ca]]
//Output
//b
//bcacabcacabcaca
#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin >> t;
	while(t--){
		string s; cin >> s;
		stack<string> st;
		stack<int> st1;
		int i=0;
		while(i<s.size()){
			if(s[i]<='9'&&s[i]>='0'){
				int x=0;
				while(s[i]<='9'&&s[i]>='0'){
					x=x*10+s[i]-'0';
					++i;
				}
				--i;
				st1.push(x);
			}
			else if(s[i]==']'){
				string w="";
				while(st.top()!="["){
					w=st.top()+w;
					st.pop();
				}
				st.pop();
				string a="";
				int x=st1.top(); st1.pop();
				while(x--) a+=w;
				st.push(a);
			}
			else{
				st.push(string(1,s[i]));
				if(s[i]=='['&&(i==0||s[i-1]<'0'||s[i-1]>'9')) st1.push(1);
			}
			++i;
		}
		string w="";
		while(!st.empty()){
			w=st.top()+w;
			st.pop();
		}
		cout << w << endl;
	}
}