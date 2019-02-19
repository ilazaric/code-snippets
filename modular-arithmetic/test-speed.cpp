#include <iostream>
#include <chrono>
#include <iomanip>

#include "mint-simple.cpp"

using namespace std;
using namespace std::chrono;

const int Mod = 1e9 + 7;
const int Limit = 3e8;

using mint = MintSimple::mint<Mod>;

mint calcMint(){
  mint acc(0);
  srand(432);
  for (int i = 0; i < Limit; ++i){
    acc += mint::unsafe(2*i+12345);
    acc *= mint::unsafe(5*i+65432);
  } return acc;
}

inline int add(int a, int b){return (a += b) < Mod ? a : a-Mod;}
inline int sub(int a, int b){return (a -= b) < 0 ? a+Mod : a;}
inline int mul(int a, int b){return (int)((long long)a * b % Mod);}
int calcStupid(){
  int acc = 0;
  srand(432);
  for (int i = 0; i < Limit; ++i){
    acc = add(acc, 2*i+12345);
    acc = mul(acc, 5*i+65432);
  } return acc;
}

#define DISPLAY_TIMED(expression) {					\
    auto __t1__ = high_resolution_clock::now();				\
    cout << left << setw(20) << ((string)#expression + ": ");		\
    cout << left << setw(20) << (expression);				\
    auto __t2__ = high_resolution_clock::now();				\
    cout << " [" << right << setfill(' ') << setw(5) <<			\
      duration_cast<milliseconds>(__t2__ - __t1__).count() << "ms]" <<	\
      setfill(' ') << endl;						\
  }


int main(){

  DISPLAY_TIMED(calcMint());
  DISPLAY_TIMED(calcStupid());
    
  return 0;
}
