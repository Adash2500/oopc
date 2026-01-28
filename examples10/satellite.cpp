#include <iostream>
using namespace std;

struct Task
{
  int next_event_time;
  void execute(){};
  virtual void get_debug(){ cout << "Task" << endl;};
  virtual int f(int){};
};

struct Displayed
{
  int x;
  int y;
  int z;
  int rotx;
  int roty;
  int rotz;
  virtual void draw(){};
  virtual void get_debug(){cout << "Displayed" << endl;};
  double f(double){};
};


struct Satellite : public Task, public Displayed
{
  double uplink_frequency;
  double downlink_frequency;
  void transmit();
  using Displayed::f;
  using Task::f;
  virtual void get_debug(){cout << "Satellite" << endl;};
};


struct Test {
   int a;
   double b;
};


int main()
{
  cout << sizeof(Task) << endl;
  cout << sizeof(Displayed) << endl;
  cout << sizeof(Satellite) << endl;

  Satellite s;
  Satellite* sptr = &s;

  cout << (char*)(&(sptr->next_event_time)) - (char*)sptr << endl;
  cout << (char*)(&(sptr->x)) - (char*)sptr << endl;
  cout << (char*)(&(sptr->rotz)) - (char*)sptr << endl;
  cout << (char*)(&(sptr->uplink_frequency)) - (char*)sptr << endl;


  cout << offsetof(Test, b) << endl;

  Task* tptr = sptr;
  Displayed* dptr = sptr;

  cout << sptr << "," << tptr << "," << dptr << endl;

  return 1;

  tptr -> get_debug();
  dptr -> get_debug();

  sptr -> get_debug();

  sptr -> f(1);
  return 0;
}


