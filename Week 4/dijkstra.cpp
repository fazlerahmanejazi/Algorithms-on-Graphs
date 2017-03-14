#include <bits/stdc++.h>
using namespace std ;

#define inf 10000000
int T, n, m, s, t, a, b, w ;
vector<vector<pair<int, int> > > adj ;
pair<int, int> temp ;
vector<int> dist ;

void dijkstra(int start)
  {
    int u, v ;
    priority_queue<pair<int, int> , vector<pair<int, int> > , greater<pair<int, int> > > discovered ;
    discovered.push(make_pair(0, start)) ;
    dist[start]=0 ;
    while(!discovered.empty())
      {
        temp=discovered.top() ;
        discovered.pop() ;
        w=temp.first ; u=temp.second ;
        if(dist[u]<w) continue ;
        for(int i=0 ; i<adj[u].size() ; i++)
          {
            temp=adj[u][i] ;
            w=temp.second ; v=temp.first ;
            if(dist[u]+w < dist[v])
              {
                dist[v]=dist[u]+w  ;
                discovered.push(make_pair(dist[v], v)) ;
              }
          }
      }
  }

int main()
{
  ios_base::sync_with_stdio (false) ;
  cin>> n >> m ;
  adj.clear() ;
  dist.assign(n+1, inf) ;
  adj.resize(n+1) ;
  for(int i=0 ; i<m ; i++)
    {
      cin>> a >> b >> w ;
      adj[a].push_back(make_pair(b,w)) ;
    }
  cin>> s >> t ;
  dijkstra(s) ;
  if(dist[t]==inf) cout<< -1 ;
  else cout<< dist[t] ;
  return 0 ;
 }
