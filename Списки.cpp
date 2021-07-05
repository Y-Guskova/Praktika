#include <iostream>
using namespace std;

// Задание 3.1 
struct Node
{
	int val;
	Node* next = NULL;
};

void init(Node* node)
{
	 node->val = 0;
	 node->next = NULL;
}

void show(Node* head)
{
	Node* a = head;
	
	while(a->next !=NULL)
	{
		cout << a->val << " ";
		temp = a->next;
	}
}

void pushNode(Node* head, Node* node)
{
	Node* a = head;
	while(a->next != NULL) 
	a = a->next;
	a->next = new Node;
	a->val = node->val;
}
    
    
// Задание 3.2 
    
void CopyMas(Node* source, Node* dest) 
	{
    	while (source->next != NULL && dest->next != NULL) 
		{
        	dest->val = source->val;
        	dest = dest->next;
        	source = source->next;
    	}
	}


    
    
bool TestInit()
{
	Node* head = new Node;
	init(head);
	return (head->val == 0);
}

int testCopyMas() 
{
    Node* source = new Node;
    Node* dest = new Node;
    Node* SourceNode = source, * DestNode = dest;


    for (int i = 0; i <= 10; i++)
	   {
        pushNode(source, new Node);
        pushNode(dest, new Node);
        init(DestNode);
        SourceNode = SourceNode->next;
        DestNode = DestNode->next;
    	}

   		 if (compareMas(source, dest) != 0)
        	return -1;
    	 source->next->next->val = -1;
    	 if (compareMas(source, dest) != -1)
        	return -1;
    return 0;
}

    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    


