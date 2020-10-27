#include "value.h"

String::String(std::string value) : value_(value), Value() {}
bool String::operator<=(const Value& value) const {
  const Value* test = &value;
  if (const String* stringV = dynamic_cast<const String*>(test)) {
    return this->value() < stringV->value(); 
  } else if (const Integer* integerV = dynamic_cast<const Integer*>(test)) {
    return true;
  } else if (const Float* floatV = dynamic_cast<const Float*>(test)) {
    return true;
  }
}
bool String::operator<(const String& str_v) const { // ¹Ì±¸Çö
  return true;
}
bool String::operator<(const Integer& int_v) const { return true; }
bool String::operator<(const Float& float_v) const { return true; }
const std::string& String::value() const { return value_; }
std ::string String::ToString() const { return value_; }

Integer::Integer(int value) : value_(value), Value() {}
bool Integer::operator<=(const Value& value) const {
  const Value* test = &value;
  if (const String* stringV = dynamic_cast<const String*>(test)) {
    return false;
  } else if (const Integer* integerV = dynamic_cast<const Integer*>(test)) {
    return this->value() < integerV->value();
  } else if (const Float* floatV = dynamic_cast<const Float*>(test)) {
    return this->value() < floatV->value();
  }
}
bool Integer::operator<(const String& str_v) const { return false; }
bool Integer::operator<(const Integer& int_v) const {
  float tempThis = this->value();
  float tempPara = int_v.value();
  if (tempThis - tempPara > 0) { return true;
  } else if (tempThis - tempPara <= 0) return false;
   
}
bool Integer::operator<(const Float& float_v) const {
  float tempThis = this->value();
  float tempPara = float_v.value();
  if (tempThis - tempPara > 0) {
    return true;
  } else if (tempThis - tempPara <= 0)
    return false;
}
int Integer::value() const { return this->value_; }
std ::string Integer::ToString() const {
  std::string returnV = std::to_string(this->value_);
  return returnV;
}

Float::Float(float value) : value_(value), Value() {}
bool Float::operator<=(const Value& value) const {
  const Value* test = &value;
  if (const String* stringV = dynamic_cast<const String*>(test)) {
    return false;
  } else if (const Integer* integerV = dynamic_cast<const Integer*>(test)) {
    return this->value() < integerV->value();
  } else if (const Float* floatV = dynamic_cast<const Float*>(test)) {
    return this->value() < floatV->value();
  }
}
bool Float::operator<(const String& str_v) const { return false; }
bool Float::operator<(const Integer& int_v) const {
  float tempThis = this->value();
  float tempPara = int_v.value();
  if (tempThis - tempPara > 0) {
    return true;
  } else if (tempThis - tempPara <= 0)
    return false;
}
bool Float::operator<(const Float& float_v) const {
  float tempThis = this->value();
  float tempPara = float_v.value();
  if (tempThis - tempPara > 0) {
    return true;
  } else if (tempThis - tempPara <= 0)
    return false;
}
float Float::value() const { return this->value_; }
std ::string Float::ToString() const {
  std::string returnV = std::to_string(this->value_);
  return returnV;
}
