#ifndef ULOGGER
#define ULOGGER
#include "base_logger.hpp"

namespace uni_logger
{

class data_logger : base_logger
{
    public:
    
    static void waterfall_log(std::string &file_name, std::string &dir);

    private:

};

};

#endif