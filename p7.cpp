#include <iostream>

using namespace std;

int Szukaj(int T[], int n, int k, int p)
{
  for(int i = p; i < n; i++)
    if(T[i] == k) return i;

  return -1;
}

int main()
{
  int * Z,n,k,i;
  
  cin >> n;

  Z = new int [n];

  for(i = 0; i < n; i++) cin >> Z[i];

  cin >> k;

  cout << endl << Szukaj(Z,n,k,0) << endl << endl;

  delete [] Z;

  return 0;
} 