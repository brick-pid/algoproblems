#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <fstream>

using namespace std;
int edistance(const string &X, const string &Y);
int min3(int a, int b, int c);
int main()
{
  ifstream file;
  string word1, word2;
  file.open("words.txt");
  while (!file.eof())
  {
    file >> word1 >> word2;
    cout << "the distance between \"" << word1 << "\" and \"" << word2 << "\" is " << edistance(word1, word2) << endl;
  }
  file.close();
  return 0;
}

int edistance(const string &X, const string &Y)
{
  int n = X.size(), m = Y.size();
  int D[n + 1][m + 1];
  for (int i = 0; i <= n; i++)
    D[i][0] = i;

  for (int j = 0; j <= m; j++)
    D[0][j] = j;

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      if (X[i - 1] == Y[j - 1])
      {
        D[i][j] = D[i - 1][j - 1];
      }
      else
      {
        int del = D[i - 1][j] + 1;
        int ins = D[i][j - 1] + 1;
        int subst = D[i - 1][j - 1] + 1;
        //printf("del = %d  ins = %d  subst=%d\n", del, ins, subst);
        D[i][j] = min3(del, ins, subst);
      }
    }
  }
  return D[n][m];
}

int min3(int a, int b, int c)
{
  return min(a, min(b, c));
}