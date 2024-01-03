#include <iostream>
using namespace std;

// class Pet {
// private:
//     string Name;
// public:
//     Pet(string n) : Name(n) {}
//     virtual string getSound() {
//         return "Say it";
//     }
//     void makeSound() {
//         cout << Name << " says: ";
//         cout << getSound() << endl;
//     }
// };

// class Cat : public Pet {
// public:
//     Cat(string n) : Pet(n) {}
//     string getSound() {
//         return "Meow! Meow!";
//     }
// };

// int main() {
//     Pet *a_pet = new Cat("Kitty");
//     cout << a_pet->getSound() << endl;
//     a_pet->makeSound();
//     return 0;
// }

class Pet {
      private:
            string Name;
      public:
            Pet(string n) { Name = n; }
           string getSound(){
                return "Say it";
            }
          void makeSound() {
             cout << Name << " says: ";
             cout<< getSound() << endl; 
          }
};

class Cat : public Pet {
       public:
			Cat(string n) : Pet(n) { }
 			string getSound() { 
				return "Meow! Meow!";
			}
}; 

int main() {
     Pet *a_pet = new Cat("Kitty");
     cout<< a_pet-> getSound();
     a_pet->makeSound();

}
