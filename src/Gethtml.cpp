#include "Gethtml.h"

Gethtml::Gethtml(std::string urlA) {
    url_ = urlA;
}

std::string Gethtml::fetch_html() {
    cpr::Response r = cpr::Get(cpr::Url{url_});
    return r.text;
}