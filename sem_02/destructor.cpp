#include <iostream>

class MyClassInterface {
 public:
  MyClassInterface() {}

  virtual ~MyClassInterface() { std::cout << "MyClassInterface\n"; }

  virtual void func() = 0;

 private:
};

class SecondInterfaceClass {
 public:
  SecondInterfaceClass() {}

  virtual ~SecondInterfaceClass() { std::cout << "SecondInterfaceClass\n"; }

  virtual void func2() = 0;

 private:
};

class Derived : public MyClassInterface, public SecondInterfaceClass {
 public:
  Derived() {}

  ~Derived() { std::cout << "Derived\n"; }

  void func() override {}

  void func2() override {}

 private:
};

int main() {
  Derived* d = new Derived();

  delete d;

  MyClassInterface* ptr = new Derived;

  delete ptr;
}