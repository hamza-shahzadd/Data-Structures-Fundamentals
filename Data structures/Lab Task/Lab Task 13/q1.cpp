#include <iostream>
using namespace std;
//Node class
class Node
{
    public:
    int data;
    Node* left;
    Node* right;
};

//Tree class
class Tree
{
   public: Node* root;
   //Constructor
   public: Tree()
   {
     root=nullptr;  
   }
   //Function to insert
   public: void insert(int data)                                                          
   {
       Node* new_node=new Node();
       new_node->data=data;
       new_node->right=nullptr;
       new_node->left=nullptr;
       
       if(root==nullptr)
         root=new_node;
       else
       {
           Node* current=root;
           Node* prev=root;
           //Loop to find right place
           while(current!=nullptr)
           {
               prev=current;
               if(current->data==data)
               cout<<"Dublication";
               else if(current->data<data)
                current=current->right;
               else
                current=current->left;
           }
           
           //Linking new node 
           if(prev->data<data)
            prev->right=new_node;
           else
            prev->left=new_node;
       }
   }
   
   
   //Function to display
   public: void display(Node* root)
   {
       if(root==nullptr)
       return;
       else
       
       {
       display(root->left);
       cout<<root->data<<" \n";
       display(root->right);
       }
   }
   
   int gdiameter(Node* root)
   {
   
   	int diameter, rightD, leftD, maxD;
       	if (root == NULL) 
       	{
           		return 0;
       	}
       	rightD = gdiameter(root->right);
       	leftD = gdiameter(root->left);
       	maxD = maxHeight(root->right) + maxHeight(root->left) + 3;
       	if (maxD > rightD && maxD > leftD)
       	    diameter = maxD;
       	else if (leftD > rightD && leftD > maxD)
       	    diameter = leftD;
       	else
       	     diameter = rightD;
       	return  diameter;
   }
   
   
   
   
   int maxHeight(Node* root)
   {
    if (root == nullptr)
        return -1;
    else
    {
    	Node* temp= new Node;
   	temp= root;
   	
        //Compute the Height of each subtree
        int lHeight = maxHeight(root->left);
        int rHeight  = maxHeight(root->right);
     
        // Use the larger one
        if (lHeight > rHeight)
            return(lHeight + 1);
        else return(rHeight + 1);
    }
   }
   
   
   /////
   
   void makeDeletion(Node *&nodePtr)  // additional function of deleteNode that is used when their are two childs or 1 left or right child
	{
		Node *tempNodePtr; // Temperary pointer
		if (nodePtr->right == NULL) 
		{ // case for leaf and one (left) child
		tempNodePtr = nodePtr;
		nodePtr = nodePtr->left; 
		delete tempNodePtr;
		}
		else if (nodePtr->left == NULL) 
		{ 
			tempNodePtr = nodePtr;
			nodePtr = nodePtr->right; 
			delete tempNodePtr;
		}
		else 
		{ 
			tempNodePtr = nodePtr->right; 
			while (tempNodePtr->left) 
			{ 
				tempNodePtr = tempNodePtr->left;
			}
			tempNodePtr->left = nodePtr->left; 
			tempNodePtr = nodePtr;
			nodePtr = nodePtr->right; 
			delete tempNodePtr;
		}
	}
	
	
	
	
	
	void deleteNode(int num, Node *&nodePtr)            // delete function to delete nodes from the bst
	{
		if (nodePtr == NULL) 
		cout << num <<" not found.\n";
		else if (num < nodePtr->data)
		deleteNode(num, nodePtr->left); 
		else if (num > nodePtr->data)
		deleteNode(num, nodePtr->right); 
		else 
		makeDeletion(nodePtr); 


	}
   
   
   ////////////**************************************** 		FUNCTION FOR FINDING OUT WHETHER NODES ARE COUSINS OR NOT
   
   
   void isCusine(int a, int b)
   {
   
   	Node *temp= new Node;
   	temp= root;
   	Node *GrandParent= new Node;
   	GrandParent=NULL;
   	
   	while(temp != NULL)
   	{
   		if(temp->left->left->data == a)
   		{
   			GrandParent= temp;
   			break;
   		}	
   			
   		else if(temp->left->right->data == a)
   		{
   			GrandParent= temp;
   			break;
   		}
   			
   	
   		else if(temp->right->left->data == a)
   		{
   			GrandParent= temp;
   			break;
   		}
   		else if(temp->right->right->data == a)	
		{
			GrandParent= temp;
   			break;
		}
		else 
		{
			if(temp->data > a)
			{
				temp=temp->left;
			}
			else
			temp=temp->right;
		}
		
	}
	if(temp == NULL)
	{
		cout << "Not cousins " << endl;
	}
	else
	{
		if(GrandParent->left->left->data == a)
   		{
   			if(GrandParent->right->right->data == b || GrandParent->right->left->data ==b)
   			{
   				cout << "They are cousins" << endl;
   			}
   			else
   			cout << "Not cousins " << endl;
   			
   		}	
   			
   		else if(GrandParent->left->right->data == a)
   		{
   			if(GrandParent->right->right->data == b || GrandParent->right->left->data  ==b)
   			{
   				cout << "They are cousins" << endl;
   			}
   			else
   			cout << "Not cousins " << endl;
   		}
   			
   	
   		else if(GrandParent->right->left->data == a)
   		{
   			if(GrandParent->left->left->data == b || GrandParent->left->right->data ==b)
   			{
   				cout << "They are cousins" << endl;
   			}
   			else
   			cout << "Not cousins " << endl;
   		}
   		else if(GrandParent->right->right->data == a)	
		{
			if(GrandParent->left->left->data == b || GrandParent->left->right->data ==b)
   			{
   				cout << "They are cousins" << endl;
   			}
   			else
   			cout << "Not cousins " << endl;
		}
	}		   
   } 
};



//Main Function
int main()
{

int d;
    Tree* tree=new Tree();
    tree->insert(40);
    tree->insert(30);
    tree->insert(44);
    tree->insert(45);
    tree->insert(10);
    tree->insert(26);
    tree->insert(9);
    tree->insert(2);
    tree->insert(20);
    tree->insert(18);
  
    
    cout<<"Tree Values: \n";
    tree->display(tree->root);
    cout<<"Height of Tree is: "<<tree->maxHeight(tree->root);
    cout << endl;
    d=tree->gdiameter(tree->root);
    cout << "Diameter of tree is " << d << endl;

    tree->deleteNode(18, tree->root);
    cout << "After deleting 18" << endl;
    tree->display(tree->root);
    tree->isCusine(10,2);
    
    return 0;
}
