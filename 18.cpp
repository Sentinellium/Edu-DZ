#include <iostream>

using namespace std;

struct Node
 {
     int x;
     Node *Next,*Prev;
 };

 class List
 {
     Node *Head,*Tail;
 public:
     List():Head(NULL),Tail(NULL){};
     ~List();
     void Show();
     void Add(int x);
     void Sort();
 };

List::~List()
 {
     while (Head)
     {
         Tail=Head->Next;
         delete Head;
         Head=Tail;
     }
 }

 void List::Add(int x)
 {
   Node *temp=new Node;
   temp->Next=NULL;
   temp->x=x;

   if (Head!=NULL)
   {
       temp->Prev=Tail;
       Tail->Next=temp;
       Tail=temp;
   }
   else
   {
       temp->Prev=NULL;
       Head=Tail=temp;
   }
 }

 void List::Show()
 {
     Node *temp=Tail;
     while (temp!=NULL)
     {
        cout<<temp->x<<" ";
        temp=temp->Prev;
     }
     cout <<endl;


     //temp=Head;
     // while (temp!=NULL)
     //{
     //   cout<<temp->x<<" ";
     //   temp=temp->Next;
     //}
     //cout <<endl;
 }

 void List::Sort()
 {

    Node *list=Head;
    Node *node,*node2;
      for(node=list;node;node=node->Next)
        for(node2=list;node2;node2=node2->Next)
            if( node->x>node2->x){
                int i=node->x;
                node->x=node2->x;
                node2->x=i;
            }
 }

int main ()
{
 List list;
 for (int i=0;i<10;i++)
    list.Add(rand());
 list.Sort();
 list.Show();
 list;
}
