# C++ primer

#### 13.6.2 Move Constructor and Move Assignment

- To enable move operations for our own types, we define a move a constructor and a move-assignment operator.
- In addition to moving resources, the move constructoor must ensure that the moved-from object is left in a state such that destroying that object will be harmless.

## Ch15 OOP

Object-oriented programming is base on three fundamental concepts: data abstraction and inheritance and dynamic binding.

### 15.1 OOP: An Overview

**Inheritance**:

  - A derived class must specify the class(es) from which it intends to inherit. It does so in a **class derivation list**, which in a colon followed by a comma-separated list of base classes each of which may have an optional specifier.
  - `override`

**Dynamic Binding**:

  - **run-time binding**
  - In C++, dynamic binding happens when a virtual function is called through a reference (or a pointer) to a base class.

**Member Functions and Inheritance**

**Access Control and Inheritance**

  - A derived class inherits the members defined in its base class. However, the member functions in a derived class may not necessarily access the members that are inerited from the base class.
  - A derived class may access the `public` members of its base class but may not access `private` members.
  - A derived class may include the `virtual` keyword on the functions it overrides, but it is not required to do so.
  - The fact that a derived object contains subobjects for its base classes is key to how inheritance works
  - A derived class must use a base-class constructor to initialize its base-class part.

```c++
Deribed(arg0, arg1, ...) : BaseConstructor(arg0, arg1,...), mem(argn) {}
```

  - A derived class may access the `public` and `protected` members of its base class.
  - The scope of a derived class is nested inside the scope of its base class.
  - If a base class defines a `static` member, there is only one such member defined for the entire heierarchy.
  - **Declaration** contains the class name but does not include its derivation list
  - `final`
  - The conversion from derived to base exists because every derived object contains a base-class part to which a pointer or reference of the base-class type can be found. A base-class object can exist either as an independent object or as part of a derived object.
  - The compiler has no way to know (at compile time) that a specific conversion will be safe at run time.
  - If the base class has one or more virtual functions, we can use a `dynamic_cast` to request a conversion that is checked at run time. Alternatively, in those cases when we know that the conversion from base to derived is safe, we can use a `static_cast` to override the compiler.
  - The automatic derived-to-base conversion applies only for conversions to a reference or pointer type.
  - When we initialize or assign an object of a base type from an object of a derived type, only the base-class part of the derived object is copied, moved or assigned. The derived part of the object is ignored.
  - Calls to nonvirtual functions are bound at compile time. Similarly, calls to any function (virtual or not) on an object are also bound at compile time.
  - The version of the virtual function that is run is the one defined by the type of the object to which the reference is bound or to which the pointer points.
  - It is legal for a derived class to define a function with the same name as a virtual in its base but with a different parameter list. The compiler considers such a function to be independent from the base-class function. In such cases, the derived version does not override the version in the base class.
  - We can specify `override` on a virtual function in a derived class. The compiler will reject a program if a function marked `override` does not override an existing virtual function.
  - When a call is made through a reference or pointer to base, the default arguments will be those in the base class. The base-class arguments will be used even when the dereived version of the function if run.
  - Virtual functions that have default arguments should use the same argument values in the base and derived classes.

### 15.4 Abstract Base Classes

### 15.5 Access Control and Inheritance

- Sometimes we need to change the access level of a name that a derived class inherits. We can do so by providing a `using` declaration.
- By default, a derived class defined with the `class` keyword has `private` inheritance; a derived class defined with `struct` has `public` inheritance.

### 15.6 Class Scope under Inheritance

- Under inheritance, the scope of a derived class is nested inside the scope of its base classes.

**Name Lookup Happens at Compile Time**

- Aside from overriding inherited virtual functions, a derived class usually should not reuse names defiend in its base class.
- The base member is hidden even if the functions have different parameter list.
- Instead of overriding every base-class version that it inherits, a derived class can provide a `using` declaration for the overloaded member. Thus, a `using` declaration for a base-class member function adds all the overloaded instances of that function to the scope of the derived class.

### 15.7 Constructors and Copy Control

**virtual destructors**
```c++
class Quote {
  public virtual ~Quote() = default;
};
```

- If that pointer points to a type in an inheritance hierarchy, it is possible that the static type of the pointer might differ from the dynamic type of the object being destroyed.
- Executing `delete` on a pointer to base that points to a derived object has undefined behavior if the base's destructor is not virtual.
- If a class defines a destructor -- even if it uses `=default` to use the synthesized version -- the compiler will not synthesize a move operator for that class.
- Unlike the constructors and assignment operators, the destructor is responsible only for destroying the resources allocated by the derived class.
- When a derived class defines a copy or move operation, that operation is responsible for copying or moving the entire object, including base-class members.

```c++
class Base { /* ... */ };
class D: public Base {
public:
  // by default, the base class default constructor initializes the base part of an object
  // to use the copy or move constructor, we must explicitly call that
  // constructor in the constructor initializer list
  D(const D& d) : Base(d) {}
  D(D&& d) : Base(std::move(d)) {}
}
```

- The base-class parts of an object are implicitly destroyed. As a result, unlike the constructors and assignment operators, a derived destructor is responsible only for destroying the resources allocated by the derived class.
