class Storable {
  public:
    virtual ~Storable(){};
};

class Component : public virtual Storable { /* ... */
};
class Receiver : public Component { /* ... */
};
class Transmitter : public Component { /* ... */
};
class Radio : public Receiver, public Transmitter { /* ... */
};

int main()
{
    Radio r;

    Storable* s = &r;

    Transmitter* t = dynamic_cast<Transmitter*>(&r);

    Component* c = t;

    Radio* rptr = dynamic_cast<Radio*>(c);
}
