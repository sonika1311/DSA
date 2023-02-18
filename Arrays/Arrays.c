#include <stdio.h>

void populate();
void display();
void insert();
void delete();
int a[50],size=0;

int main(){
    int choice=1;
    do{
    if(choice>6 || choice<1){
        printf("please enter valid input\n");
    }
    printf("enter 1 to populate array\n");
    printf("enter 2 to insert element\n");
    printf("enter 3 to delete element\n");
    printf("enter 6 to exit\n");

    scanf("%d",&choice);
    switch(choice){
        case 1:
            populate();
            break;
        case 2:
            insert();
            break;
        case 3:
            delete();
            break;
        case 6:
            break;
    }
    printf("\n");
    }while(choice!=6);
    printf("Thanx!!");
}

void display(){
    printf("the array elements are : ");
    for(int i=0;i<size;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}
void populate(){
    printf("enter the size of array : ");
    scanf("%d",&size);
    for(int i=0 ; i<size ; i++){
        printf("enter element %d : ",i+1);
        scanf("%d",&a[i]);
    }
    display();
}
void insert(){
    int pos,i,ele;
    printf("enter the position at which you want to insert element : ");
    scanf("%d",&pos);
    //printf("size=%d , pos = %d", size,pos);
    for(i=size-1 ;i>=pos-1 ; i--){
        a[i+1] = a[i];
        //printf("%d , %d ", a[i+1],a[i]);
    }
    printf("enter the element you want to insert : ");
    scanf("%d",&ele);
    a[pos-1] = ele;
    size++;
    printf("\n");
    display();
    return;
}
void delete(){
    int pos,i;
    printf("enter the position of element you want to delete : ");
    scanf("%d",&pos);
    for(int i= pos-1; i<size-1 ;i++){
        a[i] = a[i+1];
    }
    size--;
    printf("\n");
    display();
}
