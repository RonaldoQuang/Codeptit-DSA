#include <bits/stdc++.h>
using namespace std;
string operator*(string a, int b){
    if(a=="0"||b==0) return "0";
    string s(a.size(),'0');
    int sum=0;
    for(int i=a.size()-1;i>=0;i--){
        sum+=(a[i]-'0')*b;
        s[i]=sum%10+'0';
        sum/=10;
    }
    if(sum>0) s=to_string(sum)+s;
    return s;
}
string kq(int n){
	vector<int> v;
    for(int i=n+2;i<=2*n;i++) v.push_back(i);
    for(int i=2;i<=n;i++){
    	int x=i;
        for(int j=0;j<v.size();j++){
			int d=__gcd(v[j],x);
			x/=d;
            v[j]/=d;
        }
    }
    string s="1";
    for(int i=0;i<v.size();i++){
    	s=s*v[i];
	}
	return s;
}
int main(){
	int t; cin >> t;
	while(t--){
		short int n; cin >> n;
		cout << kq(n) << endl;
	}
}