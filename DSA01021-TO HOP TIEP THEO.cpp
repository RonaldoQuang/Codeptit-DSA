//Cho số nguyên dương (1<N<40) và số nguyên dương K<N. 
//Với 1 tổ hợp chập K phần tử của N, hãy cho biết tổ hợp tiếp theo sẽ có bao nhiêu phần tử mới. 
//Nếu tổ hợp đã cho là cuối cùng thì kết quả là K. 
//Dữ liệu vào: Dòng đầu ghi số bộ test, không quá 20. Mỗi bộ test viết trên hai dòng
//Dòng 1: hai số nguyên dương N và K (K<N)
//Dòng 2 ghi K số của tổ hợp ban đầu. Theo đúng thứ tự tăng dần, không có số nào trùng nhau.
//Kết quả: Với mỗi bộ dữ liệu in ra số lượng phần tử mới.
//Input
//3
//5 3
//1 3 5
//5 3
//1 4 5
//6 4
//3 4 5 6
//Output
//1
//2
//4
#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin >> t;
	while(t--){
		int n, k, cnt=0; cin >> n >> k;
		int a[k+1];
		map<int,int> mp;
		for(int j=1;j<=k;j++){
			cin >> a[j];
			mp[a[j]]=1;
		}
		int i=k;
        while(i>=1){
            if(a[i]<n-(k-i)){
        	    a[i]+=1;
                for(int j=i+1;j<=k;j++){
                    a[j]=a[j-1]+1;
                }
				break;
            }
            else{
                --i;
            }
        }
        if(i>=1){
        	for(int j=1;j<=k;j++){
        		mp[a[j]]++;
			}
			for(int j=1;j<=k;j++){
				if(mp[a[j]]==1) ++cnt;
			}
			cout << cnt;
		}
		else{
			cout << k;
		}
		cout << endl;
	}
}