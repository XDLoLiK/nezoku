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

class Scope {
public:
    Scope(std::shared_ptr<Scope> parent_scope = nullptr);
    Scope(const std::string& scope_name, std::shared_ptr<Scope> parent_scope = nullptr);

    [[nodiscard]]
    auto parent() const noexcept -> std::shared_ptr<Scope>;

    void add_child(std::shared_ptr<Scope> child_scope);
    void add_variable(const std::string& name, llvm::Value* variable);
    void add_function(const std::string& name, llvm::Function* function);

    llvm::Value* get_variable(const std::string& name);
    llvm::Function* get_function(const std::string& name);

private:
    static size_t UNNAMED_COUNT;

    std::string name_;
    std::shared_ptr<Scope> parent_;
    std::unordered_map<std::string, llvm::Value*> variables_;
    std::unordered_map<std::string, llvm::Function*> functions_;
    std::vector<std::shared_ptr<Scope>> children_;
};

llvm::Value* scope_find_variable(const std::string& name, std::shared_ptr<Scope> scope);
llvm::Function* scope_find_function(const std::string& name, std::shared_ptr<Scope> scope);

}; // namespace nezoku

#endif // SCOPE_HPP
