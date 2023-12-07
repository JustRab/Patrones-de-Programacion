// Evita la inclusión múltiple del mismo archivo de encabezado
#pragma once

// Incluye el archivo de encabezado que contiene las dependencias necesarias
#include "Prerequisites.h"

// Clase base para representar una pizza
class BPizza {
public:
    void agregarParte(const string& _parte) {
        m_partes.push_back(_parte);
    }

    void print() {
        cout << "Partes de la pizza: ";
        for (int i = 0; i < m_partes.size(); ++i) {
            cout << m_partes[i];
            if (i < m_partes.size() - 1) {
                cout << ", ";
            }
        }
        cout << endl;
    }

private:
    vector<string> m_partes;
};

// Clase abstracta para construir pizzas
class BuilderPizza {
public:
    virtual void buildMasa() = 0;
    virtual void buildSalsa() = 0;
    virtual void buildIngredientes() = 0;
    virtual BPizza* obtenerPizzaHawaiana() = 0;
    virtual BPizza* obtenerPizzaVegetariana() = 0;
};

// Clase concreta para construir pizzas
class ConstructorPizza : public BuilderPizza {
public:
    ConstructorPizza() {
        m_pizzaH = new BPizza();
        m_pizzaV = new BPizza();
    }

    void buildMasa() {
        m_pizzaH->agregarParte("Masa Tradicional");
        m_pizzaV->agregarParte("Masa Vegetariana");
    }

    void buildSalsa() {
        m_pizzaH->agregarParte("Salsa de Jitomate");
        m_pizzaV->agregarParte("Salsa de Jitomate");
    }

    void buildIngredientes() {
        m_pizzaH->agregarParte("Queso, Jamón & Piña");
        m_pizzaV->agregarParte("Queso, Champiñones & Pimiento");
    }

    BPizza* obtenerPizzaHawaiana() override {
        return m_pizzaH;
    }

    BPizza* obtenerPizzaVegetariana() override {
        return m_pizzaV;
    }

private:
    BPizza* m_pizzaH;
    BPizza* m_pizzaV;
};

// Clase para dirigir la construcción de pizzas
class DirectorPizza {
public:
    DirectorPizza(BuilderPizza* _builder) : m_builder(_builder) { }

    void build() {
        m_builder->buildMasa();
        m_builder->buildSalsa();
        m_builder->buildIngredientes();
    }

private:
    BuilderPizza* m_builder;
};