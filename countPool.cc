#include <iostream>
#include <vector>
#include <string>

using namespace std;
void dfs(vector<string> &v, int i, int j);
int main()
{
  int m, n;
  int count = 0;
  vector<string> v;

  cin >> n >> m;
  for (int i = 0; i < n; i++)
  {
    string s;
    cin >> s;
    v.push_back(s);
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (v[i][j] == 'W')
      {
        count++;
        dfs(v, i, j);
      }
    }
  }

  cout << count << endl;

  return 0;
}

void dfs(vector<string> &v, int i, int j)
{
  if (v[i][j] == '.')
    return;
  if (v[i][j] == 'W')
    v[i][j] = '.';
  for (int p = -1; p <= 1; p++)
  {
    for (int q = -1; q <= 1; q++)
    {
      if (i + p >= 0 && i + p < v.size() && j + q >= 0 && j + q < v[0].size())
      {
        dfs(v, i + p, j + q);
      }
    }
  }
  return;
}