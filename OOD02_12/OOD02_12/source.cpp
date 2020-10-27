#include <iostream>

class Bird {
 public:
  Bird(int height , int speed) : height_(height), speed_(speed) {}
  virtual int GetHeight() const = 0;
  virtual int GetSpeed() const = 0;
  int height() const { return height_; }
  int speed() const { return speed_; }
 protected:
  const int height_;
  const int speed_;
};
class Eagle : public Bird {
 public:
  Eagle(int height, int speed) : Bird(height, speed) {}
  int GetHeight() const { return height_; }
  int GetSpeed() const { return speed_; }
};
class hawk : public Bird {
 public:
  hawk(int height, int speed) : Bird(height, speed) {}
  int GetHeight() const { return height_; }
  int GetSpeed() const { return speed_; }
};
class falcon : public Bird {
 public:
  falcon(int height, int speed) : Bird(height, speed) {}
  int GetHeight() const { return height_; }
  int GetSpeed() const { return speed_; }
};
int main() {
  Eagle* hanwha = new Eagle(1, 2);
  std::cout << (*hanwha).GetHeight() << std::endl;
}
