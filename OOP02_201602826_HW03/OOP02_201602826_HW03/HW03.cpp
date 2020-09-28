// "Copyright [2020] <Copyright rbcks513>"
#include<string>
#include<iostream>

class Door {
 public:
  Door() : locked_(false), opened_(false) {}  //  Set initial value
  bool locked() { return locked_; }
  bool opened() { return opened_; }
  void Unlock() { locked_ = false; }
  //  Lock must be after close
  void Lock() {
    if (!opened_) locked_ = true;
  }
  //  Open must be after unlock
  void Open() {
    if (!locked_) opened_ = true;
  }
  void Close() { opened_ = false; }

 private:
  bool locked_;
  bool opened_;
};
class Pedal {
 public:
  Pedal() : base_power_(0) {}
// If purchase_year over 2010
  explicit Pedal(int base_power)
      : base_power_(base_power) {}
  int Push(int power) { return power + base_power_; }

 private:
  const int base_power_;
};

struct CarState {
  bool doors_loked_state[4];
  bool doors_opened_state[4];
  int current_speed_ = 0;
};

class Car{
 private:
  const std::string name_;
  const int purchase_year_;
  Door doors_[4];
  Pedal accel_;
  Pedal brake_;
  int current_speed_;

 public:
  Car(std::string name, int purchase_year)
    :name_(name), purchase_year_(purchase_year) {
    Door doors_[4] = {Door(), Door(), Door(), Door()};
    if (purchase_year_ > 2011) {  // puchase year and currnet power set
    Pedal accel_ = Pedal(3);
    Pedal brake_ = Pedal(3);
    } else {
    Pedal accel_ = Pedal();
    Pedal brake_ = Pedal();
    }
    current_speed_ = 0;
  }
  std::string name() { return name_; }
  int purchase_year() { return purchase_year_; }
  CarState GetCarState() {
    CarState GetCarState{
      {doors_[0].locked(), doors_[1].locked(),
       doors_[2].locked(), doors_[3].locked()},
      {doors_[0].opened(), doors_[0].opened(),
      doors_[0].opened(), doors_[0].opened()}
      , current_speed_
    };
    return GetCarState;
  }

  void UnlockDoor() {  //  Unlock every door
    doors_[0].Unlock();
    doors_[1].Unlock();
    doors_[2].Unlock();
    doors_[3].Unlock();
  }
  void UnlockDoor(int target_door) {  // Unlock target door
    doors_[target_door].Unlock();
  }
  //  Lock every door
  void LockDoor() {  //  Look condition is handled by Door class
    doors_[0].Lock();
    doors_[1].Lock();
    doors_[2].Lock();
    doors_[3].Lock();
  }
  void LockDoor(int target_door) {  //  Lock target door
    doors_[target_door].Lock();
  }
  void OpenDoor(int target_door) {  //  Open target door
    doors_[target_door].Open();
  }
  void CloseDoor(int target_door) {  // Close target door
    doors_[target_door].Close();
  }
  void PushAccel() {
    PushAccel(1);
  }
  void PushAccel(int power) {
    int temp = current_speed_ + accel_.Push(power);
    current_speed_ += accel_.Push(power);
    if (temp > 100) {  // current speed range set
      current_speed_ = 100;
    }
  }
  void PushBrake() {
    PushBrake(1);
  }
  void PushBrake(int power) {
    int temp = current_speed_ + brake_.Push(power);
    current_speed_ += brake_.Push(power);
    if (temp < 0) {  // current speed range set
      current_speed_ = 0;
    }
  }
};
