#include <iostream> // komentarz

using namespace std;

// Oblicza n-t� liczb� Fibonacciego
//---------------------------------
unsigned long long fibo(int n)
{
  unsigned long long q11,q12,q21,q22, // macierz Q

  if(n < 2) return n;

  // ustawiamy macierz Q

  q11 = q12 = q21 = 1;
  q22 = 0;

  // w macierzy W tworzymy macierz jednostkow�

  w11 = w22 = 1;
  w12 = w21 = 0;

  n--;      // b�dzie nam potrzebna n-1 pot�ga Q

  while(n)
  {
     if(n & 1)
     {
       // wykonujemy mno�enie P = W x Q

       p11 = w11*q11 + w12 * q21; p12 = w11*q12 + w12 * q22;
       p21 = w21*q11 + w22 * q21; p22 = w21*q12 + w22 * q22;

       // wynik przenosimy: W = P

       w11 = p11; w12 = p12;
       w21 = p21; w22 = p22;

     }

     n >>= 1;    // usuwamy z n sprawdzony bit

     if(!n) break;

     // podnosimy Q do kwadratu:  P = Q x Q

     p11 = q11*q11 + q12 * q21; p12 = q11*q12 + q12 * q22;
     p21 = q21*q11 + q22 * q21; p22 = q21*q12 + q22 * q22;

     // wynik przenosimy: Q = p

     q11 = p11; q12 = p12;
     q21 = p21; q22 = p22;

  }

  return w11;
}

// Program g��wny
//---------------

int main()
{
  for(int i = 0; i < 94; i++) cout << "F(" << i << ") = " << fibo(i) << endl;
  return 0;