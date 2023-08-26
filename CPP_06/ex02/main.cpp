#include <cstdlib>
#include <ctime>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void) {
    int random = std::rand();
    if (random % 4 == 1)
        return new A;
    else if (random % 3 == 0)
        return new B;
    else if (random % 3 == 2)
        return new C;
    else
        return new Base;
}

void identify(Base* p) {
    if(dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if(dynamic_cast<B*>(p))
        std::cout << "B"<< std::endl;
    else if(dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else  
        std::cout << "Unindentified Pointer Restart PC" << std::endl;
}

void identify(Base& p) {
    if(dynamic_cast<A*>(&p))
        std::cout << "A" << std::endl;
    else if(dynamic_cast<B*>(&p))
        std::cout << "B"<< std::endl;
    else if(dynamic_cast<C*>(&p))
        std::cout << "C" << std::endl;
    else  
        std::cout << "Unindentified Reference Reset Memory" << std::endl;
}

int main() {
    std::srand(std::time(0));
    Base *base[10];
    for(int i = 0; i < 10; i++) {
        base[i] = generate();
        std::cout << "\nID = " << i << std::endl;
        std::cout << "pointer = "; identify(base[i]);
        std::cout << "reference = "; identify(*base[i]);
    }
    for(int i = 0; i < 10; i++){
        delete base[i];
    }
}