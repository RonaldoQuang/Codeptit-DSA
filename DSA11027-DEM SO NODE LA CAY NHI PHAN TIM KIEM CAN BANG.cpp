//Hãy xây dựng một cây nhị phân tìm kiếm cân bằng từ dãy số A[] =(a0, a1, .., an-1}. 
//Đưa ra phép duyệt theo thứ tự sau (post-order) của cây tìm kiếm cân bằng.  
//Ví dụ với dãy A[]={40, 28, 45, 38, 33, 15, 25, 20, 23, 35, 30} 
//Ta sẽ có phép duyệt theo thứ tự trước của cây nhị phân tìm kiếm cân bằng với node gốc là 33 : 15, 23, 20, 30, 28, 25, 35, 38, 45, 40, 33. 
//Input
//2
//11
//40  28  45 38  33  15  25  20  23  35  30
//10
//1  2  3  4  5  6  7  8  9  10
//Output
//5
//4
#include <bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	Node *left, *right;
	Node(int x){
		this->data=x;
		this->left=NULL;
		this->right=NULL;
	}
};
typedef struct Node* node;
void Insert(node &a, int x){
	if(a==NULL) a=new Node(x);
	else{
		if(x<a->data){
			if(a->left==NULL) a->left=new Node(x);
			else Insert(a->left,x);
		}
		else{
			if(a->right==NULL) a->right=new Node(x);
			else Insert(a->right,x);
		}
	}
}
void load(node &a, int b[], int l, int r){
	if(l>=r) return;
	int m=(l+r-1)/2;
	Insert(a,b[m]);
	load(a,b,l,m);
	load(a,b,m+1,r);
}
void dem(node a, int &cnt){
	if(a->left==NULL&&a->right==NULL) ++cnt;
	if(a->left!=NULL) dem(a->left,cnt);
	if(a->right!=NULL) dem(a->right,cnt );
}
int main(){
	int t; cin >> t;
	while(t--){
		int n, cnt=0; cin >> n;
		node a=NULL;
		int b[n];
		for(int &x:b) cin >> x;
		sort(b,b+n);
		load(a,b,0,n);
		dem(a,cnt);
		cout << cnt << endl;
	}
}