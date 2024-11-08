#include <iostream>
#include <fstream>
#include <string>

class Sequence {
private:
    std::string sequence;

public:
    Sequence() : sequence("") {}

    // Metoda 1
    void readFasta(const std::string &Path) {
        std::ifstream file(Path);
        if (!file.is_open()) {
            std::cerr << "Nie można otworzyć pliku " << Path << std::endl;
            return;
        }

        std::string line;

        while (std::getline(file, line)) {
            if (line[0] == '>') {
                continue;
            } else {
                sequence += line;
            }
        }

        file.close();
    }

    // Metoda 2
    void printSequence() const {
        std::cout << "Sekwencja: " << sequence << std::endl;
    }
};

int main() {
    Sequence seq;

    seq.readFasta("/home/frankie/Documents/Studia/Obiektowe_Cpp/Zadanie_1/seq.txt");

    seq.printSequence();

    return 0;
}


