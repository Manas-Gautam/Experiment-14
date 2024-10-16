# Experiment-14
## Theory: - 
### Inheritance in C++

**Inheritance** is one of the core concepts of object-oriented programming (OOP) in C++. It allows one class (called a **derived class** or **child class**) to inherit attributes and behaviors (methods) from another class (called a **base class** or **parent class**). Inheritance facilitates code reuse, establishes a relationship between classes, and allows the creation of a class hierarchy.

### Key Concepts of Inheritance:

1. **Base Class (Parent Class):** The class whose properties and methods are inherited by another class.
2. **Derived Class (Child Class):** The class that inherits from the base class.
3. **Access Specifiers in Inheritance:** The `public`, `protected`, and `private` access specifiers control the visibility of the base class members in the derived class.
4. **Types of Inheritance:** C++ supports various types of inheritance, including:
   - Single inheritance
   - Multiple inheritance
   - Multilevel inheritance
   - Hierarchical inheritance
   - Hybrid inheritance

### 1. **Basic Syntax of Inheritance:**

The syntax for creating a derived class from a base class is:

```cpp
class BaseClass {
    // Base class members
};

class DerivedClass : access_specifier BaseClass {
    // Derived class members
};
```

The `access_specifier` can be `public`, `protected`, or `private`, and it determines how the members of the base class are accessible in the derived class.

### 2. **Types of Inheritance:**

#### a) **Single Inheritance:**
Single inheritance occurs when a class inherits from one base class.

```cpp
class Base {
public:
    int x;
    void show() {
        cout << "Base class show()" << endl;
    }
};

class Derived : public Base {
public:
    void display() {
        cout << "Derived class display()" << endl;
    }
};

int main() {
    Derived obj;
    obj.show();    // Inherited from Base class
    obj.display(); // Derived class method
    return 0;
}
```

#### Output:
```
Base class show()
Derived class display()
```

In this example, `Derived` class inherits from the `Base` class, and the `show()` method is accessible to objects of the `Derived` class.

#### b) **Multiple Inheritance:**
Multiple inheritance occurs when a class inherits from more than one base class.

```cpp
class Base1 {
public:
    void show() {
        cout << "Base1 class show()" << endl;
    }
};

class Base2 {
public:
    void display() {
        cout << "Base2 class display()" << endl;
    }
};

class Derived : public Base1, public Base2 {
    // Derived class inheriting from both Base1 and Base2
};

int main() {
    Derived obj;
    obj.show();    // Inherited from Base1
    obj.display(); // Inherited from Base2
    return 0;
}
```

#### Output:
```
Base1 class show()
Base2 class display()
```

Here, the `Derived` class inherits from both `Base1` and `Base2`.

#### c) **Multilevel Inheritance:**
In multilevel inheritance, a class is derived from a class that is also derived from another class.

```cpp
class Base {
public:
    void show() {
        cout << "Base class show()" << endl;
    }
};

class Intermediate : public Base {
public:
    void display() {
        cout << "Intermediate class display()" << endl;
    }
};

class Derived : public Intermediate {
public:
    void print() {
        cout << "Derived class print()" << endl;
    }
};

int main() {
    Derived obj;
    obj.show();    // Inherited from Base class
    obj.display(); // Inherited from Intermediate class
    obj.print();   // Derived class method
    return 0;
}
```

#### Output:
```
Base class show()
Intermediate class display()
Derived class print()
```

Here, `Derived` inherits from `Intermediate`, and `Intermediate` inherits from `Base`.

#### d) **Hierarchical Inheritance:**
In hierarchical inheritance, multiple classes inherit from the same base class.

```cpp
class Base {
public:
    void show() {
        cout << "Base class show()" << endl;
    }
};

class Derived1 : public Base {
public:
    void display1() {
        cout << "Derived1 class display1()" << endl;
    }
};

class Derived2 : public Base {
public:
    void display2() {
        cout << "Derived2 class display2()" << endl;
    }
};

int main() {
    Derived1 obj1;
    Derived2 obj2;
    
    obj1.show();    // Inherited from Base
    obj1.display1(); // Derived1 method
    
    obj2.show();    // Inherited from Base
    obj2.display2(); // Derived2 method

    return 0;
}
```

