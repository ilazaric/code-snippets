#include <iostream>


namespace MintSimple {
  // Base should be able to contain 2*(Mod-1)
  // MulBase should be able to contain (Mod-1)*(Mod-1)
  template<typename Base, typename MulBase, Base Mod>
  struct GeneralMint {
    Base value;

    GeneralMint() = default;
    
    template<typename T>
    explicit GeneralMint(T x) : value((Base)(x < 0 ? x % Mod + Mod : x % Mod)){}

    template<typename T>
    static inline GeneralMint unsafe(T t){
      GeneralMint m;
      m.value = t;
      return m;
    }

    inline friend GeneralMint operator+(GeneralMint a, GeneralMint b){
      a.value += b.value;
      if (a.value >= Mod) a.value = (Base)(a.value-Mod);
      return a;
    }

    inline friend GeneralMint operator-(GeneralMint a, GeneralMint b){
      a.value = (Base)(a.value < b.value ? a.value + (Mod-b.value) : a.value-b.value);
      return a;
    }

    inline friend GeneralMint operator*(GeneralMint a, GeneralMint b){
      a.value = (Base)((MulBase)a.value * b.value % Mod);
      return a;
    }

    inline friend GeneralMint operator+=(GeneralMint &a, GeneralMint b){
      return a = a + b;
    }

    inline friend GeneralMint operator-=(GeneralMint &a, GeneralMint b){
      return a = a - b;
    }

    inline friend GeneralMint operator*=(GeneralMint &a, GeneralMint b){
      return a = a * b;
    }

    inline friend std::ostream &operator<<(std::ostream &out, GeneralMint x){
      return out << x.value;
    }
  };

  // a lot faster using unsigned
  template<int Mod>
  using mint = GeneralMint<unsigned int, unsigned long long, Mod>;
}
