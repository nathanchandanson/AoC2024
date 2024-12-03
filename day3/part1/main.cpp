#include <iostream>
#include <regex>
#include <fstream>
#include <sstream>

int main()
{
    /* Extraction des données */
    std::ifstream file("input_day3.txt");

    std::string line;
    std::regex expression("mul\\((\\d{1,3}),(\\d{1,3})\\)");
    std::smatch match_expression;
    int a,b;
    int result = 0;
    while(std::getline(file, line))
    {
        // Création des itérateurs : permet de capturer toutes les occurences
        std::sregex_iterator begin(line.begin(), line.end(), expression);
        std::sregex_iterator end;

        // Parcourt des occurences trouvées
        for(auto it = begin; it!=end; ++it){
            match_expression = *it;
            result += stoi(match_expression[1]) * stoi(match_expression[2]);
        }
    }
    std::cout << "Le résultat des multiplications est : " << result << std::endl;

    return 0;
}