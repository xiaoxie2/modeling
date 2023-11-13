#include "base.h"
#include <vector>

body* createbasebody(int ty)
{
	body* m_body = new body();

	if (ty == 0) {
		point p1, p2, p3, p4, p5, p6, p7, p8;
		p1.setpos(0, 0, 0);
		p2.setpos(0, 3, 0);
		p3.setpos(3, 3, 0);
		p4.setpos(3, 0, 0);

		p5.setpos(1, 1, 0);
		p6.setpos(2, 1, 0);
		p7.setpos(2, 2, 0);
		p8.setpos(1, 2, 0);

		p1.setcolor(1, 0, 0);
		p2.setcolor(0.5, 0, 0);
		p3.setcolor(0.5, 0.5, 0);
		p4.setcolor(0.0, 0.0, 1.0);
		p5.setcolor(0.5, 0.5, 0);
		p6.setcolor(1, 0, 0);
		p7.setcolor(0.5, 0, 0);
		p8.setcolor(0.5, 0.5, 0);

		std::vector<point> po;
		po.push_back(p1);
		po.push_back(p2);
		po.push_back(p3);
		po.push_back(p4);
		po.push_back(p5);
		po.push_back(p6);
		po.push_back(p7);
		po.push_back(p8);

		m_body = mvfs();
		m_body->m_vertex->setpoint(po[0]);

		vertex* tmpvertex = m_body->m_vertex;
		loop* tmploop = m_body->m_face->m_loop;

		for (int i = 0; i < 3; i++) {

			tmpvertex = mev(tmpvertex, tmploop);

			tmpvertex->setpoint(po[i + 1]);

		}

		face* tmpfa = m_body->m_face;

		tmpfa = mef(tmpfa, m_body->m_vertex, tmpvertex);

		vertex* inneevertex = tmpvertex;

		tmpvertex = m_body->m_vertex;
		for (int i = 0; i < 4; i++) {
			tmpvertex = mev(tmpvertex, tmploop);
			tmpvertex->setpoint(po[i + 4]);
			if (i == 0) {
				inneevertex = tmpvertex;
			}

		}

		tmpfa = m_body->m_face;
		tmpfa = mef(tmpfa, inneevertex, tmpvertex, m_body->m_vertex);

		coedge* coe1 = m_body->m_face->m_loop->m_coedge;

		bool getedg = false;


		while (!getedg)
		{
			if (coe1->startvertex == m_body->m_vertex && coe1->endvertex == inneevertex) {
				break;
			}
			coe1 = coe1->nextcoedge;
		}

		edge* edf = static_cast<edge*>(coe1->m_edge);

		kemr(m_body->m_face->m_loop, edf);
	}
	else {
		point p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12;
		p1.setpos(0, 0, 0);
		p2.setpos(0, 3, 0);
		p3.setpos(6, 3, 0);
		p4.setpos(6, 0, 0);

		p5.setpos(1, 1, 0);
		p6.setpos(2, 1, 0);
		p7.setpos(2, 2, 0);
		p8.setpos(1, 2, 0);

		p9.setpos(3, 1, 0);
		p10.setpos(4, 1, 0);
		p11.setpos(4, 2, 0);
		p12.setpos(3, 2, 0);

		p1.setcolor(1, 0, 0);
		p2.setcolor(0.5, 0, 0);
		p3.setcolor(0.5, 0.5, 0);
		p4.setcolor(0.0, 0.0, 1.0);
		p5.setcolor(0.5, 0.5, 0);
		p6.setcolor(1, 0, 0);
		p7.setcolor(0.5, 0, 0);
		p8.setcolor(0.5, 0.5, 0);

		p9.setcolor(0.5, 0.5, 0);
		p10.setcolor(1, 0, 0);
		p11.setcolor(0.5, 0, 0);
		p12.setcolor(0.5, 0.5, 0);

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

		m_body = mvfs();
		m_body->m_vertex->setpoint(po[0]);

		vertex* tmpvertex = m_body->m_vertex;
		loop* tmploop = m_body->m_face->m_loop;

		for (int i = 0; i < 3; i++) {

			tmpvertex = mev(tmpvertex, tmploop);

			tmpvertex->setpoint(po[i + 1]);

		}

		face* tmpfa = m_body->m_face;

		tmpfa = mef(tmpfa, m_body->m_vertex, tmpvertex);
		vertex* inneevertex = tmpvertex;

		tmpvertex = m_body->m_vertex;
		for (int i = 0; i < 4; i++) {
			tmpvertex = mev(tmpvertex, tmploop);
			tmpvertex->setpoint(po[i + 4]);
			if (i == 0) {
				inneevertex = tmpvertex;
			}

		}

		tmpfa = m_body->m_face;
		tmpfa = mef(tmpfa, inneevertex, tmpvertex, m_body->m_vertex);

		coedge* coe1 = m_body->m_face->m_loop->m_coedge;

		bool getedg = false;


		while (!getedg)
		{
			if (coe1->startvertex == m_body->m_vertex && coe1->endvertex == inneevertex) {
				break;
			}
			coe1 = coe1->nextcoedge;
		}

		edge* edf = static_cast<edge*>(coe1->m_edge);

		kemr(m_body->m_face->m_loop, edf);


		tmpvertex = m_body->m_vertex;
		for (int i = 0; i < 4; i++) {
			tmpvertex = mev(tmpvertex, tmploop);
			tmpvertex->setpoint(po[i + 8]);
			if (i == 0) {
				inneevertex = tmpvertex;
			}

		}
		tmpfa = m_body->m_face;
		tmpfa = mef(tmpfa, inneevertex, tmpvertex, m_body->m_vertex);

		coe1 = m_body->m_face->m_loop->m_coedge;

		getedg = false;


		while (!getedg)
		{
			if (coe1->startvertex == m_body->m_vertex && coe1->endvertex == inneevertex) {
				break;
			}
			coe1 = coe1->nextcoedge;
		}

		edf = static_cast<edge*>(coe1->m_edge);

		kemr(m_body->m_face->m_loop, edf);


	}
	
	

	return m_body;
}
