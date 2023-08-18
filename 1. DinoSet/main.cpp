#include <iostream>
#include <iomanip>
#include "dinoset.h"

int main()
{
    DinoSet a;
    a.add(DinoId::tyrannosaurus);
    a.add(DinoId::triceratops);
    // std::cout << std::boolalpha;
    // std::cout << a.contains(DinoId::velociraptor) << "\n";
    // std::cout << a.contains(DinoId::tyrannosaurus) << "\n";
    // std::cout << a.to_string() << "\n";

    DinoSet b;
    b.add(DinoId::triceratops);
    b.add(DinoId::stegosaurus);

    DinoSet c = a + b;

    std::cout << c.to_string() << "\n";

    return 0;
}
