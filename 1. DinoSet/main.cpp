#include <iostream>
#include <iomanip>
#include "dinoset.h"

int main()
{
    DinoSet a;
    a.add(DinoId::velociraptor);
    a.add(DinoId::stegosaurus);
    std::cout << std::boolalpha;
    std::cout << a.contains(DinoId::velociraptor) << "\n";
    std::cout << a.contains(DinoId::tyrannosaurus) << "\n";
    std::cout << a.to_string() << "\n";
    return 0;
}
