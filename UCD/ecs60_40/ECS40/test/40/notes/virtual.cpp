#include <iostream>
#include <cstring>

using namespace std;

class Animal
{
  char* name;

public:
  Animal(const char* nam)
  {
    if(nam)
    {
      name = new char[strlen(nam) + 1];
      strcpy(name, nam);
    }
    else
    {
      name = new char[1];
      name[0] = '\0';
    }
  }

  ~Animal()
  {
    delete[] name;
  }

  const char* getName() const
  {
    return name;
  }

  virtual void sound() const = 0;
};

class Cat : public Animal
{
public:
  Cat(const char* name) : Animal(name) {}

  void sound() const
  {
    cout << getName() << " says meow\n";
  }
};

class Dog : public Animal
{
public:
  Dog(const char* name) : Animal(name) {}

  void sound() const
  {
    cout << getName() << " says woof\n";
  }
};

class Tiger : public Cat
{
public:
  Tiger(const char* name) : Cat(name) {}

  void sound() const
  {
    cout << getName() << " says roar\n";
  }
};

int main()
{
  Cat cat("Tom");
  Dog dog("Spike");
  Tiger tiger("Tony");

  Animal* ptr = &cat;
  ptr->sound();  // Tom says meow  (Cat::sound)
  ptr = &dog;
  ptr->sound();  // Spike says woof  (Dog::sound)
  ptr = &tiger;
  ptr->sound();  // Tony says roar  (Tiger::sound)

  Cat* cptr = &cat;
  cptr->sound();  // Tom says meow  (Cat::sound)
  cptr = &tiger;
  cptr->sound(); // Tony says roar  (Tiger::sound even though not virtual in Cat)

  return 0;
}

