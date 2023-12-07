// Evita la inclusión múltiple del mismo archivo de encabezado
#pragma once

// Clase Singleton que almacena un valor entero
class Singleton {
public:
    Singleton() : m_value(0) {};  // Constructor por defecto inicializa el valor a 0

    // Método estático para obtener la instancia única del Singleton
    static Singleton* getInstance() {
        if (m_instance != nullptr) {
            return m_instance;
        }
        else {
            m_instance = new Singleton;  // Crea una nueva instancia si no existe
        }
        return m_instance;
    }

    ~Singleton() = default;  // Destructor predeterminado

    // Método para establecer el valor del Singleton
    void setValue(int _v) {
        m_value = _v;
    }

    // Método para obtener el valor almacenado en el Singleton
    int getValue() {
        return m_value;
    }

private:
    static Singleton* m_instance;  // Instancia única de la clase (Singleton)
    int m_value;                  // Valor almacenado en el Singleton
};