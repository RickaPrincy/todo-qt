#ifndef TODO_H
#define TODO_H

#include <string>

class Todo
{
private:
    std::string _name, _description;
    bool _is_done = false;
public:
    std::string get_name();
    std::string get_description();
    bool get_status();
    Todo(std::string name, std::string description): _name(name), _description(description){};
};

#endif // TODO_H
