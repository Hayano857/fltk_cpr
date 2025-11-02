#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Text_Buffer.H>
#include <FL/Fl_Text_Display.H>

#include "Gethtml.h"

int main() {
    Gethtml getter("https://www.merriam-webster.com/word-of-the-day/ostracize-2025-11-01");
    std::string html_content = getter.fetch_html();

    Fl_Window *win = new Fl_Window(640, 480, "Text Display Example");
    
    // Create the text buffer
    Fl_Text_Buffer *buff = new Fl_Text_Buffer();
    
    // Create the text display widget and set its buffer
    Fl_Text_Display *disp = new Fl_Text_Display(20, 20, 600, 440);
    disp->buffer(buff);
    
    win->resizable(*disp);
    win->show();
    
    // Load some text into the buffer
    buff->text(html_content.c_str());

    return Fl::run();
}
