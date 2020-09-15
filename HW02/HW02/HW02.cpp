#include<iostream>
#include<string>
#include<algorithm>

class NamingConventionCorrector {
 public:
  std::string ToTypeName(std::string* input, int size) {
    // To Do
    std::string temp;
    std::string change_capital;
    for (int i = 0; i < size; i++) {
      change_capital = input[i];
      std::transform(change_capital.begin(),
        change_capital.begin() + 1, change_capital.begin(), toupper);
      temp += change_capital;
    }
    std::cout << temp << std::endl;
    return temp;
  }

  std::string ToVariableName(std::string* input, int size) {
    // To Do
    std::string temp;
    for (int i = 0; i < size; i++) {
      temp += input[i] + "_";
    }
    temp.pop_back();
    std::cout << temp << std::endl;
    return temp;
  }

  std::string ToClassMemberName(std::string* inputLine, int size) {
    // To Do
    std::string temp;
    for (int i = 0; i < size; i++) {
      temp += inputLine[i] + "_";
    }
    std::cout << temp  << std::endl;
    return temp;
  }

  std::string ToStructMemberName(std::string* inputLine, int size) {
    // To Do
    std::string temp;
    for (int i = 0; i < size; i++) {
      temp += inputLine[i] + "_";
    }
    temp.pop_back();
    std::cout << temp << std::endl;
    return temp;
  }

  std::string ToConstantName(std::string* inputLine, int size) {
    // To Do
    std::string temp;
    std::string change_capital;
    for (int i = 0; i < size; i++) {
      change_capital = inputLine[i];
      std::transform(change_capital.begin(), change_capital.begin() + 1,
                     change_capital.begin(), toupper);
      temp += change_capital;
    }
    std::cout << "k"+temp << std::endl;
    return "k"+temp;
  }

  std::string ToFunctionName(std::string* inputLine, int size) {
    // To Do
    std::string temp;
    std::string change_capital;
    for (int i = 0; i < size; i++) {
      change_capital = inputLine[i];
      std::transform(change_capital.begin(), change_capital.begin() + 1,
                     change_capital.begin(), toupper);
      temp += change_capital;
    }
    std::cout << temp << std::endl;
    return temp;
  }
};

int main(int argc, char** argv) {
  NamingConventionCorrector corrector;
  // somoonjaman
  int kArraySize = 2;
  std::string* str_list = new std::string[kArraySize];
  str_list[0] = "apple";
  str_list[1] = "banana";
  std::string type_name = corrector.ToTypeName(str_list,
    kArraySize);
  std::string variable_name = corrector.ToVariableName(str_list,
    kArraySize);
  std::string class_member_name = corrector.ToClassMemberName(str_list,
    kArraySize);
  std::string struct_member_name = corrector.ToStructMemberName(str_list,
    kArraySize);
  std::string constant_name = corrector.ToConstantName(str_list,
    kArraySize);
  std::string function_name = corrector.ToFunctionName(str_list,
    kArraySize);
  return 0;
}
