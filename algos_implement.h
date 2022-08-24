#include<bits/stdc++.h>

using namespace std;
class algos_implement{
public:
  void dfs_s(vector<vector<pair<int,int > > >  &spanning_tree,int current,int cost[],int parent[],int visited[],int t){
    int n=spanning_tree.size();
    visited[current]=-1;
    for(int i=0;i<spanning_tree[current].size();i++)
    {
      if(visited[spanning_tree[current][i].first]==0){
        parent[spanning_tree[current][i].first]=current;
        cost[spanning_tree[current][i].first]=max(min(spanning_tree[current][i].second,cost[current]),cost[spanning_tree[current][i].first]);

        dfs_s(spanning_tree,spanning_tree[current][i].first,cost,parent,visited,t);
      }
    }
    visited[current]=1;
    return;
  }
  int dfs(vector<vector<pair<int,int > > >  &spanning_tree,int start,int end){
    int n=spanning_tree.size();
    int parent[n+1];
    int visited[n+1];
    int cost[n+1];
    for(int i=0;i<n+1;i++)
    {
      visited[i]=0;
      parent[i]=-1;
      cost[i]=INT_MIN;
    }
    for(int i=0;i<spanning_tree[start].size();i++)
    {
      visited[start]=-1;
      if(visited[spanning_tree[start][i].first]==0){

        parent[spanning_tree[start][i].first]=start;
        cost[spanning_tree[start][i].first]=spanning_tree[start][i].second;

        dfs_s(spanning_tree,spanning_tree[start][i].first,cost,parent,visited,end);
      }
      visited[start]=1;
    }
    //dfs_s(start)
    int temp=end;
    vector<int> path;
    while(temp!=-1)
    {
      path.push_back(temp);
      temp=parent[temp];
    }
    cout<<"Path is: ";
    for(int i=path.size()-1;i>=0;i--)
    {
      cout<<path[i]<<" ";
    }
    cout<<"\n";
    cout<<"Maximum Bandwidth for the path is: ";
    return cost[end];
  }
  void union_fn(vector<int> &p,vector<int> &rank,int r1,int r2)
  {
    if(rank[r1]>rank[r2])
    {
      p[r2]=r1;
    }
    else if (rank[r2]>rank[r1])
    {
      p[r1]=r2;
    }
    else{
      p[r2]=r1;
      rank[r1]=rank[r1]+1;
    }
    return;
  }

  int find(int v,vector<int> &p)
  {
    int w=v;
    vector<int> s;
    for (w = v; p[w] != -1;)
    {
      s.push_back(w);
      w = p[w];
    }
    for(int i=0;i<s.size();i++)
    {
      p[s[i]]=w;
    }

    return w;
  }
  vector<vector<pair<int,int > > > kruskals(vector<pair<int,pair<int,int> > > &sorted_edges)
  {
    vector<vector<pair<int,int > > > T(5010);
    vector<int> p(5010, -1);
    vector<int> rank(5010, 0);

    // for(int i=0;i<5010;i++)
    // {
    //   vector<pair<int,int > > v;
    //   T.push_back(v);
    // }
    for(int i=0;i<sorted_edges.size();i++)
    {
      if(find(sorted_edges[i].second.first,p)!=find(sorted_edges[i].second.second,p))
      {
       //  if(sorted_edges[i].second.first==2){
       //   cout<<find(sorted_edges[i].second.first,p)<<" "<<rank[2]<<rank[3]<<" "<<sorted_edges[i].second.first<<" "<<find(sorted_edges[i].second.second,p)<<" "<<sorted_edges[i].second.second<<"\n";
       // }
        T[sorted_edges[i].second.first].push_back(make_pair(sorted_edges[i].second.second,sorted_edges[i].first));

        T[sorted_edges[i].second.second].push_back(make_pair(sorted_edges[i].second.first,sorted_edges[i].first));
        // cout<<"     "<<sorted_edges[i].second.first<<" " <<sorted_edges[i].second.second<<"\n";
        // if(sorted_edges[i].second.first==2 && sorted_edges[i].second.second==3)
        // {
        //   cout<<"printing before ";
        //   cout<<p[2]<<" "<<p[3]<<"\n";
        //   cout<<rank[2]<<" "<<rank[3]<<"\n";
        // }
        union_fn(p,rank,find(sorted_edges[i].second.first,p),find(sorted_edges[i].second.second,p));
        // if(sorted_edges[i].second.first==2 && sorted_edges[i].second.second==3)
        // {
        //   cout<<"printing";
        //   cout<<p[2]<<" "<<p[3]<<"\n";
        //   cout<<rank[2]<<" "<<rank[3]<<"\n";
        // }
      }
    }
    return T;

  }

