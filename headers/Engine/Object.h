#ifndef __E_OBJECT_H
#define __E_BBJECT_H

#include <iostream>
#include <vector>

namespace eng
{
    class Object
    {
        private:
            std::vector<Object> childs;
        public:
            std::string name;
            bool visible;
            int z;

            Object& getChild(int pos);
            void addChild(Object child, int pos = 0);
            void remChild(int pos);
    };

    std::ostream& operator<<(std::ostream& out, eng::Object o);
}
#endif