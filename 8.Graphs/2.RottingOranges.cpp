#inlude <iostream>
using namespace std


class Solution {
    private:

void bfs(vector<vector<int>>& grid)
{

}

pair<int, int> findRotten(vector<vector<int>>& grid)
{
    int numRow=grid.size();
    int numCol=grid[0].size();
 for(int i=0 ; i< numRow ; i++){
 for(int j=0 ; j< numCol ; j++){
if(grid[i][j]==2) return { i , j };
 }   
 }
  return {-1, -1};   
}

public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
       pair<int, int> rotten=findRotten(grid);
       int i=0;
       int j=0;

  if(rotten.first !=-1 ){
   i= rotten.first; 
   j=rotten.second;
  }
  else if(grid.size()==1 && grid[0].size()==1 && grid[0][0]==0)
 {
    return 0;
 }

 int time=0; 
 
 queue<pair<int,int>> q;

 vector <int> colOffSet={-1,0,1,0};
 vector <int> rowOffSet={0,-1,0,1};


q.push(i,j);
while (!q.empty())
{
 pair<int,int> index= q.pop();
 index.first;
 
}

}
};