#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;
#define MOD 1000
#define MAX 100000

int main()
{
  srand( time( NULL ) );
  // int x = rand() % MOD;
  int x = 1;
  int tam = MAX;
  cout << x << "\n";
  cout << tam << "\n";
  for( int i = 0 ; i< tam ; ++i )
    cout << 1 << "\n";
    // cout << (rand() % (MOD+1))-MOD << "\n";
  return 0;
}
