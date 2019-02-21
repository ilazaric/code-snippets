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
  for (int i = 0; i < Limit; ++i){
    acc += mint::unsafe(2*i+12345);
    acc *= mint::unsafe(5*i+65432);
  } return acc;
}

using uint = unsigned int;
inline uint add(uint a, uint b){return (a += b) < Mod ? a : a-Mod;}
inline uint sub(uint a, uint b){return a < b ? a+(Mod-b) : a-b;}
inline uint mul(uint a, uint b){return (uint)((unsigned long long)a * b % Mod);}
uint calcStupid(){
  uint acc = 0;
  for (uint i = 0; i < Limit; ++i){
    acc = add(acc, 2*i+12345);
    acc = mul(acc, 5*i+65432);
  } return acc;
}

#define DISPLAY_TIMED(expression) {					\
    auto __t1__ = high_resolution_clock::now();				\
    auto value = (expression);						\
    auto __t2__ = high_resolution_clock::now();				\
    cout << left << setw(20) << ((string)#expression + ": ");		\
    cout << left << setw(20) << value;					\
    cout << " [" << right << setfill(' ') << setw(5) <<			\
      duration_cast<milliseconds>(__t2__ - __t1__).count() << "ms]" <<	\
      setfill(' ') << endl;						\
  }


int main(){

  calcMint();
  calcStupid();

  DISPLAY_TIMED(calcMint());
  DISPLAY_TIMED(calcStupid());
    
  return 0;
}
