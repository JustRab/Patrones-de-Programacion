// Evita la inclusión múltiple del mismo archivo de encabezado
#pragma once

// Incluye el archivo de encabezado que contiene las dependencias necesarias
#include "Prerequisites.h"

// Clase encargada de ser el objeto base de los productos que se crearán
class Product {
public:
    virtual void operacion() = 0; // Método virtual puro para la operación del producto
};

// Clase que es el objeto base que sirve para crear las instancias de cada producto con la función "crearProducto()"
class Factory {
public:
    virtual Product* crearProducto() = 0; // Método virtual puro para crear productos
};

// Clase usada para realizar operaciones tras recibir el producto
class ConcreteProduct : public Product {
public:
    void operacion() override {
        cout << "Acá se realiza una operación" << endl; // Implementación de la operación en el producto concreto
    }
};

//Clase usada para crear nuevos productos
class ConcreteFactory : public Factory {
public:
    Product* crearProducto() override {
        return new ConcreteProduct(); // Crea una instancia del producto concreto
    }
};

// ACTVIDAD FACTORY

class Vehiculo {
public:
    virtual void descripcion() {
        cout << "Hola, soy un vehículo" << endl; // Descripción predeterminada para un vehículo
    }
};

class ConcreteCoche : public Vehiculo {
public:
    void descripcion() override {
        cout << "Hola, soy un coche" << endl; // Descripción específica para un coche
    }
};

class ConcreteBicicleta : public Vehiculo {
public:
    void descripcion() override {
        cout << "Hola, soy una bicicleta" << endl; // Descripción específica para una bicicleta
    }
};

class FactoryVehiculos {
public:
    virtual Vehiculo* crearVehiculo() = 0; // Método virtual puro para crear vehículos
};

class ConcreteFactoryCoche : public FactoryVehiculos {
public:
    Vehiculo* crearVehiculo() override {
        return new ConcreteCoche(); // Crea una instancia de un coche
    }
};

class ConcreteFactoryBicicleta : public FactoryVehiculos {
public:
    Vehiculo* crearVehiculo() override {
        return new ConcreteBicicleta(); // Crea una instancia de una bicicleta
    }
};