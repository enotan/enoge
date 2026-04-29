#include "app/Application.hpp"

int main() {
    enoge::app::Application application;
    if (!application.initialize()) {
        return 1;
    }

    return application.run();
}