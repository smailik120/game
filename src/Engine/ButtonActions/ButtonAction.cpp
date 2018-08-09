#include <string>
#include "../ButtonActions/ButtonAction.h"
void ButtonAction::setName(std::string name) {
    nameAction = name;
}
string ButtonAction::getName() {
    return nameAction;
}