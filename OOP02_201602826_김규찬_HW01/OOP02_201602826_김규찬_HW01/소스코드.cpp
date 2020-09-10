// "Copyright [2020] <Copyright rbcks513>"
// HW1 입출력 테스트
#include <fstream>
#include <iostream>
#include <string>


int main(int argc, char* argv[]) {
  std::string input_path = argv[1];
  // std::string output_path = argv[2];

  std::ifstream input_file;
  //  std::ofstream output_file;

  input_file.open(input_path);

  if (input_file.is_open()) {  // test read file
    std::string line;
    // how to divide the string
    getline(input_file, line);
    std::cout << line << std::endl;  // check
  } else {  // If input file do not open print out error
    std::cerr << "입력 파일이 존재하지 않습니다.";
    return -1;
  }
  input_file.close();
}
