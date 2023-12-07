// Evita la inclusión múltiple del mismo archivo de encabezado
#pragma once
#include "Prerequisites.h"

// Incluye el archivo de encabezado que contiene las dependencias necesarias
class Prototype {
public:
    virtual Prototype* clonar() = 0;         // Método para clonar el prototipo
    virtual void configurar(string _value) = 0;  // Método para configurar el valor del prototipo
    virtual void print() = 0;                 // Método para imprimir información del prototipo
};

// Clase concreta que implementa la interfaz del prototipo
class PrototipocConcreto : public Prototype {
public:
    // Método para clonar el prototipo concreto
    Prototype* clonar() override {
        PrototipocConcreto* copy = new PrototipocConcreto();
        copy->configurar(m_value);
        return copy;
    }

    // Método para configurar el valor del prototipo concreto
    void configurar(string _value) override {
        m_value = _value;
    }

    // Método para imprimir información del prototipo concreto
    void print() override {
        cout << "Valor: " << m_value << endl;
    }

private:
    string m_value;  // Variable que almacena el valor del prototipo concreto
};