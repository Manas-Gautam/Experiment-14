//Name: - Manas Gautam
//PRN: - 23070123081
//Batch: - E&Tc {B}

// Experimnet 14 A: -

#include <iostream>
using namespace std;

// Base class
class Vehicle {
public:
    void start() {
        cout << "Vehicle is starting" << endl;
    }
};

// Derived class
class Car : public Vehicle {
public:
    void honk() {
        cout << "Car is honking" << endl;
    }
};

int main() {
    Car myCar;
    myCar.start(); // Inherited from Vehicle
    myCar.honk();  // Method of Car class
    return 0;
}

// Experimnet 14{B}: - 

#include <iostream>
using namespace std;

// Base class 1
class Printer {
public:
    void printDocument() {
        cout << "Printer is printing a document" << endl;
    }
};

// Base class 2
class Scanner {
public:
    void scanDocument() {
        cout << "Scanner is scanning a document" << endl;
    }
};

// Derived class
class AllInOne : public Printer, public Scanner {
public:
    void faxDocument() {
        cout << "AllInOne is faxing a document" << endl;
    }
};

int main() {
    AllInOne device;
    device.printDocument();  
    device.scanDocument();   
    device.faxDocument();    
    return 0;
}

//Experiment 14{C}: - 

#include <iostream>
using namespace std;

// Base class
class Shape {
public:
    void setDimensions(int w, int h) {
        width = w;
        height = h;
    }
    void showDimensions() {
        cout << "Width: " << width << ", Height: " << height << endl;
    }

protected:
    int width;
    int height;
};

// Derived class from Shape
class Rectangle : public Shape {
public:
    int area() {
        return width * height;
    }
};

// Derived class from Rectangle
class ColoredRectangle : public Rectangle {
public:
    void setColor(string c) {
        color = c;
    }
    void showColor() {
        cout << "Color: " << color << endl;
    }

private:
    string color;
};

int main() {
    ColoredRectangle myRectangle;
    myRectangle.setDimensions(5, 10); 
    myRectangle.showDimensions();    

    cout << "Area: " << myRectangle.area() << endl; 

    myRectangle.setColor("Blue");      
    myRectangle.showColor();           

    return 0;
}

//Experiment 14{D}: - 


#include <iostream>
using namespace std;
// Base class
class Animal {
public:
    void eat() {
        cout << "Animal is eating" << endl;
    }
};
// Derived class 1
class Dog : public Animal {
public:
    void bark() {
        cout << "Dog is barking" << endl;
    }
};
// Derived class 2
class Cat : public Animal {
public:
    void meow() {
        cout << "Cat is meowing" << endl;
    }
};

int main() {
    Dog d;
    Cat c;
    d.eat();  // Inherited from Animal
    d.bark(); // Method of Dog class

    c.eat();  // Inherited from Animal
    c.meow(); // Method of Cat class
    return 0;
}