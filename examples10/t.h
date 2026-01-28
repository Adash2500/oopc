#include <iostream>
using namespace std;

class Task {
  public:
    virtual void get_debug()
    {
        cout << "Task::get_debug()" << endl;
    };
    virtual ~Task(){};
};

class Displayed {
  public:
    virtual void get_debug()
    {
        cout << "Displayed::get_debug()" << endl;
    };
    virtual ~Displayed(){};
};
