#include<bits/stdc++.h>
using namespace std;
class heap{
public:

  int present_at_index[5010];
  //bw, vertex pair
  vector<pair<int,int> > H;
  heap()
  {
    for(int i=0;i<5010;i++)
    {
      present_at_index[i]=-1;
    }
  }
  void swap(int x,int y)
  {
      present_at_index[H[x].second]=y;
      present_at_index[H[y].second]=x;
      pair<int,int> temp=H[x];
      H[x]=H[y];
      H[y]=temp;
  }
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
  pair<int,int> get_max()
  {
      if(H.size()==0)
      {
          pair<int,int> temp(-1,-1);
        //  temp.first=-1;
          //temp.second=-1;
          return temp;
      }
      int max_vertex=H[0].second;
      pair<int,int> temp=H[0];
      swap(0,H.size()-1);
      H.pop_back();
      fix_heap_downward(0);
      present_at_index[max_vertex]=-1;
      return temp;
  }
  void delete_vertex(int vertex)
  {
    int idx=present_at_index[vertex];
    if(idx==-1)
    {

      //cout<<"\n"<<vertex<<" Not present";
      return;
    }
    if(idx==(H.size()-1))
    {
      H.pop_back();
    }
    else{
      swap(idx,H.size()-1);
      //present_at_index[H[idx].second]=idx;
      H.pop_back();
      fix_heap_downward(idx);
      present_at_index[vertex]=-1;
    }
  }
  void insert(int bw,int vertex)
  {

    H.push_back(make_pair(bw,vertex));
    present_at_index[vertex] = H.size()-1;
    fix_heap(H.size()-1);
    //cout<<"inserted"<<vertex<<" at "<<present_at_index[vertex]<<" ";
  }
  void print_heap()
  {
    for(int i=0;i<H.size();i++)
    {
      cout<<i<<" " <<H[i].first<<" "<<H[i].second<<"\n";
    }
  }
};
