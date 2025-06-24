//Hãy viết chương trình chuyển đổi một xâu mã nhị phân X có độ dài n thành một xâu mã Gray.
//2
//01001
//01101
//Output
//01101
//01011
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t; cin >> t;
    while(t--){
    	string s; cin >> s;
		string a="";
		a+=s[0];
		for(int i=1;i<s.size();i++){
            if(s[i]!=s[i-1]) a+="1";
            else a+="0";
        }
		cout << a << endl;	
	}
	
}