#ifndef NEZOKU_CMDLINE_HPP
#define NEZOKU_CMDLINE_HPP

#include <iostream>
#include <functional>
#include <unordered_map>
#include <string>
#include <vector>

namespace nezoku {

class CmdLineParser {
    using ArgCallback = std::function<void (const std::string&)>;
    using DefaultCallback = std::function<bool (const std::string&)>;

public:
    void add_default(DefaultCallback callback) {
        default_callback_ = std::move(callback);
    }

    void add_callback(std::string arg, ArgCallback callback) {
        callbacks_.insert(std::make_pair(std::move(arg), std::move(callback)));
    }

    bool parse_arg(const std::string& arg) {
        auto [start, end] = callbacks_.equal_range(arg);

        for (auto curr = start; curr != end; curr++) {
            (curr->second)(arg);
        }

        return start != end;
    }

    void parse_args(const std::vector<std::string>& args) {
        for (const auto& arg: args) {
            if (!parse_arg(arg) && !(default_callback_)(arg)) {
                std::cerr << "Unknown arg: " << arg << std::endl;
                break;
            }
        }
    }

private:
    std::unordered_multimap<std::string, ArgCallback> callbacks_;
    DefaultCallback default_callback_;
};

}; // namespace nezoku

#endif // NEZOKU_CMDLINE_HPP
