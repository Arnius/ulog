#include "base_logger.hpp"

int uni_logger::base_logger::new_log(std::string file_name, std::string dir)
{
    std::string full_path(dir + file_name);
    std::ofstream new_file(full_path);
    m_log_files.push_back(std::move(new_file));
    int id = static_cast<int>(m_log_files.size());
    m_log_files_index.insert(std::pair<std::string, int>(file_name, id));
    return 0;
}

int uni_logger::base_logger::remove_log(std::string file_name)
{
    auto log_iter = m_log_files_index.find(file_name);
    if(log_iter == m_log_files_index.end())
        return 1;
    
    // Close and erase log file handle
    m_log_files.at(log_iter->second-1).close();
    m_log_files.erase(m_log_files.begin()+log_iter->second-1);

    // If the log file is somewhere in the midle of map we must update the indexes of all the other elements before erasing it
    for(auto i = log_iter; i != m_log_files_index.end(); ++i)
        i->second--;

    // Erase the map entry with log index 
    m_log_files_index.erase(log_iter);

    return 0;
}