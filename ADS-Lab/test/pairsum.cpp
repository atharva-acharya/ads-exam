#include<bits/stdc++.h>
using namespace std;

class Node {
    public : int data;
    Node* next;
};

Node* XOR(Node* a, Node* b) {
    return (struct Node*) ((uintptr_t) (a) ^ (uintptr_t) (b));
}

void insert(Node** head_ref, int data) {
    Node* new_node = new Node();
    new_node->data = data;

    new_node->next = *head_ref;

    if(*head_ref != NULL) {
        (*head_ref)->next = XOR(new_node, (*head_ref)->next);
    }
    *head_ref = new_node;
}

void pairSum(struct Node *head, int x)
{
	struct Node *first = head;
	struct Node *next_node = NULL, *prev = NULL;
	struct Node *second = head;
	while (second->next != prev)
	{
		struct Node *temp = second;
		second = XOR(second->next, prev);
		prev = temp;
	}
	next_node = NULL;
	prev = NULL;

	bool flag = false;
	while (first != NULL && second != NULL &&
			first != second && first != next_node)
	{
		if ((first->data + second->data)==x)
		{
			cout << "(" << first->data << ","
				<< second->data << ")" << endl;

			flag = true;

			struct Node *temp = first;
			first = XOR(first->next,prev);
			prev = temp;

			temp = second;
			second = XOR(second->next, next_node);
			next_node = temp;
		}
		else
		{
			if ((first->data + second->data) < x)
			{
				struct Node *temp = first;
				first = XOR(first->next,prev);
				prev = temp;
			}
			else
			{
				struct Node *temp = second;
				second = XOR(second->next, next_node);
				next_node = temp;
			}
		}
	}
	if (flag == false)
		cout << "No pair found" << endl;
}

int main()
{
	struct Node* head = NULL;
	int x = 17;

	insert(&head, 11);
	insert(&head, 10);
	insert(&head, 9);
	insert(&head, 8);
	insert(&head, 7);
	insert(&head, 6);
	insert(&head, 3);

	pairSum(head,x);
	return 0;
}