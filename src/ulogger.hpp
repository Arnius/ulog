#ifndef ULOGGER
#define ULOGGER

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
    static int new_log(std::string file_name, std::string dir = L_HOME_DIR);

    // Remove a log file entry.
    static int remove_log(std::string file_name);

    private:
    std::vector<std::ofstream> m_log_files;
    std::map<std::string, int> m_log_files_index;
};

};

#endif