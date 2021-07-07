#ifndef _LIST_HPP_
#define _LIST_HPP_

#include <memory>

#ifdef FOR_TEST
  #include <vector>
  using std::vector;
#endif

namespace ll {

namespace algorithm {

template<typename Type>
class Node {
 public:
  Node()
    : next { nullptr } {}
  Node(Type d) 
    : data { d },
      next { nullptr } {}
  virtual ~Node() = default;

  Type data;
  Node<Type>* next;
};

template<typename Type>
class DoublyNode {
 public:
  DoublyNode()
    : next { nullptr },
      pre { nullptr } {}

  DoublyNode(Type d)
    : data { d },
      next { nullptr },
      pre { nullptr } {}

  virtual ~DoublyNode() = default;

  Type data;
  DoublyNode<Type>* next;
  DoublyNode<Type>* pre;
};

template<typename Type>
class List {
 public:
  List() : head { new(std::nothrow) Node<Type> } {}
  List(const List<Type>& rh) {
    if (rh.head) {
      this->head = new(std::nothrow) Node<Type>;
      Node<Type>* rh_node = rh.head;
      this->head->data = rh_node->data;
      this->head->next = rh_node->next;
      rh_node = rh_node->next;
      Node<Type>* tmp = this->head;
      while (rh_node) {
        tmp->next = new(std::nothrow) Node<Type>;
        tmp = tmp->next;
        if (!tmp) {
          break;
        }
        tmp->data = rh_node->data;
        tmp->next = rh_node->next;
        rh_node = rh_node->next;
      }
    }
  }

  // copy and swap 优雅的赋值
  List<Type>& operator=(const List<Type>& rh) {
    List<Type> tmp(rh);
    Swap(tmp);
    return *this;
  }

  List<Type>& operator=(List<Type>&& rh) {
    Swap(rh);
    return *this;
  }

  List(List<Type>&& rh)
    : head { rh.head } {
    rh.head = nullptr;
  }

  virtual ~List() {
    Node<Type>* tmp = this->head;
    while (tmp) {
      Node<Type>* tmp2 = tmp->next;
      delete tmp;
      tmp = tmp2;
    }
    this->head = nullptr;
  }

  void insert(const Type& d, Node<Type>* n) {
    if (!n) {
      return;
    }
    Node<Type>* node = new(std::nothrow) Node<Type>(d);
    node->next = n->next;
    n->next = node;
  }

  void push_back(const Type& d) {
    insert(d, this->head);
  }

  Node<Type>* search(const Type& d) const {
    Node<Type>* tmp = this->head;
    while (tmp) {
      if (tmp->data == d) {
        return tmp;
      }
      tmp = tmp->next;
    }
    return nullptr;
  }

  void erase(Node<Type>* n) {
    if (!n) {
      return;
    }
    // 找到节点的前趋
    Node<Type>* tmp = this->head;
    while (tmp->next != n) {
      tmp = tmp->next;
    }
    tmp->next = n->next;
    delete n;
  }

#ifdef FOR_TEST
  vector<Type> print() {
    // cout << __FILE__ << " " << __FUNCTION__ << " ";
    vector<Type> res;
    if (!head) {
      return res;
    }
    Node<Type>* tmp = this->head->next;
    while (tmp) {
      res.push_back(tmp->data);
      tmp = tmp->next;
    }
    return res;
  }
#endif

 private:
  void Swap(List<Type>& other) noexcept {
    std::swap(this->head, other.head);
  }
  Node<Type>* head;
};

template<typename Type>
class DoublyList {
 public:
  DoublyList() : head { new(std::nothrow) DoublyNode<Type> } {
    head->next = head;
    head->pre = head;
  }

  virtual ~DoublyList() {
    clear();
    delete head;
    head = nullptr;
  }

  DoublyList(const DoublyList<Type>& rh) = delete;
  DoublyList(DoublyList<Type>&& rh) = delete;
  DoublyList& operator=(const DoublyList<Type>& rh) = delete;
  DoublyList& operator=(DoublyList<Type>&& rh) = delete;

  // 摧毁除head外其余节点
  void clear() {
    if (!head) {
      return;
    }
    auto node = head->next;
    while (node && node != head) {
      node = erase(node);
    }
  }

  // 在节点n之后插入一个节点
  void insert(const Type& d, DoublyNode<Type>* n) {
    if (!n) {
      return;
    }
    DoublyNode<Type>* tmp = new DoublyNode<Type>(d);
    tmp->next = n->next;
    tmp->pre = n;
    n->next->pre = tmp;
    n->next = tmp;
  }

  void push_back(const Type& d) {
    insert(d, this->head);
  }

  DoublyNode<Type>* search(const Type& d) {
    if (!head) {
      return nullptr;
    }
    auto node = head->next;
    while (node && node != head) {
      if (node->data == d) {
        return node;
      }
      node = node->next;
    }
    return nullptr;
  }

  DoublyNode<Type>* erase(DoublyNode<Type>* n) {
    if (!n) {
      return nullptr;
    }
    DoublyNode<Type>* res = n->next;
    n->pre->next = n->next;
    n->next->pre = n->pre;
    delete n;
    return res;
  }

#ifdef FOR_TEST
  vector<Type> print() {
    // cout << __FILE__ << " " << __FUNCTION__ << " ";
    vector<Type> res;
    if (!head) {
      return res;
    }
    DoublyNode<Type>* tmp = this->head->next;
    while (tmp != this->head) {
      res.push_back(tmp->data);
      tmp = tmp->next;
    }
    return res;
  }
#endif

 private:
  DoublyNode<Type>* head; // 哨兵
};

}

}

#endif