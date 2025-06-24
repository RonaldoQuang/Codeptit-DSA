//Cho một bảng kích thước vô hạn được chia làm lưới ô vuông đơn vị. 
//Các hàng của bảng được đánh số từ 1 từ trên xuống và các cột của bảng được đánh số từ 1 từ trái qua phải. 
//Ô nằm trên giao điểm của hàng i, và cột j được gọi là ô (i, j). 
//Người ta điền các số nguyên liên tiếp bắt đầu từ 1 vào bảng theo quy luật sau:
//1 3 6 10 15 ...
//2 5 9 14 ... ...
//4 8 13 ... ... ...
//7 12 ... ... ... ...
//11 ... ... ... ... ... ...
//Yêu cầu 1: Xác định giá trị ghi trên ô (x, y) của bảng
//Yêu cầu 2: Xác định hàng và cột của ô chứa giá trị z.
//Input
//4 2
//8
//Output
//12
//3 2
#include <bits/stdc++.h>
using namespace std;
long long tong(long long n){
	return n*(n-1)/2;
}
int main(){
	long long x, y, z; cin >> x >> y;
    long long a=x+y-1;
    cout << 1+tong(a)+a-x << endl;
    cin >> z;
    long long b=(sqrt(8*z-7)+1)/2;
    long long c=1+tong(b);
    cout << b-z+c << " " << 1+z-c;
}