#include <iostream>


namespace MintSimple {
  template<int Mod>
  struct mint {
    int value;

    explicit mint() : value(0){}
    explicit mint(int x) : value((x % Mod + Mod) % Mod){}
    explicit mint(long long x) : value((int)(x % Mod + Mod) % Mod){}

    inline friend mint operator+(mint a, mint b){
      a.value += b.value;
      if (a.value >= Mod) a.value -= Mod;
      return a;
    }

    inline friend mint operator-(mint a, mint b){
      a.value -= b.value;
      if (a.value < 0) a.value += Mod;
      return a;    
    }

    inline friend mint operator*(mint a, mint b){
      a.value = (int)((long long)a.value * b.value % Mod);
      return a;
    }

    inline friend mint operator+=(mint &a, mint b){
      return a = a + b;
    }

    inline friend mint operator-=(mint &a, mint b){
      return a = a - b;
    }

    inline friend mint operator*=(mint &a, mint b){
      return a = a * b;
    }
  };

  template<int Mod>
  std::ostream &operator<<(std::ostream &out, mint<Mod> x){
    return out << x.value;
  }
}
