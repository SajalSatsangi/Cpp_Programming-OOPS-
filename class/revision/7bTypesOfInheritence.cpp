#include <iostream>
using namespace std;

// TYPES OF INHERITENCE--->

// SINGLE INHERITENCE :- In which one class is inherite the another class.
/*class base_class_1
{
  class definition
};
class derived_class : visibility_mode base_class_1
{
  class definition
};*/

// MULTILEVEL INHERITENCE : -In which class we can inherite the class in multilevel means child1 inherite the parent class and child2 inherite the child 1 so it called mulilevel inheritence
/*class class_A
{
  class definition
};
class class_B : visibility_mode class_A
{
  class definition
};
class class_C : visibility_mode class_B
{
  class definition
};
----->>>> note :- in this type of inheritence there is a problem of ambiguity which comes when multiple classes have same name function so class will confuse, after calling the child class it has a problem to give priority so for solving this probelm we use scope resolution operator
for example -->  
Class_C child;
child.Class_B :: function name();
*/


// MULTIPLE INHERITENCE : -
/*class class_A
{
class definition
};
class class_B: visibility_mode class_A
{
class definition
};
class class_C: visibility_mode class_B
{
class definition
};*/

// HIERARCHICAL INHERITENCE : - The inheritance in which a single base class inherits multiple derived classes is known as the Hierarchical Inheritance.
/*class class_A
{
class definition
};
class class_B: visibility_mode class_A
{
class definition
};
class class_C : visibility_mode class_A
{
class definition
};
class class_D: visibility_mode class_B
{
class definition
};
class class_E: visibility_mode class_C
{
class definition
};*/

// HYBRID INHERITENCE : -
/* class class_A
{
class definition
};
class class_B
{
class definition
};
class class_C: visibility_mode class_A, visibility_mode class_B
{
class definition
};
class class_D: visibility_mode class_C
{
class definition
};
class class_E: visibility_mode class_C
{
class definition
};*/




    int main()
{

  return 0;
}