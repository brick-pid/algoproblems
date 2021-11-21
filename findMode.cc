#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

int mode;
int modeCount;
void split(vector<int> &v, int &l, int &r)
{
  int mid = v.size() / 2;
  for (l = 0; v[l] != v[mid]; l++)
    ;

  for (r = l + 1; v[r] == v[mid]; r++)
    ;
}
void getMode(vector<int> v)
{
  int l, r;
  split(v, l, r);
  int count = r - l;
  if (count > modeCount)
  {
    modeCount = count;
    mode = v[l];
  }

  if (l + 1 > modeCount)
    getMode(vector<int>(v.begin(), v.begin() + l));
  if (v.size() - r > modeCount)
    getMode(vector<int>(v.begin() + r, v.end()));
}
int main()
{
  vector<int> v;
  string line;
  int num;
  getline(cin, line);
  istringstream iss(line);
  while (iss >> num)
  {
    v.emplace_back(num);
  }
  sort(v.begin(), v.end());
  getMode(v);
  cout << "众数是：" << mode << "\n重复次数为：" << modeCount << endl;
  return 0;
}
