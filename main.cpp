#include <iostream>
#include <vector>
#include <fstream>
#include <iostream>

#include "algorithm.hpp"

using namespace std;

int main(int argc, char *argv[]) {
    vector<int> array;
  array.push_back(78);
  array.push_back(6);
  array.push_back(82);
  array.push_back(67);
  array.push_back(55);
  array.push_back(44);
  array.push_back(34);

  int a = itis::quickselect(array);
  cout << "-----------------------" << endl;
 cout << "answer " << a << endl;
    //string files[14] = {"101", "501", "1001", "5001", "10001", "25001", "50001", "100001",
                       // "250001", "500001", "750001", "1000001", "2500001", "5000001"};

//    const string setsPath = "C:\\Users\\EvveKiNG\\Desktop\\newsets\\1000001.csv";
//    auto input_file_insert = ifstream(setsPath);
//    vector<int> array;
//    string line;
//    while (getline(input_file_insert, line, ',')) {
//        array.push_back(stoi(line));
//    }
//    int a = itis::quickselect(array);
//    cout << "-----------------------" << endl;
//    cout << "answer " << a << endl;

  return 0;
}