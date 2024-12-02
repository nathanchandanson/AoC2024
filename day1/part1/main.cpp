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
    // Tri des données
    std::sort(column1.begin(), column1.end());
    std::sort(column2.begin(), column2.end());

    // Calcul des distances
    int dist_tot = 0;
    for(int i = 0; i < column1.size(); i++)
    {
        dist_tot += abs(column1[i]-column2[i]);
    }

    // Affichage
    std::cout << "Distance totale : " << dist_tot << std::endl;
    return 0;
}