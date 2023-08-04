#include<stdio.h>
#include<stdlib.h>

#define MAX 5

int queue[MAX];
int front=-1;
int rear=-1;

void enqueue(int item)
{
    if(rear==MAX-1)
    {
        printf("\n Queue Overflow");
        return;
    }
    if(front==-1 && rear==-1)
    {
        front=0;
        rear=0;
    }
    else
    {
        rear=rear+1;
    }
    queue[rear]=item;
    printf("\n Value inserted");
}

void dequeue()
{
    int item;
    if(front==-1 || front>rear)
    {
        printf("\n Queue Underflow");
        return;
    }
    else
    {
        item=queue[front];
        if(front==rear)
        {
            front=-1;
            rear=-1;
        }
        else
        {
            front=front+1;
        }
        printf("\n Value deleted");
    }
}

void display()
{
    int i;
    if(rear==-1)
    {
        printf("\n Empty Queue");
        return;
    }
    else
    {
        printf("\n Queue elements are: ");
        for(i=front;i<=rear;i++)
        {
            printf("%d ",queue[i]);
        }
    }
}

int main()
{
    int choice,item;
    while(1)
    {
        printf("\n 1. Enqueue");
        printf("\n 2. Dequeue");
        printf("\n 3. Display");
        printf("\n 4. Exit");
        printf("\n Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("\n Enter the value to be inserted: ");
                scanf("%d",&item);
                enqueue(item);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("\n Invalid choice");
        }
    }
    return 0;
}
