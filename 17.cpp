#include <iostream>

using namespace std;

struct node {
    int x;
    node* next;
    node* prev;
};

struct dequeue {
    node* tail=NULL;
    node* head=NULL;
    ~dequeue() {
        while (tail!=NULL) {
            node* temp=tail;
            tail=tail->next;
            delete temp;
        }
    }

    void push_back(int x) {
        node* temp = new node;
        temp->x=x;
        temp->next=tail;
        temp->prev=NULL;
        tail=temp;
        if (head==NULL) {
            head=tail;
        }
        if (tail->next!=NULL) {
            tail->next->prev=tail;
        }
    }

    void push_front(int x) {
        node* temp=new node;
        temp->x=x;
        temp->next=NULL;
        temp->prev=head;
        head=temp;
        if (tail==NULL) {
            tail=head;
        }
        if (head->prev!=NULL) {
            head->prev->next=head;
        }
    }

    int back() {
        if (tail==NULL) {
            cout <<"Empty";
            return 0;
        }
        return tail->x;
    }

    int front() {
        if (head==NULL) {
            cout <<"empty";
            return 0;
        }
        return head->x;
    }

    int pop_back() {
        if (tail==NULL) {
            cout <<"empty";
            return 0;
        }
        int x=tail->x;
        if (tail->next!=NULL) {
            tail=tail->next;
            delete tail->prev;
            tail->prev=NULL;
        }
        else {
            delete tail;
            tail=head=NULL;
        }
        return x;
    }

    int pop_front() {
        if (head==NULL) {
            cout <<"empty";
            return 0;
        }
        int x=head->x;
        if (head->prev!=NULL) {
            head=head->prev;
            delete head->next;
            head->next=NULL;
        }
        else {
            delete head;
            head=tail=NULL;
        }
        return x;
    }
};

int main()
{
    return 0;
}
