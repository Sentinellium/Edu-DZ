#include <iostream>
#include <std_lib_facilities.h>
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

int main()
{
int n,c;
cout << "enter n" <<'\n';
cin >> n;
cout << "enter x"<<'\n';
Node *Tree=NULL;
int *k=new int;
*k=0;
for (int i=0;i<n;i++){
    cin >> c;
    add_node(c,Tree);
}
//show(Tree);
sum(Tree,k);
cout <<*k<<endl;
del(Tree);
}
