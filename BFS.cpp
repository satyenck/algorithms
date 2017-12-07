*****************************************************
Breadth First Walk for a directed graph
******************************************************/

#include <iostream>
#include <ostream>
#include <vector>
#include <queue>

#define TRUE 1
#define FALSE 0

struct Node
{
    int value;
    std::vector<Node *> children;
    Node * parent;
    bool visited;
};

void BFSWalk(Node * root)
{
    if(root == NULL)
    {
        std::cout << "NULL root" << std::endl;
        return;
    }

    std::queue<Node*> que;
    que.push(root);

    while(!que.empty())
    {
        Node * cNode = que.front();
        que.pop();
        if(!cNode)
        {
            std::cout << "Exception NULL pointer" << std::endl;
        }
        std::cout << "Node: " << cNode << " Value: " << cNode->value << std::endl;

        std::vector<Node *> v = cNode->children;
        for(int i=0; i<v.size(); i++)
        {
            Node * vNode = v.at(i);
            if(!vNode->visited)
            {
                que.push(vNode);
                vNode->visited = TRUE;
            }

        }
    }
}

int main()
{
    std::cout << "BFSWalk" << std::endl;

    Node * root = new Node();
    root->value = 0;
    root->parent = NULL;

    Node * c1 = new Node();
    c1->value = 1;
    c1->parent = root;

     Node * c2 = new Node();
    c2->value = 2;
    c2->parent = root;

     Node * c3 = new Node();
    c3->value = 3;
    c3->parent = root;

    std::vector<Node *> v;
    v.push_back(c1);
    v.push_back(c2);
    v.push_back(c3);
    root->children = v;

     Node * c11 = new Node();
    c11->value = 11;
    c11->parent = c1;
    std::vector<Node *> v1;
    v1.push_back(c11);
    c1->children = v1;

    BFSWalk(root);

    return 0;
}

