#pragma once

#include "config.h"

#include <inotify-cpp/Event.h>

#ifdef INOTIFY_CPP_USE_CXX17
#include <filesystem>
namespace fs = std::filesystem;
#else
#include <boost/filesystem.hpp>
namespace fs = boost::filesystem;
#endif

#include <chrono>

namespace inotify {

class Notification {
  public:
    Notification(
        const Event& event,
        const fs::path& path,
        std::chrono::steady_clock::time_point time);

  public:
    const Event event;
    const fs::path path;
    const std::chrono::steady_clock::time_point time;
};
}