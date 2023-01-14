#include "Object.h"

std::ostream &eng::operator<<(std::ostream &out, eng::Object o)
{
    // TODO: insert return statement here
    out << "[" << &o << " Object]";
    return out;
}

void eng::Object::addChild(Object child, int pos = 0)
{
}

void eng::Object::remChild(int pos)
{
}
