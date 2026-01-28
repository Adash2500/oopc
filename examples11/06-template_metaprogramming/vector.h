#ifndef __VECTOR_H__
#define __VECTOR_H__
#include <cstring>
#include <limits>
#include <tuple>
#include <type_traits>

template <class C> class vector {
  C *data;
  unsigned int size;
  unsigned int cap;

private:
  static unsigned int round_up_to_power_of_2(unsigned w) {
    constexpr auto bits = std::numeric_limits<unsigned>::digits;
    --w;
    for (unsigned s = 1; s < bits; s *= 2)
      w |= w >> s;
    return ++w;
  };

  void destroy_array(C *ptr, unsigned int s) {
    for (unsigned j = 0; j < s; ++j)
      (ptr + j)->~C();
    free(ptr);
  }

  void reserve_internal(unsigned capacity) {
    unsigned int newcap = capacity;
    C *newdata;
    if constexpr (!std::is_trivially_copyable<C>()) {
      newdata =
          static_cast<C *>(std::aligned_alloc(alignof(C), newcap * sizeof(C)));
      if (!newdata)
        throw bad_alloc();
      unsigned i;
      try {
        for (i = 0; i < size; i++)
          if constexpr (noexcept(C(std::move(data[i]))))
            new (newdata + i) C(std::move(data[i]));
          else
            new (newdata + i) C(data[i]);
      } catch (...) {
        destroy_array(newdata, i);
        throw;
      }
      destroy_array(data, size);
    } else {
      newdata = static_cast<C *>(std::realloc(data, newcap * sizeof(C)));
      if (!newdata)
        throw bad_alloc();
    }
    data = newdata;
    cap = newcap;
  }

  void resize_before_push() {
    if (size >= cap) {
      if (cap > std::numeric_limits<decltype(size)>::max() / (2 * sizeof(C)))
        throw length_error("Vector too long");
      reserve_internal((cap == 0) ? 1 : 2 * cap);
    }
  }

public:
  class index_out_of_range {};
  explicit vector(unsigned s) {

    cap = round_up_to_power_of_2(s);
    if (s == 0) {
      size = 0;
      cap = 0;
      data = 0;
      return;
    }

    data = static_cast<C *>(std::aligned_alloc(alignof(C), cap * sizeof(C)));
    if (!data)
      throw bad_alloc();
    size = s;

    unsigned i;
    try {
      for (i = 0; i < size; i++)
        new (data + i) C();
    } catch (...) {
      destroy_array(data, i);
      throw;
    }
  }

  ~vector() { destroy_array(data, size); }

  C &operator[](unsigned int pos) {
    if (pos >= size)
      throw index_out_of_range();
    return data[pos];
  }

  C operator[](unsigned int pos) const {
    if (pos >= size)
      throw index_out_of_range();
    return data[pos];
  }

  vector(const vector<C> &s) {
    cap = s.cap;
    data = static_cast<C *>(std::aligned_alloc(alignof(C), cap * sizeof(C)));
    if (!data)
      throw bad_alloc();
    size = s.size;
    unsigned i;
    try {
      for (i = 0; i < size; i++)
        new (data + i) C(s.data[i]);
    } catch (...) {
      destroy_array(data, i);
      throw;
    }
  }

  void swap(vector<C> &s) noexcept {
    C *t1 = s.data;
    unsigned int t2 = s.size;
    unsigned int t3 = s.cap;
    s.data = data;
    s.size = size;
    data = t1;
    size = t2;
    cap = t3;
  }

  vector<C> &operator=(const vector<C> &s) {
    if (this == &s)
      return *this;
    vector<C> n(s);
    swap(n);
    return *this;
  }
  friend ostream &operator<<(ostream &o, const vector<C> &v) {
    o << '[';
    for (unsigned i = 0; i < v.size; i++) {
      o << v[i];
      if (i != v.size - 1)
        o << ',';
    };
    o << ']';
    return o;
  }

  template <class... Args> C &emplace_back(Args &&...args) {
    //    cout << "emplace_back" << endl;
    resize_before_push();
    new (data + size) C(std::forward<Args>(args)...);
    return *(data + size++);
  }

private:
public:
  void reserve(unsigned capacity) {
    if (capacity > std::numeric_limits<decltype(size)>::max() / (2 * sizeof(C)))
      throw length_error("Vector too long");
    unsigned int cap_rounded_up = round_up_to_power_of_2(capacity);
    reserve_internal(cap_rounded_up);
  }

  template <class T> std::tuple<C &> push_back(T &&s) {
    C &r = emplace_back(std::forward<T>(s));
    return std::tuple<C &>(r);
  }

  template <class T, class... Args> auto push_back(T &&a, Args &&...args) {
    auto op1 = push_back(std::forward<T>(a));
    auto op2 = push_back(std::forward<Args>(args)...);
    return std::tuple_cat(op1, op2);
  }
};
#endif /* __VECTOR_H__ */
