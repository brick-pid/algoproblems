#include <iostream>
#include <vector>
using namespace std;

// 左侧边界与右侧边界的区别只在于如何收缩搜索区间，目标是否可能落在边界上。
// binary search the first number >= x
int binary_right(vector<int> &v, int x)
{
  int l = 0, r = v.size() - 1;
  while (l < r)
  {
    int mid = (l + r) / 2;
    if (v[mid] >= x)
    {
      r = mid;
    }
    else
    {
      l = mid + 1;
    }
  }

  if (v[l] >= x)
    return l;
  else
    return -1;
}

//binary find the first number < x
int binary_left(vector<int> &v, int x)
{
  int l = 0, r = v.size() - 1;
  while (l < r)
  {
    int mid = (l + r) / 2;
    if (v[mid] >= x)
    {
      r = mid - 1;
    }
    else
    {
      l = mid;
    }
  }
  if (v[l] < x)
    return l;
  else
    return -1;
}

int main()
{
  vector<int> v{1, 2, 3, 4, 5, 6};
  cout << binary_right(v, 5) << endl
       << binary_left(v, 5) << endl;
  ;
  return 0;
}