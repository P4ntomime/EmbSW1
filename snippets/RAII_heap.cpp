void f()
{
  Person* p = new Person("irgendwer");
  // mach etwas mit p
  // Problem: hier tritt Exception auf
  delete p;
}



#include <memory>
void f()
{
  std::shared_ptr<Person> 
    p(new Person("irgendwer"))
  // mach etwas mit p
  // Beim Verlassen des Blocks raeumt Dtor von 
  // shared_ptr automatisch auf und loescht
  //  Person
}