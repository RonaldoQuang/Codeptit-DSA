//Hãy viết chương trình chuyển đổi biểu thức biểu diễn dưới dạng tiền tố về dạng hậu tố.
//Input
//2
//*+AB-CD
//*-A/BC-/AKL
//Output
//AB+CD-*
//ABC/-AK/L-*
#include <bits/stdc++.h>
using namespace std;
int main(){ 
    int t; cin >> t;
    while(t--){
    	string s; cin >> s;
    	stack<string> st;
    	for(int i=s.size()-1;i>=0;i--){
    		if(s[i]<='Z'&&s[i]>='A') st.push(string(1,s[i]));
    		else{
    			string a=st.top();
    			st.pop();
    			string b=st.top();
    			st.pop();
    			string w=a+b+s[i];
    			st.push(w);
			}
		}
		cout << st.top() << endl;
	}
}