#include <iostream>

template <typename T>
class CRTPBase {
 public:
  void f() { static_cast<T*>(this)->g(); }

  ~CRTPBase() {}
};

class CRTPDerived : public CRTPBase<CRTPDerived> {
  int a;

 public:
  void g() { a = 0; }
};

class CRTPDerivedOther : public CRTPBase<CRTPDerivedOther> {
  float a;

 public:
  void g() {}
};

int main() {
  // CRTPDerivedOther crtp;
  // crtp.f();

  CRTPBase<int>* ptr;

  delete ptr;
}