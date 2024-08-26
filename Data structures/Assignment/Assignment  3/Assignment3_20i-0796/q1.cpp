// M.Hamza Shahzad
// 20i-0796
// Data Structures
// Assignment 3







#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;


class Node
{
	public:
	string data;
	string Url;
	Node* left;
	Node* right;
	
	
	Node()
	{
		data="";
		left=NULL;
		right=NULL;
	}
};

class bst
{
	public:
	Node* root;
	
	bst()
	{
		root= NULL;
	}
	
	
	void insertNode(string num,string s) 
	{
		Node *newNode, *nodePtr; // Pointer to create new node & traverse tree
		newNode = new Node; // Create a new node
		newNode->data = num;
		newNode->Url= newNode->Url+s;// to store Url of each keyword
		newNode->left = newNode->right = NULL; // setting left and right of newnode as Null
		
		if (!root) 
		{
			root = newNode; // If tree is empty.
		}
		else 
		{ // Tree is not empty
			nodePtr = root;
		//	nodePtr->right = newNode;
		//	break;
		
		while (nodePtr != NULL) 
		{
			if (num <= nodePtr->data) // = sign to cater for duplicate values or else they would be ignored
			{ // Left subtree
			if (nodePtr->left) 
			{	
				nodePtr = nodePtr->left; 
			}
			else 
			{
				nodePtr->left = newNode;
				break; 
			}
			}
		
		
		else if (num >= nodePtr->data) // = sign to cater for duplicate values or else they would be ignored
		{ // Right subtree
			if (nodePtr->right)
			{
			 nodePtr = nodePtr->right;
			}
			else 	
			{
				nodePtr->right=newNode;	
				break;
			}
		}
			
		else 
		{ 
			nodePtr=newNode;
			break;
		}
		}
		}
		
	}
	
	
	
   	
     
 	
 	
 	void inorder(Node *ro)  // Display function to show the binary search tree in ascending order
	{
   	if (ro != NULL) 
   	{
   	
      		inorder(ro->left);
      		cout<<ro->data<<endl;
      		inorder(ro->right);
   	}
   	}
   	
   		
   		int count(string ss)     // Function that count the total number of results and displays them
   	{
   		Node* found= new Node;
   		found = root;
   		int count=0;
   		
   		
   		

   			while(found != NULL)
   			{
   				
   				if(ss <= found->data )
   				{
   					
   					
   					if(found->data == ss)   // for traversing the whole tree if duplicate value is found
   					{
   						count++;
   						//cout << found->data;
   						//cout << found->Url<< endl;
   						found=found->left;
   					}
   					else
   					found=found->left;
   				}
   				else if(ss >= found->data)
   				{
   					
   					if(found->data == ss)    // for traversing the whole tree if duplicate value is found
   					{
   						count++;
   						//cout << found->data;
   						//cout << found->Url << endl; 
   						found=found->right;
   					}
   					found = found->right;
   				}
   			}
   			
   			cout << count << " result(s) found" << endl << endl;  // Displaying the result of the occurence of the keyword
   			return count;
	}
 	
 	
 	
 	void search(string sss)          // search function that is used to display the Url of the keyword that was enetered
   	{
   		Node* found= new Node;
   		found = root;
   		int count=0;
   		int s=1;
   		
   		

   			while(found != NULL)
   			{
   				
   				if(sss <= found->data )
   				{
   					
   					
   					if(found->data == sss)
   					{
   						count++;
   						//cout << found->data;
   						cout << s << ". " <<found->Url<< endl;
   						s++;
   						found=found->left;
   					}
   					else
   					found=found->left;
   				}
   				else if(sss >= found->data)
   				{
   					
   					if(found->data == sss)
   					{
   						count++;
   						//cout << found->data;
   						cout << s << ". " << found->Url << endl;
   						s++; 
   						found=found->right;
   					}
   					found = found->right;
   				}
   			}
   			
   			//cout << count << " result(s) found" << endl;
	}
	
	
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
	
	
	
	
	
	void deleteNode(string num, Node *&nodePtr)            // delete function to delete nodes from the bst
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
	
	
   		int deleteCount(string ssss)     // Function that count the total number of results and displays them
   	{
   		Node* founds= new Node;
   		founds = root;
   		int count=0;
   		
   		
   		

   			while(founds != NULL)
   			{
   				
   				if(ssss <= founds->data )
   				{
   					
   					
   					if(founds->data == ssss)   // for traversing the whole tree if duplicate value is found
   					{
   						count++;
   						//cout << found->data;
   						//cout << found->Url<< endl;
   						founds=founds->left;
   					}
   					else
   					founds=founds->left;
   				}
   				else if(ssss >= founds->data)
   				{
   					
   					if(founds->data == ssss)    // for traversing the whole tree if duplicate value is found
   					{
   						count++;
   						//cout << found->data;
   						//cout << found->Url << endl; 
   						founds=founds->right;
   					}
   					founds = founds->right;
   				}
   			}
   			
   			//cout << count << " result(s) found" << endl << endl;  // Displaying the result of the occurence of the keyword
   			return count;
	}
 	

};




int main()
{
string info;
string keyword;
bst b;
int n=0;
int d=0;
string url;
string space=" ";
int choice;
string del;




ifstream read;                                      // File reading
read.open("Assignment_data.txt");
if(read.is_open())
{
	while(read)
	{
		read>>info;                          // sending each word into the bst until all of the file is read
		
		if(info[0] == 'h' && info[1] =='t')
		{
			url= info;                   // sending url also inorder to display it in the search function when keyword is found by making Url variable in node class
		}
		else
		b.insertNode(info,url);
		
	}
	
	read.close();                                // closing the file after it is read
}
else
{
	cout << "Counldn't open file" << endl;
}	
	



///////////

	
	
		//cout << url << endl;
	
	

//	b.inorder(b.root);


//       Menu to perform the following functions 

	cout << "File Loaded Succesfully." << endl;
	cout << "Press 1 to enter a keyword for searching" << endl<< "Press 2 for deletion" << endl <<"Press 0 to end" << endl << endl;
	cin >> choice; 

	while(choice != 0)
	{
		if (choice == 1)
		{                                                           // Searching keyword
			cout << "Enter a keyword" << endl << endl;
			cin >> keyword;
			n=b.count(keyword);
			b.search(keyword);
		}
		else if(choice == 2)
		{                                                           // deletion of keyword
			cout << "Enter value for deletion" << endl;
			cin >> del;
			d=b.deleteCount(del);
			cout << endl;
			for(int i=0;i<d;i++)
			{
				b.deleteNode(del,b.root);
			}	
			
		}
		cout << endl << "Press 1 to enter a keyword for searching" << endl<< "Press 2 for deletion" << endl <<"Press 0 to end" << endl << endl;
		cin >> choice;
		
	}	

//b.inorder(b.root);
	

return 0;

}
