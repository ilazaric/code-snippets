#include <iostream>
#include <chrono>

#include "mint-simple.cpp"

using namespace std;
using namespace std::chrono;

const int Mod = 1e9 + 7;
const int Limit = 5e7;

typedef MintSimple::mint<Mod> mint;

mint calcMint(){
  mint acc;
  srand(432);
  for (int i = 0; i < Limit; ++i){
    acc += mint(rand());
    acc *= mint(rand());
  } return acc;
}

int add(int a, int b){return (a += b) < Mod ? a : a-Mod;}
int sub(int a, int b){return (a -= b) < 0 ? a+Mod : a;}
int mul(int a, int b){return (int)((long long)a * b % Mod);}
int calcStupid(){
  int acc = 0;
  srand(432);
  for (int i = 0; i < Limit; ++i){
    acc = add(acc, rand() % Mod);
    acc = mul(acc, rand() % Mod);
  } return acc;
}

int main(){

  auto t1 = high_resolution_clock::now();
  cout << calcMint() << endl;
  auto t2 = high_resolution_clock::now();
  cout << calcStupid() << endl;
  auto t3 = high_resolution_clock::now();

  cout << duration_cast<microseconds>(t2 - t1).count() << endl;
  cout << duration_cast<microseconds>(t3 - t2).count() << endl;
  
  return 0;
}
