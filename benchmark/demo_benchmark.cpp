#include <fstream>      // ifstream
#include <iostream>     // cout
#include <string>       // string, stoi
#include <string_view>  // string_view
#include <chrono>       // high_resolution_clock, duration_cast, nanoseconds
#include <sstream>      // stringstream
#include <vector>

// подключаем алгоритм
#include "algorithm.hpp"

using namespace std;

// абсолютный путь до набора данных и папки проекта
static constexpr auto kDatasetPath = string_view{PROJECT_DATASET_DIR};
static constexpr auto kProjectPath = string_view{PROJECT_SOURCE_DIR};

//Путь к папке с наборами данных для заполнения
const string setsPath = "C:/Users/Admin/Desktop/sets";

// Сгенирировать наборы даннх : https://github.com/rthoor/generation.git


//укажите названия папок с наборами данных, если они есть
string folders[5] = {"/01/","/02/","/03/","/04/","/05/"};

//если их нет
//string folders[1] = {"/"};

//укажите названия файлов с наборами данных (без .csv)
string files[8] = {"11", "51", "101", "501", "1001", "5001", "10001", "50001"};

//Путь к папке, куда нужно выгрузить результаты
const string outputPath = "C:/Users/Admin/Desktop/results/";

// Ознакомтесь с директорией "results-path-example/results"
// в папке выгруза результатов нужно будет реализовать похожую структуру,
// опираясь на названия файлов в массиве files

// -----------------------------------
// запускать main() (в самом низу)   |
// -----------------------------------

//Вывод результатов
void writeResults(string file, long time) {
    // вывод результата
    // не забудьте подготовить директорию
    std::ofstream out(outputPath + file + "/results.txt", std::ios::app);
    if (out.is_open()) {
        out << time << std::endl;
    }
    out.close();
}

void goTest() {
    for (auto file : files) {
        for (auto folder : folders) {
            for (int i = 0; i < 10; i++) { // i = сколько раз прогоняем один и тот же csv файл
                auto input_file = ifstream(setsPath + folder + file + ".csv");
                string line;

                // Создание структуры
                vector<int> array;

                // добавление
                while (getline(input_file, line, ',')) {
                    array.push_back(stoi(line));
                }
                auto time_point_before = chrono::steady_clock::now();
                itis::quickselect(array);
                auto time_point_after = chrono::steady_clock::now();
                auto time_diff_insert = time_point_after - time_point_before;
                long time = chrono::duration_cast<chrono::nanoseconds>(time_diff_insert).count();
                array.clear();
                writeResults(file, time);
            }
            std::cout << "test for " + setsPath + folder + file + " ended" + "\n";
        }
    }
}

int main() {
    goTest();
    return 0;
}
