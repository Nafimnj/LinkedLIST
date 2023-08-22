#include <iostream>
#include <string>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

void traverse(Node *head)
{

    while (head != NULL)
    {
        cout << head->data << endl;
        head = head->next;
    }
}
Node *insertfirst(Node *head, int data)
{
    Node *ptr = new Node;
    Node *p = new Node;
    ptr = head;

    p->data = data;
    p->next = head;
    return p;
}

Node *insertindex(Node *head, int data, int index)
{
    Node *ptr = new Node;
    Node *p = new Node;
    ptr = head;
    for (int i = 0; i < index - 1; i++)
    {
        ptr = ptr->next;
    }
    p->data = data;
    p->next = ptr->next;
    ptr->next = p;
    return head;
}
Node *insertlast(Node *head, int data)
{
    Node *ptr = new Node;
    Node *p = new Node;
    ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    p->data = data;
    p->next = NULL;
    ptr->next = p;
    return head;
}
Node *deletefirst(Node *head)
{
    Node *ptr = new Node;
    Node *newhead = new Node;
    ptr = head;
    newhead = ptr->next;
    free(head);
    return newhead;
}

Node *deleteindex(Node *head, int index)
{
    Node *ptr = new Node;
    Node *p = new Node;
    ptr = head;
    p = ptr->next;
    for (int i = 0; i <= index - 2; i++)
    {
        ptr = ptr->next;
        p = p->next;
    }
    ptr->next = p->next;
    free(p);
    return head;
}
Node *deletelast(Node *head)
{
    Node *ptr = new Node;
    Node *p = new Node;
    ptr = head;
    p = ptr->next;
    while (p->next != NULL)
    {
        ptr = ptr->next;
        p = p->next;
    }
    ptr->next = NULL;
    free(p);
    return head;
}

int main()
{
    Node *head;
    Node *second;
    Node *third;
    Node *fourth;
    Node *fifth;
    head = new Node;
    second = new Node;
    third = new Node;
    fourth = new Node;
    fifth = new Node;

    head->data = 10;
    second->data = 20;
    third->data = 30;
    fourth->data = 40;
    fifth->data = 50;

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = NULL;

    string input;
    cin >> input;
    if (input == "inf")
    {
        head = insertfirst(head, 100);
    }
    if (input == "ini")
    {
        head = insertindex(head, 200, 3);
    }
    if (input == "inl")
    {
        head = insertlast(head, 500);
    }
    if (input == "df")
    {
        head = deletefirst(head);
    }
    if (input == "di")
    {
        head = deleteindex(head, 3);
    }
    if (input == "dl")
    {
        head = deletelast(head);
    }

    traverse(head);

    return 0;
}