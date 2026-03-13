// Copyright 2022 UNN-CS
#include <iostream>
#include <iomanip>
#include "circle.h"
#include "tasks.h"

int main() {
    std::cout << std::fixed << std::setprecision(6);
    std::cout << "=== Тестирование класса Circle ===\n\n";
    // Создание круга с радиусом 5
    Circle c1(5.0);
    std::cout << "Круг с радиусом 5.0:\n";
    std::cout << "  Радиус: " << c1.getRadius() << " м\n";
    std::cout << "  Длина окружности: " << c1.getFerence() << " м\n";
    std::cout << "  Площадь: " << c1.getArea() << " м²\n\n";
    // Изменение радиуса
    c1.setRadius(10.0);
    std::cout << "После установки радиуса 10.0:\n";
    std::cout << "  Радиус: " << c1.getRadius() << " м\n";
    std::cout << "  Длина окружности: " << c1.getFerence() << " м\n";
    std::cout << "  Площадь: " << c1.getArea() << " м²\n\n";
    // Изменение длины окружности
    Circle c2(0);
    c2.setFerence(31.415926);
    std::cout << "Круг с длиной окружности 31.415926 м:\n";
    std::cout << "  Радиус: " << c2.getRadius() << " м\n";
    std::cout << "  Длина окружности: " << c2.getFerence() << " м\n";
    std::cout << "  Площадь: " << c2.getArea() << " м²\n\n";
    // Изменение площади
    Circle c3(0);
    c3.setArea(78.539816);
    std::cout << "Круг с площадью 78.539816 м²:\n";
    std::cout << "  Радиус: " << c3.getRadius() << " м\n";
    std::cout << "  Длина окружности: " << c3.getFerence() << " м\n";
    std::cout << "  Площадь: " << c3.getArea() << " м²\n\n";
    
    std::cout << "=== Решение задач ===\n\n";
    // Задача "Земля и веревка"
    double gap = calculateEarthRopeGap();
    std::cout << "Задача 'Земля и веревка':\n";
    std::cout << "  Радиус Земли: 6378.1 км\n";
    std::cout << "  Добавлено: 1 м к длине веревки\n";
    std::cout << "  Зазор: " << gap << " м (≈ " << gap * 100 << " см)\n\n";
    // Задача "Бассейн"
    double totalCost = calculatePoolCost();
    std::cout << "Задача 'Бассейн':\n";
    std::cout << "  Радиус бассейна: 3 м\n";
    std::cout << "  Ширина дорожки: 1 м\n";
    std::cout << "  Стоимость бетона: 1000 руб/м²\n";
    std::cout << "  Стоимость ограды: 2000 руб/м\n";
    // Детальный расчет для наглядности
    Circle pool(3.0);
    Circle outer(4.0);
    double pathArea = outer.getArea() - pool.getArea();
    double concreteCost = pathArea * 1000.0;
    double fenceCost = outer.getFerence() * 2000.0;
    std::cout << "  Площадь дорожки: " << pathArea << " м²\n";
    std::cout << "  Стоимость бетона: " << concreteCost << " руб\n";
    std::cout << "  Длина ограды: " << outer.getFerence() << " м\n";
    std::cout << "  Стоимость ограды: " << fenceCost << " руб\n";
    std::cout << "  ОБЩАЯ СТОИМОСТЬ: " << totalCost << " руб\n";
    return 0;
}
