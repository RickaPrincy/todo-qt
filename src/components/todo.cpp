#include "todo.h"

std::string Todo::get_name(){
    return _name;
}

std::string Todo::get_description(){
    return _description;
}

bool Todo::get_status(){
    return _is_done ;
}
