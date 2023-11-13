#pragma once

#include "data.h"

body* mvfs();

vertex* mev(vertex* v1, loop* lo);

face* mef(face* fac, vertex* v1, vertex* v2);

loop* kemr(loop* lo, edge* edg);

loop* kfmrh(face* delfac, face* depfac);

face* mef(face* fac, vertex* v1, vertex* v2,vertex* helpvertex);
