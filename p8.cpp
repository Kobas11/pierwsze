#include <iostream>

using namespace std;

int Szukaj(int T[], int n, int k, int p)
{
  int i;

  T[n] = k;
  for(i = p; T[i] != k; i++) ;
  if(i == n) return -1; else return i;
	//kom asdnio
}

int main()
{
  int * Z,n,k,i;
  
  cin >> n;
  Z = new int [n + 1];
  for(i = 0; i < n; i++) cin >> Z[i];
  cin >> k;
  cout << endl << Szukaj(Z,n,k,0) << endl << endl;
  delete [] Z;
  return 0;
} 