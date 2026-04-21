#include "Variables.h"

Box* InstantiateBox(Vector2 pos, bool isPushable, int img) {
	Box* b = new Box();
	b->pos = pos;
	b->isPushable = isPushable;
	b->GHandle = img;
	return b;
}

Box* Instantiate(Vector2 pos, int img) {
	Box* b = new Box();
	b->pos = pos;
	b->isPushable = false;
	b->GHandle = img;
	return b;
}