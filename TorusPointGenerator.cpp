#include "TorusPointGenerator.h"
#include <fstream>
#include <cmath>

/**
 * @brief Конструктор класса TorusPointGenerator
 * @param R Расстояние от центра тора до центра трубы
 * @param r Радиус трубы тора
 * 
 * Инициализирует параметры тора и инициализирует генератор случайных чисел.
 * Использует std::random_device для получения случайного сида.
 */
TorusPointGenerator::TorusPointGenerator(double R, double r) : R_(R), r_(r) {
    std::random_device rd;
    gen_.seed(rd());
}

/**
 * @brief Генерирует случайную точку в верхней половине тора
 * @return Объект point3d со случайными координатами в торе
 * 
 * Алгоритм использует цилиндрические координаты для равномерной генерации точек:
 * 1. Генерирует rho в диапазоне [R-r, R+r]
 * 2. Генерирует phi в диапазоне [0, 2π]
 * 3. Генерирует z в диапазоне [0, r] (верхняя половина)
 * 4. Проверяет условие попадания в тор: (rho-R)^2 + z^2 <= r^2
 * 5. Преобразует цилиндрические координаты в декартовы
 */
point3d TorusPointGenerator::rnd() {
    std::uniform_real_distribution<> rho_dist(R_ - r_, R_ + r_);
    std::uniform_real_distribution<> phi_dist(0, 2 * M_PI);
    std::uniform_real_distribution<> z_dist(0, r_);

    double rho, phi, z;
    do {
        rho = rho_dist(gen_);
        phi = phi_dist(gen_);
        z = z_dist(gen_);
    } while (std::pow(rho - R_, 2) + std::pow(z, 2) > r_ * r_);

    double x = rho * std::cos(phi);
    double y = rho * std::sin(phi);
    return point3d(x, y, z);
}

/**
 * @brief Возвращает параметр R тора (расстояние до центра трубы)
 * @return Значение R типа double
 */
double TorusPointGenerator::getR() const { return R_; }

/**
 * @brief Возвращает параметр r тора (радиус трубы) 
 * @return Значение r типа double
 */
double TorusPointGenerator::getr() const { return r_; }

/**
 * @brief Сохраняет параметры тора в файл
 * @param filename Имя файла для сохранения (по умолчанию "setting.dat")
 * 
 * Формат файла:
 * R: значение
 * r: значение
 * 
 * Используется для сохранения настроек генератора.
 */
void TorusPointGenerator::saveSettings(const std::string& filename) const {
    std::ofstream file(filename);
    if (file.is_open()) {
        file << "R: " << R_ << "\nr: " << r_ << std::endl;
        file.close();
    }
}