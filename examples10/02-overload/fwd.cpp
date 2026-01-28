class Task {
  public:
    void run();
};

class Displayed {
  public:
    void draw();
};

class Satellite {
    Task t;
    Displayed d;

  public:
    void run()
    {
        t.run();
    }
    void draw()
    {
        d.draw();
    }
};
