#ifndef SCOPE_HPP
#define SCOPE_HPP

#include <memory>
#include <string>
#include <vector>
#include <unordered_map>

namespace nezoku {

template<class V>
class Scope {
public:
    Scope(std::shared_ptr<Scope<V>> parent_scope = nullptr)
        : parent_(parent_scope) {
        name_ = "unnamed" + std::to_string(unnamed_count_++);
    }
    
    Scope(const std::string& scope_name, std::shared_ptr<Scope<V>> parent_scope = nullptr)
        : name_(scope_name)
        , parent_(parent_scope) {}

    [[nodiscard]]
    auto parent() const noexcept -> std::shared_ptr<Scope<V>> {
        return parent_;
    }

    void add_child(std::shared_ptr<Scope<V>> child_scope) {
        children_.push_back(child_scope);
    }

    void add_value(const std::string& name, V* value) {
        values_.insert(std::make_pair(name, value));
    }

    V* get_value(const std::string& name) {
        auto found = values_.find(name);

        if (found != values_.end()) {
            return found->second;
        } else {
            return nullptr;
        }
    }

private:
    size_t unnamed_count_{0};
    std::string name_;
    std::shared_ptr<Scope<V>> parent_;
    std::unordered_map<std::string, V*> values_;
    std::vector<std::shared_ptr<Scope<V>>> children_;
};

template<class V>
static V* scope_find_value(const std::string& name, std::shared_ptr<Scope<V>> scope) {
    if (!scope) {
        return nullptr;
    }

    auto found = scope->get_value(name);

    if (found) {
        return found;
    } else {
        return scope_find_value(name, scope->parent());
    }
}

}; // namespace nezoku

#endif // SCOPE_HPP
