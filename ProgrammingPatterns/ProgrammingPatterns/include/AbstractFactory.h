// Evita la inclusión múltiple del mismo archivo de encabezado
#pragma once

// Incluye el archivo de encabezado que contiene las dependencias necesarias
#include "Prerequisites.h"

// Clase base para productos A
class ProductA {
public:
    virtual void operationA() = 0; // Método virtual puro para la operación A
};

// Clase base para productos B
class ProductB {
public:
    virtual void operationB() = 0; // Método virtual puro para la operación B
};

// Clase abstracta para la fábrica abstracta
class AbstractFactory {
public:
    virtual ProductA* crearProductoA() = 0; // Método virtual puro para crear ProductoA
    virtual ProductB* crearProductoB() = 0; // Método virtual puro para crear ProductoB
};

// Clase concreta para productos A
class productA1 : public ProductA {
public:
    void operationA() override {
        cout << "Operación A en ProductoA1" << endl; // Implementación de la operación A para ProductA1
    }
};

// Clase concreta para productos B
class productB1 : public ProductB {
public:
    void operationB() override {
        cout << "Operación B en ProductoB1" << endl; // Implementación de la operación B para ProductB1
    }
};

// Clase concreta para la fábrica abstracta
class ConcreteAbsFactory : public AbstractFactory {
public:
    ProductA* crearProductoA() override {
        return new productA1(); // Crear una instancia de ProductA1
    }
    ProductB* crearProductoB() override {
        return new productB1(); // Crear una instancia de ProductB1
    }
};
