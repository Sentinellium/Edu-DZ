#include <iostream>

using namespace std;

struct Queue{
    int val;
    int size;
    Queue *Head,*Tail,*Next;
    void Add(const int x);
    void Show(const int count);
    void Del();
};

void Queue::Add(int x){
    static int count=0;
    Queue *temp = new Queue;
    temp->val=x;
    if (Head!=NULL){
        if (Head->val>x){
            temp->Next=Head;
            Head=temp;
        }
        else{
            while ((temp->Next!=NULL) && (temp->Next->val<=x))
                temp=temp->Next;
            if (temp->Next==NULL){
                Queue *tempy = new Queue;
                tempy->val=x;
                temp->Next=tempy;
                Tail=tempy;
            }
            else{
                Queue *tempy = new Queue;
                tempy->val=x;
                tempy->Next=temp->Next;
                temp->Next=tempy;
            }
        }
    }
    else Head=Tail=temp;
    count++;
    size=count;

}

void Queue::Show(const int count){
    Queue *temp=Head;

        for (int i=0;i<count;i++){
            cout<<temp->val<<" ";
            temp=temp->Next;
    }      cout<<"\n";
}

void Queue::Del(){

    Queue *temp=new Queue;
    int count=0;
    while (temp!=Tail){
        temp=Head;
        Head=Head->Next;
        delete temp;
    }
}

int main(){


    Queue Q;
    Q.Head=NULL;
    for (int i=0;i<10;i++)
        Q.Add(rand());
    Q.Show(10);
    Q.Del();
}
