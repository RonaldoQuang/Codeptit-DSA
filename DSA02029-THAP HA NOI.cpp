//Bài toán Tháp Hà Nội đã rất nổi tiểng. 
//Bắt đầu có các đĩa xếp chồng lên cột A theo thứ tự kích thước giảm dần, nhỏ nhất ở trên cùng. 
//Cột B và cột C ban đầu không có đĩa nào cả.
//Mục tiêu của bạn là di chuyển toàn bộ các đĩa theo đúng thứ tự về cột C, tuân theo các quy tắc sau:
//1. Mỗi lần chỉ có thể di chuyển một đĩa.
//2. Mỗi lần di chuyển sẽ lấy đĩa trên từ một trong các cột và đặt nó lên trên một cột khác.
//3.Không được đặt đĩa lên trên đĩa nhỏ hơn..
//Input:
//Số tự nhiên  0 < N < 10
//Output:
//In ra lần lượt từng bước theo mẫu trong ví dụ. Chú ý giữa các chữ cái và dấu -> có khoảng trống.
//Input
//3
//Output
//A -> C
//A -> B
//C -> B
//A -> C
//B -> A
//B -> C
//A -> C
#include <bits/stdc++.h>
using namespace std;
void Try(int n, char a, char b, char c){
	if(n==1) cout << a << " -> " << c << endl;
	else{
		Try((n-1),a,c,b);
		cout << a << " -> " << c << endl;
		Try(n-1,b,a,c);
	}
}
int main() {
	int n; cin >> n;
	Try(n,'A','B','C');
}