#pragma once
#include <cstdlib>
#include <time.h>
#include <vector>


// Заголовочный файл с объявлением структуры данных

namespace itis {
    //генерация рандомного индекса
    // (previous нужен для того, чтобы алгоритм много ращз подряд не генерировал один и тот же индекс
    //чтобы не было "бестолковых" итераций подряд
    int random(int total, int previous) {
        srand(time(NULL));
        int answer = previous;
        while(answer == previous){
            answer = rand() % total;
        }
        return answer;
    }

    //алгоритм для рекурсивного вызова
    double quickselect(std::vector<int> array, int med, int prev_pivot){
        if(array.size()==1){
            return array.front();
        }
        else {
            int pivot = random(array.size(), prev_pivot);
            std::vector<int> lesser_els;
            std::vector<int> great_els;
            for (int i = 0; i < array.size(); i++) {
                if (array.at(i) <= array.at(pivot)) {
                    lesser_els.push_back(array.at(i));
                } else {
                    great_els.push_back(array.at(i));
                }
            }
            array.clear();
            if (med <= lesser_els.size()) {
                return quickselect(lesser_els, med, pivot);

            } else {
                return quickselect(great_els, med - lesser_els.size(), pivot);
            }
        }
    }

    //основной алгоритм
    double quickselect(std::vector<int> array){

        if(array.size()==1){
            return array.front();
        }
        else {
            int med = array.size() / 2 + 1;
            int pivot = random(array.size(), -1);
            std::vector<int> lesser_els;
            std::vector<int> great_els;
            for (int i = 0; i < array.size(); i++) {
                if (array.at(i) <= array.at(pivot)) {
                    lesser_els.push_back(array.at(i));
                } else {
                    great_els.push_back(array.at(i));
                }
            }
            array.clear();
            if (med <= lesser_els.size()) {
                return quickselect(lesser_els, med, pivot);
            } else {
                return quickselect(great_els, med - lesser_els.size(), pivot);
            }
        }
    }
}  // namespace itis