#ifndef MAP_HPP
# define MAP_HPP

# include <stdexcept> // std::allocator

# include "../iterators/map_iterator.hpp"
# include "../iterators/map_reverse_iterator.hpp"
# include "../utils/utils.hpp" // ft::less

namespace ft
{
  template < class Key, class T, class Compare = ft::less<Key>, class Alloc = std::allocator<std::pair<const Key, T> >
  > class map
  {
    public:
      /* Member types */
      typedef Key                               key_type;
      typedef T                                 mapped_type;
      typedef Compare                           key_compare;
      typedef std::pair<key_type, mapped_type>  value_type;
      typedef Alloc                             allocator_type;
      typedef value_type&                       reference;
      typedef const value_type&                 const_reference;
      typedef value_type*                       pointer;
      typedef const value_type*                 const_pointer;
      typedef long int                          difference_type;
      typedef size_t                            size_type;
      typedef typename ft::map_iterator<Key, T, Compare, Node, false> iterator;
      typedef typename ft::map_iterator<Key, T, Compare, Node, true>  const_iterator;
      typedef typename ft::map_reverse_iterator<Key, T, Compare, Node, false> reverse_iterator;
      typedef typename ft::map_reverse_iterator<Key, T, Compare, Node, true>  const_reverse_iterator;
      class value_compare 
      : public std::binary_function<value_type, value_type, bool>
      {
        protected:
          key_compare     comp;
          value_compare(key_compare compare) : comp(compare) {}
        
        public:
          typedef bool          result_type;
          typedef value_type    first_argument_type;
          typedef value_type    second_argument_type;

          bool  operator()(const value_type& x, const value_type& y) const
          {
            return comp(x.first, y.first);
          }
      }


    private: 
      /* Node Attributes */
      struct Node
      {
        std::pair<const Key, T>   content;
        Node*                     parent;
        Node*                     left;
        Node*                     right;
      };

      Node*                       root;
      Node*                       last;
      size_type                   size;
      allocator_type              alloc;
      key_compare                 comp;
      std::allocator<Node>        allocNode;


    public:
      /* Member functions */
      // 1. Copilien form
      // defalut constructor
      explicit map(const key_compare& compare = key_compare(), const allocator_type& allocator = allocator_type())
      : size(0), alloc(allocator), comp(compare)
      {
        last = createNode(std::pair<const key_type, mapped_type>());
        root = last;
        last->left = last;
        last->right = last;
      }

      // range constructor
      template <class InputIterator>
      map(
        InputIterator first, InputIterator last, 
        const key_compare& comp = key_compare(), 
        const allocator_type& alloc = allocator_type(),
        typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type* = 0
      )
      : size(0), alloc(alloc), comp(comp)
      {
        last = createNode(std::pair<const key_type, mapped_type>());
        root = last;
        last->left = last;
        last->right = last;

        while (first != last)
        {
          insert(*first);
          ++first;
        }
      }

      // copy constructor
      map(const map& x)
      : size(0), alloc(x.alloc), comp(x.comp)
      {
        last = createNode(std::pair<const key_type, mapped_type>());
        root = last;
        last->left = last;
        last->right = last;

        const_iterator it = x.begin();
        while (it != x.end())
        {
          insert(*it);
          ++it;
        }
      }

      ~map() {
        clear();
        deallocateNode(last);
      }

      map&      operator=(const map& x) {
        map tmp(x);
        swap(tmp);

        return (*this);
      }

      // 2. Iterators
      iterator                begin() {}
      const_iterator          begin() const {}
      iterator                end() {}
      const_iterator          end() const {}
      reverse_iterator        rbegin() {}
      const_reverse_iterator  rbegin() const {}
      reverse_iterator        rend() {}
      const_reverse_iterator  rend() const {}

      // 3. Capacity
      bool                    empty() const {}
      size_type               size() const {}
      size_type               max_size() const {}

      // 4. Element access
      mapped_type&    operator[](const key_type& k) {}

      // 5. Modifiers
      pair<iterator,bool>     insert(const value_type& val) {}
      iterator                insert(iterator position, const value_type& val) {}

      template <class InputIterator>
      void                    insert(InputIterator first, InputIterator last) {}

      void                    erase(iterator position) {}
      size_type               erase(const key_type& k) {}
      void                    erase(iterator first, iterator last) {}
      void                    swap(map& x) {}
      void                    clear() {}

      // 6. Observers
      key_compare             key_comp() const {}
      value_compare           value_comp() const {}

      // 7. Operations
      iterator                find(const key_type& k) {}
      const_iterator          find(const key_type& k) const {}
      size_type               count(const key_type& k) const {}
      iterator                lower_bound(const key_type& k) {}
      const_iterator          lower_bound(const key_type& k) const {}
      iterator                upper_bound(const key_type& k) {}
      const_iterator          upper_bound(const key_type& k) const {}
      pair<const_iterator,const_iterator>   equal_range(const key_type& k) const {}
      pair<iterator,iterator>               equal_range(const key_type& k) {}

      // 8. Allocator
      allocator_type          get_allocator() const {}
  };
}

#endif