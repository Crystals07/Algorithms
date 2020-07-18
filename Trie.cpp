using namespace std;

string res;

struct Trie
{
    Trie* child[26];
    
    bool isend;
    
    Trie()
    {
        memset(child,0,sizeof(child));
        isend = 0;
    }
    
}*root = 0;



bool completesrc(string com)
{
    
    Trie* curr = root;
    
    if(!root) return 0;
    
    int index;
    
    for(auto ch: com)
    {
        index = ch -'a';
        
        if(!curr->child[index]) return 0;
        
        curr = curr->child[index];
    }
    
    return curr->isend;
}



void display(Trie* curr)
{
    

     
    if(curr->isend) 
    {
        cout<<res<<" ";
        
    }
    
    int j = 0;
    
    for(;j<26;j++)
    {
        if(curr->child[j]) 
        {    
            res.push_back('a'+j);
            display(curr->child[j]);
            res.pop_back();
        }
    
            
    }

    

}

void insert(string str)
{
    Trie* curr = root;
    
    int index;
    
    for(auto ch: str)
    {
        index = ch -'a';
        
        if(!curr->child[index]) curr->child[index] = new Trie;
        
        curr = curr->child[index];
    
    }
    
    curr->isend = 1;
}



void contactsrc(string prefix)
{
    Trie* curr = root; 
    
    int index;
    
   // cout<<" @ "<<prefix<<endl;
    
    for(auto ch: prefix)
    {
        index = ch - 'a';
    
        if(!curr->child[index])
        {
            cout<<0;
            return;
        }
        
        res.push_back(ch);
            
        curr = curr->child[index];
        
    }
    
    
                display(curr);
    
}


//to clear all trie nodes

  void clear(Trie* start)
  {
        Trie* curr = start; 
      
        for(int i =0;i<26;i++)
        {
            if(curr->child[i]) clear(curr->child[i]);
        }
        
        delete curr;
        
        curr = 0;
  }


int main()
{

    int t,N;
    
    
    cin>>t;
    
    while(t--)
    {
        cin>>N;
        
        root = new Trie;
    
        string contacts,query,temp;
        
        while(N--)
        {
            cin>>contacts;
            insert(contacts);
        }
        
        cin>>query;
       
        int len = query.size(),i=0;
        
        
        temp = "";
        
        while(len--)
       {
            temp.push_back(query[i]);
            
            contactsrc(temp);
       
            res = "";
            
            i++;
       
            cout<<"\n";
            
       }
        
       
           clear(root);
            
           root = NULL;
            
    }

   
    
}