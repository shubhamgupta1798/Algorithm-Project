#include<bits/stdc++.h>
using namespace std;
class graph{
  int number_of_vertex;
  vector<pair<int,int> > edges[5010];
  int a[5010][5010];
  public:
    graph()
    {
      for(int i=0;i<5010;i++)
      {
        for(int j=0;j<5010;j++)
        {
          a[i][j]=0;
        }
        a[i][i]=1;
      }
    }
    void make_graph(int vertex,int max_edges)
    {
      for(int j=0;j<vertex;j++)
      {
          set<int> s;
          a[j][j+1]=1;
          a[j+1][j]=1;
          s.insert((j+1)%vertex);
          while(s.size()!=(max_edges/2))
          {
            int temp=rand()%vertex;

            //cout<<temp<<" ";
            if(a[j][temp]==0)
              s.insert(temp);
          }
          for(auto i=s.begin();i!=s.end();i++)
          {
            a[j][*i]=1;
            a[*i][j]=1;
            int wt=(rand()%1000)+1;
            edges[*i].push_back(make_pair(j,wt));
            edges[j].push_back(make_pair(*i,wt));
          }
      }
      /*for(int i=0;i<vertex;i++)
      {
        cout<<"Index: "<<i;
        for(int j=0;j<edges[i].size();j++)
        {
          cout<<" Edge: "<<edges[i][j].first<<" Weight: "<<edges[i][j].second<<" ";
        }
        cout<<"\n";
      }
      */
    }
    void write_to_txt(string name="graph.txt")
    {
      std::ofstream filewriter(name);
      int count=0;
       if (filewriter.is_open())
       {
         for(int i=0;i<5000;i++)
         {
           count+=edges[i].size();
           for(int j=0;j<edges[i].size();j++)
           {

             filewriter<<edges[i][j].first<<","<<edges[i][j].second<<",";
           }
           filewriter<<"\n";
         }
       }
       else
       {
         std::cout << "Something went wrong while saving graph!";
       }
       cout<<count;

      filewriter.close();
    }

};
