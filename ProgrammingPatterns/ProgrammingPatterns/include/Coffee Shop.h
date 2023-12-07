// Evita la inclusión múltiple del mismo archivo de encabezado
#pragma once

// Incluye el archivo de encabezado que contiene las dependencias necesarias
#include "Prerequisites.h"

// Clase principal que representa una tienda de café
class CoffeeShop {
public:
	// Método virtual para preparar café
	virtual void prepareCoffee() {
		cout << "Coffee prepared" << endl;
	}
};

// Clase abstracta para los condimentos del café
class CoffeeCondiment {
public:
	// Método virtual puro para agregar condimento al café
	virtual void addCondiment() = 0;
};

// Clase concreta para la leche como condimento
class Milk : public CoffeeCondiment {
public:
	// Constructor que recibe una instancia de la tienda de café
	Milk(CoffeeShop* _coffee) : m_coffee(_coffee) {}

	// Implementación del método para agregar leche al café
	virtual void addCondiment() override {
		m_coffee->prepareCoffee(); // Llama al método de preparación de café en la tienda
		cout << "Milk added" << endl; // Agrega leche al café
	}

private:
	CoffeeShop* m_coffee; // Puntero a la tienda de café
};

// Clase concreta para el azúcar como condimento
class Sugar : public CoffeeCondiment {
public:
	// Constructor que recibe una instancia de la tienda de café
	Sugar(CoffeeShop* _coffee) : m_coffee(_coffee) {}

	// Implementación del método para agregar azúcar al café
	virtual void addCondiment() override {
		m_coffee->prepareCoffee(); // Llama al método de preparación de café en la tienda
		cout << "Sugar added" << endl; // Agrega azúcar al café
	}

private:
	CoffeeShop* m_coffee; // Puntero a la tienda de café
};