#include <string>
#include <iostream>

class Person {
public:
  std::string name;
  Person(std::string name) : name(name) {}
  void hello() {
    std::string text = "Hello! I'm ";
    text += name;
    std::cout << text << std::endl;
  }
};

int main() {
  Person john = Person("john");
  john.hello();
}