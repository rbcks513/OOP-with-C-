#include <iostream>

class Fish{
 public:
  Fish(int age, int length) : age_(age), length_(length) {}
  virtual int GetAge() = 0;
  virtual int GetLength() = 0;
  int age() const { return age_; }
  int length() const { return length_; }
 protected:
  int age_;
  int length_;
};

class WelsCatfish : public Fish {
 public:
  WelsCatfish(int age, int length) : Fish(age, length) {}
  int GetAge() { return age_; }
  int GetLength() { return length_; }
};

class Guppy : public Fish{
 public:
  Guppy(int age, int length) : Fish(age, length) {}
  int GetAge() { return age_; }
  int GetLength() { return length_; }
};

class goldfish : public Fish {
 public:
  goldfish(int age, int length) : Fish(age, length) {}
  int GetAge() { return age_; }
  int GetLength() { return length_; }
};

int main() {
  WelsCatfish* a = new WelsCatfish(500, 60);
  std::cout << (*a).GetAge() << "\n";
  std::cout << (*a).GetLength() << "\n";

  Guppy b = Guppy(4, 5);
  std::cout << b.GetAge() << "\n";
  std::cout << b.GetLength() << "\n";

  goldfish c = goldfish(30, 30);
  std::cout << c.GetAge() << "\n";
  std::cout << c.GetLength() << "\n";
}
