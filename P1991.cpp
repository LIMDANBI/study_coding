#include <iostream>
using namespace std;

int tree[26][2];

void preorder(int n){
    if(n==-1) return;
    cout << (char)(n+'A');
    preorder(tree[n][0]);
    preorder(tree[n][1]);
}

void inorder(int n){
    if(n==-1) return;
    inorder(tree[n][0]);
    cout << (char)(n+'A');
    inorder(tree[n][1]);
}

void postorder(int n){
    if(n==-1) return;
    postorder(tree[n][0]);
    postorder(tree[n][1]);
    cout << (char)(n+'A');
}

int main(){
    int n; cin>>n;
    for(int i=0; i<n; i++){
        char parent, leftchild, rightchild;
        cin >> parent >> leftchild >> rightchild;
        parent = parent-'A';

        if(leftchild == '.') tree[parent][0] = -1;
        else tree[parent][0] = leftchild-'A';

        if(rightchild == '.') tree[parent][1] = -1;
        else tree[parent][1] = rightchild-'A';

    }
    preorder(0); cout << '\n';
    inorder(0); cout << '\n';
    postorder(0); cout << '\n';
}