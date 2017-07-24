#include <iostream>

using namespace std;

int pow( int base , int exp )
{
  int res = 1;
  while( exp-- )
    res *= base;
  return res;
}

int naive( int* poly , int& tam , int& x )
{
  int res = 0;
  for( int i = 0 ; i< tam ; ++i )
    res += pow( x  , i ) * poly[ i ];
  return res;
}

//recomended use with mod
int fpow( int base , int exp )
{
  int ans = 1, power = base;
  while( exp )
  {
    if( exp & 1 )
      ans *= power;
    power *= power;
    exp <<= 1;
  }
  return ans;
}

int fastPow( int* poly , int& tam , int& x )
{
  int res = 0;
  for( int i = 0 ; i< tam ; ++i )
    res += fpow( x  , i ) + poly[ i ];
  return res;
}

int horners( int* poly , int& tam , int& x )
{
  int ans = poly[ tam-1 ];
  for( int i = tam-2 ; i >=  0 ; --i )
    ans = ans*x + poly[ i ];
  return ans;
}

int other( int* poly , int& tam , int& x )
{
  int exp[ tam+1 ];
  exp[ 0 ] = 1;
  for( int i = 1 ; i < tam ; ++i )
    exp[ i ] = exp[ i -1 ] * x;
  int ans  = 0 ;
  for( int i = 0 ; i < tam ; ++i )
    ans += exp[ i ] * poly[ i ];
  return ans;
}

int main()
{
  int poly[] = {-1, 2, -6, 2};
  int x = 3;
  int tam = 4;
  cout << naive(poly,tam,x) << "\n";
  cout << fastPow(poly,tam,x) << "\n";
  cout << horners(poly,tam,x) << "\n";
  cout << other(poly,tam,x) << "\n";
  return 0;
}
