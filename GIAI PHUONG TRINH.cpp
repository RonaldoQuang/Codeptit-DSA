//Giải phương trình Ax^3 + Bx = C với A, B, C là các số nguyên dương.
//Input
//3
//1 3 5
//1 1 1
//1 2 10
//Output
//1.1542
//0.6823
//1.8474
#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin >> t;
	while(t--){
		float a, b, c; cin >> a >> b >> c;
		float delta=-3*a*b;
		float k=(27*a*a*c)/(2*sqrt(pow(abs(delta),3)));
		float m=sqrt(abs(delta))/(3*a);
		float n=cbrt(k+sqrt(k*k+1))+cbrt(k-sqrt(k*k+1));
		cout << fixed << setprecision(4) << m*n << endl;
	}
}
