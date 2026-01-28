#include <iostream>
using namespace std;

class Link {
  public:
    Link* next;
    virtual void Print() = 0;
};

class Displayed : public Link {
    string name;

  public:
    Displayed(string n) : name(n){};
    void Print() override
    {
        cout << name << endl;
    };
};

class Task : public Link {
    string name;

  public:
    Task(string n) : name(n){};
    void Print() override
    {
        cout << name << endl;
    };
};

class Satellite : public Task, public Displayed {
  public:
    Satellite(string n) : Task("Task:" + n), Displayed("Displayed:" + n){};
    void Print() override
    {
        Task::Print();
        Displayed::Print();
    };
};

Link* insert(Link* list, Link* node)
{
    node->next = list;
    return node;
}

int main()
{
    Link* displayedList = NULL;
    displayedList = insert(displayedList, new Displayed("a"));
    displayedList = insert(displayedList, new Displayed("b"));

    Satellite* s = new Satellite("e");
    Displayed* sd = s;

    displayedList = insert(displayedList, sd);

    Link* taskList = NULL;
    taskList = insert(taskList, new Task("c"));
    taskList = insert(taskList, new Task("d"));

    Task* st = s;
    taskList = insert(taskList, st);

    Link* iterator = displayedList;

    while (iterator) {
        iterator->Print();
        iterator = iterator->next;
    }

    iterator = taskList;

    while (iterator) {
        iterator->Print();
        iterator = iterator->next;
    }
}
