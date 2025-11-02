#pragma once

#include <string>
#include <cpr/cpr.h>

class Gethtml {
public:
    Gethtml(std::string urlA);
    std::string fetch_html();
private:
    std::string url_;
    
};
