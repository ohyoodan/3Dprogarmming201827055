#pragma once
#include <iostream>
using namespace std;
//https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=kimjw1218&logNo=70178503080 회전, 이동 , 스케일
//https://3001ssw.tistory.com/232 호도법 과 60분법
//https://blog.hexabrain.net/177 연산자 오버로딩
//https://steemit.com/kr-dev/@codingman/c-10-3x3--1561681495960 3x3 행렬의 곱
//https://boycoding.tistory.com/219 참조 및 값 변환


namespace MuSoenMath {


	class vec3 {
	public: float vec[3][1]{
		{0},
		{0},
		{1}
	};
	public: float po[3][3]{
			  {},
			  {},
			  {}
	};
		  // m*n 행렬 m행 i열 : 3행 1열 배열 
		  vec3() {

		  }
		  ~vec3() {

		  }

	public: void showVec3() {
		cout << "" << endl;
	}

		  vec3 operator*(vec3& ref) {
			  for (int i = 0; i < 3; i++) {
				  for (int j = 0; j < 3; j++) {
					  for (int k = 0; k < 3; k++) {
						  ref.vec[i][j] += ref.vec[i][k] * ref.vec[k][j];
					  }
				  }
			  }
		  }
	};





	class mat3 {
		//초기화
	public: float  mat[3][3]{
		{1,0,0},
		{0,1,0},
		{0,0,1}
	};

		  mat3() {
			  
				  
			  

		  }
		  ~mat3() {

		  }

	public: void Rotateinput(float Degree) {
		// 60분법을 호도법으로 바꾸고 기입
		/*float PI = 3.141592;
		float theta = (PI / 180) * (Degree);
		float cos;
		float sin;
		mat[0][0] = cos;
		mat[1][1] = cos;
		mat[1][0] = sin;
		mat[0][1] = (-1 * sin);*/
	}

	public:void Scaleinput(float scale) {
		//단순히 비율 증가 시  만약 x,y따로 하고싶으면 [1][1]위치에 y를 배치
		mat[0][0] = scale;
		mat[1][1] = scale;
	}
	public:void Translateinput(float x, float y) {
		//전치 되었다 가정
		mat[2][0] = x;
		mat[2][1] = y;
	}

	public: void showVec3() {
		//출력부
			for (int i = 0; i < 3; i++) {
				cout << endl;
				for (int j = 0; j < 3; j++) {
					cout << " " << mat[i][j];				
			}
		}

	}


		  mat3 operator*(mat3& ref) {
			  mat3 a;
			  for (int i = 0; i < 3; i++) {
				  for (int j = 0; j < 3; j++) {
					  for (int k = 0; k < 3; k++) {
						  
						  a.mat[i] [j] += ref.mat[i][k] * ref.mat[k][j];
					  }}}
			  return a;
				  }

		  
	};

}




