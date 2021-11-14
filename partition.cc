#include <iostream>
#include <vector>

using namespace std;

void partition(vector<int> &v)
{
  int pivot = v[0];
  int i = 0, j = 1;
  for (; j < v.size(); j++)
  {
    if (v[j] <= pivot)
    {
      i++;
      swap(v[i], v[j]);
    }
  }
  swap(v[0], v[i]);
}

void partitionOdd(vector<int> &v)
{
  int i = -1, j = 0;
  for (; j < v.size(); j++)
  {
    if (v[j] % 2 == 1)
    {
      i++;
      swap(v[j], v[i]);
    }
  }
}

void printVector(vector<int> &v)
{
  for (int i = 0; i < v.size(); i++)
  {
    cout << v[i] << " ";
  }
  cout << endl;
}

int main()
{
  vector<int> v{2, 1, 4, 3, 5, 10, 12, 11, 13};
  printVector(v);
  partition(v);
  printVector(v);
  //---
  partitionOdd(v);
  printVector(v);
  return 0;
}