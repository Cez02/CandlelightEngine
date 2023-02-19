#include <iostream>
#include "core/Application.h"

using namespace Core_NS;

int main(int argc, char **argv) {
    Core_NS::Application app;

    if(app.init(argc, argv) < 0)
        exit(-1);

    app.loop();

    return 0;
}
