#include "euleroperation.h"
#include <cstddef>


body* mvfs()
{
	body* new_body = new body();
	face* new_face =new face();
	loop* new_loop =new loop();
	vertex* new_vertex = new vertex();

	new_face->nextface = NULL;

	new_loop->nextloop = NULL;

	new_body->nectbody = NULL;

	new_vertex->nextvertex = NULL;

	new_body->m_face = new_face;

	/*new_face.m_body = new_body;*/

	new_face->m_loop = new_loop;

	new_loop->m_face = new_face;

	new_loop->m_coedge = NULL;
	if (new_loop->m_coedge == NULL) {
		int a = 0;
	}
	else {
		int a = 1;
	}

	new_body->m_vertex = new_vertex;


	return new_body;
}

vertex* mev(vertex* v1, loop* lo)
{

	vertex* ver = new vertex();
	coedge* coe1 = new coedge();
	coedge* coe2 = new coedge();
	edge* edg = new edge();

	edg->m_coedge1 = coe1;
	edg->m_coedge2 = coe2;

	coe1->startvertex = v1;
	coe1->endvertex = ver;

	coe2->startvertex = ver;
	coe2->endvertex = v1;


	

	coe1->m_loop = lo;

	coe2->m_loop = lo;

	coe1->m_edge = edg;
	coe2->m_edge = edg;

	///*coe1.m_edge = edg;*/

	///*coe2.m_edge = edg;*/

	

	if (lo->m_coedge == nullptr) {
		lo->m_coedge = coe1;

		coe1->nextcoedge = coe2;
		coe2->precoedge = coe1;
		coe1->precoedge = coe2;

		coe2->nextcoedge = coe1;
	}
	else {
		coedge* tmpco = lo->m_coedge;
		while (tmpco->endvertex != v1) {
			tmpco = tmpco->nextcoedge;
		}
		coedge* nexco = tmpco->nextcoedge;

		tmpco->nextcoedge = coe1;
		coe1->precoedge = tmpco;

		coe1->nextcoedge = coe2;
		coe2->precoedge = coe1;

		coe2->nextcoedge = nexco;
		nexco->precoedge = coe2;
	}

	return ver;
}

face* mef(face* fac, vertex* v1, vertex* v2)
{
	edge* edg = new edge();
	coedge* coe1 = new coedge();
	coedge* coe2 = new coedge();



	coe1->startvertex = v2;
	coe1->endvertex = v1;

	coe2->startvertex = v1;
	coe2->endvertex = v2;

	edg->m_coedge1 = coe1;
	edg->m_coedge2 = coe2;

	coe1->m_edge = edg;
	coe2->m_edge = edg;

	face* tmpfa = fac;

	
	loop* lo = tmpfa->m_loop;
	while (lo->nextloop != nullptr) {
		lo = lo->nextloop;
	}

	coedge* tmpcoe = lo->m_coedge;
	while (tmpcoe->endvertex != v2) {
		tmpcoe = tmpcoe->nextcoedge;
	}

	coedge* lascoedge = lo->m_coedge;
	while (lascoedge->endvertex != v1) {
		lascoedge = lascoedge->nextcoedge;
	}
	coedge* nexco = tmpcoe->nextcoedge;
	tmpcoe->nextcoedge = coe1;
	coe1->precoedge = tmpcoe->nextcoedge;
	

	
	
	coe1->nextcoedge = lascoedge->nextcoedge;
	lascoedge->nextcoedge->precoedge = coe1;

	lo->m_coedge = lascoedge->nextcoedge;

	face* fa = new face();
	loop* new_lo = new loop();
	fa->m_loop = new_lo;

	fa->nextface = tmpfa->nextface;

	tmpfa->nextface = fa;

	fa->preface = tmpfa;
	


	
	new_lo->m_coedge = coe2;
	new_lo->nextloop = nullptr;

	coe2->nextcoedge = nexco;
	nexco->precoedge = coe2;



	lascoedge->nextcoedge = coe2;
	coe2->precoedge = lascoedge;

	return fa;
}

loop* kemr(loop* lo, edge* edg)
{
	coedge* coe1 = edg->m_coedge1;
	coedge* coe2 = edg->m_coedge2;

	loop* new_loop = new loop();

	face* fa = static_cast<face*>(lo->m_face);
	
	new_loop->m_coedge = coe1->nextcoedge;
	lo->m_coedge = coe2->nextcoedge;

	while (lo->nextloop != nullptr) {
		lo = lo->nextloop;
	}


	new_loop->preloop = lo;
	new_loop->nextloop = nullptr;

	new_loop->m_face = fa;

	lo->nextloop = new_loop;

	coe1->precoedge->nextcoedge = coe2->nextcoedge;

	coe2->precoedge->nextcoedge = coe1->nextcoedge;

	delete(edg);
	return NULL;
}

loop* kfmrh(face* delfac, face* depfac)
{
	loop* lo = depfac->m_loop;

	while (lo->nextloop != NULL) {
		lo = lo->nextloop;
	}

	loop* ne = delfac->m_loop;



	lo->nextloop = ne;

	ne->m_face = depfac;

	delfac->preface->nextface = delfac->nextface;

	delete(delfac);


	return NULL;
}

face* mef(face* fac, vertex* v1, vertex* v2, vertex* helpvertex)
{
	edge* edg = new edge();
	coedge* coe1 = new coedge();
	coedge* coe2 = new coedge();



	coe1->startvertex = v2;
	coe1->endvertex = v1;

	coe2->startvertex = v1;
	coe2->endvertex = v2;

	edg->m_coedge1 = coe1;
	edg->m_coedge2 = coe2;

	coe1->m_edge = edg;
	coe2->m_edge = edg;

	face* tmpfa = fac;


	loop* lo = tmpfa->m_loop;
	/*while (lo->nextloop != nullptr) {
		lo = lo->nextloop;
	}*/

	coedge* tmpcoe = lo->m_coedge;
	while (tmpcoe->endvertex != v2) {
		tmpcoe = tmpcoe->nextcoedge;
	}

	coedge* lascoedge = lo->m_coedge;
	while (true) {
		if (lascoedge->endvertex == v1) {
			if (lascoedge->startvertex != helpvertex) {
				break;
			}
		}
		lascoedge = lascoedge->nextcoedge;
		
	}
	coedge* nexco = tmpcoe->nextcoedge;
	tmpcoe->nextcoedge = coe1;
	coe1->precoedge = tmpcoe->nextcoedge;




	coe1->nextcoedge = lascoedge->nextcoedge;

	lascoedge->nextcoedge->precoedge = coe1;

	lo->m_coedge = lascoedge->nextcoedge;

	face* fa = new face();
	loop* new_lo = new loop();
	fa->m_loop = new_lo;

	fa->nextface = tmpfa->nextface;

	tmpfa->nextface = fa;

	fa->preface = tmpfa;




	new_lo->m_coedge = coe2;
	new_lo->nextloop = nullptr;

	coe2->nextcoedge = nexco;
	nexco->precoedge = coe2;



	lascoedge->nextcoedge = coe2;
	coe2->precoedge = lascoedge;

	return fa;
}




