 
// Activity Selection Problem

#include<bits/stdc++.h>
using namespace std;

    
struct Activity
{
  int start;
  
  string name;
  
  int finish;
};
     
bool cmp(Activity A1,Activity A2)
{
    return A1.finish < A2.finish;
}


int main()
{
    Activity Arr[6];
    
    int start,finish;
    
    string name;
    
    cout<<"\nInput each Activity\n";
    
    for(int i =0;i<6; i++)
    {   
        name = 'A'+to_string(i+1);
        cout<<"\n"<<name<<"\n";
        cin>>start>>finish;
        Arr[i].name = name;
        Arr[i].start = start;
        Arr[i].finish = finish;
    }
    
    sort(Arr,Arr + 6,cmp);
    
    cout<<"\nAfter sorting acc to finish time\n";
    
    for(int i =0; i < 6; i++)
    {
        cout<<"\n"<<Arr[i].name<<endl;
        cout<<Arr[i].start<<endl;
        cout<<Arr[i].finish<<endl;
    }
    
    cout<<"\n";
    
    int count = 1 , prev = 0;
    
    int totaltime = Arr[0].finish;
    
    cout<<"\nSelected Activites\n";
    
    for(int i =0 ; i<6 ; i++)
    {
        if(i == 0) cout<<Arr[i].name<<" ";
        
        else if(Arr[prev].finish <= Arr[i].start)
        {
            cout<<Arr[i].name<<" ";
            count++;
            totaltime += Arr[i].finish;
            prev = i;
        }
    }
    
    cout<<"\nTotal activities : "<<count<<"\n";
    
    cout<<"\nTotal time : "<<totaltime<<"\n";
}