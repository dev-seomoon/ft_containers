#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

namespace ft
{
  // Random-access iterator
  template<typename T, bool Const>
  class vector_iterator
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
      vector_iterator(): _value(0) {}
      vector_iterator(pointer value): _value(value) {}
      vector_iterator(const vector_iterator& other): _value(other._value) {}
      ~vector_iterator() {}

      // 2. Operators:
      vector_iterator   &operator=(const vector_iterator& other)
      {
        _value = other._value;
        return (*this);
      }

      reference         operator*() { return (*_value); }
      pointer           operator->() { return (_value); }
      reference         operator[](int index) { return (*(_value + index)); }
      vector_iterator   operator++(int) {
        vector_iterator tmp(*this);
        ++(*this);
        return (tmp);
      }
      vector_iterator   operator--(int) {
        vector_iterator tmp(*this);
        --(*this);
        return (tmp);
      }
      bool              operator==(const vector_iterator& other) { 
        return (_value == otehr._value);
      }
      bool              operator!=(const vector_iterator& other) {
        return (_value != other._value);
      }
      bool              operator<(const vector_iterator& other) {
        return (_value < other._value);
      }
      bool              operator<=(const vector_iterator& other) {
        return (_value <= other._value);
      }
      bool              operator>(const vector_iterator& other) {
        return (_value > other._value);
      }
      bool              operator>=(const vector_iterator& other) {
        return (_value >= other._value);
      }
      vector_iterator   operator+(int num) {
        vector_iterator tmp(*this);
        return (tmp += value);
      }
      vector_iterator   operator-(int num) {
        vector_iterator tmp(*this);
        return (tmp -= value);
      }
      vector_iterator   operator+=(int num) {
        _value += num;
        return (*this);
      }
      vector_iterator   operator-=(int num) {
        _value -= num;
        return (*this);
      }
  };
}

#endif