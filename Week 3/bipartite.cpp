#include <bits/stdc++.h>
using namespace std ;

vector<vector<int> > adj ;
vector<int> color ;
bool check ;

void reach(int t, int p)
  {
    color[t]=p ;
    for(int i=0 ; i<adj[t].size() ; i++)
      if(color[adj[t][i]]==-1)
        reach(adj[t][i], 1-p) ;
      else if(color[adj[t][i]]==p)
        check=false ;
  }

int main()
  {
    int n, m;
    cin >> n >> m ;
    check=true ;
    adj.resize(n+1) ;
    color.assign(n+1, -1) ;
    for (int i = 0; i < m; i++)
      {
        int x, y;
        cin >> x >> y;
        adj[x - 1].push_back(y - 1);
        adj[y - 1].push_back(x - 1);
      }
    for(int i=0 ; i<n ; i++)
      if(color[i]==-1)
        reach(i, 1) ;
    if(check) cout<< 1 ;
    else cout<< 0 ;
    return 0 ;
  }
