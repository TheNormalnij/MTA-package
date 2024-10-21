// ml_package, Native lua package system
// See LICENSE in the top level directory

#pragma once

#ifdef __linux__
bool ImportLua();
#else
bool ImportLua() {
    return true;
};
#endif
