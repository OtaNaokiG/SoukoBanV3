#include "Variables.h"

void Box::StartMove(Vector2 dir) {
    if (isMoving) return;

    moveStart = pos;
    moveEnd = { pos.x + dir.x * TILESIZE, pos.y + dir.y * TILESIZE };
    isMoving = true;
}

void Box::Update() {
    if (!isMoving) return;

    Vector2 diff = moveEnd - pos;

    if (abs(diff.x) <= objectsSpeed && abs(diff.y) <= objectsSpeed) {
        pos = moveEnd;
        isMoving = false;
    }
    else {
        pos.x += (diff.x > 0 ? objectsSpeed : (diff.x < 0 ? -objectsSpeed : 0));
        pos.y += (diff.y > 0 ? objectsSpeed : (diff.y < 0 ? -objectsSpeed : 0));
    }
}
