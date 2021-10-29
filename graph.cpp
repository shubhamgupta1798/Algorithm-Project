#include<bits/stdc++.h>
#include"node.h"
using namespace std;


int main(){
  int input;
  cin>>input;
  switch(input){
    case 1:{
      graph* obj=new graph();
      obj->make_graph(5000,6);
      obj->write_to_txt();
      break;
    }
    case 2:{
      graph* obj=new graph();
      obj->make_graph(5000,1000);
      obj->write_to_txt("graph1.txt");
      break;
    }

}



}
