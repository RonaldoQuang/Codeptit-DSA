//Cho số nguyên dương N được biểu diễn như một xâu ký tự số. 
//Nhiệm vụ của bạn là tìm tổng của tất cả các số tạo bởi các xâu con của N. 
//Ví dụ N=”1234” ta có kết quả là 1670 = 1 + 2 + 3 + 4 + 12 + 23 + 34 + 123 + 234 + 1234.
//Input
//2
//1234
//421
//Output
//1670
//491
#include <bits/stdc++.h>
using namespace std;
int main(){ 
    int t; cin >> t; 
	while(t--){ 
	    string s; cin >> s; 
		long long sum=0; 
		for(int i=0;i<s.size();i++){ 
		    string res=""; 
			for(int j=i;j<s.size();j++){ 
			    res+=s[j]; 
				sum+=stoll(res); 
			} 
		} 
		cout << sum << endl; 
	} 
}