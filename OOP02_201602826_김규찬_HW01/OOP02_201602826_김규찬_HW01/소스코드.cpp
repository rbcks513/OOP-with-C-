// "Copyright [2020] <Copyright rbcks513>"
// HW01 Input&Output test
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>  // for using the string stream


int main(int argc, char* argv[]) {
  //  Set file path
  std::string input_path = argv[1];
  std::string output_path = argv[2];
  std::cout << input_path+"\n";
  std::cout << output_path+"\n";
  std::ifstream input_file;
  std::ifstream cheack_output_file;
  // Cheack output
  cheack_output_file.open(output_path);
  if (cheack_output_file.is_open()) {            //  If Ouptut.txt have already
    std::cerr << "��� ������ �̹� �����մϴ�";  //  print error
    cheack_output_file.close();
    return -2;
  }
  cheack_output_file.close();

  //  Set Output & Open file
  std::ofstream output_file;
  output_file.open(output_path);
  input_file.open(input_path);
  if (input_file.is_open()) {
    std::string first_line;
    getline(input_file, first_line);
    std::string second_line;
    getline(input_file, second_line);
    // Ready to tokenize
    std::string temp_first_line;
    std::string temp_second_line;
    std::stringstream ss_first_line(first_line);
    std::stringstream ss_second_line(second_line);
    std::vector<std::string> tokens_first_line;
    std::vector<std::string> tokens_second_line;

    //  Tokenize and Synthesize
    while (ss_first_line >> temp_first_line) {
      if (ss_second_line >> temp_second_line) {
        tokens_first_line.push_back(temp_first_line);
        tokens_second_line.push_back(temp_second_line);
        output_file << temp_first_line + " " + temp_second_line << std::endl;
      } else {  // The number of second line is smaller than first line
        std::cerr << "�л��� ���� ������ ���� ��ġ���� �ʽ��ϴ�";
        input_file.close();
        output_file.close();
        return -3;
      }
    }
    //  The number of second line is bigger than first line
    if (ss_second_line >> temp_second_line) {
      std::cerr << "�л��� ���� ������ ���� ��ġ���� �ʽ��ϴ�";
      input_file.close();
      output_file.close();
      return -3;
    }
  } else {  //  If input file do not open
    std::cerr << "�Է� ������ �������� �ʽ��ϴ�.";
    input_file.close();
    output_file.close();
    return -1;
  }
  input_file.close();
  output_file.close();
}
