#include<bits/stdc++.h>
using namespace std;
class heapsortclass{
public:

  //int present_at_index[5010];
  //bw, vertex pair
  vector<pair<int,pair<int,int> > > H;
  heapsortclass()
  {

  }
  void swap(int x,int y)
  {
    //  present_at_index[H[x].second]=y;
      //present_at_index[H[y].second]=x;
      pair<int,pair<int,int> > temp=H[x];
      H[x]=H[y];
      H[y]=temp;
  }
  //Fix the heap for x and its Parent
  // if parent is smaller than current swap them and recursively call parent.
  void fix_heap(int x)
  {
    if(x<0)
    {
      return;
    }
    if(H[x].first>H[(x-1)/2].first)
    {
      swap((x-1)/2,x);
      fix_heap((x-1)/2);
    }
  }
  void fix_heap_downward(int x)
  {
    int left_child=2*x+1;
    int right_child=2*x+2;
    int largest=x;
    if(left_child<H.size())
    {
      if(H[left_child].first>H[largest].first)
      {
        largest=left_child;
      }
    }
    if(right_child<H.size())
    {
      if(H[right_child].first>H[largest].first)
      {
        largest=right_child;
      }
    }
    if(largest!=x)
    {
      swap(x,largest);
      fix_heap_downward(largest);
    }
  }
  pair<int,pair<int,int> > get_max()
  {
      if(H.size()==0)
      {
          pair<int,pair<int,int> > temp;
        //  temp.first=-1;
          //temp.second=-1;
          return temp;
      }
    //  int max_vertex=H[0].second;
      pair<int,pair<int,int> > temp=H[0];
      swap(0,H.size()-1);
      H.pop_back();
      fix_heap_downward(0);
      //present_at_index[max_vertex]=-1;
      return temp;
  }

  void insert(int bw,int start,int end)
  {

    H.push_back(make_pair(bw,make_pair(start,end)));
    //present_at_index[vertex] = H.size()-1;
    fix_heap(H.size()-1);
  }
  //Improved Sorting suggested for sorting edges based on Bandwidth. The algorithm is based on Hasing based implemetation of Sorting

  vector<pair<int,pair<int,int> > > improved_sort(vector< vector <pair<int,int> > > G)
  {
    vector<pair<int,pair<int,int> > > sorted_list;
    vector<pair<int,int> > v[1005];
    for(int i=0;i<G.size();i++)
    {
      for(int j=0;j<G[i].size();j++)
      {
        v[G[i][j].second].push_back(make_pair(G[i][j].first,i));
      }
    }
    for(int i=1004;i>=0;i--)
    {
      //cout<<v[i].size();
      for(int j=0;j<v[i].size();j++)
      {

        sorted_list.push_back(make_pair(i,v[i][j]));
      }
    }
    return sorted_list;
  }
  //Insert all the elements in heap and then take out the max element and push it to a vector
  vector<pair<int,pair<int,int> > > heap_sort(vector< vector <pair<int,int> > > G)
  {
    for(int i=0;i<G.size();i++)
    {
      for(int j=0;j<G[i].size();j++)
      {
        insert(G[i][j].second,G[i][j].first,i);
      }
    }
    vector<pair<int,pair<int,int> > > sorted_list;
    while(H.size()!=0)
    {
      pair<int,pair<int,int> > temp=get_max();
      sorted_list.push_back(temp);
      //pair<int,int> temp2=temp.second;
      //cout<<temp.first<<" "<<temp2.first<<" "<<temp2.second<<"\n";
    }
    return sorted_list;
  }
};
