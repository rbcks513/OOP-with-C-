//  "Copyright [2020] <Copyright rbcks513>"
#include<iostream>


class Dog {
 public:
  Dog(int age, int speed) : age_(age), speed_(speed) {}
  virtual int getage() const = 0;
  virtual int getspeed() const = 0;
  int age() const { return age_; }
  int speed() const { return speed_; }

 protected:
  const int age_;
  const int speed_;
};

class Poodle : public Dog {
 public:
  Poodle(int age, int speed) : Dog(age, speed) {}
  int getage() const { return age_; }
  int getspeed() const { return speed_; }
};

class Shiba : public Dog {
 public:
  Shiba(int age, int speed) : Dog(age, speed) {}
  int getage() const { return age_ + 1; }
  int getspeed() const { return speed_ + 1; }
};

class Corgi : public Dog {
 public:
  Corgi(int age, int speed) : Dog(age, speed) {}
  int getage() const { return age_ + 2; }
  int getspeed() const { return speed_ + 2; }
};

int main() {
  Poodle* choco = new Poodle(8, 100);
  std::cout <<choco->getage() << std::endl;
  std::cout << choco->getspeed() << std::endl;
}
