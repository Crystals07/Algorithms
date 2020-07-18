#include<bits/stdc++.h>
using namespace std;

int main()
{

	int V,E,z;

	cin>>V;

	int adj[V][V];

	for (int i=1;i<=V;i++)
	{
		for(int j=1;j<=V;j++)
		{
			cin>>z;
			adj[i][j]=z;
		}
		
	} 

	for(int k=1;k<=V;k++)
	{
		for(int i=1;i<=V;i++)
		{
			for(int j=1;j<=V;j++)
			{
				adj[i][j]=min(adj[i][j],adj[i][k]+adj[k][j]);
			}
		}
	}

	//cout<<"\n All pair shortest path\n";

		for (int i=1;i<=V;i++)
	{
		for(int j=1;j<=V;j++)
		{
			cout<<adj[i][j]<<" ";
		}

		cout<<"\n";
		
	} 


}