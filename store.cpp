#include <iostream>
#include <fstream>
#include <vector>
#include <string>

void store(std::vector<int> output_code) {
    std::string temp = "";
    std::ofstream file("c1.txt");

    if (file.is_open()) {
        for (int i = 0; i < output_code.size(); i++) {
            temp += std::to_string(output_code[i]) + "\n";
        }

        file << temp;
        file.close();
        std::cout << "Values have been stored in the file successfully." << std::endl;
    } else {
        std::cout << "Unable to open the file." << std::endl;
    }
}

int main() {
    std::vector<int> output_code = {65, 66, 67, 68, 69};

    store(output_code);

    return 0;
}
