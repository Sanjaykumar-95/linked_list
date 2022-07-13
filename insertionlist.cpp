#include<bits/stdc++.h>
using namespace std;
class node{
public:
	int data;
	node* next;
};
//inserting at starting
void push(node**head_ref,int new_data){
	node* new_node=new node();
	new_node->data=new_data;
	new_node->next=(*head_ref);
	(*head_ref)=new_node;
}
//inserting at end
void middle(node* prev_node,int new_data){
	if (prev_node == NULL) 
    { 
        cout<<"The given previous node cannot be NULL"; 
        return; 
    } 
	node* new_node=new node();
	new_node->data=new_data;
	new_node->next=prev_node->next;
	prev_node->next=new_node;
}
//inserting at last
void last(node**head_ref,int new_data){
	node*new_node=new node();
	node*last=*head_ref;
	new_node->data=new_data;
	new_node->next=NULL;
	if(*head_ref==NULL){ //empty list
		*head_ref=new_node;
		return;
	}
	while(last->next!=NULL){
		last=last->next;
	}
	last->next=new_node;
	return;
}
//counting no.of elements
int count(node*head){
	int count=0;
	node*current=head;
	while(current!=NULL){
		count++;
		current=current->next;
	}
	return count;
}
//to print the list
void printList(node* n)
{
    while (n != NULL) {
        cout << n->data << " ";
        n = n->next;
    }
}
int main(){
	node*head=NULL;
	push(&head,6);
	push(&head,1);
	push(&head,7);
	last(&head,8);
	middle(head->next,4);
	middle(head->next->next,3);
	printList(head);
	cout<<endl;
	cout<<"length of list is:"<<count(head);
	return 0; 
}