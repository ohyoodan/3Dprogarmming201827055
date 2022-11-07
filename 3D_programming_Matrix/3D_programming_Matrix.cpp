#include"MuSoenMath.h"

using namespace MuSoenMath;

int main() {



	vec3 v(0,0);// 처음 좌표위치 클래스 선언
	

	mat3 Translate, Rotate, Scale;// 3개의 매트릭스 생성
	Translate.Translateinput(2,3);// 매트릭스에 이동 값 기입
	Scale.Scaleinput(2);//매트릭스에 스케일 값 기입
	Rotate.Rotateinput(30);//매트릭스에 60분법으로 기입
	
	 vec3 p;// 계산 완료할 좌표위치 클래스 선언
	
	p=  v * Translate * Rotate * Scale;
	p.showVec3();//출력
	

}

