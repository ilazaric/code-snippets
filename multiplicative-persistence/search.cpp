#include <iostream>
#include <thread>
#include <cassert>
#include <string>

#include <gmpxx.h>

using namespace std;

using BigInt = mpz_class;

int trial(BigInt num){
  int sol = 0;
  while (num >= 10){
    ++sol;
    BigInt nxt(1);
    const auto &digits = num.get_str();
    for (auto digit : digits) nxt *= digit - '0';
    num = nxt;
  } return sol;
}

struct Solution {
  BigInt start;
  int length;

  Solution(){}
  explicit Solution(const BigInt &start_) : start(start_), length(trial(start_)){}

  friend bool operator<(const Solution &a, const Solution &b){return a.length < b.length;}
};

const int THREAD_COUNT = 16;
const int EXPONENT_UPPERBOUND = 200;

Solution solve(int p, int q, int r){
  cerr << "running on " << p << ", " << q << ", " << r << endl;
  
  array<Solution, THREAD_COUNT> thread_outputs;
  thread_outputs.fill(Solution(BigInt(0)));
  array<thread, THREAD_COUNT> threads;

  for (int i = 0; i < THREAD_COUNT; ++i){
    cerr << "starting thread #" << i << endl;
    threads[i] = thread([&output = thread_outputs[i], rem = i, p, q, r]{
	for (int pi = rem; pi < EXPONENT_UPPERBOUND; pi += THREAD_COUNT)
	  for (int qi = 0; qi < EXPONENT_UPPERBOUND; ++qi)
	    for (int ri = 0; ri < EXPONENT_UPPERBOUND; ++ri){
	      string tmp = string(pi, (char)(p + '0')) + string(qi, (char)(q + '0')) + string(ri, (char)(r + '0'));
	      if (tmp.empty()) tmp = "1";
	      output = max(output, Solution(BigInt(tmp)));
	    }
      });
  }

  for (int i = 0; i < THREAD_COUNT; ++i)
    threads[i].join();

  cerr << "threads closed" << endl;

  Solution solution(BigInt(1));
  for (int i = 0; i < THREAD_COUNT; ++i)
    solution = max(solution, thread_outputs[i]);

  return solution;
}

int main(){
  assert(trial(BigInt("277777788888899")) == 11);

  // the product of digits is (if not 0) writable as 2^x * 3^y * 5^z * 7^w
  // 2 and 5 can't exist at the same time because otherwise we would get a 0 in the first iteration

  Solution solution = max(solve(2, 3, 7), solve(3, 5, 7));

  cout << "best starting point = " << solution.start << endl;
  cout << "length of path = " << solution.length << endl;
  
  return 0;
}
