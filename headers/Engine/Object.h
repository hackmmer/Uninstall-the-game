#ifndef __E_OBJECT_H
#define __E_BBJECT_H

#include <iostream>
#include <list>

namespace eng
{
    class Object
    {
        private:
            std::list<Object> childs;
        public:
            std::string name;
            bool visible;
            int z;

            void addChild(Object child, int pos = 0);
            void remChild(int pos);
    };

    std::ostream& operator<<(std::ostream& out, eng::Object o);
}
#endif