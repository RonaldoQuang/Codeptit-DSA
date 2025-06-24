#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin >> t;
	while(t--){
		string s; cin >> s;
		map<char,int> mp;
		for(int i=0;i<s.size();i++){
			mp[s[i]]++;
		}
		int max=-1e9;
		for(auto x:mp){
			if(x.second>max) max=x.second;
		}
		if(s.size()%2==0){
			if(max<=s.size()/2) cout << "1\n";
			else cout << "-1\n";
		}
		else{
			if(max<=s.size()/2+1) cout << "1\n";
			else cout << "-1\n";
		}
	}
}