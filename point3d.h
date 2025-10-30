#ifndef POINT3D_H
#define POINT3D_H

#include <iostream>

/**
 * @brief Структура, представляющая точку в трёхмерном пространстве.
 */
struct point3d {
    double x, y, z;
    /**
    * @brief Конструктор по умолчанию.
    * @param x Координата X (по умолчанию 0.0).
    * @param y Координата Y (по умолчанию 0.0).
    * @param z Координата Z (по умолчанию 0.0).
    */
    point3d(double x = 0.0, double y = 0.0, double z = 0.0);
    /**
    * @brief Выводит координаты точки в консоль.
    */
    void print() const;
    /**
    * @brief Возвращает координату X.
    * @return Значение координаты X.
    */
    double getBackX() const;
    /**
    * @brief Возвращает координату Y.
    * @return Значение координаты Y.
    */
    double getBackY() const;
    /**
    * @brief Возвращает координату Z.
    * @return Значение координаты Z.
    */
    double getBackZ() const;
};
#endif 