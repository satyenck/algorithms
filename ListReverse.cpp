/************************************************************
List Reverse - Recursive and Non-recursive
************************************************************/

#include <iostream>
#include <ostream>

struct Node
{
        int val;
        Node * next;
};

void reverseListRecur(Node * n, Node * p, Node *& head)
{
        if(n == NULL)
                return;

        reverseListRecur(n->next, n, head);
        if(n->next == NULL)
                head = n;

        n->next = p;
        std::cout << "Node: " << n << " Value: " << n->val << std::endl;
}

void printList(Node * n)
{
        while (n != NULL)
        {
                std::cout << "Node: " << n << " Value: " << n->val << std::endl;
                n = n->next;
        }

        return;
}

Node* reverseListIter(Node * n)
{
        Node * current = n;
        Node * prev = NULL;
        Node * next = NULL;

        while(current != NULL)
        {
                std::cout << "----Current: " <<current << " Value: " << current->val << std::endl;
                next = current->next;
                current->next = prev;
                prev = current;
                current = next;
        }

        return prev;   
}

int main()
{
        Node * n1 = new Node();
        Node * n2 = new Node();
        Node * n3 = new Node();
        Node * head = NULL;

        n1->val = 1;
        n2->val = 2;
        n3->val = 3;

        n1->next = n2;
        n2->next = n3;
        n3->next = NULL;

        printList(n1);
        //reverseListRecur(n1, NULL, head);
        head = reverseListIter(n1);
        printList(head);

        return 0;
}
