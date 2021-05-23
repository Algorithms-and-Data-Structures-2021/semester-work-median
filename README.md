# Поиск медианы в массиве за O(N)

[![CMake](https://github.com/Algorithms-and-Data-Structures-2021/semester-work-median/actions/workflows/cmake.yml/badge.svg)](https://github.com/Algorithms-and-Data-Structures-2021/semester-work-median/actions/workflows/cmake.yml)

  Медиа́на набора чисел — число, которое находится в середине этого набора, если его упорядочить по возрастанию, то есть такое число, что половина из элементов набора не меньше него, а другая половина не больше.
  
	Например, медианой набора {11, 9, 3, 5, 5} является число 5, так как оно стоит в середине этого набора после его упорядочивания: {3, 5, 5, 9, 11}. Если в выборке чётное число элементов, медиана может быть не определена однозначно: тогда для числовых данных чаще всего используют полусумму двух соседних значений (то есть медиану набора {1, 3, 5, 7} принимают равной 4). В математической статистике медиана может использоваться как одна из характеристик выборки или совокупности чисел.
	
	Нахождение медианы списка может казаться тривиальной задачей, но ее выполнение за линейное время требует серьезного подхода. Для этого используется алгоритм, который является частным случаем «quickselect», разработанного Тони Хоаром, который также изобрел алгоритм сортировки с похожим названием — quicksort. Это рекурсивный алгоритм, и он может находить любой элемент (не только медиану).

  В среднем pivot разбивает список на две приблизительно равных части. Поэтому каждая последующая рекурсия оперирует с 1⁄2 данных предыдущего шага.
  
  ![alt text](https://lh5.googleusercontent.com/JSoLLSqoyJxcdk-eR_b-yt5UCy1KwF_v4lXVRM-BvsLaB9xv1yx_erqOOWaF37aYBBL3kh6kNggtG_qjmInfxNttzPWs6V6aTQZA7rAqo6yVonlV6EW4Bv4ZKXqfZah6GzFJn-_9)


## Команда "Fixiki"

| Фамилия Имя    | Вклад (%) | Прозвище              |
| :---           |   ---:    |  ---:                 |
| Видеева Ирина  | 50        |  Симка                |
| Бадамшин Артур | 50        |  Нолик                |

**Девиз команды**
«А кто такие фиксики — большой-большой секрет!»

## Структура проекта

_Описание основных частей семестрового проекта._

Проект состоит из следующих частей:

- [`src`](src)/[`include`](include) - реализация алгоритма (исходный код и заголовочные файлы);
- [`benchmark`](benchmark) - контрольные тесты производительности структуры данных (поиск медианы);
- [`examples`](examples) - примеры работы со структурой данных;
- [`dataset`](dataset) - наборы данных для запуска контрольных тестов и их генерация;

## Требования (Prerequisites)

Рекомендуемые требования:

- :black_square_button: С++ компилятор c поддержкой стандарта C++17 (например, _GNU GCC 8.1.x_ и выше).
- :black_square_button: Система автоматизации сборки _CMake_ (версия _3.12.x_ и выше).
- :black_square_button: Java Development Kit (версия 8 и выше).
- :black_square_button: Рекомендуемый объем оперативной памяти - не менее 4 ГБ.
- :black_square_button: Свободное дисковое пространство объемом ~ 1 ГБ (набор данных для контрольных тестов).
- :white_check_mark: Желание

## Сборка и запуск

### Пример (Windows)

#### Сборка проекта

Склонируйте проект к себе на устройство через [Git for Windows](https://gitforwindows.org/) (либо используйте
возможности IDE):

```shell
git clone https://github.com/Algorithms-and-Data-Structures-2021/semester-work-aa-tree-fixiki.git
```

Для ручной сборки проекта в терминале введите:

```shell
# переход в папку с проектом
cd C:\Users\username\asd-projects\semester-work-aa-tree-fixiki

# создание папки для файлов сборки (чтобы не засорять папку с проектом) 
mkdir -p build && cd build 

# сборка проекта
cmake .. -DCMAKE_BUILD_TYPE=RelWithDebInfo && cmake --config RelWithDebInfo --build . 
```

#### Генерация тестовых данных

Генерация тестового набора данных в
формате [comma-seperated values (CSV)](https://en.wikipedia.org/wiki/Comma-separated_values)

1) Склонируйте проект генератора набора случайных чисел [ЗДЕСЬ](https://github.com/rthoor/generation.git) к себе на устройство 
2) Ознакомьтесь с инструкциями генерации
3) Сгенерируйте наборы данных

#### Контрольные тесты (benchmarks)

Тестирование:
1) Последовательно добавляются элементы из файла со сгенерированным набором данных
2) Засекается время
3) Выполняется алгоритм поиска медианы
4) Фиксируется время
5) Время записывается в файл-результат

Результаты наших тестов:
[ЗДЕСЬ](https://drive.google.com/drive/folders/1rFm2efkkVMAexTKysEGn6NOiWKzQiQfR?usp=sharing)

##### Список контрольных тестов

| Название                  | Описание                                | Метрики         |
| :---                      | ---                                     | :---            |
| `demo_benchmark.cpp` | поиск медианы                  | _время_         |


## Источники
- [Статья на Хабре](https://habr.com/ru/post/346930/)
- [Видео на YouTube](https://www.youtube.com/watch?v=sNtu2oGDRvU)
