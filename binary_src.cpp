
#include<bits/stdc++.h>
using namespace std;

int bin_search(int A[],int left,int right,int k);

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int N;
        cin>>N;
        int a[N];
        for(int i=0;i<N;i++)
            cin>>a[i];
        int key;
        cin>>key;
        int found = bin_search(a,0,N-1,key);
        cout<<"@ :"<<found<<endl;
    }

    return 0;
}
// } Driver Code Ends


/*You need to complete this function */
int bin_search(int A[], int left, int right, int k)
{
    int mid = (left+right)/2;
    
    bool b = false;
    
    while(right >= left)
    {
        if(A[mid] == k)
        {
            b = true;
            break;
        }

        else if(k < A[mid])
        {
            right = mid-1;
        }
        
         else
        {
            left = mid+1;
        }
        
        mid = (left+right)/2;
        
    }
        if(!b) return -1;

         return mid;
}