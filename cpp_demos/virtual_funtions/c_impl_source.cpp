#include <iostream>

class Base1 {
 public:
  Base1() : base1_1(11) {}
  int base1_1;
  virtual void __stdcall base1_fun1() {
    std::cout << "Base1::base1_fun1()" << std::endl;
  }
};

class Base2 {
 public:
  Base2() : base2_1(21) {}
  int base2_1;
};

class Base3 {
 public:
  Base3() : base3_1(31) {}
  int base3_1;
  virtual void __stdcall base3_fun1() {
    std::cout << "Base3::base3_fun1()" << std::endl;
  }
};

class Derive1 : public Base1, public Base2, public Base3 {
 public:
  Derive1() : derive1_1(11) {}
  int derive1_1;

  virtual void __stdcall base3_fun1() {
    std::cout << "Derive1::base3_fun1()" << std::endl;
  }
  virtual void __stdcall derive1_fun1() {
    std::cout << "Derive1::derive1_fun1()" << std::endl;
  }
};

struct CBase2 {
  int base2_1;
};

struct CBase1 {
  void** __vfptr;
  int base1_1;
};

struct CBase1_VFTable {
  void(__stdcall* base1_fun1)(CBase1* that);
};

void __stdcall base1_fun1(CBase1* that) {
  std::cout << "base1_fun1()" << std::endl;
}

struct CBase3 {
  void** __vfptr;
  int base3_1;
};

struct CBase3_VFTable {
  void(__stdcall* base3_fun1)(CBase3* that);
};

void __stdcall base3_fun1(CBase3* that) {
  std::cout << "base3_fun1()" << std::endl;
}

struct CDerive1 {
  CBase1 base1;
  CBase3 base3;
  CBase2 base2;

  int derive1_1;
};

struct CBase1_CDerive1_VFTable {
  void(__stdcall* base1_fun1)(CBase1* that);
  void(__stdcall* derive1_fun1)(CDerive1* that);
};

struct CBase3_CDerive1_VFTable {
  void(__stdcall* base3_fun1)(CDerive1* that);
};

void __stdcall base3_derive1_fun1(CDerive1* that) {
  std::cout << "base3_derive1_fun1()" << std::endl;
}

void __stdcall derive1_fun1(CDerive1* that) {
  std::cout << "derive1_fun1()" << std::endl;
}

void foo(Base1* pb1, Base2* pb2, Base3* pb3, Derive1* pd1) {
  std::cout << "Base1::\n"
            << "    pb1->base1_1 = " << pb1->base1_1 << "\n"
            << "    pb1->base1_fun1(): ";
  pb1->base1_fun1();

  std::cout << "Base2::\n"
            << "    pb2->base2_1 = " << pb2->base2_1 << std::endl;

  std::cout << "Base3::\n"
            << "    pb3->base3_1 = " << pb3->base3_1 << "\n"
            << "    pb3->base3_fun1(): ";
  pb3->base3_fun1();

  std::cout << "Derive1::\n"
            << "    pd1->derive1_1 = " << pd1->derive1_1 << "\n"
            << "    pd1->derive1_fun1(): ";
  pd1->derive1_fun1();
  std::cout << "    pd1->base3_fun1(): ";
  pd1->base3_fun1();

  std::cout << std::endl;
}

int main() {
  // CBase1 ���麯����
  CBase1_VFTable __vftable_base1;
  __vftable_base1.base1_fun1 = base1_fun1;

  // CBase3 ���麯����
  CBase3_VFTable __vftable_base3;
  __vftable_base3.base3_fun1 = base3_fun1;

  // CDerive1 �� CBase1 ���õ��麯����
  CBase1_CDerive1_VFTable __vftable_base1_derive1;
  __vftable_base1_derive1.base1_fun1 = base1_fun1;
  __vftable_base1_derive1.derive1_fun1 = derive1_fun1;

  CBase3_CDerive1_VFTable __vftable_base3_derive1;
  __vftable_base3_derive1.base3_fun1 = base3_derive1_fun1;

  CDerive1 d1;
  d1.derive1_1 = 1;

  d1.base1.base1_1 = 11;
  d1.base1.__vfptr = reinterpret_cast<void**>(&__vftable_base1_derive1);

  d1.base2.base2_1 = 21;

  d1.base3.base3_1 = 31;
  d1.base3.__vfptr = reinterpret_cast<void**>(&__vftable_base3_derive1);

  char* p = reinterpret_cast<char*>(&d1);
  Base1* pb1 = reinterpret_cast<Base1*>(p + 0);
  Base2* pb2 = reinterpret_cast<Base2*>(p + sizeof(CBase1) + sizeof(CBase3));
  Base3* pb3 = reinterpret_cast<Base3*>(p + sizeof(CBase1));
  Derive1* pd1 = reinterpret_cast<Derive1*>(p);

  foo(pb1, pb2, pb3, pd1);

  return 0;
}