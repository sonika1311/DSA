#include<iostream>
using namespace std;

void create();
void display();
struct Node *temp, *head = NULL;
struct Node{
    int data;
    struct Node* next;
};
int main(){
    int choice;
    
    do{
        cout<<"Singly Linked List"<<endl;
        cout<<"Enter 1 to create linked list"<<endl;
        cout<<"Enter 2 to display linked list"<<endl;
        cin>> choice;
        switch(choice){
            case 1: create();
            break;
            case 2: display();
            break;
        }
    }while(choice == 7);
    return 0;
}

void create(){
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
}
