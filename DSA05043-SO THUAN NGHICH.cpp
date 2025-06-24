//Cho số nguyên dương N có không quá 1000 chữ số. 
//Hãy tính độ dài lớn nhất của một số thuận nghịch tạo được bằng cách lấy liên tiếp các chữ số trong N.
//Input
//2
//13731456
//44444
//Output
//5
//5
#include <bits/stdc++.h> 
using namespace std; 
int check(string s){ 
    int l=0,r=s.size()-1; 
	while(l<=r){ 
	    if(s[l]!=s[r]) return 0; 
		l++; 
		r--; 
	} 
	return 1; 
} 
int main(){ 
    int t; cin >> t; 
	while(t--){ 
	    string s; cin >> s;  
		int max1=1; 
		for(int i=0;i<s.size();i++){ 
		    string a=""; 
			for(int j=i;j<s.size();j++){ 
			    a+=s[j]; 
				if(check(a)){
				    int k=a.size(); 
				    max1=max(max1,k); 
				} 
			} 
		} 
		cout << max1 << endl; 
	} 
}