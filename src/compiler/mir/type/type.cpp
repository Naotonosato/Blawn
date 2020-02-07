#include "type.hpp"
#include <iostream>

#include "../context/context.hpp"
#include <map>
namespace mir {

void TypeKind::operator=(TypeKindEnum new_type_kind) {
    type_kind = new_type_kind;
    notify();
}

void TypeKind::operator=(TypeKind& new_type_kind) {
    type_kind = new_type_kind.type_kind;
    notify();
}

bool TypeKind::operator==(TypeKind& value)
{
    return operator==(value.type_kind);
}

bool TypeKind::operator==(const TypeKindEnum& value) {
    return type_kind == value;
}

bool TypeKind::operator!=(const TypeKindEnum& value) {
    return type_kind != value;
}

bool TypeKind::operator!=(TypeKind& value)
{
    return type_kind != value.type_kind;
}

void TypeKind::notify() { _owner.receive_notification(*this); }

Type::Type(std::shared_ptr<Context> context, TypeKindEnum type_kind_enum)
:context(context),type_kind(std::make_unique<TypeKind>(type_kind_enum,*this))
{}

Type::Type(std::shared_ptr<Context> context)
:context(context),type_kind(std::make_unique<TypeKind>(LAZY,*this))
{}

std::shared_ptr<Type> Type::create(std::shared_ptr<Context> context, TypeKindEnum type_kind_enum)
{
    auto shared_this = std::make_shared<CreateHelper<Type>>(context,type_kind_enum);
    shared_this->shared_this = shared_this->shared_from_this();
    return shared_this;
}

std::shared_ptr<Type> Type::create(std::shared_ptr<Context> context)
{
    auto shared_this = std::make_shared<CreateHelper<Type>>(context);
    shared_this->shared_this = shared_this->shared_from_this();
    return shared_this;
}


void Type::fetch(std::shared_ptr<Type> new_type) {
    *type_kind = *new_type->type_kind;
}

void Type::receive_notification(TypeKind& info) { notify(); }

void Type::receive_notification(Type& from) { solve(from); }

bool Type::solve(Type& info)
{
    if (*type_kind == LAZY)
    {
        *type_kind = *info.type_kind;
        return true;
    }
    if ((*type_kind) == *(info.type_kind))
    {
        *type_kind = *info.type_kind;
        return true;
    }
    return false;
}

void Type::notify(){
    
    if (*type_kind != LAZY) {
        for (auto& type : have_influence) {
            assert((type->get_type_kind() == LAZY || type->get_type_kind() == *type_kind) && "type can't be fetched new type because the type is already fetched");
            if (type->get_type_kind() == LAZY)
            {
                type->receive_notification(*this);
            }
        }
    }
}

void Type::depend(std::shared_ptr<Type> depend_on) {
    depend_on->accept(shared_this);
    dependencies.push_back(depend_on);
}

void Type::accept(std::shared_ptr<Type> request) { have_influence.push_back(request); }

bool Type::is_array() const { return *type_kind == ARRAY; }

bool Type::is_struct() const { return *type_kind == STRUCT; }

bool Type::is_function() const { return *type_kind == FUNCTION; }

TypeKind Type::get_type_kind() const { return *type_kind; }

std::vector<std::shared_ptr<Type>> Type::get_dependencies() const
{
    return dependencies;
}

std::vector<std::shared_ptr<Type>> Type::get_have_influence() const
{
    return have_influence;
}

}

int main()
{
    auto c = std::shared_ptr<mir::Context>(new mir::Context());
    auto t1 = mir::Type::create(c,mir::LAZY);
    auto t2 = mir::Type::create(c,mir::LAZY);
    auto t3 = mir::Type::create(c,mir::LAZY);
    std::map<std::shared_ptr<mir::Type>,std::string> debug;
    debug[t1] = "t1";
    debug[t2] = "t2";
    debug[t3] = "t3";
    t1->depend(t2);
    t2->depend(t1);
    t3->depend(t2);
    t2->depend(t3);
    t1->depend(t1);
    
    for (auto&tf:t1->get_have_influence())
    {
        std::cout << debug[t1] << " is depended by " << debug[tf] << std::endl;
    }

    for (auto&tf:t2->get_have_influence())
    {
        std::cout << debug[t2] << " is depended by " << debug[tf] << std::endl;
    }

    for (auto&tf:t3->get_have_influence())
    {
        std::cout << debug[t3] << " is depended by " << debug[tf] << std::endl;
    }

    t1->fetch(mir::Type::create(c,mir::LAZY));
    std::cout << (t1->get_type_kind()==mir::INTEGER) << std::endl;
    std::cout << (t2->get_type_kind()==mir::INTEGER) << std::endl;
    std::cout << (t3->get_type_kind()==mir::INTEGER) << std::endl;
    t2->fetch(mir::Type::create(c,mir::FUNCTION));
    std::cout << "-----------------------------" << std::endl;
    std::cout << (t1->get_type_kind()==mir::FUNCTION) << std::endl;
    std::cout << (t2->get_type_kind()==mir::FUNCTION) << std::endl;
    std::cout << (t3->get_type_kind()==mir::FUNCTION) << std::endl;
}