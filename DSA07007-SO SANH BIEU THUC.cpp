//Cho P1, P2 là hai biểu thức đúng chỉ bao gồm các ký tự mở ngoặc ‘(’ hoặc đóng ngoặc ‘)’ và các toán hạng in thường. 
//Nhiệm vụ của bạn là định xem P1 và P2 có giống nhau hay không.
//Input
//2
//-(a+b+c)
//-a-b-c
//a-b-(c-d)
//a-b-c-d
//Output
//YES
//NO
#include <bits/stdc++.h>
using namespace std;
char chuyen(char a){
	if(a=='+') return '-';
	else if(a=='-') return '+';
}
string biendoi(string s){
	stack<char> st;
	for(int i=s.size()-1;i>=0;i--){
		if(s[i]!='('){
			st.push(s[i]);
		}
		else{
			string a="";
			while(st.top()!=')'){
				a+=st.top();
				st.pop();
			}
			st.pop();
			if(s[i-1]=='-'){
				for(int j=a.size()-1;j>=0;j--){
					if(a[j]=='+'||a[j]=='-') st.push(chuyen(a[j]));
					else st.push(a[j]);
				}
			}
			else{
				for(int j=a.size()-1;j>=0;j--){
					st.push(a[j]);
				}
			}
		}			
	}
	string w="";
	while(!st.empty()){
		w+=st.top();
		st.pop();
	}
	return w;
}
int main(){
	int t; cin >> t;
	while(t--){
		string a, b; cin >> a >> b;
		if(biendoi(a)==biendoi(b)) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}
