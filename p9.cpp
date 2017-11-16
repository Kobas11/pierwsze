#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <time.h>

using namespace std;

const int N = 20;

int main()
{
  int Z[N + 1],i,j,v,x;

  srand((unsigned)time(NULL));

  // Przygotowujemy tablicê Z[]

  for(i = 0; i < N; i++) Z[i] = rand() % 1000;

  // Na koñcu Z[] umieszczamy wartownika

  Z[N] = 1000;

  // Wyœwietlamy Z[] przed podzia³em

  for(i = 0; i < N; i++) cout << setw(4) << Z[i];
  cout << endl;

  // Dzielimy Z[] na dwie partycje

  v = Z[0]; i = 0; j = N;
  while(i < j)
  {
    while(Z[++i] < v) ;
    while(Z[--j] > v) ;
    if(i < j)
    {
      x = Z[i]; Z[i] = Z[j]; Z[j] = x;
    }
  }
  Z[0] = Z[j]; Z[j] = v;

  // Wyœwietlamy Z[] po podziale

  for(i = 0; i < N; i++)
    cout << (i == j ? "|---" : "----");

  for(i = 0; i < N; i++)
    if(i == j) cout << "|" << setw(3) << Z[i];
    else       cout << setw(4) << Z[i];

  for(i = 0; i < N; i++)
    cout << (i == j ? "|---" : "----");

  cout << endl << endl;

  return 0;
} 