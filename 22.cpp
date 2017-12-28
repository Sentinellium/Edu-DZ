#include <iostream>
//#include <std_lib_facilities.h>
using namespace std;

struct Node
{
    int x;
    Node *l,*r;
};

void show(Node *&Tree)
{
    if (Tree!=NULL)
    {
        show(Tree->l);
        cout<<Tree->x<<endl;
        show(Tree->r);
    }
}

void del(Node *&Tree){
    if (Tree!=NULL)
    {
        del(Tree->l);
        del(Tree->r);
        delete Tree;
        Tree = NULL;
    }
}
void sum(Node *&Tree,int *s){
    if (Tree!=NULL){
        *s+=Tree->x;
        sum(Tree->l,s);
        sum(Tree->r,s);
    }
}

void isitin(int x,Node *&MyTree)
{
    if (MyTree!=NULL)
    {
        if (x=MyTree->x)
        {
            cout << "True"<<'\n';
        }
        if (x>MyTree->x){
            isitin(x,MyTree->l);
        }
        if (x<MyTree->x){
            isitin(x,MyTree->r);
        }
    }
    else
    cout << "False"<<'\n';
}

void add_node(int x,Node *&MyTree)
{
    if (NULL==MyTree)
    {
        MyTree=new Node;
        MyTree->x=x;
        MyTree->l=MyTree->r=NULL;
    }
    if (x<MyTree->x)
    {
    if (MyTree->l!=NULL) add_node(x,MyTree->l);
    else
    {
        MyTree->l=new Node;
        MyTree->l->l=MyTree->l->r=NULL;
        MyTree->l->x=x;
    }
    }
    if (x>MyTree->x)
    {
        if (MyTree->r!=NULL) add_node(x,MyTree->r);
        else
        {
            MyTree->r=new Node;
            MyTree->r->l=MyTree->r->r=NULL;
            MyTree->r->x=x;
        }
    }
}
void ideal(Node *&MyTree,int *arr,int left,int right){
    add_node(arr[(left+right)/2],MyTree);
    if (left==right){
        return;
    }
    ideal(MyTree,arr,(left+right)/2+1,right);
    ideal(MyTree,arr,left,(left+right)/2);
}

int main()
{
int n;
cout << "enter n" <<'\n';
cin >> n;
Node *Tree=NULL;
int *arr=new int[n];
for (int i=0;i<n;i++){
    arr[i]=rand();
}
for (int i=0;i<n;i++){
    for (int k=0;k<n-1-i;k++){
        if (arr[k]>arr[k+1]){
            swap(arr[k],arr[k+1]);
        }
    }
}
for (int i=0;i<n;i++){
    cout <<arr[i]<<endl;}
ideal(Tree,arr,0,n-1);
show(Tree);
del(Tree);
}
