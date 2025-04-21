// Television/channel.cpp
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description:  Television Http API device class

#include "Devices/Controllers/Television/Television.h"

inline void Television::channel(const unsigned short v) {
  if(v < 99){
    channelState = v;
  }else{
      log->error("Channel out of range.");
      std::cout << "Out of range. "
                << "Even Bruce Springsteen sang that there were 99 channels and nothing on." << std::endl;
  }
};
