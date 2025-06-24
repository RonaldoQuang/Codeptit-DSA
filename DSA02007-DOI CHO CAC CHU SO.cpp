//Cho số tự nhiên K và xâu ký tự các chữ số S.  
//Nhiệm vụ của bạn là đưa ra số lớn nhất bằng cách thực hiện nhiều nhất K lần đổi chỗ các ký tự trong S. 
//Ví dụ K =3 và S = “1234567” ta được “7654321”.
//Input:
//Dòng đầu tiên đưa vào số lượng bộ test T.
//Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai dòng: dòng thứ nhất là số K; dòng tiếp theo là xâu ký tự S.
//T, K, S thỏa mãn ràng buộc: 1≤T ≤100; 1≤K≤10; 1≤.lenght(S)≤7.
//Output:
//Đưa ra kết quả mỗi test theo từng dòng.
//Input
//3
//4
//1234567
//3
//3435335
//2
//1034
//Output
//7654321
//5543333
//4301
#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		string s; cin >> s;
		string a="", x=s;
		int b[17];
		for(int i=0;i<s.size();i++){
			b[i]=s[i];
		}
		sort(b,b+s.size());
		for(int i=0;i<s.size();i++) a+=b[s.size()-1-i];
		int cnt=0, i=0;
		while(cnt<n&&i<s.size()){
			if(a[i]!=s[i]){
				++cnt;
				string z;
				for(int j=0;j<s.size();j++){
					if(j!=i&&s[j]==a[i]){
						swap(s[i],s[j]);
						z=s;
						swap(s[i],s[j]);
					}
					if(z>x) x=z;					
				}
				s=x;
			}
			else i++;
		}
		cout << x << endl;
	}
}