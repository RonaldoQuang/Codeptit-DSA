//Một bộ ba số (a,b,c) được gọi là bộ ba số Pytago nếu a2 = b2 + c2.
//Người ta mở rộng thêm khái niệm mới, bộ ba số được gọi là “siêu Pytago” nếu 2*a2 = b2 + c2. 
//Trong đó (a,b,c) từng đôi một khác nhau.
//Bài toán đặt ra là cho số nguyên dương a, hãy kiểm tra xem liệu có tồn tại các giá trị b,c để tạo ra bộ ba số “siêu Pytago” hay không. 
//Chú ý: 1 ≤ a, b, c ≤ 105
//Input
//Chỉ có một số nguyên dương a (1 ≤ a ≤ 105)
//Output
//Ghi ra YES hoặc NO tuỳ thuộc kết quả kiểm tra.
//Input
//1005
//Output
//YES
#include <bits/stdc++.h>
using namespace std;
int check(int n){
	if((int)sqrt(n)*(int)sqrt(n)==n) return 1;
	else return 0;
}
int main(){	
    int a, ok=0; cin >> a;
    for(int i=1;i<=sqrt(2*a*a);i++){
    	int x=2*a*a-i*i;
    	if(i!=a&&check(x)==1&&sqrt(x)!=a&&i!=sqrt(x)){
    		cout << i << " " << sqrt(x) << endl;
    		ok=1;
    		break;
		}
	}
	if(ok) cout << "YES";
	else cout << "NO";
}