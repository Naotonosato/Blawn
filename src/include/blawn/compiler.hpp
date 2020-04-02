#pragma once

namespace ast {
class Builder;
}
namespace mir {
class Builder;
}

int compile(int argc, char** argv);

namespace compiler {
class CompilerOptions;
class Compiler {
    private:
    CompilerOptions& options;

    public:
    Compiler(CompilerOptions& options) : options(options) {}
    Compiler() = delete;
    Compiler(const Compiler&) = delete;
    Compiler(Compiler&&) = delete;
};
}  // namespace compiler