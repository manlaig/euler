#include <iostream>
#include <vector>
using namespace std;

/*
What is the greatest product of four adjacent numbers in the same direction (up, down, left, right, or diagonally) in the 20x20 grid?
*/
int main()
{
  vector< vector<int> > grid(20,vector<int>(20));
  cout << "Enter the values of the 20x20 grid" << endl;
  for(int grid_i = 0;grid_i < 20;grid_i++)
    for(int grid_j = 0;grid_j < 20;grid_j++)
      cin >> grid[grid_i][grid_j];
  
  long sum = 0;
  long left = 0, down = 0, diagonal = 0, diagonalR = 0;
  for(int i = 0; i < 20; i++)
    for(int j = 0; j < 20; j++)
    {
      if(j < 17)
          left = 1L * grid[i][j] * grid[i][j+1] * grid[i][j+2] * grid[i][j+3];
      if(i < 17)
          down = 1L * grid[i][j] * grid[i+1][j] * grid[i+2][j] * grid[i+3][j];
      if(i < 17 && j < 17)
          diagonal = 1L * grid[i][j] * grid[i+1][j+1] * grid[i+2][j+2] * grid[i+3][j+3];
      if(j >= 3 && i < 17)
          diagonalR = 1L * grid[i][j] * grid[i+1][j-1] * grid[i+2][j-2] * grid[i+3][j-3];
      
      long m = max(left, down);
      long m2 = max(diagonal, diagonalR);
      long l = max(m, m2);
      if(l > sum)
          sum = l;    
    }
  cout << sum << endl;
  return 0;
}