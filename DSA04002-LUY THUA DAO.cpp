//Cho mảng số N. 
//Ta gọi số đảo của N là R. 
//Hãy tìm lũy thừa R của N. 
//Đưa ra kết quả của bài toán dưới dạng modulo với 10^9 + 7.
//Input
//2
//2
//12
//Output
//4
//864354781
#include <bits/stdc++.h> 
using namespace std; 
int mod=1e9+7; 
long long pow(long long n, long long k){ 
    if(k==0) return 1; 
    long long x=pow(n,k/2); 
    if(k%2==0) return x*x%mod; 
    return n*(x*x%mod)%mod; 
} 
long long dao(long long n){ 
    long long rev=0; 
    while(n!=0) { 
        rev=rev*10+n%10; 
        n/=10; 
    } 
    return rev; 
} 
int main() { 
    int t; cin >> t; 
    while(t--){ 
        long long n; cin >> n; 
        cout << pow(n,dao(n)) << endl; 
    } 
}