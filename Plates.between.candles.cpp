#include<iostream> 
#include<vector> 

using namespace std; 

class Solution{
public: 
      vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        vector<int> res; 

        int m = s.size(); 
        vector<int> prefix(m,0); 
        vector<int> left(m,-1); 
        vector<int> right(m,-1); 
        int totalplate =0; 
        for(int i=0; i<m;++i){
          if(s[i]=='*') ++totalplate; 
          prefix[i] = totalplate; 
        }
        int candle = -1;
        for(int i=0; i<m;++i){
          if(s[i]=='|') candle = i; 
          left[i]=candle; 
        }
        candle = -1; 
        for(int i=m-1; i>=0; --i){
          if(s[i]=='|') candle =i; 
          right[i]=candle; 
        }
        for(auto q:queries){
          int l = right[q[0]]; 
          int r = left[q[1]]; 

          if( l!= -1 && r!=-1 && l<r) res.push_back(prefix[r]-prefix[l]); 
          else res.push_back(0); 
        }
        return res; 
      }
};
int main(){
  string s = "**|**|***|"; 
  vector<vector<int>> queries = {{2,5},{5,9}};
  Solution sol; 
  vector<int> res = sol.platesBetweenCandles(s, queries); 
  for(int n: res) cout << n << ","; 
  cout <<endl; 
  return 0; 
}
