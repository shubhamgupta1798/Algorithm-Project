#include<bits/stdc++.h>
using namespace std;
class graph{
  int number_of_vertex;
  vector<pair<int,int> > edges[5010];
  public:
    void make_graph(int vertex,int max_edges)
    {
      for(int j=0;j<vertex;j++)
      {
          set<int> s;
          s.insert((j+1)%vertex);
          while(s.size()!=max_edges-1)
          {
              s.insert(rand()%vertex);
          }
          for(auto i=s.begin();i!=s.end();i++)
          {
            edges[j].push_back(make_pair(*i,(rand()%1000)+1));
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

       if (filewriter.is_open())
       {
         for(int i=0;i<5000;i++)
         {
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

      filewriter.close();
    }

};
