#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<int> a(n + 1, 1);
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= i / 2; j++)
    {
      if (j * 10 + i > n / 2)
      {
        a[i] += a[j];
      }
    }
  }
  cout << a[n] << endl;
}