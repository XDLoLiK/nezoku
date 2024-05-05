#include "scanner.hpp"
#include "driver.hpp"

namespace nezoku {

Scanner::Scanner(Driver& driver)
    : driver(driver) {}

Scanner::~Scanner() {}

}; // namespace nezoku
