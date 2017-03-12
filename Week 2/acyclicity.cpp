#include <bits/stdc++.h>
using namespace std ;

vector<vector<int> > adj ;
vector<bool> visit ;
vector<int> parent ;
bool cycle ;

void reach(int t)
  {
    if(cycle) return ;
    visit[t]=true ;
    for(int i=0 ; i<adj[t].size() ; i++)
      if(!visit[adj[t][i]])
        {
          parent.push_back(t) ;
          reach(adj[t][i]) ;
          parent.pop_back() ;
        }
      else
        {
          for(int j=0 ; j<parent.size() ; j++)
            if(adj[t][i]==parent[j])
              {
                cycle=true ;
                return ;
              }
        }
  }

int main()
  {
    int n, m;
    cin >> n >> m ;
    adj.resize(n+1) ;
    visit.assign(n+1, false) ;
    cycle=false ;
    for (int i = 0; i < m; i++)
      {
        int x, y;
        cin >> x >> y;
        adj[x - 1].push_back(y - 1);
      }
    for(int i=0 ; i<n ; i++)
      if(!visit[i])
        {
          if(cycle) break ;
          reach(i) ;
        }
    if(cycle) cout<< 1 ;
    else cout<< 0 ;
    return 0 ;
  }
