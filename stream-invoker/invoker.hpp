#pragma once

#include <utility>

namespace ivl {

  template<typename Callable>
  struct StreamInvoker {
    Callable callable;

    constexpr StreamInvoker(Callable&& callable) : callable(std::forward<Callable>(callable)) {}

    StreamInvoker(const StreamInvoker&) = delete;
    StreamInvoker(StreamInvoker&&) = delete;

    StreamInvoker& operator=(const StreamInvoker&) = delete;
    StreamInvoker& operator=(StreamInvoker&&) = delete;

    constexpr ~StreamInvoker() = default;

    template<typename IArg>
    constexpr StreamInvoker& operator<<(IArg&& arg){
      callable(std::forward<IArg>(arg));
      return *this;
    }
  };

#define IVL_STREAM_INVOKER2(arg, expr) ::ivl::StreamInvoker{[&](auto&& arg){expr;}}
#define IVL_STREAM_INVOKER(expr) IVL_STREAM_INVOKER2(arg, expr)
  
} // namespace ivl
