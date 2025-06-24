//Hãy viết chương trình chuyển tính toán giá trị của biểu thức hậu tố.
//Input
//2
//231*+9-
//875*+9-
//Output
//-4
//34
#include <bits/stdc++.h>
using namespace std;
int tinh(int a, int b, char c){
	if(c=='+') return a+b;
	if(c=='-') return a-b;
	if(c=='*') return a*b;
	if(c=='/') return a/b;
}
int main(){ 
    int t; cin >> t;
    while(t--){
    	string s; cin >> s;
    	stack<int> st;
    	for(int i=0;i<s.size();i++){
    		if(s[i]>='0'&&s[i]<='9') st.push(s[i]-'0');
    		else{
    			int b=st.top(); st.pop();
    			int a=st.top(); st.pop();
    			st.push(tinh(a,b,s[i]));
			}
		}
		cout << st.top() << endl;
	}
}