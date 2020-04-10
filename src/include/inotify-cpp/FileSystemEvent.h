#pragma once
#include "config.h"

#ifdef INOTIFY_CPP_USE_CXX17
#include <filesystem>
namespace fs = std::filesystem;
#else
#include <boost/filesystem.hpp>
namespace fs = boost::filesystem;
#endif

#include <chrono>
#include <string>

namespace inotify {
class FileSystemEvent {
  public:
    FileSystemEvent(
        int wd,
        uint32_t mask,
        const fs::path& path,
        const std::chrono::steady_clock::time_point& eventTime);

    ~FileSystemEvent();

  public:
    int wd;
    uint32_t mask;
    fs::path path;
    std::chrono::steady_clock::time_point eventTime;
};
}