#### Output:
```
Base class show()
Derived1 class display1()
Base class show()
Derived2 class display2()
```

Both `Derived1` and `Derived2` inherit from the `Base` class.

#### e) **Hybrid Inheritance:**
Hybrid inheritance is a combination of two or more types of inheritance. It often involves a combination of hierarchical and multiple inheritance.

### 3. **Access Specifiers in Inheritance:**

- **Public Inheritance:** When the base class is inherited publicly, all the public members of the base class remain public in the derived class, and protected members remain protected.
  ```cpp
  class Derived : public Base { };
  ```
- **Protected Inheritance:** When inherited with protected access, public and protected members of the base class become protected in the derived class.
  ```cpp
  class Derived : protected Base { };
  ```
- **Private Inheritance:** When inherited privately, all public and protected members of the base class become private in the derived class.
  ```cpp
  class Derived : private Base { };
  ```

#### Example: Access Specifiers in Inheritance

```cpp
class Base {
protected:
    int x;
public:
    Base() : x(10) { }
};

class Derived : public Base {
public:
    void display() {
        cout << "x = " << x << endl;  // Accessing protected member of base class
    }
};

int main() {
    Derived obj;
    obj.display();  // Allowed
    // obj.x = 20;  // Error: x is protected in Derived class
    return 0;
}
```

### 4. **Constructor and Destructor in Inheritance:**

- **Constructor Order:** When an object of a derived class is created, the constructor of the base class is called first, followed by the constructor of the derived class.
- **Destructor Order:** When an object of a derived class is destroyed, the destructor of the derived class is called first, followed by the destructor of the base class.

#### Example: Constructor and Destructor Order

```cpp
#include <iostream>
using namespace std;

class Base {
public:
    Base() { cout << "Base class constructor" << endl; }
    ~Base() { cout << "Base class destructor" << endl; }
};

class Derived : public Base {
public:
    Derived() { cout << "Derived class constructor" << endl; }
    ~Derived() { cout << "Derived class destructor" << endl; }
};

int main() {
    Derived obj;
    return 0;
}
```

#### Output:
```
Base class constructor
Derived class constructor
Derived class destructor
Base class destructor
```

### 5. **Virtual Inheritance:**
Virtual inheritance is used to solve the **diamond problem** (ambiguity caused by multiple inheritance) by ensuring that only one instance of the base class is inherited by the derived classes.

```cpp
class Base {
public:
    int x;
};

class Derived1 : virtual public Base { };

class Derived2 : virtual public Base { };

class Final : public Derived1, public Derived2 { };
```

In this example, the class `Final` only gets a single instance of `Base`, avoiding ambiguity.


## Experimnet 14{A}: - Single Inheritance

## Code: - 

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

## Output: - 
![image](https://github.com/user-attachments/assets/a63bff46-f941-44bf-91b5-8ba11bb1f9ea)

## Experimnet 14{B}: - Multiple Inheritance
## Code: - 

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

## Output:- 
![image](https://github.com/user-attachments/assets/f3de63b8-ecce-4fc0-abfe-462cbef146f0)

## Experimnet 14{C}: - Multilevel Inheritance

## Code: - 

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

## Output: - 
![image](https://github.com/user-attachments/assets/1d4bb709-2b0e-4a2c-aadb-a14231e9923a)

## Experiment 14 {D}: - Hierarchical Inheritance

## Code :- 

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

## Output: - 
![image](https://github.com/user-attachments/assets/efe353eb-f6b9-4ab0-b428-e1a1caf5eb3c)


### Conclusion:

Inheritance in C++ allows for code reuse and establishes a relationship between classes. It provides a mechanism to create new classes based on existing ones, leading to a hierarchical class structure. Proper use of inheritance can simplify the code, promote reusability, and establish a logical structure for class-based programs. However, it should be used thoughtfully to avoid complexities like the diamond problem, which can be resolved with virtual inheritance.
