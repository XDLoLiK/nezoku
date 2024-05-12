#ifndef SCOPE_HPP
#define SCOPE_HPP

#include <memory>
#include <string>
#include <vector>
#include <unordered_map>

#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"

namespace nezoku {

template<class F, class V>
class Scope {
public:
    Scope(std::shared_ptr<Scope<F, V>> parent_scope = nullptr)
        : parent_(parent_scope) {
        name_ = "unnamed" + std::to_string(unnamed_count_++);
    }
    
    Scope(const std::string& scope_name, std::shared_ptr<Scope<F, V>> parent_scope = nullptr)
        : name_(scope_name)
        , parent_(parent_scope) {}

    [[nodiscard]]
    auto parent() const noexcept -> std::shared_ptr<Scope<F, V>> {
        return parent_;
    }

    void add_child(std::shared_ptr<Scope<F, V>> child_scope) {
        children_.push_back(child_scope);
    }

    void add_variable(const std::string& name, V* variable) {
        variables_.insert(std::make_pair(name, variable));
    }

    void add_function(const std::string& name, F* function) {
        functions_.insert(std::make_pair(name, function));
    }

    V* get_variable(const std::string& name) {
        auto found = variables_.find(name);

        if (found != variables_.end()) {
            return found->second;
        } else {
            return nullptr;
        }
    }

    F* get_function(const std::string& name) {
        auto found = functions_.find(name);

        if (found != functions_.end()) {
            return found->second;
        } else {
            return nullptr;
        }
    }

private:
    size_t unnamed_count_{0};
    std::string name_;
    std::shared_ptr<Scope<F, V>> parent_;
    std::unordered_map<std::string, V*> variables_;
    std::unordered_map<std::string, F*> functions_;
    std::vector<std::shared_ptr<Scope<F, V>>> children_;
};

template<class F, class V>
static V* scope_find_variable(const std::string& name, std::shared_ptr<Scope<F, V>> scope) {
    if (!scope) {
        return nullptr;
    }

    auto found = scope->get_variable(name);

    if (found) {
        return found;
    } else {
        return scope_find_variable(name, scope->parent());
    }
}

template<class F, class V>
static F* scope_find_function(const std::string& name, std::shared_ptr<Scope<F, V>> scope) {
    if (!scope) {
        return nullptr;
    }

    auto found = scope->get_function(name);

    if (found) {
        return found;
    } else {
        return scope_find_function(name, scope->parent());
    }
}

}; // namespace nezoku

#endif // SCOPE_HPP
