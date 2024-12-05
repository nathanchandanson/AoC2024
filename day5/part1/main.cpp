#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

/* 
    Look for all the constraints for a specified num 
    Returns a pair of all numbers that need to be before, and all that need to be after
*/
std::pair<std::vector<int>,std::vector<int>> find_constraints(int num, const std::vector<std::pair<int,int>>& constraints)
{
    std::vector<int> numbers_before, numbers_after;
    for(auto [num1, num2] : constraints){
        if(num1 == num){
            numbers_after.push_back(num2);
        }else if(num2 == num){
            numbers_before.push_back(num1);
        }
    }
    return std::pair<std::vector<int>,std::vector<int>> (numbers_before, numbers_after);
}

/* Check if the constraints are verified */
bool check_constraints(int index_num, 
                        const std::pair<std::vector<int>,std::vector<int>>& numbers_before_after,
                        std::vector<int>& data)
{
    // Vérif si les nombres qui doivent être avant sont pas après
    for(int constraint : numbers_before_after.first){
        for(int i = index_num+1; i<data.size(); i++){
            if(constraint == data[i]){return false;}
        }
    }
    // Vérif si les nombres qui doivent être après sont pas avant
    for(int constraint : numbers_before_after.second){
        for(int i = index_num-1; i>=0; i--){
            if(constraint == data[i]){return false;}
        }
    }
    return true;
}

int main()
{
    std::ifstream file("input_day5.txt");

    std::vector<std::pair<int,int>> constraints;

    std::string stringLine;
    // Première partie du fichier
    while(std::getline(file, stringLine) && !stringLine.empty())
    {
        // Extract data to put it in constraints
        std::stringstream StreamLine(stringLine);
        std::string a,b;
        std::getline(StreamLine, a, '|');
        std::getline(StreamLine, b, '|');
        std::pair<int,int> constraint(stoi(a), stoi(b));
        constraints.push_back(constraint);
    }

    int sum = 0;
    bool wrong_update = false;
    while(std::getline(file, stringLine))
    {
        // Extract data to analyse
        std::vector<int> data;
        std::stringstream StreamLine(stringLine);
        std::string datum;
        while(std::getline(StreamLine, datum, ',')){
            data.push_back(stoi(datum));
        }

        // Analyse data
        for(int i = 0; i<data.size(); i++){
            if(check_constraints(i, find_constraints(data[i], constraints), data) == false){
                wrong_update = true;
                break;
            }
        }
        if(!wrong_update){
            sum += data[(data.size()-1)/2];
        }else{
            wrong_update = false;
        }

    }
    std::cout << "Sum of the middle digits of correct updates : " << sum << std::endl;

    file.close();
    return 0;
}