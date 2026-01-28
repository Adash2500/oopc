#ifndef __ASSOCTAB_H__
#define __ASSOCTAB_H__
#include <string.h>

class assocTab {
  private:
    struct node {
        node* next;
        char* key;
        int val;
        node(const char* k) : next(NULL)
        {
            key = new char[strlen(k) + 1];
            strcpy(key, k);
        };
        ~node()
        {
            delete[] key;
        }
        node(const node& s) : next(NULL)
        {
            if (s.key == NULL)
                key = NULL;
            else {
                key = new char[strlen(s.key) + 1];
                strcpy(key, s.key);
            }
            val = s.val;
        };

      private: // assignment not allowed
        node& operator=(const node&);
    };
    node* head;
    void insert(const char* key, int value);
    void clear();
    node* find(const char* key) const;
    void swap(assocTab& l);

  public:
    assocTab();
    assocTab(const assocTab& l);
    assocTab& operator=(const assocTab& l);
    ~assocTab();
    int& operator[](const char*);
};

#endif /* __ASSOCTAB_H__ */
