#include "Prerequisites.h"
#include "Singleton.h"
#include "RegistroActividad.h"
#include "Factory.h"
#include "AbstractFactory.h"
#include "Builder.h"
#include "Pizza.h"
#include "Adapter.h"
#include "Drawing.h"
#include "Prototype.h"
#include "Document.h"
#include "Decorator.h"
#include "Coffee Shop.h"
#include "Composite.h"
#include "File.h"

// Instancias iniciales de las clases Singleton
Singleton* Singleton::m_instance = nullptr;
ActivityRegister* ActivityRegister::m_instance = nullptr;

int main() {
    // SINGLETON EXAMPLE
    cout << "========== SINGLETON EXAMPLE ==========" << endl;
    Singleton* SingleMan = Singleton::getInstance();
    SingleMan->setValue(27);

    Singleton* SingleMan2 = Singleton::getInstance();
    cout << "Value: " << SingleMan2->getValue() << endl;

    cout << "========================================" << endl;

    // SINGLETON ACTIVITY
    cout << "\n========== SINGLETON ACTIVITY ==========" << endl;
    ActivityRegister* Registro = ActivityRegister::getInstance();
    ActivityRegister* Registro2 = ActivityRegister::getInstance();
    Registro->addActivity("Primer actividad");
    Registro->addActivity("Segunda actividad");
    Registro->addActivity("Tercea actividad");
    Registro->addActivity("Cuarta actividad");

    Registro2->showActivities();

    cout << "========================================" << endl;

    // FACTORY EXAMPLE
    cout << "\n========== FACTORY EXAMPLE ==========" << endl;
    Factory* factory = new ConcreteFactory();
    Product* product = factory->crearProducto();
    product->operacion();

    delete factory;
    delete product;

    cout << "========================================" << endl;

    // FACTORY ACTIVITY
    cout << "\n========== FACTORY ACTIVITY ==========" << endl;
    FactoryVehiculos* factoryV = new ConcreteFactoryCoche();
    Vehiculo* vehiculo = factoryV->crearVehiculo();
    vehiculo->descripcion();

    delete factoryV;
    delete vehiculo;

    cout << "========================================" << endl;

    // ABSTRACT FACTORY EXAMPLE
    cout << "\n========== ABSTRACT FACTORY EXAMPLE ==========" << endl;
    AbstractFactory* AFactory = new ConcreteAbsFactory();
    ProductA* productA = AFactory->crearProductoA();
    ProductB* productB = AFactory->crearProductoB();
    productA->operationA();
    productB->operationB();

    delete AFactory;
    delete productA;
    delete productB;

    cout << "========================================" << endl;

    // BUILDER EXAMPLE
    cout << "\n========== BUILDER EXAMPLE ==========" << endl;
    Builder* constructor = new BuilderConcreto();
    Director director(constructor);

    director.build();

    BProduct* producto = constructor->obtenerProducto();
    producto->print();

    delete producto;
    delete constructor;

    cout << "\n========================================" << endl;

    // BUILDER ACTIVITY
    cout << "\n========== BUILDER ACTIVITY ==========" << endl;
    BuilderPizza* constructorPizza = new ConstructorPizza();
    DirectorPizza directorPizza(constructorPizza);

    directorPizza.build();

    BPizza* pizzaHawaiana = constructorPizza->obtenerPizzaHawaiana();
    BPizza* pizzaVegetariana = constructorPizza->obtenerPizzaVegetariana();

    pizzaHawaiana->print();
    pizzaVegetariana->print();

    delete pizzaHawaiana;
    delete pizzaVegetariana;
    delete constructorPizza;

    cout << "========================================" << endl;

    // ADAPTER
    cout << "\n========== ADAPTER EXAMPLE ==========" << endl;
    InterfazVieja* objetoViejo = new InterfazVieja();
    InterfazNueva* objetoNuevo = new Adapter(objetoViejo);

    objetoNuevo->NewMethod();

    delete objetoViejo;
    delete objetoNuevo;

    cout << "========================================" << endl;

    // ADAPTER ACTIVITY
    cout << "\n========== ADAPTER ACTIVITY ==========" << endl;
    Circle* circle = new Circle();
    Square* square = new Square();

    Drawable* circleAdapter = new CircleAdapter(circle);
    Drawable* squareAdapter = new SquareAdapter(square);

    circleAdapter->draw();
    squareAdapter->draw();

    delete circle;
    delete square;
    delete circleAdapter;
    delete squareAdapter;

    cout << "========================================" << endl;

    // PROTOTYPE EXAMPLE
    cout << "\n========== PROTOTYPE EXAMPLE ==========" << endl;
    Prototype* prototype = new PrototipocConcreto();
    prototype->configurar("Ejemplo");

    Prototype* copia = prototype->clonar();
    prototype->print();
    copia->print();

    delete prototype;
    delete copia;

    cout << "========================================" << endl;

    // PROTOTYPE ACTIVITY
    cout << "\n========== PROTOTYPE ACTIVITY ==========" << endl;
    DocumentPrototype* textPrototype = new TextDocument();
    textPrototype->configure("Hello World!");

    DocumentPrototype* imagePrototype = new ImageDocument();
    imagePrototype->configure("img_01.png");

    DocumentPrototype* textCopy = textPrototype->clone();
    DocumentPrototype* imageCopy = imagePrototype->clone();

    textCopy->configure("Hello to you!");
    imageCopy->configure("img_02.png");

    textPrototype->configure("Hello World! | ORIGINAL");
    imagePrototype->configure("img_01.png | ORGINAL");

    textPrototype->clone()->print();
    textCopy->print();

    imagePrototype->clone()->print();
    imageCopy->print();

    cout << "========================================" << endl;

    // DECORATOR
    cout << "\n========== DECORATOR EXAMPLE ==========" << endl;
    ConcreteComponent* objeto = new ConcreteComponent();
    ConcreteDecoratorA* decoratorA = new ConcreteDecoratorA(objeto);
    ConcreteDecoratorB* decoratorB = new ConcreteDecoratorB(decoratorA);

    objeto->operacion();
    decoratorA->operacion();
    decoratorB->operacion();

    delete objeto;
    delete decoratorA;
    delete decoratorB;

    cout << "========================================" << endl;

    // DECORATOR ACTIVITY
    cout << "\n========== DECORATOR ACTIVITY ==========" << endl;
    CoffeeShop* coffee = new CoffeeShop();
    Milk* coffeWithMilk = new Milk(coffee);
    Sugar* coffeWithSugar = new Sugar(coffee);

    coffee->prepareCoffee();
    coffeWithMilk->addCondiment();
    coffeWithSugar->addCondiment();

    delete coffee;
    delete coffeWithMilk;
    delete coffeWithSugar;

    cout << "========================================" << endl;

    // COMPOSITE
    cout << "\n========== COMPOSITE EXAMPLE ==========" << endl;
    Leaf* hoja1 = new Leaf();
    Leaf* hoja2 = new Leaf();
    Composite* composite = new Composite();

    composite->addLeaf(hoja1);
    composite->addLeaf(hoja2);

    composite->operacion();

    delete hoja1;
    delete hoja2;
    delete composite;

    cout << "========================================" << endl;

    // COMPOSITE ACTIVITY
    cout << "\n========== COMPOSITE ACTIVITY ==========" << endl;
    SystemFile* file_01 = new SystemFile();
    SystemFile* file_02 = new SystemFile();

    SystemFolder* folder_01 = new SystemFolder();

    folder_01->agregarSistema(file_01);
    folder_01->agregarSistema(file_02);

    folder_01->ShowInfo();

    delete file_01;
    delete file_02;
    delete folder_01;

    cout << "========================================" << endl;

    return 0;
}