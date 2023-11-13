#include "sweeping.h"
#include <vector>

body* createbody()
{
	point p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, p16;
	p1.setpos(0, 0, 0);
	
	p2.setpos(0, 3, 0);
	
	p3.setpos(3, 3, 0);
	
	p4.setpos(3, 0, 0);
	
	p5.setpos(0, 0, 3);
	
	p6.setpos(0, 3, 3);
	p7.setpos(3, 3, 3);
	p8.setpos(3, 0, 3);
	p9.setpos(1, 1, 0);
	p10.setpos(2, 1, 0);
	p11.setpos(2, 2, 0);
	p12.setpos(1, 2, 0);
	p13.setpos(1, 2, 3);
	p14.setpos(1, 1, 3);
	p15.setpos(2, 1, 3);
	p16.setpos(2, 2, 3);

	p1.setcolor(1, 0, 0);
	p2.setcolor(0.5, 0, 0);
	p3.setcolor(0.5, 0.5, 0);
	p4.setcolor(0.0, 0.0, 1.0);
	p5.setcolor(0.5, 0.5, 0);

	p6.setcolor(1, 0, 0);
	p7.setcolor(0.5, 0, 0);
	p8.setcolor(0.5, 0.5, 0);
	p9.setcolor(0.0, 0.0, 1.0);
	p10.setcolor(0.5, 0.5, 0);

	p11.setcolor(1, 0, 0);
	p12.setcolor(0.5, 0, 0);
	p13.setcolor(0.5, 0.5, 0);
	p14.setcolor(0.0, 0.0, 1.0);
	p15.setcolor(0.5, 0.5, 0);
	p16.setcolor(0.5, 0.5, 0);

	std::vector<point> po;
	po.push_back(p1);
	po.push_back(p2);
	po.push_back(p3);
	po.push_back(p4);
	po.push_back(p5);
	po.push_back(p6);
	po.push_back(p7);
	po.push_back(p8);
	po.push_back(p9);
	po.push_back(p10);
	po.push_back(p11);
	po.push_back(p12);
	po.push_back(p13);
	po.push_back(p14);
	po.push_back(p15);
	po.push_back(p16);

	body* m_body = mvfs();
	m_body->m_vertex->setpoint(po[0]);

	vertex* tmpvertex = m_body->m_vertex;
	loop* tmploop = m_body->m_face->m_loop;
	
	for (int i = 0; i < 3; i++) {


		tmpvertex = mev(tmpvertex, tmploop);


		tmpvertex->setpoint(po[i+1]);
		
	}

	face* tmpfa = m_body->m_face;

	/*tmpfa = mef(tmpfa, m_body->m_vertex, tmpvertex);*/

	coedge* coe1 = m_body->m_face->m_loop->m_coedge;

	tmploop = tmpfa->m_loop;
	int i = 0;
	std::vector<vertex*> ver;

	tmpvertex = coe1->startvertex;
	tmpvertex = mev(tmpvertex, tmploop);
	tmpvertex->setpoint(po[i+4]);
	ver.push_back(tmpvertex);
	i++;
	coe1 = coe1->nextcoedge;

	
	while (coe1!= m_body->m_face->m_loop->m_coedge) {
		tmpvertex = coe1->startvertex;
		tmpvertex = mev(tmpvertex, tmploop);
		tmpvertex->setpoint(po[i+4]);
		ver.push_back(tmpvertex);
		i++;
		coe1 = coe1->nextcoedge;
	}
	for (int j = 0; j < ver.size();j++) {
		auto v1 = ver[j];
		auto v2 = ver[(j + 1) % ver.size()];
		/*tmpfa = mef(tmpfa, v2, v1);*/
	}

	tmploop = m_body->m_face->m_loop;
	tmpvertex = tmploop->m_coedge->startvertex;
	vertex* outver = tmpvertex;

	vertex* start = new vertex();
	for (int i = 0; i < 4; i++) {
		tmpvertex = mev(tmpvertex, tmploop);
		tmpvertex->setpoint(po[i + 8]);
		if (i == 0) {
			start = tmpvertex;
		}
	}

	tmpfa = m_body->m_face;
	/*tmpfa = mef(tmpfa, tmpvertex, start);*/

	coedge* tmpco = tmploop->m_coedge;
	edge* edf =static_cast<edge *>(tmpco->m_edge);
	bool getedg = false;
	while (!getedg) {
		if (tmpco->startvertex == outver && tmpco->endvertex == start) {
			edf = static_cast<edge*>(tmpco->m_edge);
			break;
		}
		tmpco = tmpco->nextcoedge;
	}
	kemr(tmploop, edf);

	tmploop = tmpfa->m_loop;
	tmpco = tmploop->m_coedge;

	i = 0; 
	ver.clear();
	ver.push_back(tmpco->startvertex);
	tmpco = tmpco->nextcoedge;
	while (tmpco!=tmploop->m_coedge)
	{
		ver.push_back(tmpco->startvertex);
		tmpco = tmpco->nextcoedge;
	}

	std::vector<vertex*> va;
	for (i = 0; i < 4; i++) {
		tmpvertex = mev(ver[i], tmploop);
		tmpvertex->setpoint(po[i + 12]);
		va.push_back(tmpvertex);
		
	}

	for (int j = 0; j < ver.size(); j++) {
		auto v1 = va[j];
		auto v2 = va[(j + 1) % va.size()];
		/*tmpfa = mef(tmpfa, v1, v2);*/
	}

	kfmrh(tmpfa,tmpfa->preface);

	return m_body;
}

body* sweep(body* m_body, float offest)
{
	
	face* tmpfa = m_body->m_face;

	std::vector<face*> usedfce;
	while (tmpfa->nextface!=nullptr)
	{
		usedfce.push_back(tmpfa->nextface);
		tmpfa = tmpfa->nextface;
	}
	face* depfa = tmpfa;

	loop* tmploop = tmpfa->m_loop;

	loop* originloop = m_body->m_face->m_loop;
	int i = 0;
	while (originloop != nullptr) {
		tmpfa = usedfce[usedfce.size() - 1 - i];

		tmploop = tmpfa->m_loop;
		coedge* coe1 = originloop->m_coedge;

		std::vector<vertex*> ver;
		vertex* originvertex = coe1->startvertex;
		vertex* tmpvertex = mev(originvertex, tmploop);

		point p;
		p = originvertex->entpoint;
		p.pos[2] = p.pos[2] + offest;
		tmpvertex->setpoint(p);
		ver.push_back(tmpvertex);

		coe1 = coe1->nextcoedge;

		while (coe1 != originloop->m_coedge) {
			originvertex = coe1->startvertex;
			tmpvertex = mev(originvertex, tmploop);
			p = originvertex->entpoint;
			p.pos[2] = p.pos[2] + offest;
			tmpvertex->setpoint(p);
			ver.push_back(tmpvertex);
			
			coe1 = coe1->nextcoedge;
		}

		
		for (int j = 0; j < ver.size(); j++) {
			auto v1 = ver[j];
			auto v2 = ver[(j + 1) % ver.size()];
			tmpfa = mef(tmpfa, v2, v1);
		}

		if (i == 0) {
			depfa = tmpfa;
		}
		if (i > 0) {
			kfmrh(tmpfa,depfa);
		}

		i++;
		originloop = originloop->nextloop;
		
	}

	
	return m_body;
}





