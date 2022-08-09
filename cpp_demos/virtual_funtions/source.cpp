#include <iostream>

class Base1 {
 public:
  int base1_1;
  int base1_2;

  virtual void __cdecl base1_fun(int x) {
    std::cout << "Base1::base1_fun(" << x << ")\n";
  }
};

class Base2 {
 public:
  int base2_1;

  virtual void __cdecl base2_fun(int x) {
    std::cout << "Base2::base2_fun(" << x << ")\n";
  }

  int base2_2;
};

class Derive : public Base1, public Base2 {
 public:
  Derive() {
    base1_1 = 11;
    base1_2 = 12;
    base2_1 = 21;
    base2_2 = 22;

    derive1 = 1;
    derive2 = 2;
  }

  int derive1;
  int derive2;

  virtual void __cdecl derive_fun1() {}
  virtual void __cdecl derive_fun2() {}
};

class Derive_Derive : public Derive {
 public:
  virtual void __cdecl derive_fun2() {}
  int ddd;
};

void foo2(Base1* pb1, Base2* pb2, Derive* pd, Derive_Derive* pdd) {}

void foo(Base1* pb1, Base2* pb2, Derive* pd) {
  /*
  std::cout << "--------------------------------------" << std::endl;
  std::cout << "pb1:\n"
    << "\t&pb1->base1_1  : " << &pb1->base1_1 << "\n"
    << "\t&pb1->base1_2  : " << &pb1->base1_2 << "\n"
    << "\t&pb1->base1_fun: " << &pb1->base1_fun << "\n"
    << std::endl;
  std::cout << "-------------------------------------" << std::endl;*/

  std::cout << "Base1:\n"
            << "\tbase1_1 = " << pb1->base1_1 << "\n"
            << "\tbase1_2 = " << pb1->base1_2 << "\n"
            << std::endl;

  std::cout << "Base2:\n"
            << "\tbase2_1 = " << pb2->base2_1 << "\n"
            << "\tbase2_2 = " << pb2->base2_2 << "\n"
            << std::endl;

  std::cout << "Derive:\n"
            << "\tderive1 = " << pd->derive1 << "\n"
            << "\tderive2 = " << pd->derive2 << "\n"
            << std::endl;

  pb1->base1_fun(11);
  pb2->base2_fun(22);

  pd->derive_fun1();
  pd->derive_fun2();
}

struct Base1_VPTR_VPTR {
  void(__cdecl* base1_fun)(Base1* that, int x);
};

struct Base1_VPTR {
  Base1_VPTR_VPTR* pvptr;
  int base1_1;
  int base1_2;
};

struct Base2_VPTR_VPTR {
  void(__cdecl* base2_fun)(Base2* that, int x);
};

struct Base2_VPTR {
  Base2_VPTR_VPTR* pvptr;
  int base2_1;
  int base2_2;
};

void __cdecl base1_fun(Base1* that, int x) { std::cout << x << std::endl; }

void __cdecl base2_fun(Base2* that, int x) { std::cout << x << std::endl; }

struct Derive_C {
  Base1_VPTR base1;
  Base2_VPTR base2;

  int derive1;
  int derive2;
};

class Test1 {
 public:
  int a;
  int b;
  virtual void f1() {}
  virtual void f2() {}
};

int main() {
  Base1 b1;
  std::cout << "offsetof Base1::base1_1 = " << (int)&b1.base1_1 - (int)&b1
            << std::endl;

  Derive d1;
  std::cout << "offsetof Derive::derive2 = " << (int)&d1.derive2 - (int)&d1
            << std::endl;

  Derive_Derive ddd;
  std::cout << "offsetof DD::ddd = " << (int)&ddd.ddd - (int)&ddd << std::endl;
  foo2(&ddd, &ddd, &ddd, &ddd);

  Test1 test1;
  Test1 test2;

  // ͬһ�����͵Ĳ�ͬ������麯������ַ��ͬ
  // std::cout << *(int*)&test1 << std::endl;
  // std::cout << *(int*)&test2 << std::endl;

  std::cout << "sizeof(Base1  ) = " << sizeof(Base1) << std::endl;
  std::cout << "sizeof(Base2  ) = " << sizeof(Base2) << std::endl;
  std::cout << "sizeof(Test1   ) = " << sizeof(Test1) << std::endl;
  std::cout << "sizeof(Derive  ) = " << sizeof(Derive) << std::endl;
  std::cout << "sizeof(Derive_C) = " << sizeof(Derive_C) << std::endl;

  Derive dd;
  foo(&dd, &dd, &dd);
  dd.derive_fun1();

  Derive_C d;
  Base1_VPTR_VPTR base1_vptr_vptr;
  Base2_VPTR_VPTR base2_vptr_vptr;

  base1_vptr_vptr.base1_fun = base1_fun;
  base2_vptr_vptr.base2_fun = base2_fun;

  d.base1.base1_1 = 11;
  d.base1.base1_2 = 12;
  d.base1.pvptr = &base1_vptr_vptr;

  d.base2.base2_1 = 21;
  d.base2.base2_2 = 22;
  d.base2.pvptr = &base2_vptr_vptr;

  d.derive1 = 1;
  d.derive2 = 2;

  foo((Base1*)&d.base1, (Base2*)&d.base2, (Derive*)&d);

  return 0;
}