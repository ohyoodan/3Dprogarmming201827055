#include"MuSoenMath.h"

using namespace MuSoenMath;

int main() {



	vec3 v;

	mat3 Translate, Rotate, Scale;
	Translate.Translateinput(2,3);
	Scale.Scaleinput(2);
	Rotate.Rotateinput(30);
	
	
	
	//vec3 p = v * Translate * Rotate * Scale;   // 3,5 이동 | 30도 회전 | 2배 확대
	vec3 p;
		p.reset();
		p= v * Translate;
	p.showVec3();
	//출력 부 작성

}

