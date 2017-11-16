#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

const double eps = 1e-12;
const double eps1 = 1e-12;

// Funkcja dokonuje rozk³adu LU macierzy A
//----------------------------------------
bool ludist(int n, double ** A)
{
  int i,j,k;

  for(k = 0; k < n - 1; k++)
  {
    if(fabs(A[k][k]) < eps) return false;

    for(i = k + 1; i < n; i++)
      A[i][k] /= A[k][k];

    for(i = k + 1; i < n; i++)
      for(j = k + 1; j < n; j++)
        A[i][j] -= A[i][k] * A[k][j];
  }

  return true;
}

// Funkcja wyznacza wektor X na podstawie A i B
//---------------------------------------------
bool lusolve(int n, double ** A, double * B, double * X)
{
  int    i,j;
  double s;

  X[0] = B[0];

  for(i = 1; i < n; i++)
  {
    s = 0;

    for(j = 0; j < i; j++) s += A[i][j] * X[j];

    X[i] = B[i] - s;
  }

  if(fabs(A[n-1][n-1]) < eps) return false;

  X[n-1] /= A[n-1][n-1];

  for(i = n - 2; i >= 0; i--)
  {
    s = 0;

    for(j = i + 1; j < n; j++) s += A[i][j] * X[j];

    if(fabs(A[i][i]) < eps) return false;

    X[i] = (X[i] - s) / A[i][i];
  }

  return true;
}

// Program g³ówny

int  main()
{
  double **A, *B, *X;
  int n,i,j;

  cout << setprecision(4) << fixed;

  // odczytujemy liczbê niewiadomych

  cin >> n;

  // tworzymy macierze A, B i X

  A = new double * [n];
  B = new double [n];
  X = new double [n];

  for(i = 0; i < n; i++) A[i] = new double[n];

  // odczytujemy dane dla macierzy A i B

  for(i = 0; i < n; i++)
  {
    for(j = 0; j < n; j++) cin >> A[i][j];
    cin >> B[i];
  }

  // rozwi¹zujemy uk³ad i wyœwietlamy wyniki

  if(ludist(n,A) && lusolve(n,A,B,X))
  {
    for(i = 0; i < n; i++) cout << "x" << i + 1 << " = " << setw(9) << X[i] << endl;
  }
  else cout << "DZIELNIK ZERO\n";

  // usuwamy macierze z pamiêci

  for(i = 0; i < n; i++) delete [] A[i];
  delete [] A;
  delete [] B;
  delete [] X;

  return 0;
} 