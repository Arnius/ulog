#include "ulogger.hpp"

static uni_logger::data_logger app_logger;

void uni_logger::data_logger::waterfall_log(std::string &file_name, std::string &dir)
{
    app_logger.new_log(file_name, dir);
}