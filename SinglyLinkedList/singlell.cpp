#include<iostream>
using namespace std;

void createNode();
void display();
void insert();
void deleteEle();
void reverse();
struct Node *tail, *head = NULL;
int size=0;
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
        cout<<"Enter 4 to delete a node from linked list"<<endl;
        cout<<"Enter 5 to reverse linked list"<<endl;
        cout<<"Enter 7 to exit"<<endl;
        cin>> choice;
        switch(choice){
            case 1: createNode();
            break;
            case 2: display();
            break;
            case 3: insert();
            break;
            case 4: deleteEle();
            break;
            case 5: reverse();
            break;
            default: cout<<"Invalid choice"<<endl;
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
        tail = newnode;
    }
    else{
        tail->next = newnode;
        tail = tail->next;
    }
    //cout<<temp->data;
    size++;
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
    do{
        cout<<"Enter the position to insert"<<endl;
        cin>>pos;
        if(pos<1 || pos>size+1)
            cout<< "Please enter position value between 1 and "<<size+1<<endl;
    }while((pos<1 || pos>size+1));

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
        //insert in between and end
        struct Node * temp=head;
        int cnt = pos-2;
        while(cnt>0){
            temp = temp->next;
            cnt--;   
        }
        struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
        
        newnode->data = value;
        if(temp->next!=NULL){
        //handles insert in between
        newnode->next = temp->next;
        }
        temp->next=newnode;
        if(newnode->next==NULL) tail = newnode;
    }
    size++;
    display();

}

void deleteEle(){
    int pos;
    do{
        cout<<"Enter position of element to delete"<<endl;
        cin>>pos;
        if(pos<1 || pos>size)
            cout<< "Please enter position value between 1 and "<<size<<endl;
    }while((pos<1 || pos>size));

    if(pos==1){
        head = head->next;
    }
    else{
        struct Node* elePos, *temp=head;
        int cnt = pos-2;
        while(cnt>0){
            temp = temp->next;
            cnt--;
        }
        elePos = temp->next;
        temp->next = elePos->next;
    }
    size--;
    display();
}
void reverse(){
    struct Node *first,*second,*temp;
    first = head;
    second = first->next;

    while(second !=NULL){
        temp = second->next;
        second->next = first;
        first = second;
        second = temp;
    }
    head->next=NULL;
    tail=head;
    head=first;
    display();
}