// Television/volume.cpp
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: Television Http API device class

#include "Devices/Controllers/Television/Television.h"

inline void Television::volume(const unsigned short v) {
    if(v < 99){
        volumeState = v;
    }else{
      log->error("Volume out of range.");
      std::cout << "Volume out of range. "
    }
};
