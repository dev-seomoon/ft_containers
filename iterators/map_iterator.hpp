#ifndef MAP_ITERATOR_HPP
# define MAP_ITERATOR_HPP

namespace ft
{
  // Bydirectional iterator
  template <class Key, class T, class Compare, typename Node, bool isConst>
  class map_iterator
  {
    public:
      /* Member types */
      typedef Key                                     key_type;
      typedef T                                       mapped_type;
      typedef Compare                                 key_compare;
      typedef std::pair<const key_type, mapped_type>   value_type;
      typedef std::bidirectional_iterator_tag         iterator_category;
      typedef long int                                difference_type;
      typedef value_type*                             pointer;
      typedef value_type&                             reference;
      typedef Node*                                   node_pointer;

    private:
      /* Node Attributes & functions */
      node_pointer        n;
      node_pointer        last;
      key_compare         comp;

      node_pointer    searchMaxNode(node_pointer root)
      {
        if (root && root != last && root->right && root->right != last)
          return searchMaxNode(root->right);
        return (root);
      }

      node_pointer    searchMinNode(node_pointer root)
      {
        if (root && root != last && root->left && root->left != last)
          return searchMinNode(root->left);
        return (root);
      }

    public: 
      /* Getters */
      node_pointer        getNode() const 
      {
        return (n);
      }

      node_pointer        getLastElement() const 
      {
        return (last);
      }

      key_compare         getComp() const 
      {
        return (comp);
      }

      /* Member functions */
      // 1. Copilien form
      map_iterator(node_pointer node = 0, node_pointer last_element = 0, const key_compare& compare = key_compare())
      : n(node), last(last_element), comp(compare)
      {
      }

      map_iterator(map_iterator<Key, T, Compare, Node, false>& src)
      {
        n = src.getNode();
        last = src.getLastElement();
        comp = src.getComp();
      }

      ~map_iterator {}

      map_iterator&   operator=(const map_iterator& src)
      {
        if (this != &src)
        {
          n = src.getNode();
          last = src.getLastElement();
          comp = src.getComp();
        }
        return (*this);
      }

      // 2. Operators
      reference         operator*() const 
      {
        return (n->content);
      }

      pointer           operator->() const 
      {
        return (&n->content);
      }

      map_iterator&     operator++()
      {
        node_pointer  prevNode = n;

        if (n == last) 
        {
          n = last->right;
          return (*this);
        }

        while (n != last && !comp(prevNode->content.first, n->content.first))
        {
          if (n->right && (n->right == last || comp(prevNode->content.first, n->right->content.first)))
          {
            n = n->right;
            node_pointer tmp = NULL;
            tmp = searchMinNode(n);
            if (n != last && tmp) {
              n = tmp;
            }
          }
          else
            n = n->parent;
        }

        return (*this);
      }

      map_iterator      operator++(int)
      {
        map_iterator    result(*this);

        if (n == last)
        {
          n = last->right;
          return (result);
        }

        while (n != last && !comp(result->first, n->content.first))
        {
          if (n->right && ( node->right == last || comp(result->first, n->right->content.first)))
          {
            n = n->right;

            node_pointer tmp = NULL;
            tmp = searchMinNode(n);
            if (n != last && tmp)
              n = tmp;
          }
          else
            n = n->parent;
        }

        return (result);
      }

      map_iterator&     operator--()
      {
        node_pointer    prevNode = n;

        if (n == last)
        {
          n = last->left;
          return (*this);
        }

        while (n != last && !comp(n->content.first, prevNode->content.first))
        {
          if (n->left && (n->left == last || comp(n->left->content->first, prevNode->content.first)))
          {
            n = n->left;

            node_pointer tmp = NULL;
            tmp = searchMaxNode(n);
            if (n != last && tmp)
              n = tmp;
          }
          else
            n = n->parent;
        }

        return (*this);
      }

      map_iterator      operator--(int)
      {
        map_iterator    result(*this);

        if (n == last)
        {
          n = last->left;
          return (result);
        }

        while (n != last && !comp(n->content.first, result->first))
        {
          if (n->left && (n->left == last || comp(n->left->content.first, result->first)))
          {
            n = n->left;

            node_pointer tmp = NULL;
            tmp = searchMaxNode(n);
            if (n != last && tmp)
              n = tmp;
          }
          else
            n = n->parent;
        }

        return (result);
      }
  };
}

#endif