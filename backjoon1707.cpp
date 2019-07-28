#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int e;
int n,m;
vector<int> v[20001];
int visited[20001];
int cnt=0;
void dfs(int node, int x){
	visited[node]=x;
	for(int i=0;i<v[node].size();i++){
		int y=v[node][i];
		if(visited[y]==0) dfs(y,3-x);
	}
}
void clear()
{
	for(int i=1;i<=n;i++){
		visited[i]=0;
		v[i].clear();
	}
}
int main()
{
	cin>>e;
	for(int i=0;i<e;i++){
		cin>>n>>m;
		clear();
		for(int i=0;i<m;i++){
			int p,q;
			cin>>p>>q;
			v[p].push_back(q);
			v[q].push_back(p);
		}
		
		for(int i=1;i<=n;i++){
			if(visited[i]==0){
				dfs(i,1);
			}
		}
		bool check=true;
		for(int i=1;i<=n;i++){
			for(int j=0;j<v[i].size();j++){
				 if(visited[i]==visited[v[i][j]]){
				 	check=false;
				 }
			}
		}
		if(check==true) cout<<"YES\n";
		else cout<<"NO\n";
		
    }
	return 0;
}
