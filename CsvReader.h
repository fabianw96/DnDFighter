//
// Created by wittg on 03/10/2024.
//

#ifndef CSVREADER_H
#define CSVREADER_H
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include "HelperMacros.h"
#include <iostream>
#include <algorithm>
#include <map>
#include <set>


class CsvReader {
public:
    static std::vector<std::pair<std::string, std::vector<int>>> ReadCsvData(const std::string& filename);
};



#endif //CSVREADER_H
