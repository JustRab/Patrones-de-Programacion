// Evita la inclusión múltiple del mismo archivo de encabezado
#pragma once

// Incluye el archivo de encabezado que contiene las dependencias necesarias
#include "Prerequisites.h"

// Clase Singleton que registra actividades
class ActivityRegister {
public:
    ActivityRegister() : m_numActs(0) {}

    // Método estático para obtener la instancia única del registro de actividades
    static ActivityRegister* getInstance() {
        if (m_instance != nullptr) {
            return m_instance;
        }
        else {
            m_instance = new ActivityRegister;  // Crea una nueva instancia si no existe
        }
        return m_instance;
    }

    // Método para agregar una actividad al registro
    void addActivity(const string activity) {
        if (m_numActs < m_maxActs) {
            m_acts.push_back(activity);  // Agrega la actividad al registro si hay espacio disponible
            m_numActs++;
        }
        else {
            cout << "Activity register is full." << endl;  // Muestra un mensaje si el registro está lleno
        }
    }

    // Método para mostrar todas las actividades registradas
    void showActivities() {
        cout << "Activity Register:" << endl;
        for (const string activity : m_acts) {
            cout << activity << endl;  // Imprime cada actividad registrada
        }
    }

private:
    static ActivityRegister* m_instance;  // Instancia única de la clase (Singleton)
    static const int m_maxActs = 20;      // Número máximo de actividades que pueden registrarse
    vector<string> m_acts;                // Vector que almacena las actividades registradas
    int m_numActs;                        // Número actual de actividades registradas
};