/**********************************************************
Depth First Search for a directed graph
**********************************************************/

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

void DFSWalk(Node * root)
{
    if(root == NULL)
    {
        std::cout << "NULL root" << std::endl;
        return;
    }

        std::cout << "Node: " << root << " Value: " << root->value << std::endl;

        std::vector<Node *> v = root->children;
        std::vector<Node*>::iterator it = root->children.begin();

        /*
        while(it != root->children.end())
        {
                Node * vNode = *it;
                DFSWalk(vNode);
                it++;
        }
        */
        for(int i=0; i<v.size(); i++)
        {
                Node * vNode = v.at(i);
                DFSWalk(vNode);
        }
}

int main()
{
    std::cout << "DFSWalk" << std::endl;

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

    DFSWalk(root);

    return 0;
}

