//This code is contributed by Jaideep Rana

#include<bits/stdc++.h>
using namespace std;

int dis[10000],V,E;

bool Bellman(int src,int value,int end,vector<pair<int,int> > v[])
{

	bool flag = false;
	dis[src]  = value;

	for(int i=1;i<=V;i++)
	{
		for(auto neigh: v[i])
		
			if(dis[neigh.first]>dis[i]+neigh.second)
			{	
				flag=true;
				dis[neigh.first]=dis[i]+neigh.second;
				cout<<"\n("<<i<<","<<neigh.first<<") "<<"dis :"<<dis[neigh.first]<<"\n";
			}
		
	}

	return flag;
}

int main()
{

	int x,y,z,end;

	cin>>V>>E;

	vector<pair<int,int> > v[(int)1e2];

	for(int i=0;i<E;i++)
	{
		cin>>x>>y>>z;
		v[x].push_back({y,z});
	}

	for(auto &k: dis) k=1000;

	cout<<"\n input end vertex\n";

	cin>>end;

	for(int i=1;i<=V-1;i++) cout<<"\n"<<Bellman(1,0,end,v)<<"\n"; 
		

	if(Bellman(1,0,end,v))  cout<<"\nContains negative weight cycle\n" ;

	else cout<<"\nDoes not contains negative cyle\n";

	for(int i=1;i<=V;i++) cout<<i<<" MIN DISTANCE :"<<dis[i]<<"\n";

}