#include "point3d.h"

/**
 * @brief Конструктор структуры point3d
 * @param x Координата X (по умолчанию 0.0)
 * @param y Координата Y (по умолчанию 0.0) 
 * @param z Координата Z (по умолчанию 0.0)
 * 
 * Инициализирует точку с заданными координатами используя список инициализации.
 */
point3d::point3d(double x, double y, double z) : x(x), y(y), z(z) {}

/**
 * @brief Выводит координаты точки в стандартный поток вывода
 * 
 * Формат вывода: (x, y, z)
 * Используется для отладки и демонстрации координат точки.
 */
void point3d::print() const {
    std::cout << "(" << x << ", " << y << ", " << z << ")" << std::endl;
}

/**
 * @brief Возвращает координату X точки
 * @return Значение координаты X типа double
 */
double point3d::getBackX() const { return x; }

/**
 * @brief Возвращает координату Y точки  
 * @return Значение координаты Y типа double
 */
double point3d::getBackY() const { return y; }

/**
 * @brief Возвращает координату Z точки
 * @return Значение координаты Z типа double
 */
double point3d::getBackZ() const { return z; }