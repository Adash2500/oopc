
class a {};

class b : virtual public a {};

class c : virtual public a {};

class d : public b, public c, virtual public a {};

class e : public virtual b, public virtual d {};

class f : public virtual e, public virtual b {};
