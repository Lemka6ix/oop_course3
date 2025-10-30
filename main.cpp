/**
 * @file main.cpp
 * @brief Основная программа для генерации и управления точками в торе
 * @author Климентий
 * @version 1.0
 * @date 2025
 */

#include <iostream>
#include <vector>
#include <fstream>
#include "point3d.h"
#include "TorusPointGenerator.h"
#ifdef WITH_MATHGL
#include <mgl2/mgl.h>
#endif

/**
 * @brief Основная функция программы
 * 
 * Программа генерирует случайные точки в верхней половине тора и предоставляет
 * интерактивный интерфейс для управления этими точками.
 * 
 * @return Код завершения программы (0 - успешное завершение)
 */
int main() {
    // Ввод параметров тора
    double R, r;
    std::cout << "Введите параметры тора (R и r): ";
    std::cin >> R >> r;

    /// Создание генератора точек с заданными параметрами
    TorusPointGenerator generator(R, r);
    generator.saveSettings();

    // Ввод количества точек для генерации
    int K;
    std::cout << "Введите количество точек K: ";
    std::cin >> K;

    /// Вектор для хранения сгенерированных точек
    std::vector<point3d> points;
    
    /// Генерация K случайных точек в торе
    for (int i = 0; i < K; ++i) {
        points.push_back(generator.rnd());
    }

    /**
     * @brief Основной цикл программы с интерактивным меню
     * 
     * Предоставляет пользователю следующие возможности:
     * - Просмотр координат точек
     * - Добавление новых точек
     * - Сохранение точек в файл
     * - Визуализация точек
     */
    int choice;
    do {
        std::cout << "\n1. Вывести точку\n2. Вывести координату\n3. Добавить точку\n4. Сохранить в файл\n5. Визуализировать\n0. Выход\nВыберите: ";
        std::cin >> choice;
        
        /// @brief Обработка вывода полных координат точки
        if (choice == 1) {
            int index;
            std::cout << "Введите индекс точки: ";
            std::cin >> index;
            if (index >= 0 && index < points.size()) {
                points[index].print();
            } else {
                std::cout << "Неверный индекс!" << std::endl;
            }
        } 
        /// @brief Обработка вывода конкретной координаты точки
        else if (choice == 2) {
            int index;
            char coord;
            std::cout << "Введите индекс точки и координату (x, y, z): ";
            std::cin >> index >> coord;
            if (index >= 0 && index < points.size()) {
                switch (coord) {
                    case 'x': std::cout << points[index].getBackX() << std::endl; break;
                    case 'y': std::cout << points[index].getBackY() << std::endl; break;
                    case 'z': std::cout << points[index].getBackZ() << std::endl; break;
                }
            } else {
                std::cout << "Неверный индекс!" << std::endl;
            }
        } 
        /// @brief Обработка добавления новой точки с ручным вводом координат
        else if (choice == 3) {
            double x, y, z;
            std::cout << "Введите координаты (x y z): ";
            std::cin >> x >> y >> z;
            points.emplace_back(x, y, z);
        } 
        /// @brief Обработка сохранения всех точек в файл
        else if (choice == 4) {
            std::ofstream file("points.txt");
            for (const auto& p : points) {
                file << p.getBackX() << " " << p.getBackY() << " " << p.getBackZ() << "\n";
            }
            file.close();
            std::cout << "Файл сохранён." << std::endl;
        } 
        /// @brief Обработка визуализации точек с использованием MathGL
        else if (choice == 5) {
#ifdef WITH_MATHGL
            /// Подготовка данных для визуализации
            mglData xData(points.size()), yData(points.size()), zData(points.size());
            for (size_t i = 0; i < points.size(); ++i) {
                xData.a[i] = points[i].getBackX();
                yData.a[i] = points[i].getBackY();
                zData.a[i] = points[i].getBackZ();
            }
            
            /// Создание графика и визуализация точек
            mglGraph gr;
            gr.SetRanges(xData.Minimal(), xData.Maximal(), 
                        yData.Minimal(), yData.Maximal(), 
                        zData.Minimal(), zData.Maximal());
            gr.Axis();
            gr.Plot(xData, yData, zData, " .b");  ///< Синие точки
            gr.WriteFrame("points.png");
            std::cout << "Визуализация сохранена в points.png" << std::endl;
#else
            std::cout << "Визуализация не поддерживается!" << std::endl;
#endif
        }
    } while (choice != 0);  ///< Цикл продолжается до выбора варианта "Выход"

    return 0;  ///< Успешное завершение программы
}