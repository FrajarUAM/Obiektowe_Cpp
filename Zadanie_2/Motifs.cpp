#include <iostream>
#include <fstream>
#include <string>

class Sequence {
private:
    std::string motif;
    std::string genome;
    int k;

public:
    Sequence(const std::string &motifPath, const std::string &genomePath, int k) {
        this->k = k;
        readFasta(motifPath, motif);
        readFasta(genomePath, genome);
    }

    // Metoda 1
    void readFasta(const std::string &Path, std::string &sequence) {
        std::ifstream file(Path);
        if (!file.is_open()) {
            std::cerr << "Nie można otworzyć pliku " << Path << std::endl;
            return;
        }

        std::string line;
        sequence = "";

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
    int count_mismatches(const std::string &s1, const std::string &s2) {
        int mismatches = 0;
        int length = std::min(s1.size(), s2.size());

        // Zliczenie różnicy
        for (int i = 0; i < length; ++i) {
            if (s1[i] != s2[i]) {
                ++mismatches;
            }
        }

        return mismatches;
    }

    // Metoda do wyszukiwania podobnych podciągów
    void find_similar_substrings() {
        int motif_length = motif.size();
        int genome_length = genome.size();

        for (int i = 0; i <= genome_length - motif_length; ++i) {
            std::string substring_t = genome.substr(i, motif_length);

            int mismatches = count_mismatches(motif, substring_t);

            if (mismatches <= k) {

                int max_length = motif_length - mismatches;


                for (int len = max_length; len <= motif_length; ++len) {
                    std::cout << i + 1 << " " << len << std::endl;
                }
            }
        }
    }

    // Metoda do printu motifu i genomu
    void printSequences() const {
        std::cout << "Motif: " << motif << std::endl;
        std::cout << "Genome: " << genome << std::endl;
    }


};

int main() {
    std::string motifPath = "/home/frankie/Documents/Studia/Obiektowe_Cpp/Zadanie_2/motif.txt";
    std::string genomePath = "/home/frankie/Documents/Studia/Obiektowe_Cpp/Zadanie_2/seq.txt";
    int k;

    std::cout << "Podaj k: ";
    std::cin >> k;

    Sequence seq(motifPath, genomePath, k);

    seq.printSequences();

    seq.find_similar_substrings();

    return 0;
}
    


