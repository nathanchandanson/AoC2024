#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

enum class directions { Haut, Bas, Droite, Gauche };

class game
{
private: 
    std::vector<std::vector<char>> plateau;
    std::pair<int,int> pos_player;
    directions direction_player;
public:
    game(std::vector<std::vector<char>>& input_plateau, std::pair<int,int> input_pos_player, directions input_direction_player): plateau(input_plateau), pos_player(input_pos_player), direction_player(input_direction_player)
    {}

    std::pair<int,int> get_pos_player(){ return pos_player; }

    std::pair<int,int> get_plateau_size(){ return {plateau.size(), plateau[0].size()}; }

    /* 
    Update the game state 
    Return false if it is the end of the game, true if not
    */
    bool update()
    {
        plateau[pos_player.first][pos_player.second] = 'X';
        int new_i, new_j;
        switch (direction_player)
        {
        case directions::Haut:
            new_i = pos_player.first-1;
            new_j = pos_player.second;
            if(new_i<0 || new_i>=plateau.size() || new_j<0 || new_j>=plateau[0].size()){return false;}
            if(plateau[new_i][new_j] == '#'){
                direction_player = directions::Droite;
            }else{
                pos_player.first = new_i;
            }
            break;
        case directions::Bas:
            new_i = pos_player.first+1;
            new_j = pos_player.second;
            if(new_i<0 || new_i>=plateau.size() || new_j<0 || new_j>=plateau[0].size()){return false;}
            if(plateau[new_i][new_j] == '#'){
                direction_player = directions::Gauche;
            }else{
                pos_player.first = new_i;
            }
            break;
        case directions::Droite:
            new_i = pos_player.first;
            new_j = pos_player.second+1;
            if(new_i<0 || new_i>=plateau.size() || new_j<0 || new_j>=plateau[0].size()){return false;}
            if(plateau[new_i][new_j] == '#'){
                direction_player = directions::Bas;
            }else{
                pos_player.second = new_j;
            }
            break;
        case directions::Gauche:
            new_i = pos_player.first;
            new_j = pos_player.second-1;
            if(new_i<0 || new_i>=plateau.size() || new_j<0 || new_j>=plateau[0].size()){return false;}
            if(plateau[new_i][new_j] == '#'){
                direction_player = directions::Haut;
            }else{
                pos_player.second = new_j;
            }
            break;
        }
        return true;
    }

    /* Count the number of X's */
    int count_X()
    {
        int res = 0;
        for(int i = 0; i<plateau.size(); i++){
            res += std::count(plateau[i].begin(), plateau[i].end(), 'X');
        }
        return res;
    }
};

int main()
{
    // Extraction des données
    std::ifstream file("input_day6.txt");
    // std::ifstream file("test1.txt");

    std::string line;
    std::vector<char> vec_line;
    std::vector<std::vector<char>> plateau;
    int i = 0;
    std::pair<int,int> input_pos;
    while(std::getline(file, line)){
        i++;
        vec_line.resize(line.size());
        for(int j = 0; j<line.size(); j++){
            vec_line[j] = line[j];
            if(line[j] == '^'){input_pos.first = i; input_pos.second = j;}
        }
        plateau.push_back(vec_line);
    }
    file.close();

    // Actualisation du jeu, jusqu'à ce qu'on arrive à la fin
    game theGame(plateau, input_pos, directions::Haut);
    // std::pair<int,int> plateau_size = theGame.get_plateau_size();
    // std::cout << "Size of the plateau : " << plateau_size.first << "×" << plateau_size.second << std::endl;
    while(theGame.update()){}

    // std::cout << theGame.get_pos_player().first << "," << theGame.get_pos_player().second << std::endl;

    // Affichage résultat : pb : j'ai 5132 mais la réponse est 5131
    std::cout << "Number of different cases visited : " << theGame.count_X() << std::endl; 

    return 0;
}