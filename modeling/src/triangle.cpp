#include "triangle.h"

std::vector<point> triangle(body* m_body,bool fir)
{
	body* bo = m_body;
	std::vector<point> vertices_3;
	face* tmpfa = bo->m_face;
	int fano = 0;

	while (tmpfa != nullptr) {
		loop* tmplo = tmpfa->m_loop;

		if (tmplo->nextloop != nullptr) {
			if (tmplo->nextloop->nextloop == nullptr) {
				loop* inloop = tmplo->nextloop;
				coedge* incoe = inloop->m_coedge;
				std::vector<point> invertex;


				invertex.push_back(incoe->startvertex->entpoint);

				incoe = incoe->nextcoedge;

				while (incoe != inloop->m_coedge) {
					invertex.push_back(incoe->startvertex->entpoint);
					incoe = incoe->nextcoedge;
				}

				coedge* outcoe = tmplo->m_coedge;
				std::vector<point> outvertex;

				outvertex.push_back(outcoe->startvertex->entpoint);
				outcoe = outcoe->nextcoedge;

				while (outcoe != tmplo->m_coedge) {
					outvertex.push_back(outcoe->startvertex->entpoint);
					outcoe = outcoe->nextcoedge;
				}

				for (int i = 0; i < outvertex.size(); i++) {

					float min = 1000000;
					int minj = 0;

					for (int j = 0; j < invertex.size(); j++) {
						float dia = outvertex[i].distance(invertex[j]);
						if (dia < min) {
							min = dia;
							minj = j;
						}
					}

					vertices_3.push_back(outvertex[i]);
					vertices_3.push_back(outvertex[(i + 1) % outvertex.size()]);
					vertices_3.push_back(invertex[(minj - 1) % invertex.size()]);

					vertices_3.push_back(outvertex[i]);
					vertices_3.push_back(invertex[minj]);
					vertices_3.push_back(invertex[(minj - 1) % invertex.size()]);
				}
			}
			else {
				loop* inloop1 = tmplo->nextloop;
				loop* inloop2 = inloop1->nextloop;

				coedge* incoe = inloop1->m_coedge;
				std::vector<point> invertex1;


				invertex1.push_back(incoe->startvertex->entpoint);

				
				incoe = incoe->nextcoedge;

				while (incoe != inloop1->m_coedge) {
					invertex1.push_back(incoe->startvertex->entpoint);
					incoe = incoe->nextcoedge;
				}

				incoe = inloop2->m_coedge;
				std::vector<point> invertex2;


				invertex2.push_back(incoe->startvertex->entpoint);

				incoe = incoe->nextcoedge;

				while (incoe != inloop2->m_coedge) {
					invertex2.push_back(incoe->startvertex->entpoint);
					incoe = incoe->nextcoedge;
				}

				coedge* outcoe = tmplo->m_coedge;
				std::vector<point> outvertex;

				outvertex.push_back(outcoe->startvertex->entpoint);
				outcoe = outcoe->nextcoedge;

				while (outcoe != tmplo->m_coedge) {
					outvertex.push_back(outcoe->startvertex->entpoint);
					outcoe = outcoe->nextcoedge;
				}
				

				int i1=0, i2=0, j1=0, j2=0;
				for (int i = 0; i < 4; i++) {
					if (invertex1[i].pos[0] == 2 && invertex1[i].pos[1] == 1) {
						i1 = i;
						if (fano == 0) {
							i2 = (i + 1) % invertex1.size();
						}
						else {
							i2 = (i - 1) % invertex1.size();
						}
					}
					if (invertex2[i].pos[0] == 3 && invertex2[i].pos[1] == 1) {
						j1 = i;
						if (fano == 0) {
							j2 = (i - 1) % invertex2.size();
						}
						else {
							j2 = (i + 1) % invertex2.size();
						}
						
					}
				}

				

				vertices_3.push_back(invertex1[i1]);
				vertices_3.push_back(invertex2[j1]);
				vertices_3.push_back(invertex2[j2]);
				vertices_3.push_back(invertex2[j2]);
				vertices_3.push_back(invertex1[i2]);
				vertices_3.push_back(invertex1[i1]);
				
				for (int i = 0; i < 4; i++) {
					float min1 = 10000,min2 =10000;
					int minj1 = 0, minj2 = 0;
					float dia = 0;
					for (int j = 0; j < 4; j++) {
						dia = outvertex[i].distance(invertex1[j]);
						if (min1 > dia) {
							min1 = dia;
							minj1 = j;
						}
					}

					for (int j = 0; j < 4; j++) {
						dia = outvertex[i].distance(invertex2[j]);
						if (min2 > dia) {
							min2 = dia;
							minj2 = j;
						}
					}

					if (min1 < min2) {
						vertices_3.push_back(outvertex[i]);
						vertices_3.push_back(invertex1[minj1]);
						if (fano == 0) {
							vertices_3.push_back(invertex1[(minj1 - 1) % invertex1.size()]);

							vertices_3.push_back(outvertex[i]);
							vertices_3.push_back(invertex1[(minj1 - 1) % invertex1.size()]);
							vertices_3.push_back(outvertex[(i + 1) % outvertex.size()]);
						}
						else {
							vertices_3.push_back(invertex1[(minj1 + 1) % invertex1.size()]);

							vertices_3.push_back(outvertex[i]);
							vertices_3.push_back(invertex1[(minj1 + 1) % invertex1.size()]);
							vertices_3.push_back(outvertex[(i - 1) % outvertex.size()]);
						}

						if (i % 2 == 0) {
							vertices_3.push_back(outvertex[i]);
							vertices_3.push_back(invertex1[minj1]);
							vertices_3.push_back(invertex2[minj2]);
						}
					}

					else {
						vertices_3.push_back(outvertex[i]);
						vertices_3.push_back(invertex2[minj2]);
						if (fano == 0) {
							vertices_3.push_back(invertex2[(minj2 - 1) % invertex2.size()]);

							vertices_3.push_back(outvertex[i]);
							vertices_3.push_back(invertex2[(minj2 - 1) % invertex2.size()]);
							vertices_3.push_back(outvertex[(i + 1) % invertex2.size()]);
						}
						else{
							vertices_3.push_back(invertex2[(minj2 + 1) % invertex2.size()]);

							vertices_3.push_back(outvertex[i]);
							vertices_3.push_back(invertex2[(minj2 + 1) % invertex2.size()]);
							vertices_3.push_back(outvertex[(i - 1) % invertex2.size()]);
						}
						

						if (i % 2 == 0) {
							vertices_3.push_back(outvertex[i]);
							vertices_3.push_back(invertex2[minj2]);
							vertices_3.push_back(invertex1[minj1]);
						}
					}
					
				}



			}
		}
		else {
			int i = 0;
			coedge* tmpco = tmplo->m_coedge;
			vertices_3.push_back(tmpco->startvertex->entpoint);

			vertices_3.push_back(tmpco->endvertex->entpoint);
			i++;
			tmpco = tmpco->nextcoedge;
			while (tmpco != tmplo->m_coedge) {
				if (i % 2 == 0) {
					vertices_3.push_back(tmpco->startvertex->entpoint);
				}
				vertices_3.push_back(tmpco->endvertex->entpoint);

				tmpco = tmpco->nextcoedge;
				i++;
			}
		}
		if (fir) {
			break;
		}
		tmpfa = tmpfa->nextface;
		fano++;
	}
	return vertices_3;
}
