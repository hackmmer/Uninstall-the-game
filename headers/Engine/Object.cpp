#include "Object.h"

std::ostream &eng::operator<<(std::ostream &out, eng::Object o)
{
    // TODO: insert return statement here
    out << "[" << &o << " Object]";
    return out;
}