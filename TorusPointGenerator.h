#ifndef TORUSPOINTGENERATOR_H
#define TORUSPOINTGENERATOR_H

#include "point3d.h"
#include <random>

/**
 * @brief Класс для генерации случайных точек в верхней половине тора.
 */
class TorusPointGenerator {
    double R_; ///< Расстояние от центра тора до центра трубы.
    double r_; ///< Радиус трубы.
    std::mt19937 gen_; ///< Генератор случайных чисел.

public:
    /**
     * @brief Конструктор с параметрами.
     * @param R Расстояние от центра тора до центра трубы.
     * @param r Радиус трубы.
     */
    TorusPointGenerator(double R, double r);

    /**
     * @brief Генерирует случайную точку в верхней половине тора.
     * @return Объект point3d с координатами точки.
     */
    point3d rnd();

    /**
     * @brief Возвращает параметр R.
     * @return Значение R.
     */
    double getR() const;

    /**
     * @brief Возвращает параметр r.
     * @return Значение r.
     */
    double getr() const;

    /**
     * @brief Сохраняет параметры тора в файл.
     * @param filename Имя файла (по умолчанию "setting.dat").
     */
    void saveSettings(const std::string& filename = "setting.dat") const;
};

#endif // TORUSPOINTGENERATOR_H