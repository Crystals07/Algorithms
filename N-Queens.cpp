#include <bits/stdc++.h>
using namespace std;

int chess[10+1][10+1] = {0};

int solution = 0;

void print()
{
    if(solution == 0) cout<<-1;
    cout<<"-1";
}


bool isvalid(int x,int y,int N)
{
    //checking col
    
    int i = x, j = y;
    
     while(i > 0)
     {
         if(chess[i][j]) return false;
         i--;
     }
     
     //checking left diag
     
     i = x;
     
     while(i > 0 && j > 0)
     {
         if(chess[i][j]) return false;
         i--;
         j--;
     }
     
     //checking right diag
     
     i = x;
     j = y;
     
     while(j <= N && i > 0)
     {
         if(chess[i][j]) return false;
         j++;
         i--;
     }
     
     return true;
}

bool solvequeen(int x,int y,int n)
{
    if(x == n+1)
    {
        //boundary condition

        cout<<"[";
        
        for(int i =1 ; i <= n ; i++)
        {
            
            
            for(int j = 1; j <= n; j++)
            {
                if(chess[i][j])
                {
                    cout<<j<<" "; 
                    solution = 1;
                }
            }
           
        }
         cout<<"] ";
         
        
        
        return false;
    }
    
    //placing queen in correct col
    
    //If it turns out wrong we will shift the queen
    
    for(int col = 1; col <= n ; col++ )
    {
        if(isvalid(x,col,n))
        
        {
        
            chess[x][col] = 1;
        
            bool shift = solvequeen(x+1,col,n);
        
            if(shift) return true; 
        
            else chess[x][col] = 0;
            
        }    
    }
    
    //if all pos fails for queen then return false
    
    return false;
}

int main() 
{
	
    int t;
    
    cin>>t;
    
    while(t--)
    {
        int n;
        
        cin>>n;
        
        if(n == 1 || n == 3 || n == 2)
        {    
            if(n == 1) cout<<"[1 ]";
            
            else  cout<<-1;
            
            cout<<endl;
        }    
        
        else
        {
            solvequeen(1,1,n);
            
            cout<<endl;
        
        }
    }
}