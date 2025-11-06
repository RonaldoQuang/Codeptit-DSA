//Cho 3 số nguyên A, B và K. 
//Trong các xâu có độ dài bằng A + B, gồm A kí tự ‘a’ và B kí tự ‘b’, hãy tìm xâu có thứ tự từ điển bằng K.
//Input
//Dữ liệu đầu vào gồm 3 số nguyên A, B và K (1 ≤ A, B ≤ 30, 1 ≤ K ≤ S với S là số lượng xâu có A kí tự ‘a’ và B kí tự ‘b’, S có giá trị không vượt quá phạm vi số nguyên 64 bit).
//Output
//In ra xâu tìm được
//Input
//2 2 4
//Output
//baab
//Giải thích test
//aabb, abab, abba, baab, baba, bbaa.
#include <bits/stc++.h>
using namespace std;
long long nCk(int n, int k) {
    if(k<0||k>n) return 0;
    long long tich=1;
    k=min(k,n-k);
    for(int i=1;i<=k;i++){
    	tich*=(n-i+1);
    	tich/=i;
	}
    return tich;
}
int main() {
    int a, b;
	long long k;
	cin >> a >> b >> k;
	string s="";
	while(a!=0||b!=0){
		if(a==0){
			s+="b";
			--b;
		}
		else if(b==0){
			s+="a";
			--a;
		}
		else{
			if(k<=nCk(a+b-1,a-1)){
				s+="a";
				--a;
			}
			else{
				s+="b";
				k-=nCk(a+b-1,a-1);
				--b;
			}
		}
	}    
	cout << s;
}
