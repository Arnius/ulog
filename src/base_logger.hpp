#ifndef BASE_LOGGER
#define BASE_LOGGER

#include <string>
#include <time.h>
#include <fstream>
#include <vector>
#include "definitions.hpp"
#include <map>

namespace uni_logger
{

class base_logger
{   
    public:

    // Add a new log file entry.
    int new_log(std::string file_name, std::string dir = L_HOME_DIR);

    // Remove a log file entry.
    int remove_log(std::string file_name);

    private:
    std::vector<std::ofstream> m_log_files;
    std::map<std::string, int> m_log_files_index;
};

};

#endif