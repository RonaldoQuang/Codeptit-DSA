//Cho cây nhị phân, nhiệm vụ của bạn là kiểm tra xem cây nhị phân có phải là một cây hoàn hảo hay không (perfect tree)? 
//Một cây nhị phân được gọi là cây hoàn hảo nếu tất cả các node trung gian của nó đều có hai node con và tất cả các node lá đều có cùng một mức.
//Input
//3
//6
//10 20 L 10 30 R 20 40 L 20 50 R 30 60 L 30 70 R
//2
//18 15 L 18 30 R
//5
//1 2 L 2 4 R 1 3 R 3 5 L 3 6 R
//Output
//Yes
//Yes
//No
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
void makeNode(node a, int x, int y, char z){
    if(z=='L'){
    	a->left=new Node(y);
	}	
	else a->right=new Node(y);
}
void Insert(node &a, int x, int y, char z){
	if(a==NULL) return;
	if(a->data==x) makeNode(a,x,y,z);
	else{
		Insert(a->left,x,y,z);
		Insert(a->right,x,y,z);
	}
}
void check(node a, int &ok){
	if((a->left==NULL&&a->right!=NULL)||(a->left!=NULL&&a->right==NULL)){
		ok=0;
		return;
	}
	else if(a->left!=NULL&&a->right!=NULL){
		check(a->left,ok);
		check(a->right,ok);
	}
}
int dem(node a){
	if(a==NULL) return 0;
	if(a->left==NULL&&a->right==NULL) return 1;
	else return dem(a->left)+dem(a->right);
}
int main(){
	int t; cin >> t;
	while(t--){
		int n, ok=1; cin >> n;
		node a=NULL;
		while(n--){
			int x, y; char z;
			cin >> x >> y >> z;
			if(a==NULL){
				a=new Node(x);
			}
			Insert(a,x,y,z);
		}
		check(a,ok);
		if(a==NULL) cout << "No" << endl;
		else{
			if(dem(a->left)==dem(a->right)&&ok==1) cout << "Yes" << endl;
			else cout << "No" << endl;
		}
	}
}