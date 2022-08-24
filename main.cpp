#include<bits/stdc++.h>
#include"node.h"
#include"heap.h"
#include"heapsort.h"
#include"algos_implement.h"
#include"create_graph_from_file.h"
#include <fstream>
using namespace std;


int main(){
  int input;
  cout<<"First execute 1 & 2 to generate graphs\n";
  cout<<"Enter input \n1. Generate New Sparse Graphs \n2. Generate New Dense Graph \n3. Use Generated Sparse Graphs for Modified Dijkstra without heap \n4. Use Generated Dense Graphs for Modified Dijkstra without heap\n5. Use Generated Sparse Graphs for Modified Dijkstra with heap \n6. Use Generated Dense Graphs for Modified Dijkstra with heap \n7. Use Generated Sparse Graphs for Modified Kruskal with Heap sort\n8. Use Generated Dense Graphs for Modified Kruskal with Heap sort\n9. Use Generated Sparse Graphs for Modified Kruskal with Hash based sort\n10. Use Generated Dense Graphs for Modified Kruskal with Hash based sort\n11. To execute all algos on spare graphs \n 12. To run all algos on dense graph\n";
  cin>>input;

  //cout<<input<<"\n";

  switch(input){
    case 1:{
      //cout<<"1";
      for(int i=0;i<5;i++)
      {
        graph* obj=new graph();
        obj->make_graph(5000,6);
        char c=i+(int)'0';
        string name="graph_sparse";
        name+=c;
        name+=".txt";
        cout<<name;
        obj->write_to_txt(name);
      }
      break;
    }
    case 2:{
      for(int i=0;i<5;i++)
      {
        graph* obj=new graph();
        obj->make_graph(5000,1000);
        char c=i+(int)'0';
        string name="graph_dense";
        name+=c;
        name+=".txt";
        cout<<name;
        obj->write_to_txt(name);
      }
      break;
    }
    case 3:{
      for(int j=0;j<5;j++){
        char c=j+(int)'0';
        string name="graph_sparse";
        name+=c;
        name+=".txt";
        cout<<"Calculating for :"<<name<<"\n";
        create_graph_from_file* obj= new create_graph_from_file(name);
        algos_implement* algo_implementation=new algos_implement();
        //time_t start = clock();
        srand(time(NULL));
        for(int i=0;i<5;i++){

          time_t start = clock();
          int start_vertex=rand()%5000;
          int end_vertex=rand()%5000;
          cout<<algo_implementation->dijkstra_without_heap(obj->G,start_vertex,end_vertex);
          time_t end=clock();
          cout<<"\nTime taken for traversal using Dijkstra without heap from "<<start_vertex<<" to "<<end_vertex<<" is "<<(end-start)/(double)CLOCKS_PER_SEC<<"\n";
        }
      }
      break;
    }
    case 4:{
      for(int j=0;j<5;j++){
        char c=j+(int)'0';
        string name="graph_dense";
        name+=c;
        name+=".txt";
        cout<<"Calculating for :"<<name<<"\n";
        create_graph_from_file* obj= new create_graph_from_file(name);
        algos_implement* algo_implementation=new algos_implement();
        time_t start = clock();
        srand(time(NULL));
        for(int i=0;i<5;i++){

          time_t start = clock();
          int start_vertex=rand()%5000;
          int end_vertex=rand()%5000;
          cout<<algo_implementation->dijkstra_without_heap(obj->G,start_vertex,end_vertex);
          time_t end=clock();
          cout<<"\nTime taken for traversal using Dijkstra without heap for dense graph from "<<start_vertex<<" to "<<end_vertex<<" is "<<(end-start)/(double)CLOCKS_PER_SEC<<"\n";
        }
      }
      break;
    }
    case 5:{
      for(int j=0;j<5;j++){
        char c=j+(int)'0';
        string name="graph_sparse";
        name+=c;
        name+=".txt";
        cout<<"Calculating for :"<<name<<"\n";
        create_graph_from_file* obj= new create_graph_from_file(name);
        algos_implement* algo_implementation=new algos_implement();
        //time_t start = clock();
        srand(time(NULL));
        for(int i=0;i<5;i++){
          heap* heap1=new heap();
          time_t start = clock();
          int start_vertex=rand()%5000;
          int end_vertex=rand()%5000;
          cout<<algo_implementation->dijkstra_with_heap(obj->G,start_vertex,end_vertex,heap1);
          time_t end=clock();
          cout<<"\nTime taken for traversal using Dijkstra with heap from "<<start_vertex<<" to "<<end_vertex<<" is "<<(end-start)/(double)CLOCKS_PER_SEC<<"\n";
        }
      }
      break;
    }
    case 6:{
      for(int j=0;j<5;j++){
        char c=j+(int)'0';
        string name="graph_dense";
        name+=c;
        name+=".txt";
        cout<<"Calculating for :"<<name<<"\n";
        create_graph_from_file* obj= new create_graph_from_file(name);
        algos_implement* algo_implementation=new algos_implement();
        //time_t start = clock();
        srand(time(NULL));
        for(int i=0;i<5;i++){
          heap* heap1=new heap();
          time_t start = clock();
          int start_vertex=rand()%5000;
          int end_vertex=rand()%5000;
          cout<<algo_implementation->dijkstra_with_heap(obj->G,start_vertex,end_vertex,heap1);
          time_t end=clock();
          cout<<"\nTime taken for traversal using Dijkstra with heap from "<<start_vertex<<" to "<<end_vertex<<" is "<<(end-start)/(double)CLOCKS_PER_SEC<<"\n";
        }
      }
      break;
    }
    /*
    case 8:{
      //cout<<"here";

      create_graph_from_file* obj= new create_graph_from_file("graph.txt");
      //vector< vector <pair<int,int> > > G=obj->G;

      algos_implement* algo_implementation=new algos_implement();
      //cout<<"\n";
      //cout<<algo_implementation->dijkstra_without_heap(obj->G,1,100);

      heap* heap1=new heap();
      heap* heap2=new heap();
      //time_t start = clock();
      time_t start = clock();
      //cout<<"Reached main\n";
      srand(time(NULL));
      int start_vertex=rand()%5000;
      int end_vertex=rand()%5000;
      cout<<algo_implementation->dijkstra_with_heap(obj->G,start_vertex,end_vertex,heap1);
      time_t end=clock();
      cout<<"Time taken for traversal using Dijkstra without heap from "<<start_vertex<<" to "<<end_vertex<<" is "<<(end-start)/(double)CLOCKS_PER_SEC<<"\n";
      start = clock();
      start_vertex=rand()%5000;
      end_vertex=rand()%5000;
      //cout<<"Time taken for traversal using Dijkstra without heap from "<<start_vertex<<" to "<<end_vertex<<" is "<<(end-start)/(double)CLOCKS_PER_SEC<<"\n";
      cout<<algo_implementation->dijkstra_with_heap(obj->G,400,4000,heap2);
      end=clock();
      cout<<"Time taken for traversal using Dijkstra  heap from "<<start_vertex<<" to "<<end_vertex<<" is "<<(end-start)/(double)CLOCKS_PER_SEC<<"\n";
      cout<<"\n";
      break;
      //cout<<algo_implementation->dijkstra_with_heap(obj->G,400,4000,heap1);

      //cout<<"\n";
      //break;
    }


    case 10:{
      heap* heap1=new heap();
      heap1->insert(5,10);
      heap1->insert(15,1);
      heap1->insert(25,11);
      heap1->insert(0,12);
      heap1->delete_vertex(11);
      heap1->delete_vertex(12);
      pair<int,int> temp=heap1->get_max();
      cout<<temp.first<<" "<<temp.second;
      cout<<"\n";
      temp=heap1->get_max();
      cout<<temp.first<<" "<<temp.second;
      cout<<"\n";
      temp=heap1->get_max();
      cout<<temp.first<<" "<<temp.second;

    }
    case 11:{
      create_graph_from_file* obj= new create_graph_from_file("graph1.txt");
      //vector< vector <pair<int,int> > > G=obj->G;
      algos_implement* algo_implementation=new algos_implement();
      cout<<"\n";
      heap* heap1=new heap();
      time_t start = clock();
      cout<<"here";
      cout<<algo_implementation->dijkstra_with_heap(obj->G,1,7,heap1);
      time_t end=clock();
      cout<<"time taken"<<(end-start)/(double)CLOCKS_PER_SEC<<"\n";
      heap* heap2=new heap();
      start = clock();
      cout<<algo_implementation->dijkstra_with_heap(obj->G,1,9,heap2);
      end=clock();
      cout<<"time taken"<<(end-start)/(double)CLOCKS_PER_SEC<<"\n";
      cout<<"\n";
      break;
    }
    */
    case 7:{

      for(int j=0;j<5;j++){
        char c=j+(int)'0';
        string name="graph_sparse";
        name+=c;
        name+=".txt";
        cout<<"Calculating for :"<<name<<"\n";
        create_graph_from_file* obj= new create_graph_from_file(name);
        //vector< vector <pair<int,int> > > G=obj->G;
        time_t start = clock();
        heapsortclass* heap_sort1=new heapsortclass();
        vector<pair<int,pair<int,int> > > result=heap_sort1->heap_sort(obj->G);
        algos_implement* algo_implementation=new algos_implement();
        vector<vector<pair<int,int > > > spanning_tree=algo_implementation->kruskals(result);
        time_t end=clock();
        cout<<"\nTime taken for construction of Maximum spanning tree is: "<<(end-start)/(double)CLOCKS_PER_SEC<<"\n";
        for(int i=0;i<5;i++){
          //heap* heap1=new heap();
          time_t start = clock();
          int start_vertex=rand()%5000;
          int end_vertex=rand()%5000;
          cout<<algo_implementation->dfs(spanning_tree,start_vertex,end_vertex);
          time_t end=clock();
          cout<<"\nTime taken for traversal using kruskals with heap-sort from "<<start_vertex<<" to "<<end_vertex<<" is "<<(end-start)/(double)CLOCKS_PER_SEC<<"\n";
        }

      //   if (filewriter.is_open())
      //   {
      //   for(int i=0;i<spanning_tree.size();i++)
      //   {
      //     //cout<<spanning_tree[i].size();
      //     for(int j=0;j<spanning_tree[i].size();j++)
      //     {
      //       filewriter<<i<<" "<<spanning_tree[i][j].first<<" "<<spanning_tree[i][j].second<<"\n";
      //     }
      //   }
      // }
      // filewriter.close();

      }
      break;


    }
    case 8:{

      for(int j=0;j<5;j++){
        char c=j+(int)'0';
        string name="graph_dense";
        name+=c;
        name+=".txt";
        cout<<"Calculating for :"<<name<<"\n";
        create_graph_from_file* obj= new create_graph_from_file(name);
        time_t start = clock();
        heapsortclass* heap_sort1=new heapsortclass();
        vector<pair<int,pair<int,int> > > result=heap_sort1->heap_sort(obj->G);
        algos_implement* algo_implementation=new algos_implement();
        vector<vector<pair<int,int > > > spanning_tree=algo_implementation->kruskals(result);
        time_t end=clock();
        cout<<"\nTime taken for construction of Maximum spanning tree is: "<<(end-start)/(double)CLOCKS_PER_SEC<<"\n";
        for(int i=0;i<5;i++){
          //heap* heap1=new heap();
          time_t start = clock();
          int start_vertex=rand()%5000;
          int end_vertex=rand()%5000;
          cout<<algo_implementation->dfs(spanning_tree,start_vertex,end_vertex);
          time_t end=clock();
          cout<<"\nTime taken for traversal using kruskals with heap-sort from "<<start_vertex<<" to "<<end_vertex<<" is "<<(end-start)/(double)CLOCKS_PER_SEC<<"\n";
        }
      }
      break;
    }
    case 9:{

      for(int j=0;j<5;j++){
        char c=j+(int)'0';
        string name="graph_sparse";
        name+=c;
        name+=".txt";
        cout<<"Calculating for :"<<name<<"\n";
        create_graph_from_file* obj= new create_graph_from_file(name);
        //vector< vector <pair<int,int> > > G=obj->G;
        time_t start = clock();
        heapsortclass* heap_sort1=new heapsortclass();
        vector<pair<int,pair<int,int> > > result=heap_sort1->improved_sort(obj->G);
        algos_implement* algo_implementation=new algos_implement();
        vector<vector<pair<int,int > > > spanning_tree=algo_implementation->kruskals(result);
        time_t end=clock();
        cout<<"\nTime taken for construction of Maximum spanning tree is: "<<(end-start)/(double)CLOCKS_PER_SEC<<"\n";
        for(int i=0;i<5;i++){
          //heap* heap1=new heap();
          time_t start = clock();
          int start_vertex=rand()%5000;
          int end_vertex=rand()%5000;
          cout<<algo_implementation->dfs(spanning_tree,start_vertex,end_vertex);
          time_t end=clock();
          cout<<"\nTime taken for traversal using kruskals with heap-sort from "<<start_vertex<<" to "<<end_vertex<<" is "<<(end-start)/(double)CLOCKS_PER_SEC<<"\n";
        }
      }
      break;
    }
    case 10:{

      for(int j=0;j<5;j++){
        char c=j+(int)'0';
        string name="graph_dense";
        name+=c;
        name+=".txt";
        cout<<"Calculating for :"<<name<<"\n";
        create_graph_from_file* obj= new create_graph_from_file(name);
        time_t start = clock();
        heapsortclass* heap_sort1=new heapsortclass();
        vector<pair<int,pair<int,int> > > result=heap_sort1->improved_sort(obj->G);
        algos_implement* algo_implementation=new algos_implement();
        vector<vector<pair<int,int > > > spanning_tree=algo_implementation->kruskals(result);
        time_t end=clock();
        cout<<"\nTime taken for construction of Maximum spanning tree is: "<<(end-start)/(double)CLOCKS_PER_SEC<<"\n";
        for(int i=0;i<5;i++){
          //heap* heap1=new heap();
          time_t start = clock();
          int start_vertex=rand()%5000;
          int end_vertex=rand()%5000;
          cout<<algo_implementation->dfs(spanning_tree,start_vertex,end_vertex);
          time_t end=clock();
          cout<<"\nTime taken for traversal using kruskals with Improved-sort from "<<start_vertex<<" to "<<end_vertex<<" is "<<(end-start)/(double)CLOCKS_PER_SEC<<"\n";
        }
      }
      break;
    }
    case 11:{
      cout<<"\n\nExecute on same data and Sparse graph\n\n";
      for(int i=0;i<5;i++){
        char c=i+(int)'0';
        string name="graph_sparse";
        name+=c;
        name+=".txt";
        cout<<"Calculating for :"<<name<<"\n";

        create_graph_from_file* obj= new create_graph_from_file(name);

        time_t start = clock();
        heapsortclass* heap_sort1=new heapsortclass();
        vector<pair<int,pair<int,int> > > result=heap_sort1->heap_sort(obj->G);
        algos_implement* algo_implementation=new algos_implement();
        vector<vector<pair<int,int > > > spanning_tree=algo_implementation->kruskals(result);
        time_t end=clock();
        cout<<"\nTime taken for construction of Maximum spanning tree is: "<<(end-start)/(double)CLOCKS_PER_SEC<<"\n";
        start = clock();
        int start_vertex=rand()%5000;
        int end_vertex=rand()%5000;
        cout<<"\n\n";
        cout<<algo_implementation->dijkstra_without_heap(obj->G,start_vertex,end_vertex);
        end=clock();
        cout<<"\nTime taken for traversal using Dijkstra without heap for dense graph from "<<start_vertex<<" to "<<end_vertex<<" is "<<(end-start)/(double)CLOCKS_PER_SEC<<"\n";

        heap* heap1=new heap();
        start = clock();
        //int start_vertex=rand()%5000;
        //int end_vertex=rand()%5000;
        cout<<"\n\n";
        cout<<algo_implementation->dijkstra_with_heap(obj->G,start_vertex,end_vertex,heap1);
        end=clock();
        cout<<"\nTime taken for traversal using Dijkstra with heap from "<<start_vertex<<" to "<<end_vertex<<" is "<<(end-start)/(double)CLOCKS_PER_SEC<<"\n";

        start = clock();
        //start_vertex=rand()%5000;
        //int end_vertex=rand()%5000;
        cout<<"\n\n";
        cout<<algo_implementation->dfs(spanning_tree,start_vertex,end_vertex);
        end=clock();
        cout<<"\nTime taken for traversal using kruskals with heap-sort from "<<start_vertex<<" to "<<end_vertex<<" is "<<(end-start)/(double)CLOCKS_PER_SEC<<"\n";
      }
      break;

    }
    case 12:{
      cout<<"\n\nExecute on same data and Dense graph\n\n";
      for(int i=0;i<5;i++){
        char c=i+(int)'0';
        string name="graph_dense";
        name+=c;
        name+=".txt";
        cout<<"Calculating for :"<<name<<"\n";

        create_graph_from_file* obj= new create_graph_from_file(name);

        time_t start = clock();
        heapsortclass* heap_sort1=new heapsortclass();
        vector<pair<int,pair<int,int> > > result=heap_sort1->heap_sort(obj->G);
        algos_implement* algo_implementation=new algos_implement();
        vector<vector<pair<int,int > > > spanning_tree=algo_implementation->kruskals(result);
        time_t end=clock();
        cout<<"\nTime taken for construction of Maximum spanning tree is: "<<(end-start)/(double)CLOCKS_PER_SEC<<"\n";
        start = clock();
        int start_vertex=rand()%5000;
        int end_vertex=rand()%5000;
        cout<<"\n\n";
        cout<<algo_implementation->dijkstra_without_heap(obj->G,start_vertex,end_vertex);
        end=clock();
        cout<<"\nTime taken for traversal using Dijkstra without heap for dense graph from "<<start_vertex<<" to "<<end_vertex<<" is "<<(end-start)/(double)CLOCKS_PER_SEC<<"\n";

        heap* heap1=new heap();
        start = clock();
        //int start_vertex=rand()%5000;
        //int end_vertex=rand()%5000;
        cout<<"\n\n";
        cout<<algo_implementation->dijkstra_with_heap(obj->G,start_vertex,end_vertex,heap1);
        end=clock();
        cout<<"\nTime taken for traversal using Dijkstra with heap from "<<start_vertex<<" to "<<end_vertex<<" is "<<(end-start)/(double)CLOCKS_PER_SEC<<"\n";

        start = clock();
        //start_vertex=rand()%5000;
        //int end_vertex=rand()%5000;
        cout<<"\n\n";
        cout<<algo_implementation->dfs(spanning_tree,start_vertex,end_vertex);
        end=clock();
        cout<<"\nTime taken for traversal using kruskals with heap-sort from "<<start_vertex<<" to "<<end_vertex<<" is "<<(end-start)/(double)CLOCKS_PER_SEC<<"\n";
        }
      break;

    }
  }






}
