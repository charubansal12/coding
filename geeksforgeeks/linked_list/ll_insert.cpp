#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;
};
void insertAtBegining(struct node** headRef, int newData);
void insertAtEnd(struct node** headRef, int newData);
void printList(struct node *node)
{
    while (node != NULL)
    {
        cout<<node->data<<' ';
        node = node->next;
    }
    cout<<' ';
}
int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        int n, ch, tmp;
        struct node* head = NULL;
        cin>>n;
        for(int i=0; i<n; i++)
        {
            cin>>tmp>>ch;
            if(ch) insertAtEnd(&head, tmp);
            else insertAtBegining(&head, tmp);
        }
        printList(head);
    }
    return 0;
}

void insertAtBegining(struct node** headRef, int newData)
{
    struct node *temp = new node;
    temp->data = newData;
    temp->next = NULL;
    
    if(*headRef == NULL)
        *headRef = temp;
    else
    {
        temp->next = *headRef;
        *headRef = temp;
    }
    
}
// function appends the data at the end of the list
void insertAtEnd(struct node** headRef, int newData)
{
    // Code here
    
    struct node *new_node = new node;
    struct node *temp;
    new_node->data = newData;
    new_node->next = NULL;
    
    if(*headRef == NULL)
      *headRef = new_node;
    else
    {
        temp = *headRef;
        while(temp->next!=NULL)
          temp = temp->next;
        temp->next = new_node;
    }
}