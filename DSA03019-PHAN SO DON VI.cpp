//Một phân số đơn vị nếu tử số của phân số đó là 1. 
//Mọi phân số nguyên dương đều có thể biểu diễn thành tổng các phân số đơn vị. 
//Ví dụ 2/3 = 1/2  + 1/6. 
//Cho phân số nguyên dương P/Q bất kỳ (P < Q), hãy biểu diễn phân số nguyên dương thành tổng phân số đơn vị với số hạng tử là ít nhất.
//Input
//2
//2 3
//1 3
//Output
//1/2 + 1/6
//1/3
#include<bits/stdc++.h>
using namespace std;
int main(){ 
    int t; cin >> t; 
	while(t--){ 
	    long long p, q; cin >> p >> q;
	    while(q%p!=0){
	    	long long x=q/p+1;
	    	cout << "1/" << x << " + ";
	    	p=p*x-q;
	    	q*=x;
		}
		cout << "1/" << q/p << endl;
	} 
}