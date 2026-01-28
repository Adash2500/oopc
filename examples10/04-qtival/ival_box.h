#ifndef IVAL_BOX_H
#define IVAL_BOX_H

class Ival_box {
  public:
    virtual int get_value() = 0;
    virtual void set_value(int i) = 0;
    virtual void reset_value(int i) = 0;
    virtual void prompt() = 0;
    virtual bool was_changed() const = 0;
    virtual ~Ival_box() {}
};

#endif /* IVAL_BOX_H */