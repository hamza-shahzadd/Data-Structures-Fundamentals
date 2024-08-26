// M.Hamza Shahzad
// 20i-0796
// Data structure




#include<iostream>
using namespace std;





class node
{
	public:
	
	int data;
	node* right;
	node* left;
	
	node()
	{
		right= NULL;
		left= NULL;
		data= 0;
		
	}


};


class binaryTree
{
	public:
	
	node* root;
	
	
	binaryTree()
	{
		root= NULL;
	}
	
	
	void insert(int value)
	{
		node *newnode= new node;
		newnode->data= value;
		newnode->right= NULL;
		newnode->left= NULL;
		
		
		
		
		if(root == NULL)
		{
			root= newnode;
		}
		else
		{
			node* temp= new node;
			temp = root;
				
			if(value % 2 == 0) 
			{
				while(temp->left != NULL )
				{
					temp=temp->left;
				}
				temp->left= newnode;
			}
			else
			{
				while(temp->right != NULL )
				{
					temp=temp->right;
				}
				temp->right= newnode;
				
			}
		}	
		
		
	}
	
	void display_inorder()
	{
		if(root == NULL)
		{
			return;
		}
		else
		{
			node* a= new node;
			a= root;
			
			while(a != NULL)
			{
				cout << a->data << " ";
				a= a->left;
			} 
			a=root->right;
			while(a != NULL)
			{
				cout << a->data << " ";
				a= a->right;
			} 
		
		}
	}
	

	void find_height()
	{
	
	int count_br=0;
	int count_bl=0;
	
		if(root == NULL)
		{
			return;
		}
		else
		{
			node* b= new node;
			b= root;
			
			while(b->left != NULL)
			{
				count_br ++;
				b=b->left;
			} 
			b=root;
			
			while(b->right != NULL)
			{
				count_bl ++;
				b=b->right;
			} 
		}
		
		if(count_br > count_bl)
		{
			cout << count_br;
		}
		else
		{
			cout << count_bl;
		}
	}

	void find_depth(int find)
	{
	
		int count_bl= 0;
		int count_br= 0;
		node* c= new node;
		c= root;
			
		if(root == NULL)
		{
			return;
		}
		else
		{
			
			while(c->left != NULL ) 
			{
				if(c->data == find)
				{	
					break;
				}
				
				count_bl ++;
				c=c->left;
			
		
			}
		}	 
			
			if(c->left == NULL)
			{
				c=root;
			
				while(c->left != NULL) 
				{
					if(c->data == find)
					{
						break;
					}
					count_br ++;
					c=c->right;
				}
				
				cout << "Depth = " << count_br;
			}	
			else
			{
				cout << "Depth = " << count_bl;
			} 
	}
		
		
	
};



int main()
{
	// The binary tree is sorted on the basis of even and odd.
	// if the number is even, it goes to the right side of the node
	// if the number is odd, it goes to the left side of the node
	
	binaryTree s;
	s.insert(3);
	s.insert(5);
	s.insert(16);
	s.insert(11);
	s.insert(36);
	s.insert(40);
	cout << "Binary tree = ";
	s.display_inorder();
	cout << endl;
	cout << "Height = ";
	s.find_height();
	cout << endl;
	s.find_depth(36);
	cout << endl;
	s.find_depth(5);
	cout << endl;
	
	
	return 0;
	

}

