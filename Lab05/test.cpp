AnimalPen a1;
FarmAnimal* a = new Cow();
Cow* c = static_cast<Cow*>(a);
c -> setMilkProduced(10);

a1.addAnimal(a);
std::cout << a1.peakAtNextAnimal();

std::cout << c->getMilkProduced();
