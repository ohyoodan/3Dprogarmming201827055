#include"MuSoenMath.h"

using namespace MuSoenMath;

int main() {



	vec3 v(0,0);// 처음 좌표위치 클래스 선언
	float t[3][3]={ 
		{1,2,2},
		{4,2,9},
		{1,3,3}
	};

	float te[3][3] = {
		{2,3,4},
		{2,4,2},
		{2,5,3}
	};
	mat3 s(t);
	mat3 se(te);
	mat3 translate, rotate, scale;// 3개의 매트릭스 생성
	translate.Translateinput(2,3);// 매트릭스에 이동 값 기입
	scale.Scaleinput(2);//매트릭스에 스케일 값 기입
	rotate.Rotateinput(30);//매트릭스에 60분법으로 기입
	
	 vec3 p(2,3);// 계산 완료할 좌표위치 클래스 선언
	 mat3 test;
	 v = p * translate * rotate * scale;	 
	 
	 
	v.show();//출력
	
	p =p * 3;
	p.transpose();
	p.show();
	p = p / 2;
	p.show();

	
	
}

