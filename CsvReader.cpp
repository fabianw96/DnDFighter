//
// Created by wittg on 03/10/2024.
//

#include "CsvReader.h"


/// <summary>
/// <para> Function to extract Data from a CSV file. </para>
/// <param name="filename"> Path to CSV file </param>
/// <returns> A vector of a pair consisting of a string and a int vector </returns>
/// </summary>
std::vector<std::pair<std::string, std::vector<int>>> CsvReader::ReadCsvData(const std::string& filename)
{
    //maybe use map/dictionary?
    std::vector<std::pair<std::string, std::vector<int>>> resultData;

    std::ifstream inputFile(filename);

    if (!inputFile.is_open()) throw std::runtime_error("Could not open CSV ");

    std::string line;
    std::string colname;
    int value;

    if (inputFile.good())
    {
        std::getline(inputFile, line);

        std::stringstream ss(line);

        while (std::getline(ss, colname, ','))
        {
            resultData.emplace_back(colname, std::vector<int> {});
        }
    }

    while (std::getline(inputFile, line))
    {
        std::stringstream ss(line);

        int colIdx = 0;

        while (ss >> value)
        {
            resultData.at(colIdx).second.emplace_back(value);

            if (ss.peek() == ',') ss.ignore();

            colIdx++;
        }
    }

    inputFile.close();

    return resultData;
}