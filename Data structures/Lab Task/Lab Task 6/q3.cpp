 // M.Hamza Shahzad
 // 20i-0796
 // Question 3

#include<iostream>
using namespace std;

class node
{
	public:
    	int data;
    	node *previous;
    	node *next;
};    
 

class doublylinkedlist
{
	public:
 	node *head = NULL; 
	node *tail = NULL;
 

void addNode(int data) {
   
     node *newNode = new node;
    newNode->data = data;
    
    
    if(head == NULL) 
    {
        
        head = newNode; 
        tail = newNode;
       
        head->previous = NULL;
        
        tail->next = NULL;
    }
    else {
       
        tail->next = newNode;
        
        newNode->previous = tail;
       
        tail = newNode;
     
        tail->next = NULL;
    }

 
void removeDuplicateNode() 
{
 
    node *current, *index, *temp;
    
  
    if(head == NULL) {
        return;
    }
    else {
        
        for(current = head; current != NULL; current = current->next) {
           
            for(index = current->next; index != NULL; index = index->next) {
                if(current->data == index->data) {
                    
                    temp = index;
                    
                    index->previous->next = index->next;
                    if(index->next != NULL)
                        index->next->previous = index->previous;
                    
                    temp = NULL;
                }
            }
        }
    }
}
 

void display() 
{
    //Node current will point to head
    struct node *current = head;
    if(head == NULL) {
        cout << "List is empty\n");
        return;
    }
    while(current != NULL) {
        //Prints each node by incrementing pointer.
        cout << current->data;
        current = current->next;
    }
    cout << endl;
}
 }
 };
int main()
{
    //Add nodes to the list
    addNode(1);
    addNode(2);
    addNode(3);
    addNode(2);
    addNode(2);
    addNode(4);
    addNode(5);
    addNode(3);
    
    cout << "Originals list: \n";
    display();
    
    //Removes duplicate nodes
    removeDuplicateNode();
    
    cout << "List after removing duplicates: \n";
    display();
 
    return 0;
}