    int dijkstra_without_heap(vector< vector <pair<int,int> > > &G,int s, int t)
  {
    //cout<<"Made to fn";

    int n=G.size()+1;
    int status[n];
    int parent[n];
    int bw[n];
    //    status == 0 -> unseen
    //    status == 1 -> intree
    //    status == -1 -> fringe
    for(int i=0;i<n;i++)
    {
      status[i]=0;
      parent[i]=-1;
      bw[i]=INT_MAX;
    }
    //2
    status[s]=1;
    int count=0;
    //3
    for(int i=0;i<G[s].size();i++)
    {
      status[G[s][i].first]=-1;
      count++;
      parent[G[s][i].first]=s;
      bw[G[s][i].first]=G[s][i].second;
    }
    while(count>0)
    {
      //4.1
      int u=-1;
      int max_bw=0;
      for(int i=0;i<n;i++)
      {
        if(status[i]==-1)
        {
          if(max_bw<bw[i])
          {
            u=i;
            max_bw=bw[i];
          }
        }
      }
      //cout<<u<<" ";
      status[u]=1;
      count--;
      //4.2
      for(int w=0;w<G[u].size();w++)
      {
        if(status[G[u][w].first]==0)
        {
          status[G[u][w].first]=-1;
          count++;
          parent[G[u][w].first]=u;
          bw[G[u][w].first]=min(bw[u],G[u][w].second);
        }
        else if(status[G[u][w].first]==-1 && (bw[G[u][w].first]<min(bw[u],G[u][w].second))){
          bw[G[u][w].first]=min(bw[u],G[u][w].second);
          parent[G[u][w].first]=u;
        }
      }
    }
    int temp=t;
    vector<int> path;
    while(temp!=-1)
    {
      path.push_back(temp);
      temp=parent[temp];
    }
    cout<<"Path is: ";
    for(int i=path.size()-1;i>=0;i--)
    {
      cout<<path[i]<<" ";
    }
    cout<<"\n";
    //cout<<parent[t];
    cout<<"Maximum bandwidth using dijkstra_without_heap is:";
    return bw[t];

    //return 0;
  }
  int dijkstra_with_heap(vector< vector <pair<int,int> > > &G,int s, int t, heap *h1)
  {

    int n=G.size()+1;
    int status[n];
    int parent[n];
    int bw[n];
    //    status == 0 -> unseen
    //    status == 1 -> intree
    //    status == -1 -> fringe
    for(int i=0;i<n;i++)
    {
      status[i]=0;
      parent[i]=-1;
      bw[i]=INT_MAX;
    }
    //2
    status[s]=1;
    int count=0;
    //3
    for(int i=0;i<G[s].size();i++)
    {
      status[G[s][i].first]=-1;
      count++;
      parent[G[s][i].first]=s;
      bw[G[s][i].first]=G[s][i].second;
      h1->insert(G[s][i].second,G[s][i].first);
    }
    while(count>0)
    {
      //cout<<count;
      //4.1
      int u=-1;
      int max_bw=0;
      pair<int,int> var=h1->get_max();
      max_bw=var.first;
      u=var.second;
      //cout<<u<<" ";
      status[u]=1;
      count--;
      //4.2

      for(int w=0;w<G[u].size();w++)
      {
        if(status[G[u][w].first]==0)
        {
          status[G[u][w].first]=-1;
          count++;
          parent[G[u][w].first]=u;
          bw[G[u][w].first]=min(bw[u],G[u][w].second);
          h1->insert(bw[G[u][w].first],G[u][w].first);
        }

        else if(status[G[u][w].first]==-1 && (bw[G[u][w].first]<min(bw[u],G[u][w].second))){
          h1->delete_vertex(G[u][w].first);
          bw[G[u][w].first]=min(bw[u],G[u][w].second);
          h1->insert(bw[G[u][w].first],G[u][w].first);
          parent[G[u][w].first]=u;
        }

      }

    }
    int temp=t;
    vector<int> path;
    while(temp!=-1)
    {
      path.push_back(temp);
      temp=parent[temp];
    }
    cout<<"Path is: ";
    for(int i=path.size()-1;i>=0;i--)
    {
      cout<<path[i]<<" ";
    }
    cout<<"\n";
    //cout<<parent[t];
    cout<<"Maximum bandwidth using dijkstra_with_heap is:";
    return bw[t];

  }
};
