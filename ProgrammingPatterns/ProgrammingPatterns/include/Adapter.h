// Evita la inclusión múltiple del mismo archivo de encabezado
#pragma once

// Incluye el archivo de encabezado que contiene las dependencias necesarias
#include "Prerequisites.h"

// Clase de interfaz vieja (deprecada)
class InterfazVieja {
public:
	// Método de interfaz vieja
	virtual void OldMethod() {
		cout << "Metodo viejo llamado." << endl;
	}
};

// Clase de interfaz nueva (objetivo)
class InterfazNueva {
public:
	// Método de interfaz nueva
	virtual void NewMethod() {
		cout << "Metodo nuevo llamado." << endl;
	}
};

// Clase de adaptador que hereda de la interfaz nueva
class Adapter : public InterfazNueva {
public:
	// Constructor que recibe un puntero a la interfaz vieja
	Adapter(InterfazVieja* _vieja) : m_interfazVieja(_vieja) {}

	// Implementación del método de la interfaz nueva
	void NewMethod() override {
		cout << "Adaptador llamado al metodo nuevo." << endl;
		// Llama al método de la interfaz vieja dentro del adaptador
		m_interfazVieja->OldMethod();
	}

private:
	InterfazVieja* m_interfazVieja; // Puntero a la interfaz vieja
};