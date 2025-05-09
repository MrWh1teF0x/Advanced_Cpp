
template <typename T>
class MyUnique {
 public:
  T& operator*() const { return *ptr; }

  T* operator->() const { return ptr; }

  MyUnique(T*&& new_ptr) : ptr(new_ptr) {}

 private:
  T* ptr = nullptr;

  MyUnique(const MyUnique&) = delete;

  MyUnique& operator=(const MyUnique&) = delete;
};

class MyClass {
 public:
  int a;
  MyClass(int v) : a(v) {}
};

template <typename T, typename... Args>
MyUnique<T> MakeUnique(Args... args) {
  return MyUnique<T>{new T(args...)};
}

MyUnique<MyClass> gl_value = new MyClass(3);
// MyUnique<MyClass> other_value = other_ptr;
// MyUnique<int> value2 = value;
auto made_ptr = MakeUnique<MyClass>(20);

class OtherClass {
 public:
  MyUnique<MyClass> value = new MyClass(3);
};

int main() {
  const OtherClass smth;
  auto val = smth.value->a;
  smth.value->a = 7;
  (*gl_value).a = 10;
  gl_value->a = 6;
}