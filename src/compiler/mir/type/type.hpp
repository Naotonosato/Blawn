#include <vector>
#include <memory>

namespace mir {
class Context;
}
// forward declarations

namespace mir {

class TypeKind;

class HasTypeKind {
    public:
    virtual void receive_notification(TypeKind& from) = 0;
};

enum TypeKindEnum {
    INTEGER,
    FLOAT,
    BOOLEAN,
    POINTER,
    ARRAY,
    STRUCT,
    FUNCTION,
    LAZY
};


class TypeKind {
    private:
    TypeKindEnum type_kind;
    HasTypeKind& _owner;

    public:
    TypeKind(TypeKindEnum type_kind, HasTypeKind& owner)
        : type_kind(type_kind), _owner(owner) {}
    void operator=(TypeKind&);
    void operator=(TypeKindEnum);
    bool operator==(TypeKind&);
    bool operator==(const TypeKindEnum&);
    bool operator!=(TypeKind&);
    bool operator!=(const TypeKindEnum&);
    void notify();
};

class Type : public HasTypeKind,public std::enable_shared_from_this<Type> {
    private:
    std::shared_ptr<Type> shared_this;
    std::shared_ptr<Context> context;
    std::unique_ptr<TypeKind> type_kind;
    bool is_constant;
    long long size;
    std::vector<std::shared_ptr<Type>> dependencies;
    std::vector<std::shared_ptr<Type>> have_influence;
    
    Type()=delete;
    Type(std::shared_ptr<Context> context, TypeKindEnum type_kind_enum);
    Type(std::shared_ptr<Context> context);

    template<typename Base>
    struct CreateHelper:Base
    {
        template<typename... Args>
        explicit CreateHelper(Args&&... args):Base(std::forward<Args>(args)...){}
    };

    public:
    Type(const Type&) = delete;
    static std::shared_ptr<Type> create(std::shared_ptr<Context> context, TypeKindEnum type_kind_enum);
    static std::shared_ptr<Type> create(std::shared_ptr<Context> context);
    Type& operator=(const Type&) = delete;
    void receive_notification(TypeKind& new_type_kind) override;
    virtual void receive_notification(Type& from);
    virtual bool solve(Type& info);
    virtual void notify();
    virtual void fetch(std::shared_ptr<Type> new_type);
    void depend(std::shared_ptr<Type> depend_on);
    void accept(std::shared_ptr<Type> request);
    bool is_array() const;
    bool is_struct() const;
    bool is_function() const;
    TypeKind get_type_kind() const;
    std::vector<std::shared_ptr<Type>> get_dependencies() const;
    std::vector<std::shared_ptr<Type>> get_have_influence() const;
};

class ArrayType : public Type {

};

class StructType : public Type {
    private:
    std::vector<std::shared_ptr<Type>> members;

};

class FunctionType : public Type {
    private:
    std::vector<std::shared_ptr<mir::Type>> argument_type;
    std::shared_ptr<Type> return_type;

};
}  // namespace mir