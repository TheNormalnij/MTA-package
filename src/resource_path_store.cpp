// ml_package, Native lua package system
// See LICENSE in the top level directory

#include "resource_path_store.h"
#include <string>
#include <string_view>
#include <unordered_map>

std::unordered_map<std::string, std::string> pathStore{};

namespace ResourcePathStore {

void addResource(std::string_view name, std::string_view path) {
    pathStore[std::string{name}] = path;
}

void removeResource(std::string_view name) {
    pathStore.erase(std::string{name});
}

std::string_view GetPath(std::string_view name) {
    auto it = pathStore.find(std::string{name});
    if (it != pathStore.end())
        return it->second;
    return {nullptr, 0};
}

}  // namespace ResourcePathStore
