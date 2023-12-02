#ifndef _TOOLS_HPP
#define _TOOLS_HPP

#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

namespace fs = std::filesystem;

/**
 * @brief c++查找指定文件
 * @note 获取数据集部分文件
 * @param 搜索的文件夹
 * @param 搜索的文件
 * @return 搜到到的文件绝对路径 没找到返回空
 */
fs::path FindFilePath(const fs::path &rootPath, const std::string &fileName)
{
    for (const auto &entry : fs::directory_iterator(rootPath))
    {
        if (entry.is_directory())
        {
            fs::path result = FindFilePath(entry.path(), fileName);
            if (!result.empty())
            {
                return result;
            }
        }
        else if (entry.is_regular_file() && entry.path().filename() == fileName)
        {
            return entry.path();
        }
    }
    return fs::path();
}

#endif