#include "data.h"

float point::distance(point p1)
{
	
	float dis = 0;

	dis = (pos[0] - p1.pos[0]) * (pos[0] - p1.pos[0]) + (pos[1] - p1.pos[1]) * (pos[1] - p1.pos[1]) + (pos[2] - p1.pos[2]) * (pos[2] - p1.pos[2]);

	return dis;
}

bool operator!=(point p1, point p2)
{
	if (p1.pos[0] != p2.pos[0] || p1.pos[1] != p2.pos[1] || p1.pos[2] != p2.pos[1]) {
		return true;
	}
	
	return false;
	
}
