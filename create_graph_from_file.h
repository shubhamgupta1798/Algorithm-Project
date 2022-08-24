#include<bits/stdc++.h>

using namespace std;
class create_graph_from_file{
public:

vector< vector <pair<int,int> > > G;
vector< vector <pair<int,int> > > return_graph()
{
  return G;
}
vector<int> split (const string &s, char delim) {
    vector<int> result;
    stringstream ss (s);
    string item;

    while (getline (ss, item, delim)) {
      if(item!="")
        result.push_back (stoi(item));
    }

    return result;
}
create_graph_from_file(string filename)
{
  std::ifstream file(filename);

  int count=0;
  if (file.is_open()) {
      std::string line;
      while (std::getline(file, line)) {
          vector<int> result=split(line,',');
          vector<pair<int,int> > temp;
          //G[count]=temp;
          for(int i=0;i<result.size();i=i+2)
          {
            temp.push_back(make_pair(result[i],result[i+1]));
            //cout<<result[i]<<" "<<result[i+1]<<"..";
          }
          G.push_back(temp);
        //  cout<<"\n";
          count++;
      }
      file.close();
  }
}




};
