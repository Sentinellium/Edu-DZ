#include <iostream>

using namespace std;

struct Node
 {
     int x;
     Node *Next;
 };

class Queue
{
    Node *Head,*Tail;
public:
    Queue(){
        Head=NULL;
        Tail=NULL;
    }
    ~Queue();
    void Show();
    void Add(int x);
};


void Queue::Add(int x){
    if (Head!=NULL)
    {
        Node *temp=Head;
        while ((temp->Next!=NULL) && (temp->Next->x<=x))
            temp=temp->Next;
        if (temp->Next==NULL){
            Node *tempy=new Node;
            tempy->x=x;
            tempy->Next=NULL;
            temp->Next=tempy;
            Tail=tempy;
        }
        else{
            Node *tempy=new Node;
            tempy->x=x;
            tempy->Next=temp->Next;
            temp->Next=tempy;
        }
    }
    else
    {
       Node *tempy=new Node;
       tempy->Next=NULL;
       tempy->x=x;
       Tail=tempy;
       Head=Tail;
    }
}

void Queue::Show()
{
    Node *temp=Head;
    while (temp!=NULL)
    {
       cout<<temp->x<<" ";
       temp=temp->Next;
    }
    cout <<endl;
}
Queue::~Queue()
 {
   while (Head)
   {
     Tail=Head->Next;
     delete Head;
     Head=Tail;
     }
 }

int main(){


    Queue Q;
    for (int i=0;i<10;i++){
        Q.Add(rand());
        //cout <<1;
    }
    Q.Show();
}
