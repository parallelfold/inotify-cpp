Inotify 
=======
A C++ interface for linux inotify which is threadsafe

## Description ##
 __Inotify__ is a C++ class, that lets you use linux inotify to watch files or directories.
See man inotify for more background information.

## Build ##
   + Include Inotify.h
   + compile with -lboost_system -lboost_filesystem -std=c++11
   + example: g++ main.cc Inotify.cc -I . -std=c++11  -lboost_system -lboost_filesystem

## Example ##
Simple example for Inotify usage.
```c++

#include <Inotify.h>
#include <sys/inotify.h> /* IN_* */

int main(){

  std::vector<std::string> ignoredFolders;
  unsigned int eventTimeout = 0;
  std::string dir("/my_dir/");
  std::string file("my_file");
  uint32_t eventMask = IN_CREATE | IN_MODIFY | IN_DELETE | IN_MOVE;


  // Init inotify
  Inotify inotify(ignoredFolders, eventTimeout, eventMask);

  // Watch a file for changes
  if(!inotify.watchFile(file)){
    std::cout << "Can´t watch file " << file << "! Errno " << inotify.getLastError() <<std::endl;
    exit(0);
  }
  
  // Wait for 5 events of this file
  for(unsigned eventCount = 0; eventCount < 5; ++eventCount){
    inotify_event event = inotify.getNextEvent();
    std::cout << "Event " << inotify.maskToString(event.mask) << "for " << file << " was triggered!" << std::endl;
  }
  
  // Watch a directory (plus all subdirectories and files)
  if(!inotify.watchDirectoryRecursively(dir)){
  std::cout << "Can´t watch directory " << dir << "! Errno " << inotify.getLastError() <<std::endl;
    exit(0);
  }
  
  // Wait for 5 events of this directory
  for(unsigned eventCount = 0; eventCount < 5; ++eventCount){
    inotify_event event = inotify.getNextEvent();
    std::cout << "Event " << inotify.maskToString(event.mask) << "for " << file << " was triggered!" << std::endl;
  }
  
  return 0;
}

```
   
## Dependencies ##
 + boost
 + c++11
 + linux 2.6.13

## Copyrigth
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>.  
This is free software: you are free to change and redistribute it.  There is NO WARRANTY, to the extent permitted by law.

## Author ##
Written by Erik Zenker (erikzenker@hotmail.com)
