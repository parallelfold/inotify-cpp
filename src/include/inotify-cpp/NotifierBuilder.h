#pragma once

#include "config.h"

#include <inotify-cpp/Inotify.h>
#include <inotify-cpp/Notification.h>

#ifdef INOTIFY_CPP_USE_CXX17
#include <filesystem>
namespace fs = std::filesystem;
#else
#include <boost/filesystem.hpp>
namespace fs = boost::filesystem;
#endif

#include <memory>
#include <string>

namespace inotify {

using EventObserver = std::function<void(Notification)>;

class NotifierBuilder {
  public:
    NotifierBuilder();

    auto run() -> void;
    auto runOnce() -> void;
    auto stop() -> void;
    auto watchPathRecursively(fs::path path) -> NotifierBuilder&;
    auto watchFile(fs::path file) -> NotifierBuilder&;
    auto unwatchFile(fs::path file) -> NotifierBuilder&;
    auto ignoreFileOnce(fs::path file) -> NotifierBuilder&;
    auto ignoreFile(fs::path file) -> NotifierBuilder&;
    auto onEvent(Event event, EventObserver) -> NotifierBuilder&;
    auto onEvents(std::vector<Event> event, EventObserver) -> NotifierBuilder&;
    auto onUnexpectedEvent(EventObserver) -> NotifierBuilder&;
    auto setEventTimeout(std::chrono::milliseconds timeout, EventObserver eventObserver)
        -> NotifierBuilder&;

  private:
    std::shared_ptr<Inotify> mInotify;
    std::map<Event, EventObserver> mEventObserver;
    EventObserver mUnexpectedEventObserver;
};

NotifierBuilder BuildNotifier();
}
