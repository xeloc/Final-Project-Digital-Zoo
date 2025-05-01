#include <iostream>
#include <vector>
#include <memory>

// Supporting class: Diet
class Diet {
    std::string type;
public:
    Diet(const std::string& type) : type(type) {}
    std::string getType() const { return type; }
};

// Supporting class: Habitat
class Habitat {
    std::string description;
public:
    Habitat(const std::string& description) : description(description) {}
    std::string getDescription() const { return description; }
};

// Base class: Animal
class Animal {
protected:
    std::string name;
    int age;
    const std::string species;
    Diet diet;
    Habitat habitat;

public:
    Animal(const std::string& name, int age, const std::string& species,
        const Diet& diet, const Habitat& habitat)
        : name(name), age(age), species(species), diet(diet), habitat(habitat) {
    }

    virtual ~Animal() {}

    virtual void makeSound() const = 0;
    virtual void eat() const = 0;

    virtual void displayInfo() const final {
        std::cout << "Name: " << name << "\n"
            << "Age: " << age << "\n"
            << "Species: " << species << "\n"
            << "Diet Type: " << diet.getType() << "\n"
            << "Habitat: " << habitat.getDescription() << "\n"
            << "--------------------------" << std::endl;
    }
};

// Derived class: Lion
class Lion : public Animal {
public:
    Lion(const std::string& name, int age, const Diet& diet, const Habitat& habitat)
        : Animal(name, age, "Lion", diet, habitat) {
    }

    void makeSound() const override {
        std::cout << name << " roars!" << std::endl;
    }

    void eat() const override {
        std::cout << name << " is eating meat." << std::endl;
    }
};

// Derived class: Elephant
class Elephant : public Animal {
public:
    Elephant(const std::string& name, int age, const Diet& diet, const Habitat& habitat)
        : Animal(name, age, "Elephant", diet, habitat) {
    }

    void makeSound() const override {
        std::cout << name << " trumpets!" << std::endl;
    }

    void eat() const override {
        std::cout << name << " is munching on plants." << std::endl;
    }
};

// Derived class: Panda
class Panda : public Animal {
public:
    Panda(const std::string& name, int age, const Diet& diet, const Habitat& habitat)
        : Animal(name, age, "Panda", diet, habitat) {
    }

    void makeSound() const override {
        std::cout << name << " squeaks softly!" << std::endl;
    }

    void eat() const override {
        std::cout << name << " is chewing bamboo." << std::endl;
    }
};

// Derived class: Aardvark
class Aardvark : public Animal {
public:
    Aardvark(const std::string& name, int age, const Diet& diet, const Habitat& habitat)
        : Animal(name, age, "Aardvark", diet, habitat) {
    }

    void makeSound() const override {
        std::cout << name << " snorts softly!" << std::endl;
    }

    void eat() const override {
        std::cout << name << " licks up ants with its tongue." << std::endl;
    }
};

void makeAllAnimalsSound(const std::vector<Animal*>& zoo) {
    for (const auto& animal : zoo) {
        animal->makeSound();
    }
}

int main() {
    // Diets and Habitats
    Diet carnivore("Carnivore");
    Diet herbivore("Herbivore");
    Diet insectivore("Insectivore");
    Diet bamboo("Bamboo");

    Habitat savannah("Open Savannah");
    Habitat rainforest("Dense Rainforest");
    Habitat mountains("Mountain Forests");
    Habitat desert("Arid Desert");

    // animals with names
    Lion* toph = new Lion("Toph", 5, carnivore, savannah);
    Lion* zuko = new Lion("Zuko", 6, carnivore, savannah);

    Elephant* katara = new Elephant("Katara", 8, herbivore, rainforest);
    Elephant* sokka = new Elephant("Sokka", 7, herbivore, rainforest);

    Panda* aang = new Panda("Aang", 10, bamboo, mountains);
    Aardvark* iroh = new Aardvark("Iroh", 12, insectivore, desert);

    Panda* bumi = new Panda("Bumi", 9, bamboo, mountains);

    // Store animals in zoo collection
    std::vector<Animal*> zoo = { toph, zuko, katara, sokka, aang, iroh, bumi };

    std::cout << "\nAnimal Sounds in the Zoo:\n";
    makeAllAnimalsSound(zoo);

    // animal information
    std::cout << "\nAnimal Info:\n";
    for (Animal* animal : zoo) {
        animal->displayInfo();
    }

    for (Animal* animal : zoo) {
        delete animal;
    }

    return 0;
}
