#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <math.h>

/* Get the values of a line into a vector */
std::vector<int> split_line(std::string stringLine)
{
    std::vector<int> res;

    std::stringstream streamLine(stringLine);
    std::string temp;

    while(std::getline(streamLine, temp, ' ')){
        res.push_back(atoi(temp.c_str()));
    }

    return res;
}

/* Check if the opération is possible */
bool is_possible(std::vector<int> theLine)
{
    int nbr_digits = theLine.size()-1;
    int nbr_ope = nbr_digits-1;
    int combinaisons_possibles = pow(2, nbr_ope);

    std::vector<bool> operators;
    operators.resize(nbr_ope);
    

}

int main()
{
    std::ifstream file("input_day7.txt");

    std::string line;
    while(std::getline(file,line)){
        std::vector<int> lineSplit = split_line(line);


    }


    return 0;
}