#include"MuSoenMath.h"

using namespace MuSoenMath;

int main() {



	vec3 v(0,0);// 처음 좌표위치 클래스 선언
	float t[3][3]={ 
		{1,2,2},
		{4,2,9},
		{1,3,3}
	};
	mat3 s(t);

	//mat3 translate, rotate, scale;// 3개의 매트릭스 생성
	//translate.translateinput(2,3);// 매트릭스에 이동 값 기입
	//scale.scaleinput(2);//매트릭스에 스케일 값 기입
	//rotate.rotateinput(30);//매트릭스에 60분법으로 기입
	//
	 vec3 p;// 계산 완료할 좌표위치 클래스 선언
	
	//p=  v * Translate * Rotate * Scale;
	//p.showVec3();//출력
	//
	 
	 s.transpose();
	 s.show();
	 s.identity();
	 s.show();
}

