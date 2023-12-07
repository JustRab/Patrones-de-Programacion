// Evita la inclusión múltiple del mismo archivo de encabezado
#pragma once

// Incluye el archivo de encabezado que contiene las dependencias necesarias
#include "Prerequisites.h"

// Clase que representa un círculo
class Circle {
public:
	// Método para dibujar un círculo
	void drawCircle() {
		cout << "   *   \n";
		cout << " *   * \n";
		cout << "*     *\n";
		cout << " *   * \n";
		cout << "   *   \n";
	}
};

// Clase que representa un cuadrado
class Square {
public:
	// Método para dibujar un cuadrado
	void drawSquare() {
		cout << "* * * * *\n";
		cout << "*       *\n";
		cout << "*       *\n";
		cout << "*       *\n";
		cout << "* * * * *\n";
	}
};

// Interfaz Drawable que define el método de dibujo
class Drawable {
public:
	virtual void draw() {
		cout << "Drawable called." << endl;
	}
};

// Adaptador para dibujar un círculo usando la interfaz Drawable
class CircleAdapter : public Drawable {
public:
	// Constructor que recibe un círculo para adaptar
	CircleAdapter(Circle* _circle) : m_circle(_circle) {}

	// Implementación del método de dibujo utilizando el círculo
	void draw() override {
		m_circle->drawCircle();
	}

private:
	Circle* m_circle; // Puntero al círculo que se va a adaptar
};

// Adaptador para dibujar un cuadrado usando la interfaz Drawable
class SquareAdapter : public Drawable {
public:
	// Constructor que recibe un cuadrado para adaptar
	SquareAdapter(Square* _square) : m_square(_square) {}

	// Implementación del método de dibujo utilizando el cuadrado
	void draw() override {
		m_square->drawSquare();
	}

private:
	Square* m_square; // Puntero al cuadrado que se va a adaptar
};