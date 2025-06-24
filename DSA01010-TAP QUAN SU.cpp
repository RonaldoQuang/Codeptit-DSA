//Tại Chương Mỹ Resort, vào nửa đêm, cả trung đội nhận lệnh tập trung ở sân. 
//Mỗi chiến sỹ được đánh số từ 1 đến N (1<N<40). 
//Giám thị yêu cầu chọn ra một dãy K chiến sỹ để tập đội ngũ và cứ lần lượt duyệt hết tất cả các khả năng chọn K người như vậy từ nhỏ đến lớn (theo số thứ tự). 
//Bài toán đặt ra là cho một nhóm K chiến sỹ hiện đang phải tập đội ngũ, hãy tính xem trong lượt chọn K người tiếp theo thì mấy người trong nhóm cũ sẽ được tạm nghỉ. 
//Nếu đã là nhóm cuối cùng thì tất cả đều sẽ được nghỉ.
//Dữ liệu vào: Dòng đầu ghi số bộ test, không quá 20. Mỗi bộ test viết trên hai dòng
//Dòng 1: hai số nguyên dương N và K (K<N)
//Dòng 2 ghi K số thứ tự của các chiến sỹ đang phải tập đội ngũ (viết từ nhỏ đến lớn)
//Kết quả: Với mỗi bộ dữ liệu in ra số lượng chiến sỹ được tạm nghỉ.
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