#include "todo_manager.h"

Todo TodoManager::add_todo(std::string name, std::string description){
    Todo todo(name, description);
    _list.push_back(todo);
    return todo;
}

bool TodoManager::remove_todo(int index){
    if(_list.size() <= index)
        return false;
    _list.erase(_list.begin() + index);
    return true;
}
