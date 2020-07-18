//This code is contributed by Jaideep Rana

#include<bits/stdc++.h>
using namespace std;

int parent[100],size[100];

int find(int x)
{
	while(x!=parent[x]) x=parent[x];
	return x;
}

int same(int x,int y)
{
	return find(x)==find(y);
}

void unite(int u,int v)
{
	u=find(u);

	v=find(v);

	if(size[u]<size[v]) swap(u,v);

	size[u]+=size[v];

	parent[v]=u;
}

int main()
{

	int V,E,u,v,z;

	vector< pair<int,pair<int,int> > > adj;

	vector< pair<int,int > > vec;

	cout<<"\nEnter the no of nodes\n";

	cin>>V;

	cout<<"\nEnter the no of Edges\n";

	cin>>E;

	cout<<"\nEnter each edges\n";

	for(int i = 0; i<E ;i++)
	{
		cin>>u>>v>>z;
		adj.push_back({z,{u,v}});
	}

	cout<<"\n Before sorting\n";

	for(int i = 0; i<E ; i++)
	{
		cout<<adj[i].second.first<<" "<<adj[i].second.second<<" weight "<<adj[i].first<<"\n";
	}


	sort(adj.begin(),adj.end());

	cout<<"\nAfter sorting edges\n";

	for(int i = 0; i<E ; i++)
	{
		cout<<adj[i].second.first<<" "<<adj[i].second.second<<" weight "<<adj[i].first<<"\n";
	}

	for(int i = 0; i<E; i++) 
	{
		parent[i] = i;
		size[i] = 1; 
	}

	int mst_weight = 0;

	for(int i = 0; i<E ;i++)
	{
		int u = adj[i].second.first;

		int v = adj[i].second.second;

		if(!same(u,v))
		{
			mst_weight += adj[i].first;

			unite(u,v);
			vec.push_back({u,v});
		}
    }	 

    cout<<"\nAfter kruskal algo required graph\n";

	for(auto vertex: vec) cout<<vertex.first<<" "<<vertex.second<<"\n";

	cout<<"\nMST cost : "<<mst_weight<<"\n";

}	
