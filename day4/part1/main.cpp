#include <iostream>
#include <fstream>
#include <vector>

/* Convert a string to a vector of characters */
std::vector<char> stovec(const std::string &theString)
{
    std::vector<char> res;
    res.resize(theString.size());
    for(int i = 0; i<res.size(); i++)
    {
        res[i] = theString[i];
    }
    return res;
}

int main()
{
    /* Ouverture du fichier puis mise sous forme de tableau*/
    std::ifstream file("input_day4.txt");

    std::vector<std::vector<char>> tableau;
    std::string string_line;

    while(std::getline(file, string_line))
    {
        tableau.push_back(stovec(string_line));
    }
    file.close();

    /* Comptage */
    // Def directions
    std::vector<std::pair<int, int>> directions ={
        {-1, 0},    // Haut
        {-1, 1},    // Haut-droite
        {0 , 1},    // Droite
        {1 , 1},    // Bas-droite
        {1 , 0},    // Bas
        {1 ,-1},    // Bas-gauche
        {0 ,-1},    // Gauche
        {-1,-1}     // Haut-gauche
    };

    int i_max = tableau.size()-1;
    int j_max = tableau[0].size()-1;
    int count = 0;
    // Parcourt tableau
    for(int i = 0; i<tableau.size(); i++){
        for(int j = 0; j<tableau[0].size(); j++){
            // Test only if it is an X
            if(tableau[i][j] == 'X'){
                // Parcourt des directions
                for(auto [d_row, d_col] : directions){
                    int new_row = i + 3*d_row;
                    int new_col = j + 3*d_col;
                    
                    // Si la nouvelle direction est bien dans le tableau
                    if(new_row >= 0 && new_row <= i_max && new_col >= 0 && new_col <= j_max){
                        if(tableau[i+d_row][j+d_col] == 'M' && tableau[i+2*d_row][j+2*d_col] == 'A' && tableau[i+3*d_row][j+3*d_col] == 'S'){count++;}
                    }
                }
            }
        }
    }

    std::cout << "XMAS appears " << count << " times" << std::endl;
    return 0;
}