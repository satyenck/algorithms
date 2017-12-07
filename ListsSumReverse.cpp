*************************************
Sum of lists representig two numbers.
Number 1: 617  List 1: 6->1->7
Number 2: 295  List 2: 2->9->5
Result List: 9->1->2
************************************/

#include <iostream>
#include <ostream>

struct Node
{
        int val;
        Node * next;
};

int addLists(Node * l1, Node * l2, Node *& head)
{
        if(l1 == NULL && l2 == NULL)
                return 0;
        int carry = 0;
        carry = addLists(l1->next, l2->next, head);

        int sum = 0;
        sum = carry + l1->val + l2->val;
        carry = sum / 10;
        sum = sum % 10;

        Node * n = new Node();
        n->val = sum;
        n->next = head;
        head = n;

        return carry;
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

int main()
{
        Node * n1 = new Node();
        Node * n2 = new Node();
        Node * n3 = new Node();
        Node * c1 = new Node();
        Node * c2 = new Node();
        Node * c3 = new Node();
        Node * head = NULL;

        n1->val = 6;
        n2->val = 1;
        n3->val = 7;
        n1->next = n2;
        n2->next = n3;
        n3->next = NULL;
        c1->val = 2;
        c2->val = 9;
        c3->val = 5;
        c1->next = c2;
        c2->next = c3;
        c3->next = NULL;

        printList(n1);
        printList(c1);
        addLists(n1, c1, head);
        printList(head);

        return 0;
}
