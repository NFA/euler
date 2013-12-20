#include <vector>
#include <string>
#include <fstream>

namespace euler {

std::vector<std::string> open_file(std::string file_name ) {
  std::ifstream file(file_name);
  std::vector<std::string> contents {};

  if (!file.is_open()) {
    std::cerr << "Couldn't find " << file_name << "." << std::endl;
    return contents;
  }

  while (file) {
    std::string name;
    file.ignore(256, '"'); //  "
    std::getline(file, name, '"'); // name until "
    contents.push_back(name);
    file.ignore(256, ','); // ",
   }

  file.close();
  return contents;
}

} /* namespace euler */


