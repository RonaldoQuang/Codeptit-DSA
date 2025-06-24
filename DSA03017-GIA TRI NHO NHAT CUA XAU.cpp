//Cho xâu ký tự S. 
//Ta gọi giá trị của xâu S là tổng bình phương số lần xuất hiện mỗi ký tự trong S. 
//Hãy tìm giá trị nhỏ nhất của xâu S sau khi thực hiện K lần loại bỏ ký tự.
//Input
//2
//2
//ABCCBC
//2
//AAAB
//Output
//6
//2
#include <bits/stdc++.h> 
using namespace std; 
int main(){ 
    int t; cin >> t; 
    while(t--){ 
        int n; cin >> n; 
        string s; cin >> s;
        map<char,int> mp;
        for(char x:s) mp[x]++;
        vector<int> v;
        for(auto x:mp) v.push_back(x.second);
        while(n){
        	sort(v.begin(),v.end());
        	v[v.size()-1]-=1;
        	n--;
		}
		long long sum=0;
		for(auto x:v) sum+=x*x;
		cout << sum << endl;
	} 	 
}