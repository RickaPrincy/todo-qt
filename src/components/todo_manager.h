#ifndef TODOMANAGER_H
#define TODOMANAGER_H

#include <vector>
#include "todo.h"

class TodoManager
{
private:
    std::vector<Todo> _list{};
public:
    Todo add_todo(std::string name, std::string description);
    bool remove_todo(int index);
    TodoManager(){};
};

#endif // TODOMANAGER_H
