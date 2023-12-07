// Evita la inclusión múltiple del mismo archivo de encabezado
#pragma once

// Incluye el archivo de encabezado que contiene las dependencias necesarias
#include "Prerequisites.h"

// Clase base para representar un archivo
class File {
public:
    virtual void ShowInfo() {
        cout << "Hey! I'm a file :D" << endl; // Muestra información predeterminada para un archivo
    }
};

// Clase base para representar una carpeta
class Folder {
public:
    virtual void ShowInfo() {
        cout << "Hi there! I'm a folder >:D" << endl; // Muestra información predeterminada para una carpeta
    }
};

// Clase abstracta que representa un sistema
class System {
public:
    virtual void ShowInfo() = 0; // Método virtual puro para mostrar información del sistema
};

// Clase concreta que representa un archivo en el sistema
class SystemFile : public File, public System {
public:
    void ShowInfo() override {
        cout << "File Operation." << endl; // Muestra información específica para operaciones de archivo

        for (auto leaf : m_file) {
            leaf->ShowInfo(); // Muestra información de los archivos contenidos en este archivo
        }
    }

    void addFile(System* _file) {
        m_file.push_back(_file); // Agrega un archivo al sistema de archivos
    }

private:
    vector<System*> m_file; // Almacena archivos contenidos en este archivo (sistema de archivos)
};

// Clase concreta que representa una carpeta en el sistema
class SystemFolder : public Folder, public System {
public:
    void ShowInfo() override {
        cout << "Folder Operation" << endl; // Muestra información específica para operaciones de carpeta

        for (auto leaf : m_folder) {
            leaf->ShowInfo(); // Muestra información de los archivos y carpetas contenidos en esta carpeta
        }
    }

    void agregarSistema(System* _folder) {
        m_folder.push_back(_folder); // Agrega un archivo o carpeta al sistema de archivos
    }

private:
    vector<System*> m_folder; // Almacena archivos y carpetas contenidos en esta carpeta (sistema de archivos)
};