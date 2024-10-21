// ml_package, Native lua package system
// See LICENSE in the top level directory

#pragma once

#include <string_view>

namespace ResourcePathStore {

constexpr std::string_view RESOURCE_PATH_ARCHIVED = "\1";

void addResource(std::string_view name, std::string_view path);
void removeResource(std::string_view name);
std::string_view GetPath(std::string_view name);

}  // namespace ResourcePathStore
