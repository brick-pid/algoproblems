#include <iostream>
#include <string>
#include <string.h>
#include <fstream>

#define a 0
#define b 1
#define c 2
using namespace std;

int waysToMultiple(const string &str);
int main()
{
  string s;
  ifstream fs;
  fs.open("str.txt");
  while (!fs.eof())
  {
    fs >> s;
    cout << "ways to get \"a\" from " << s << " = " << waysToMultiple(s) << endl;
  }
  fs.close();
  return 0;
}

int waysToMultiple(const string &str)
{
  int n = str.length();
  int ways[n][n][3];
  memset(ways, 0, n * n * 3 * sizeof(int));

  for (int i = 0; i < n; ++i)
  {
    if (str[i] == 'a')
      ways[i][i][a] = 1;
    else if (str[i] == 'b')
      ways[i][i][b] = 1;
    else if (str[i] == 'c')
      ways[i][i][c] = 1;
    else
    {
      printf("error str\n");
      return 1;
    }
  }

  for (int r = 1; r < n; ++r)
  {
    for (int i = 0; i < n; i++) //str[i..j]
    {
      int j = r + i;
      if (j < n)
      {
        for (int k = i; k < j; k++)
        {
          int d1 = ways[i][k][c] * ways[k + 1][j][a] +
                   ways[i][k][a] * ways[k + 1][j][c] +
                   ways[i][k][b] * ways[k + 1][j][c];
          ways[i][j][a] += d1;

          int d2 = ways[i][k][a] * ways[k + 1][j][a] +
                   ways[i][k][a] * ways[k + 1][j][b] +
                   ways[i][k][b] * ways[k + 1][j][b];
          ways[i][j][b] += d2;

          int d3 = ways[i][k][b] * ways[k + 1][j][a] +
                   ways[i][k][c] * ways[k + 1][j][b] +
                   ways[i][k][c] * ways[k + 1][j][c];
          ways[i][j][c] += d3;
          //printf("i=%d, j=%d, k=%d, d1=%d, d2=%d, d3=%d\n", i, j, k, d1, d2, d3);
        }
      }
    }
  }
  return ways[0][n - 1][a];
}