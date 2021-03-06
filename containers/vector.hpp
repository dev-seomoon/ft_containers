#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <stdexcept>

# include "../iterators/vector_iterator.hpp"
# include "../iterators/reverse_iterator.hpp"

namespace ft
{
  template <typename T, class Alloc = std::allocator<T> >
  class vector
  {
    public:
    /* Member types */
    typedef T           value_type;
    typedef Alloc       allocator_type;
    typedef T&          reference;
    typedef const T&    const_reference;
    typedef T*          pointer;
    typedef const T*    const_pointer;
    typedef long int    diffrence_type;
    typedef size_t      size_type;

    typedef typename ft::vector_iterator<T, false>      iterator;
    typedef typename ft::vector_iterator<T, true>       const_iterator;
    typedef typename ft::rev_vector_iterator<T, false>  reverse_iterator;
    typedef typename ft::rev_vector_iterator<T, true>   const_reverse_iterator;

    /* Member functions */
    // 1. Copilien form:
    explicit vector(const allocator_type& alloc = allocator_type()) {}

    explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) {}

    template <class InputIterator>
    vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()) {}

    vector(const vector& x) {}

    // 2. Iterators:
    iterator                begin() {}
    const_iterator          begin() const {}
    iterator                end() {}
    const_iterator          end() const {}
    reverse_iterator        rbegin() {}
    const_reverse_iterator  rbegin() const {}
    reverse_iterator        rend() {}
    const_reverse_iterator  rend() const {}

    // 3. Capacity:
    size_type               size() const {}
    size_type               max_size() const {}
    void                    resize(size_type n, value_type val = value_type()) {}
    size_type               capacity() const {}
    bool                    empty() const {}
    void                    reserve(size_type n) {}

    // 4. Element access:
    reference               operator[](size_type n) {}
    const_reference         operator[](size_type n) const {}
    reference               at(size_type n) {}
    const_reference         at(size_type n) const {}
    reference               front() {}
    const_reference         front() const {}
    reference               back() {}
    const_reference         back() const {}

    // 5. Modifiers:
    template <class InputIterator>
    void              assign(InputIterator first, InputIterator last) {}

    template <class InputIterator>
    void              insert (iterator position, InputIterator first, InputIterator last) {}
    
    void              assign(size_type n, const value_type& val) {}
    void              push_back (const value_type& val) {}
    void              pop_back() {}
    iterator          insert(iterator position, const value_type& val) {}
    void              insert(iterator position, size_type n, const value_type& val) {}
    iterator          erase(iterator position) {}
    iterator          erase(iterator first, iterator last) {}
    void              swap (vector& x) {}
    void              clear() {}

    // 6. Allocator: 
    allocator_type    get_allocator() const {}
  };
}

#endif