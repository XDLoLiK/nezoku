#include <iostream>

#include "driver.hpp"

int main(int argc, char** argv) {
    nezoku::Driver driver;

    for (int i = 1; i < argc; i++) {
        if (argv[i] == std::string("-p")) {
            driver.trace_parsing = true;
        } else if (argv[i] == std::string("-s")) {
            driver.trace_scanning = true;
        } else {
            driver.parse(argv[i]);
            driver.print_tree(argv[i + 1]);
            i++;
        }
    }

    return 0;
}
