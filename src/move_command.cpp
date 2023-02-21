#include "move_command.h"
#include "entity.h"

void MoveCommand::execute(Entity &entity) {
    entity.updateEntityState();
}

