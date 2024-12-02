#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cmath>

int main()
{
    /* Extraction des données */
    std::ifstream file("input.txt");

    std::vector<int> column1;
    std::vector<int> column2;

    int value1, value2;
    while(file >> value1 >> value2)
    {
        column1.push_back(value1);
        column2.push_back(value2);
    }

    if(column1.size() != column2.size()){
        std::cerr << "Error reading the file";
        return -1;
    }

    /* Début du calcul */
    int similarity_score = 0;
    int current_value;
    for(int i = 0; i<column1.size(); i++)
    {
        current_value = column1[i];
        similarity_score += current_value * std::count(column2.begin(), column2.end(), current_value);
    }

    // Affichage 
    std::cout << "Similarity score : " << similarity_score << std::endl;
    return 0;
}