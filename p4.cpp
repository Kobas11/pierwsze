#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>

using namespace std;

const int N  = 80;  // d³ugoœæ ³añcucha s
const int M  =  5;  // d³ugoœæ wzorca p
const int zp = 65;  // kod pierwszego znaku alfabetu
const int zk = 66;  // kod ostatniego znaku alfabetu
//dadas
int main()
{
  string s,p;
  int Last[zk - zp + 1],i,j,pp;

  srand((unsigned)time(NULL));

  // generujemy ³añcuch s

  s = "";
  for(i = 0; i < N; i++) s += zp + rand() % (zk - zp + 1);

  // generujemy wzorzec

  p = "";
  for(i = 0; i < M; i++) p += zp + rand() % (zk - zp + 1);

  // wypisujemy wzorzec

  cout << p << endl;

  // wypisujemy ³añcuch

  cout << s;

  // dla wzorca obliczamy tablicê Last[]

  for(i = 0; i <= zk - zp; i++) Last[i] = -1;
  for(i = 0; i < M; i++) Last[p[i] - zp] = i;

  // szukamy pozycji wzorca w ³añcuchu

  pp = i = 0;
  while(i <= N - M)
  {
    j = M - 1;
    while((j > -1) && (p[j] == s[i + j])) j--;
    if(j == -1)
    {
      while(pp < i)
      {
        cout << " "; pp++;
      }
      cout << "^"; pp++;
      i++;
    }
    else i += max(1,j - Last[s[i + j] - zp]);
  }
  cout << endl << endl;
  return 0;
} 