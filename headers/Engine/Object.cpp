#include "Object.h"

std::ostream &eng::operator<<(std::ostream &out, eng::Object o)
{
    // TODO: insert return statement here
    out << "[" << &o << " Object]";
    return out;
}

void eng::Object::addChild(Object child, int pos = 0)
{
    this->childs.insert(this->childs.begin()+pos, child);
}

eng::Object& eng::Object::getChild(int pos)
{
    return this->childs.at(pos);
}

void eng::Object::remChild(int pos)
{
    this->childs.erase(this->childs.begin()+pos);
}
