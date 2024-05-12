#include "scope.hpp"

namespace nezoku {

size_t Scope::UNNAMED_COUNT = 0;

Scope::Scope(std::shared_ptr<Scope> parent_scope)
    : parent_(parent_scope) {
    name_ = "unnamed" + std::to_string(UNNAMED_COUNT++);
}

Scope::Scope(const std::string& scope_name, std::shared_ptr<Scope> parent_scope)
    : name_(scope_name)
    , parent_(parent_scope) {}

[[nodiscard]]
auto Scope::parent() const noexcept -> std::shared_ptr<Scope> {
    return parent_;
}

void Scope::add_child(std::shared_ptr<Scope> child_scope) {
    children_.push_back(child_scope);
}

void Scope::add_variable(const std::string& name, llvm::Value* variable) {
    variables_.insert(std::make_pair(name, variable));
}

void Scope::add_function(const std::string& name, llvm::Function* function) {
    functions_.insert(std::make_pair(name, function));
}

llvm::Value* Scope::get_variable(const std::string& name) {
    auto found = variables_.find(name);

    if (found != variables_.end()) {
        return found->second;
    } else {
        return nullptr;
    }
}

llvm::Function* Scope::get_function(const std::string& name) {
    auto found = functions_.find(name);

    if (found != functions_.end()) {
        return found->second;
    } else {
        return nullptr;
    }
}

llvm::Value* scope_find_variable(const std::string& name, std::shared_ptr<Scope> scope) {
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

llvm::Function* scope_find_function(const std::string& name, std::shared_ptr<Scope> scope) {
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
