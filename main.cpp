#include "movableShape.h"
#include <Windows.h>

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int x1, y1, x2, y2, x3, y3, x4, y4;
    double tolerance = 0.005;

    std::cout << "Введите координаты вершин трапеции:" << std::endl;
    std::cout << "x1 y1 x2 y2 x3 y3 x4 y4: ";
    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

    MovableShape trapezoid(x1, y1, x2, y2, x3, y3, x4, y4);
    trapezoid.displayParameters();

    int choice;
    do {
        std::cout << "\nМеню:" << std::endl;
        std::cout << "1. Проверить, принадлежит ли точка границе" << std::endl;
        std::cout << "2. Проверить, пересекает ли форма ось X" << std::endl;
        std::cout << "3. Проверить, пересекает ли форма ось Y" << std::endl;
        std::cout << "4. Определить тип трапеции" << std::endl;
        std::cout << "5. Переместить фигуру" << std::endl;
        std::cout << "6. Вернуть фигуру в исходное положение" << std::endl;
        std::cout << "0. Выход" << std::endl;
        std::cout << "Введите ваш выбор: ";
        std::cin >> choice;

        int x, y, newCenterX, newCenterY;
        switch (choice) {
            case 1:
                std::cout << "Введите координаты точки (x y): ";
                std::cin >> x >> y;
                if (trapezoid.isPointOnBoundary(x, y, tolerance)) {
                    std::cout << "Точка (" << x << ", " << y << ") находится на границе формы." << std::endl;
                } else {
                    std::cout << "Точка (" << x << ", " << y << ") не находится на границе формы." << std::endl;
                }
                break;
            case 2:
                if (trapezoid.intersectsXAxis()) {
                    std::cout << "Форма пересекает ось X." << std::endl;
                } else {
                    std::cout << "Форма не пересекает ось X." << std::endl;
                }
                break;
                case 3:
                if (trapezoid.intersectsYAxis()) {
                    std::cout << "Форма пересекает ось Y." << std::endl;
                } else {
                    std::cout << "Форма не пересекает ось Y." << std::endl;
                }
                break;
            case 4:
                if (trapezoid.isTrapezoidGeneral()) {
                    std::cout << "Форма является общим трапецоидом." << std::endl;
                } else if (trapezoid.isTrapezoidIsosceles()) {
                    std::cout << "Форма является равнобедренным трапецоидом." << std::endl;
                } else if (trapezoid.isTrapezoidRectangular()) {
                    std::cout << "Форма является прямоугольным трапецоидом." << std::endl;
                }
                break;
            case 5:
                std::cout << "Введите новые координаты центра (x y): ";
                std::cin >> newCenterX >> newCenterY;
                trapezoid.moveTo(newCenterX, newCenterY);
                trapezoid.displayParameters();
                break;
            case 6:
                trapezoid.resetPosition();
                trapezoid.displayParameters();
                break;
            case 0:
                std::cout << "Выход..." << std::endl;
                break;
            default:
                std::cout << "Недопустимый выбор. Попробуйте еще раз." << std::endl;
                break;
        }
    } while (choice != 0);

    return 0;
}