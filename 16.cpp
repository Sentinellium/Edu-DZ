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
        Tail->Next=temp;
        Tail=temp;
    } else Head=Tail=temp;
    count++;
    size=count;
    Tail->Next=Head;

}

void Queue::Show(const int count){
    Queue *temp=Head;

        for (int i=0;i<count;i++){
            cout<<temp->val<<" ";
            temp=temp->Next;
    }      cout<<endl;
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
