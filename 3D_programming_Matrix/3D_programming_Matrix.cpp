#include"MuSoenMath.h"

using namespace MuSoenMath;

int main() {



	vec3 v;

	mat3 Translate, Rotate, Scale;

	vec3 p = v * Translate * Rotate * Scale;   // 3,5 이동 | 30도 회전 | 2배 확대// 전치 안한거같음 scale*rotate*translate*v가 옳은거 같음

	//출력 부 작성

}

