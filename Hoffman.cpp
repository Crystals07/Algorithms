//This code is contributed by Jaideep Rana

#include<bits/stdc++.h>
using namespace std;

/*Algo

create struct || class of node contains 

individual data,freq

left and right pointer 4 traversal

insert each node in priority queue

extract two min freq node from pq

create a new node with freq equal to sum of above freq

insert this node again in priority queue (pq)

assing left and right child of this node to exracted two min nodes  

repeat above step until size of pq.size()!=1

while traversing left print zero and one during right

Here we go */


  map<char,string> code;

  string encoded = "",decoded ="",original;


class Node
{

public:

	char data;

	int freq;

	Node *left = NULL;

	Node *right = NULL;

	Node(int freq,char data)
	{
		this->data = data;
		this->freq = freq;		
	}

	Node(int freq)
	{
		this->data = '/';
		this->freq = freq;
	}
};

  std::vector<int> curr;


  void DFS(Node* temp)
{

	if(!temp) return;

	if(temp->data != '/') 
	{
		cout<<temp->data<<" : ";
		for(auto i: curr) cout<<i;
		cout<<endl;
	}

	if(temp->left) 
	{
		curr.push_back(0);
		DFS(temp->left);
		curr.pop_back();
	}

	if(temp->right)
	{
		curr.push_back(1);
		DFS(temp->right);
		curr.pop_back();
	}
	
}

      void decodestring(Node* root)
   
    {   
        Node* curr = root;
        
        for(int i =0;i<encoded.length();i++)
        {
            if(encoded[i]=='1')  curr = curr->right;
            
            else curr = curr->left;
                    
            if(curr->left==NULL and curr->right==NULL)
            { 
                decoded.push_back(curr->data);
                curr = root;
            }
        }
    }


struct cmp
{
	bool operator()(const Node* temp1,const Node* temp2)
	{
		return temp1->freq > temp2->freq;
	}
};


    void storecode(Node* root,string str)
    {
        if(!root) return;
        
        if(root->data!='/')
        {
            code[root->data] = str;
        }
        
        storecode(root->left,str+"0");
        storecode(root->right,str+"1");
    }


int main()
{
	int N,freq;

	char data;

    original = "geekforgeeks";

	cout<<"\nEnter the total no of Alphabets\n";

	cin>>N;

	cout<<"\nEnter each Alpha and their freq\n";

	priority_queue<Node*,vector<Node*>,cmp> q;

	for(int i = 0;i<N;i++)
	{
		cin>>data>>freq;

		Node* JAI = new Node(freq,data);

		q.push(JAI);
	}

	
	while(q.size()-1)
	{
		Node* temp1 = q.top();

		q.pop();

		Node* temp2 = q.top();

		q.pop();

		Node* NEW = new Node(temp1->freq+temp2->freq);

		NEW->left = temp1;

		NEW->right = temp2;

		q.push(NEW);
	}

	cout<<"\n@ root "<<q.top()->freq<<"\n";
	
	cout<<"\nEncoded code \n";
	
	storecode(q.top(),"");

    auto it = code.begin();
    
    while(it != code.end())
    {
        cout<<it->first<<" "<<it->second<<"\n";
        it++;
    }
    
    for(auto chr: original) encoded += code[chr];
    
    cout<<"\nEncoded string\n"<<encoded<<endl;
    
    decodestring(q.top());
    
    cout<<"\nDecoded string\n";
    
    cout<<decoded<<"\n";
 
}
