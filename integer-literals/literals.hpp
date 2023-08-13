#pragma once

/*
  should be similar to
  https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2019/p1280r2.html
  example: 123_u32
  the underscore is kinda needed, try it without,
  gcc and clang should yell at you
*/

#include <cstdint>
#include <limits>

#define IVL_GEN(type, suffix)                                                  \
  consteval std::type operator"" _##suffix(unsigned long long arg) { \
    if (arg < std::numeric_limits<std::type>::min() ||                    \
        arg > std::numeric_limits<std::type>::max()){                   \
      throw "ivl::integer_literals type=" #type ", suffix=" #suffix ": value outside of range";    \
    }\
    return static_cast<std::type>(arg);\
  }

namespace ivl::integer_literals {

  namespace exact {
    IVL_GEN(uint64_t, u64)
    IVL_GEN(uint32_t, u32)
    IVL_GEN(uint16_t, u16)
    IVL_GEN(uint8_t, u8)

    IVL_GEN(int64_t, i64)
    IVL_GEN(int32_t, i32)
    IVL_GEN(int16_t, i16)
    IVL_GEN(int8_t, i8)
  } // namespace exact

  namespace least {
    IVL_GEN(uint_least64_t, u64)
    IVL_GEN(uint_least32_t, u32)
    IVL_GEN(uint_least16_t, u16)
    IVL_GEN(uint_least8_t, u8)

    IVL_GEN(int_least64_t, i64)
    IVL_GEN(int_least32_t, i32)
    IVL_GEN(int_least16_t, i16)
    IVL_GEN(int_least8_t, i8)
  } // namespace exact

} // namespace ivl::integer_literals

#undef IVL_GEN
