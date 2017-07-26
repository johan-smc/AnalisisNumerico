#include <iostream>

//Juan Pablo Peñaloza
//william Moreno
// Wiliam Farero
//Johan Murillo
using namespace std;
#define MAX 1000

 double poly1[] = {-4 , 3, -3, 0, 2};
 double poly2[] = {-4 , 3, 0, -6, 6, 7 };
 double poly3[] = {0, -4, 2, 0, 3, 0, -5};

const int degreePoly1 = 5;
const int degreePoly2 = 6;
const int degreePoly3 = 7;

double horners( double* poly , const int& tam , double& x ) {
  double ans = poly[ tam-1 ];
  for( int i = tam-2 ; i >= 0 ; --i )
    ans = ans*x + poly[ i ];
  return ans;
}

void derivada( double* poly , const int& tam ,double* derivative ) {
  for( int i = tam-1 ; i>=1 ; --i ) {
    derivative[ i-1 ]  = poly[ i ] * i ;
  }
}

int main() {
  double derivative[ MAX ];
  double valueOfX;
  // cout << "Value of X: ";
  // cin >> valueOfX;

  // Polynomial 1
  valueOfX = -2;
  cout << "Plynomial 1: " << endl;
  cout << "Result: " << horners(poly1,degreePoly1, valueOfX) << "\n";
  cout << "Derivative: ";
  derivada(poly1,degreePoly1,derivative);
  for( int i = 0 ; i < degreePoly1 ; ++i ) {
    if( i ) cout << " + ";
    cout << "(" << derivative[ i ] << "x^" << i << ")";
  }
  cout << "\n";
  cout << "Derivative Value: ";
  cout << horners( derivative , degreePoly1 - 1 , valueOfX ) << "\n";
  // End Plynomial 1

  // Polynomial 2
  valueOfX = 3;
  cout << "Plynomial 2: " << endl;
  cout << "Result: " << horners(poly2,degreePoly2, valueOfX) << "\n";
  cout << "Derivative: ";
  derivada(poly2,degreePoly2,derivative);
  for( int i = 0 ; i < degreePoly2 ; ++i ) {
    if( i ) cout << " + ";
    cout << "(" << derivative[ i ] << "x^" << i << ")";
  }
  cout << "\n";
  cout << "Derivative Value: ";
  cout << horners( derivative , degreePoly2 - 1 , valueOfX ) << "\n";
  // End Plynomial 2

  // Polynomial 3
  valueOfX = -1;
  cout << "Plynomial 3: " << endl;
  cout << "Result: " << horners(poly3,degreePoly3, valueOfX) << "\n";
  cout << "Derivative: ";
  derivada(poly3,degreePoly3,derivative);
  for( int i = 0 ; i < degreePoly3 ; ++i ) {
    if( i ) cout << " + ";
    cout << "(" << derivative[ i ] << "x^" << i << ")";
  }
  cout << "\n";
  cout << "Derivative Value: ";
  cout << horners( derivative , degreePoly3 - 1 , valueOfX ) << "\n";
  // End Plynomial 3

  return 0;
}
