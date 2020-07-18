//This code is contributed by Jaideep Rana

#include<bits/stdc++.h>
using namespace std;

/* Dis of vertex is INF

All vert has not been yet visited i.e vis to be 0

*/


long long dis[100]={100};

int vis[100]={0}, cost=0;

int parent[(int) 1e2]={-1};

void prims(int s,vector<pair<int,int> > adj[],int V)
{

	priority_queue< pair<int,int> ,vector<pair<int,int> >, greater< pair<int,int> > > q;

	q.push({0,s});

	dis[0]=0;

	int cost = 0;

	while(q.size())
	{
		int curr_v=q.top().second;

	if(!vis[curr_v]) cost += q.top().first;

	//	cout<<" cost : "<<cost<<"\n";

		q.pop();

		if(!vis[curr_v])
		{
			
			for(auto neigh: adj[curr_v])
			{
				int neighv=neigh.second;

				int weight=neigh.first;



				if(!vis[neighv] && weight<dis[neighv])
				{
					dis[neighv]=weight;
					parent[neighv]=curr_v;
				//	cout<<"@ "<<neighv<<" "<<"# "<<weight<<" "<<" curr "<<curr_v<<"\n"; 
					q.push({dis[neighv],neighv});
				}

			}

		}

		vis[curr_v] = 1;

	}

	cout<<"\nRequired MST is\n";

	for(int i=0;i<V;i++) cout<<parent[i]<<" "<<i<<"\n";

	cout<<"\nRequired distance of each vertex is\n";
	
	for(int i=0;i<V;i++) cout<<"dis ["<<i<<"]"<<" : "<<dis[i]<<"\n";	

	cout<<"\nTotal cost of mst : "<<cost<<"\n";

	
}



int main()
{
	/* code */

	std::vector<pair<int,int> > adj[100];

	int V,E,u,v,z;

	cout<<"\nEnter the no of Vertices\n";

	cin>>V;

	cout<<"\nEnter the no of Edges\n";

	cin>>E;

	cout<<"\nEnter each edges\n";

	for(int i=0;i<E;i++)
	{
		cin>>u>>v>>z;
		adj[u].push_back({z,v});
		adj[v].push_back({z,u});
	}

	memset(parent,-1,sizeof(parent));
	
	for(auto &k: dis) k=100;

	int source=0;

	prims(source,adj,V);

	return 0;
}