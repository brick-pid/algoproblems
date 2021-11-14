#include <iostream>
#include <vector>

int n = 11;
std::vector<int> v{1, 2, 3, 4, 5, 6};

//已经从前i项中得到sum，继续对i之后的项进行计算
bool dfs(int sum, int i)
{
  //全部数字都已经判断过了
  if (i == v.size() - 1)
    return sum == n;

  //判断第i项：不加该数字
  if (dfs(sum, i + 1))
    return true;

  //判断第i项：加该数字
  if (dfs(sum + v[i], i + 1))
    return true;

  //无论是否加上a[i]都不能凑成n，则返回false
  return false;
}

int main()
{
  if (dfs(0, 0))
  {
    std::cout << "OK\n";
  }
  else
  {
    std::cout << "not OK\n";
  }
  std::cout << "hello!" << std::endl;
  return 0;
}
