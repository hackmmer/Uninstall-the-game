#include "Object.h"
/*
std::ostream &eng::operator<<(std::ostream &out, eng::Object o)
{
    // TODO: insert return statement here
    out << "[" << &o << " Object " << o.name << " " << o.getChildsCount() << "]";
    return out;
}

void eng::Object::addChild(Object child, int pos)
{
    if(pos == 0)
        this->childs.insert(this->childs.end(), child);
    else if(pos > 0)
        this->childs.insert(this->childs.begin()+pos, child);
    else
        this->childs.insert(this->childs.end() + (pos * -1), child);
}
 */
template <typename T>
eng::Object<T>::Object()
{
    this->name = "Object";
}
template <typename T>
eng::Object<T>::Object(std::string name)
{
    // this->childs.clear();
    this->name = name;
}
template <typename T>
eng::Object<T>::~Object()
{
}

template class eng::Object<sf::Vector2f &>;
template class eng::Object<const float &>;

/*
eng::Object &eng::Object::getChild(int pos)
{
    if(pos < 0)
    {
        return this->childs[this->childs.size() + pos];
    }
    return this->childs[pos];
}

void eng::Object::remChild(int pos)
{
    if(pos >= 0)
        this->childs.erase(this->childs.begin()+pos);
    else
        this->childs.erase(this->childs.end()+(pos * -1));
}

size_t eng::Object::getChildsCount()
{
    return this->childs.size();
}

std::vector<eng::Object> &eng::Object::getChilds()
{
    return this->childs;
}*/
