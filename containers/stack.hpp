#ifndef STACK_HPP
# define STACK_HPP

# include "vector.hpp"

namespace ft
{
  template <typename T, class Container = ft::vector<T> >
  class stack
  {
    public:
    /* Member types */
    typedef T           value_type;
    typedef Container   container_type;
    typedef size_t      size_type;

    /* Member functions */
    explicit stack(const container_type& ctnr = container_type()) {}

    bool                empty() const {}
    size_type           size() const {}
    value_type&         top() {}
    const value_type&   top() const {}
    void                push(const value_type& val) {}
    void                pop() {}
    void                swap(stack& x) noexcept() {}

    template <class... Args>
    void                emplace(Args&&... args) {}

    private: 
  };
}

#endif