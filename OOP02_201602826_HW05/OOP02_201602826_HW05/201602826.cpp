// "Copyright [2020] <Copyright rbcks513>"
#include<iostream>
#include <optional>

class Shape {
 public:
  Shape(int width, int depth) : width_(width), depth_(depth) {}
  virtual double GetArea() const = 0;
  int width() const { return width_; }
  int depth() const { return depth_; }

 protected:
  const int width_;
  const int depth_;
};
class Rectangle : public Shape {
 public:
  Rectangle(int width, int depth) : Shape(width, depth) {}
  double GetArea() const {
    return static_cast<double>(width_) * depth_;
  }
  //  add two Rectangles and return new one
  const Rectangle operator+(const Rectangle& rect) const {
    int new_width = rect.width() + width_;
    int new_depth = rect.depth() + depth_;
    Rectangle* new_rect = new Rectangle(new_width, new_depth);
    return *new_rect;
  }
  // return newone used gap of two rectangles
  const std::optional<Rectangle> operator-(const Rectangle& rect) const {
    int new_width = abs(rect.width() - width_);
    int new_depth = abs(rect.depth() - depth_);
    if (new_width == 0 || new_depth == 0) {
      return std::nullopt;
    }
    Rectangle* new_rect = new Rectangle(new_width, new_depth);
    return *new_rect;
  }
  // mutiplex two Rectangles and return new one
  const Rectangle operator*(const Rectangle& rect) const {
    int new_width = rect.width() * width_;
    int new_depth = rect.depth() * depth_;
    Rectangle* new_rect = new Rectangle(new_width, new_depth);
    return *new_rect;
  }
};
class Triangle : public Shape {
 public:
  Triangle(int width, int depth) : Shape(width, depth) {}
  double GetArea() const {
    return static_cast<double>(width_) * depth_ * 0.5; }
  // add two triangles and return new one
  const Triangle operator+(const Triangle& tria) const {
    int new_width = tria.width() + width_;
    int new_depth = tria.depth() + depth_;
    Triangle* new_tria = new Triangle(new_width, new_depth);
    return *new_tria;
  }
  // return newone used gap of two Triange
  const std::optional<Triangle> operator-(const Triangle& tria) const {
    int new_width = abs(tria.width() - width_);
    int new_depth = abs(tria.depth() - depth_);
    if (new_width == 0 || new_depth == 0) {
      return std::nullopt;
    }
    Triangle* new_tria = new Triangle(new_width, new_depth);
    return *new_tria;
  }
  // mutiplex two triangles and return new one
  const Triangle operator*(const Triangle& tria) const {
    int new_width = tria.width() * width_;
    int new_depth = tria.depth() * depth_;
    Triangle* new_tria = new Triangle(new_width, new_depth);
    return *new_tria;
  }
};
class Circle : public Shape {
 public:
  explicit Circle(int radius) : Shape(radius, radius) {}
  double GetArea() const { return static_cast<double>(width_) * width_ * 3.14; }
  // add two circles and return new one
  const Circle operator+(const Circle& circ) const {
    int new_radius = circ.width() + width_;
    Circle* new_circ = new Circle(new_radius);
    return *new_circ;
  }
  // return newone used gap of two circle
  const std::optional<Circle> operator-(const Circle& circ) const {
    int new_radius = abs(circ.width() - width_);
    if (new_radius == 0) {
      return std::nullopt;
    }
    Circle* new_circ = new Circle(new_radius);
    return *new_circ;
  }
  // mutiplex two Circle and return new one
  const Circle operator*(const Circle& circ) const {
    int new_radius = circ.width() * width_;
    Circle* new_circ = new Circle(new_radius);
    return *new_circ;
  }
};
//  ShapeUtil designed singletone
class ShapeUtil {
 public:
  static ShapeUtil* GetInstance() {
    if (s_instance_ == NULL) {
       s_instance_ = new ShapeUtil;
    }
    return s_instance_;
  }
  double CalcVolume(const Shape* shape, int height) {
    return shape->GetArea() * height;
  }
 private:
  static ShapeUtil* s_instance_;
};
ShapeUtil* ShapeUtil::s_instance_ = NULL;

int main() {
  Rectangle* test = new Rectangle(3, 2);
  Triangle* testt = new Triangle(3, 2);
  Circle* testc = new Circle(5);
  std::cout << test->GetArea() << std::endl;
  std::cout << testt->GetArea() << std::endl;
  std::cout << testc->GetArea() << std::endl;
  ShapeUtil* testing = ShapeUtil::GetInstance();
  std::cout << testing->CalcVolume(test, 5) << std::endl;
  std::cout << testing->CalcVolume(testt, 5) << std::endl;
  std::cout << testing->CalcVolume(testc, 5) << std::endl;
}
