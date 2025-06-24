//Cho hai xâu nhị phân biểu diễn hai số. 
//Nhiệm vụ của bạn là đưa ra tích của hai số. 
//Ví dụ với xâu S1=”1100” và S2=”1010” ta sẽ có kết quả là 120.
//Input
//2
//1100 01
//01 01
//Output
//12
//1
#include <bits/stdc++.h>
using namespace std;
int main(){
    int t; cin >> t;
    while(t--){
    	string a, b; cin >> a >> b;
    	long long x=0, y=0;
    	for(int i=0;i<a.size();i++){
    		x=x*2+a[i]-'0';
		}
		for(int i=0;i<b.size();i++){
			y=y*2+b[i]-'0';
		}
		cout << x*y << endl;
	}
}