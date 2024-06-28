#include "base_logger.hpp"

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
    std::vector<std::ofstream> &log_files = application_logger.m_log_files;
    
    auto log_iter = log_file_index.find(file_name);
    if(log_iter == log_file_index.end())
        return 1;
    
    // Close and erase log file handle
    log_files.at(log_iter->second-1).close();
    log_files.erase(log_files.begin()+log_iter->second-1);

    // If the log file is somewhere in the midle of map we must update the indexes of all the other elements before erasing it
    for(auto i = log_iter; i != log_file_index.end(); ++i)
        i->second--;

    // Erase the map entry with log index 
    log_file_index.erase(log_iter);

    return 0;
}