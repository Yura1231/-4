#include <iostream>
#include <fstream>
#include <cmath>



const double PI = 3.14159265358979323846;

class Shape {
public:
    virtual double area() = 0;
    virtual void printInfo(std::ofstream& output) = 0;
};

class Circle : public Shape {



public:
    double radius;
    Circle(double r) : radius(r) {}

    double area() {
        return PI * radius * radius;
    }

    double circumference() {
        return 2 * PI * radius;
    }

    void printInfo(std::ofstream& output) {
        output << "Коло:\n";

        output << "Площа: " << area() << "\n";
        output << "Довжина кола: " << circumference() << "\n";
    }
};

class Rhombus : public Shape {


public:
    double diagonal1;
    double diagonal2;
    Rhombus(double d1, double d2) : diagonal1(d1), diagonal2(d2) {}

    double area() {
        return (diagonal1 * diagonal2) / 2.0;
    }

    void printInfo(std::ofstream& output) {
        output << "Ромб:\n";

        output << "Площа: " << area() << "\n";
    }
};

class CircleInRhombus : public Circle, public Rhombus {
public:
    CircleInRhombus(double r, double d1, double d2) : Circle(r), Rhombus(d1, d2) {}

    void printInfo(std::ofstream& output) {
        output << "Коло, вписане у Ромб:\n";
        output << "Радіус: " << Circle::radius << "\n";
        output << "Площа кола: " << Circle::area() << "\n";
        output << "Діагональ 1 Ромба: " << Rhombus::diagonal1 << "\n";
        output << "Діагональ 2 Ромба: " << diagonal2 << "\n";
        output << "Площа Ромба: " << Rhombus::area() << "\n";
    }
};

int main() {
    CircleInRhombus circleInRhombus(4.0, 6.0, 8.0);
    Circle circle(4.0);
    Rhombus rhombus(6.0, 8.0);
    std::ofstream outputFile("output.txt");

    if (outputFile.is_open()) {


        circle.printInfo(outputFile);
        rhombus.printInfo(outputFile);
        circleInRhombus.printInfo(outputFile);

        outputFile.close();
    }
    else {
        std::cerr << "Помилка відкриття файлу для запису.\n";
    }

    return 0;
}

