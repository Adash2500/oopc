#include "ival_box.h"

#include <iostream>
using namespace std;

#include <QtGui>

class Text_ival_box : public Ival_box {
  private:
    int lastval = 0;
    int val = 0;

  public:
    virtual int get_value()
    {
        cin >> val;
        lastval = val;
        return val;
    };
    virtual void set_value(int i)
    {
        val = i;
    };
    virtual void reset_value(int i)
    {
        val = i;
        lastval = i;
    };
    virtual void prompt()
    {
        cout << "Current value=" << val << " Input new value:" << endl;
    };
    virtual bool was_changed() const
    {
        return val != lastval;
    };
};
