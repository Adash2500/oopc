#include <iostream>
#include <stddef.h>

class List {
    struct BaseNode {
        BaseNode* prev;
        BaseNode* next;
    };

    struct Node : public BaseNode {
        int data;
    };

    BaseNode FirstLast{.prev = &FirstLast, .next = &FirstLast};

  public:
    //  List() {
    //    FirstLast.next = &FirstLast;
    //    FirstLast.prev = &FirstLast;
    //  };

    ~List()
    {
        BaseNode* ptr = FirstLast.next;
        while (ptr != &FirstLast) {
            BaseNode* next = ptr->next;
            delete ptr;
            ptr = next;
        }
    }

    class Iterator {
        BaseNode* ptr;

      public:
        Iterator(BaseNode* p) : ptr(p){};

        int& operator*()
        {
            return static_cast<Node*>(ptr)->data;
        }
        Iterator& operator++()
        {
            ptr = ptr->next;
            return *this;
        }
        bool operator!=(const Iterator& o)
        {
            return ptr != o.ptr;
        }
        friend class List;
    };

    void insert(Iterator i, int v)
    {
        Node* n = new Node;
        n->prev = i.ptr->prev;
        n->next = i.ptr;
        i.ptr->prev->next = n;
        i.ptr->prev = n;
        n->data = v;
    }

    Iterator begin()
    {
        return Iterator(FirstLast.next);
    };
    Iterator end()
    {
        return Iterator(&FirstLast);
    };
};

int main()
{
    List c;
    c.insert(c.begin(), 1);
    c.insert(c.begin(), 2);
    c.insert(c.begin(), 3);

    for (auto i : c)
        std::cout << i << std::endl;
}
