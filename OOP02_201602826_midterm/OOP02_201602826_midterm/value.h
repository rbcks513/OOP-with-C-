#pragma once
#ifndef MIDTERM_SOLUTION_SRCS_VALUE_H_
#define MIDTERM_SOLUTION_SRCS_VALUE_H_
#include <iostream >
#include <string >
class String;
class Integer;
class Float;
class Value {
 public:

  virtual bool operator<=(const Value& value) const = 0;
  virtual bool operator<(const String& str_v) const = 0;
  virtual bool operator<(const Integer& int_v) const = 0;
  virtual bool operator<(const Float& float_v) const = 0;
  virtual std ::string ToString() const = 0;
};
class String : public Value {
 public:
  explicit String(std ::string value);
  bool operator<=(const Value& value) const;
  bool operator<(const String& str_v) const;
  bool operator<(const Integer& int_v) const;
  bool operator<(const Float& float_v) const;
  const std ::string& value() const;
  std ::string ToString() const;

 private:
  const std ::string value_;
};
class Integer : public Value {
 public:
  explicit Integer(int value);
  bool operator<=(const Value& value) const;
  bool operator<(const String& str_v) const;
  bool operator<(const Integer& int_v) const;
  bool operator<(const Float& float_v) const;
  int value() const;
  std ::string ToString() const;

 private:
  const int value_;
};
class Float : public Value {
 public:
  explicit Float(float value);
  bool operator<=(const Value& value) const;
  bool operator<(const String& str_v) const;
  bool operator<(const Integer& int_v) const;
  bool operator<(const Float& float_v) const;
  float value() const;
  std ::string ToString() const;

 private:
  const float value_;
};
#endif  // MIDTERM_SOLUTION_SRCS_VALUE_H_