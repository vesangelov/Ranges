#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> readInput(){
    std::vector<int> borders {};

    std::string endCommand;
    int key;
    int value;

    while(std::cin >> endCommand && endCommand != "."){
        key = std::stoi(endCommand);
        std::cin >> value;

        auto lower_key = std::lower_bound(borders.begin(), borders.end(), key);
        borders.insert(lower_key, key);

        auto lower_value = std::lower_bound(borders.begin(), borders.end(), value);
        borders.insert(lower_value,value);
    }

    return borders;
}

void checkIndex(std::vector<int>& borders){

    std::string input {};
    int index;

    std::string output;

    while(std::cin >> input && input != "."){
        index = std::stoi(input);

        auto lower = std::lower_bound(borders.begin(), borders.end(), index);

        auto i = std::distance(borders.begin(), lower);

        if(lower == borders.end()){
            output += "out\n";
        }
        else {
            output += i % 2 == 0 && *lower != index ? "out\n" : "in\n";
        }
    }

    std::cout << output;
}

int main() {

    std::vector<int> borders = readInput();

    checkIndex(borders);

    return 0;
}
