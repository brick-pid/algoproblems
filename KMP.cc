#include <iostream>
#include <vector>
#include <string>

using namespace std;
void printVector(vector<int> &v);

vector<int> calculate_prefix(string p)
{
  vector<int> pi(p.size());
  for (int i = 1; i < p.size(); i++)
  {
    //calculate pi[i]
    for (int j = i - 1; j >= 0; j--)
    {
      //test each possible value for pi[i] from i-1 to 0
      if (p.substr(0, j) == p.substr(i - j + 1, j))
      {
        pi[i] = j;
        break;
      }
    }
  }
  return pi;
}

vector<int> calculate_prefix_2(string p)
{
  vector<int> pi(p.size());
  for (int i = 1; i < p.size(); i++)
  {
    //calculate pi[i]
    for (int j = pi[i - 1] + 1; j >= 0; j--) //improved: j = i - 1 => j = pi[i - 1] + 1
    {
      //test each possible value for pi[i] from i-1 to 0
      if (p.substr(0, j) == p.substr(i - j + 1, j))
      {
        pi[i] = j;
        break;
      }
    }
  }
  return pi;
}

int main()
{
  string t{"ababaca"};
  vector<int> v1 = calculate_prefix(t);
  vector<int> v2 = calculate_prefix_2(t);
  printVector(v1);
  printVector(v2);
  return 0;
}

void printVector(vector<int> &v)
{
  for (int i = 0; i < v.size(); i++)
  {
    cout << v[i] << " ";
  }
  cout << endl;
}