#ifndef __VECTOR_H__
#define __VECTOR_H__

class vector {
    int* dane;
    unsigned int size;

  public:
    vector(int s)
    {
        dane = new int[s];
        size = s;
        for (unsigned i = 0; i < size; i++)
            dane[i] = 0;
    }
    ~vector()
    {
        delete[] dane;
    }
    int& operator[](unsigned int pos)
    {
        if (pos >= size)
            abort();
        return dane[pos];
    }
    int operator[](unsigned int pos) const
    {
        if (pos >= size)
            abort();
        return dane[pos];
    }

    vector(const vector& s)
    {
        dane = new int[s.size];
        size = s.size;
        for (unsigned i = 0; i < size; i++)
            dane[i] = s.dane[i];
    }
    vector& operator=(const vector& s)
    {
        if (this == &s)
            return *this;
        delete[] dane;
        dane = new int[s.size];
        size = s.size;
        for (unsigned i = 0; i < size; i++)
            dane[i] = s.dane[i];
        return *this;
    }
    friend ostream& operator<<(ostream& o, const vector& v)
    {
        o << '[';
        for (unsigned i = 0; i < v.size; i++) {
            o << v[i];
            if (i != v.size - 1)
                o << ',';
        };
        o << ']';
        return o;
    }
};
#endif /* __VECTOR_H__ */
