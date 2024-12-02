#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

#define SIZE_BUFFER 1024

/* Split string at each space */
std::vector<std::string> split_string(std::string theString)
{
    std::vector<std::string> result;
    int index = 0;
    int next_index = 0;
    int nbr_spaces = std::count(theString.begin(), theString.end(), ' ');

    for(int i = 0; i<nbr_spaces; i++)
    {
        next_index = theString.find_first_of(' ', index);
        result.push_back(theString.substr(index, next_index-index));
        index = next_index+1;
    }
    result.push_back(theString.substr(index, std::string::npos));
    return result;
}

/* Check whether the vector satisfies the requirements to be safe */
bool check_safety(std::vector<int> theVector)
{
    int initial_order = theVector[1] - theVector[0];
    if(initial_order == 0 || abs(initial_order) > 3){return false;}
    int order;

    for(int i = 1; i<theVector.size()-1; i++){
        order = theVector[i+1] - theVector[i];
        if((initial_order < 0 && order > 0) || (initial_order > 0 && order < 0) || order == 0){
            return false;
        }
        if(abs(order) > 3){return false;}
    }
    return true;
}


int main()
{
    std::ifstream file("input_day2.txt");

    int buffer[SIZE_BUFFER];
    std::vector<std::string> values_string;
    std::vector<int> values_int;

    int nbr_safe_reports = 0;
    while(! file.eof())
    {
        std::string line;
        std::getline(file, line);
        if(line.empty()){goto finish;}

        values_string = split_string(line);
        values_int.resize(values_string.size());

        // Put the string values in the vector of the values of int
        for(int i = 0; i<values_string.size(); i++){
            values_int[i] = stoi(values_string[i]);
        }
        if(check_safety(values_int)){nbr_safe_reports++;}
    }

finish:
    std::cout << "Number of safe reports : " << nbr_safe_reports << std::endl;
    file.close();
    return 0;
}