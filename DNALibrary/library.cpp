// library.cpp
#include "library.h"  // Include the header file for declarations
#include <array>
#include <string>

std::array<int, 4> countNucleotides(const std::string& dna) {
    std::array<int, 4> counts = {0, 0, 0, 0}; // Counts for A, C, G, T
    for (char nucleotide : dna) {
        switch (nucleotide) {
            case 'A': counts[0]++; break;
            case 'C': counts[1]++; break;
            case 'G': counts[2]++; break;
            case 'T': counts[3]++; break;
        }
    }
    return counts;
}
