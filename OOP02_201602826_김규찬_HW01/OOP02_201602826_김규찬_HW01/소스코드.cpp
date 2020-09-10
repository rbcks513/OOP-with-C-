// "Copyright [2020] <Copyright rbcks513>"
// HW1 입출력 테스트
#include <fstream>
#include <iostream>
#include <string>
#include <vector>  //  
#include <sstream>  // for using the string stream


int main(int argc, char* argv[]) {
  std::string input_path = argv[1];
  // std::string output_path = argv[2];

  std::ifstream input_file;
  //  std::ofstream output_file;

  input_file.open(input_path);

  if (input_file.is_open()) {  // test read file
    std::string line; 
    getline(input_file, line);
    std::string temp;  //
    std::stringstream ss(line);
    std::vector<std::string> tokens;
    
    while (ss >> temp) {
      tokens.push_back(temp);
      std::cout << temp << std::endl;
    }
    std::cout << line << std::endl; 
  } else {  // If input file do not open print out error
    std::cerr << "입력 파일이 존재하지 않습니다.";
    return -1;
  }
  input_file.close();
}
