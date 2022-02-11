#ifndef UTILS_HPP
# define UTILS_HPP

namespace ft
{
  // ft::less
  template <typename T>
  struct less
  {
    bool  operator()(const T& x, const T& y) const {
      return (x < y);
    }
  };
}

#endif