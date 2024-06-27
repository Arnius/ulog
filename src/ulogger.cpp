#include "ulogger.hpp"

static uni_logger::base_logger application_logger;

int uni_logger::base_logger::new_log(std::string file_name, std::string dir)
{
    std::string full_path(dir + file_name);
    std::ofstream new_file(full_path);
    application_logger.m_log_files.push_back(std::move(new_file));
    int id = static_cast<int>(application_logger.m_log_files.size());
    application_logger.m_log_files_index.insert(std::pair<std::string, int>(file_name, id));
    return 0;
}

int uni_logger::base_logger::remove_log(std::string file_name)
{
    std::map<std::string, int> & log_file_index = application_logger.m_log_files_index;
    
    if(log_file_index.find(file_name) == log_file_index.end())
        return 1;


    return 0;
}