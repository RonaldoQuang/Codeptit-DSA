//Cho hai số A, B ở hệ cơ số K. 
//Hãy tính tổng hai số đó ở hệ cơ số K.
//Input
//1
//2 1 10
//Output
//11
#include <bits/stdc++.h>
using namespace std;
int main() {
	int t; cin >> t;
	while(t--){
		int k; cin >> k;
		string a, b; cin >> a >> b;
		while(a.size()<b.size()){
            a="0"+a;
        }
        while(b.size()<a.size()) {
            b="0"+b;
        }
        string s="";
        int c=0, d;
        for(int i=a.size()-1;i>=0;i--){
        	d=(a[i]-'0')+(b[i]-'0')+c;
        	s=char(d%k+'0')+s;
        	c=d/k;
		}
		if(c>0) s=char(c+'0')+s;
		cout << s << endl;
	}
}