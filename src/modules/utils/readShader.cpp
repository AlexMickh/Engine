#include "../../../include/utils/readShader.h"

const std::string utils::ReadShader(std::string pathToFile)
{
    std::string content;
    std::ifstream fileStream(pathToFile);

    if(!fileStream.is_open()) {
        std::cerr << "Could not read file " << pathToFile << ". File does not exist." << std::endl;
        return "";
    }

    std::string line = "";
    while(!fileStream.eof()) {
        std::getline(fileStream, line);
        content.append(line + "\n");
    }

    fileStream.close();

    return content;
}