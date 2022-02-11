#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

namespace ft
{
  // Random-access reverse iterator
  template<typename T, bool Const>
  class reverse_iterator
  {
    public:
    /* Member types */
      typedef std::random_access_iterator_tag   iterator_category;
      typedef T                                 value_type;
      typedef long int                          difference_type;
      typedef T*                                pointer;
      typedef T&                                reference;

    private:
      pointer _value;
    
    public:
      /* Member functions */
      // 1. Copilien form:
      reverse_iterator(): _value(0) {}
      reverse_iterator(pointer value): _value(value) {}
      reverse_iterator(const vector_iterator& other): _value(other._value) {}
      ~reverse_iterator() {}

      //2. Operators:
      reference           operator*() {
        reverse_iterator  tmp(*this);
        --tmp;
        return (*tmp);
      }
      pointer             operator->() {
        reverse_iterator  tmp(*this);
        --tmp;
        return (&(*tmp)); 
      }
      reverse_iterator&   operator++() { 
        --(*this);
        return (*this);
      }
      reverse_iterator&   operator--() {
        ++(*this);
        return (*this);
      }
      reverse_iterator    operator++(int) {
        reverse_iterator  tmp(*this);
        ++(*this);
        return (tmp);
      }
      reverse_iterator    operator--(int) {
        reverse_iterator  tmp(*this);
        --(*this);
      }
  };
}

#endif