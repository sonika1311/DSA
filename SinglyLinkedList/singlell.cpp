#include<iostream>
using namespace std;

void createNode();
void display();
void insert();
struct Node *temp, *head = NULL;
struct Node{
    int data;
    struct Node* next;
};
int main(){
    int choice;
    
    do{
        cout<<"Singly Linked List"<<endl;
        cout<<"Enter 1 to create new node in linked list"<<endl;
        cout<<"Enter 2 to display linked list"<<endl;
        cout<<"Enter 3 to insert into linked list"<<endl;
        cin>> choice;
        switch(choice){
            case 1: createNode();
            break;
            case 2: display();
            break;
            case 3: insert();
            break;
        }
    }while(choice != 7);
    return 0;
}

void createNode(){
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    //cout<<&newnode<<endl;
    //cout<<typeid(&newnode).name()<<endl;
    cout<<"Enter data"<<endl;
    cin>> newnode->data;
    newnode->next=NULL;
    if(head==NULL){
        head = newnode;
        temp = newnode;
    }
    else{
        temp->next = newnode;
        temp = temp->next;
    }
    //cout<<temp->data;
    display();
}
void display(){
    struct Node* p;
    p = head;
    int cnt=0;
    while(p->next!=NULL){
        cnt++;
        cout<<p->data << "-->";
        p = p->next;
    }
        cout<< p->data << endl;
}
void insert(){
    int pos,value;
    cout<<"Enter the position to insert"<<endl;
    cin>>pos;
    cout<<"Enter the data to insert"<<endl;
    cin>>value;
    if(pos==1){
        struct Node* newnode = (struct Node *)malloc(sizeof(struct Node));
        newnode->data = value;
        newnode->next=head;
        head=newnode;
        display();
    }
    else{
        cout<<"to be implented";
    }

}