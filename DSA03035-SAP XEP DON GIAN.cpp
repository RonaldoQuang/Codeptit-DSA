//Cho một dãy số a[] có n phần tử gồm các số từ 1 đến n theo 1 thứ tự ngẫu nhiên. 
//Nhiệm vụ của bạn là sắp xếp lại dãy số này theo thứ tự tăng dần với điều kiện : ở mỗi bước sắp xếp, bạn chỉ được chọn 1 số ở 1 vị trí bất kì và chuyển số đó lên đầu dãy hoặc về cuối dãy.
//Hãy tính số bước tối thiểu cần thực hiện để hoàn thành việc sắp xếp.
//Input
//5
//4 1 2 5 3
//Output
//2
#include <bits/stdc++.h>
using namespace std;
int main(){ 
	int n; cin >> n; 
	int a[n+1]; 
	int b[100005]; 
	int max1=0; 
	for(int i=1;i<=n;i++){ 
		cin >> a[i]; 
		b[a[i]]=b[a[i]-1]+1; 
		max1=max(max1,b[a[i]]); 
	} 
	cout << n-max1 << endl;
}