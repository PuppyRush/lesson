class A
{
public:
    int x;
    A(int x = 1) : x(x) {} // user-defined default ctr
};

class B : A
{
    B() = default;
    // B::B() is implicitly-defined, calls A::A()
};

class C
{
public:
    A a;
    // C::C() is implicitly-defined, calls A::A()
};

class D : A
{
public:
    D(int y) : A(y) {}
    // D::D() is not declared because another conclassor exists
};

class E : A
{
public:
    E(int y) : A(y) {}
    E() = default; // explicitly defaulted, calls A::A()
};

class F
{
public:
    int& ref; // reference member
    const int c; // const member
    // F::F() is implicitly defined as deleted
};

class G
{
    G() = delete;
};

int main()
{
    A a;
    //B b;   // compile error
    C c;
    //  D d; // compile error
    E e;
    //  F f; // compile error
}