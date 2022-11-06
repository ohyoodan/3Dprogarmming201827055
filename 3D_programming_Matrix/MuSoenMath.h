#pragma once
#include <iostream>
using namespace std;
//https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=kimjw1218&logNo=70178503080 회전, 이동 , 스케일
//https://3001ssw.tistory.com/232 호도법 과 60분법
//https://blog.hexabrain.net/177 연산자 오버로딩
//https://steemit.com/kr-dev/@codingman/c-10-3x3--1561681495960 3x3 행렬의 곱
//https://boycoding.tistory.com/219 참조 및 값 변환


namespace MuSoenMath {
	class mat3 {

	public: float  mat[3][3]{
		{0,0,0},
		{0,0,0},
		{0,0,0}
	};

		  mat3() {
			  mat[0][0] = 1;
			  mat[1][1] = 1;
			  mat[2][2] = 1;

		  }

		  ~mat3() {

		  }

	public: void Rotateinput(float Degree) {
		// 60분법을 호도법으로 바꾸고 기입
		float PI = 3.141592;
		float theta = (PI / 180) * (Degree);
		float cos;
		float sin;
		mat[0][0] = 0; //cos;
		mat[1][1] = -1;// cos;
		mat[1][0] = 1;//sin;
		mat[0][1] = 0;//(-1 * sin);
	}

	public:void Scaleinput(float scale) {
		//단순히 비율 증가 시  만약 x,y따로 하고싶으면 [1][1]위치에 y를 배치
		mat[0][0] = scale;
		mat[1][1] = scale;
		mat[2][2] = 1;
	}
	public:void Translateinput(float x, float y) {
		//전치 안했음
		mat[0][2] = x;
		mat[1][2] = y;
		mat[2][2] = 1;
	}

	public: void showMet3() {
		//출력부
		for (int i = 0; i < 3; i++) {
			cout << endl;
			for (int j = 0; j < 3; j++) {
				cout << " " << mat[i][j];
			}
		}

	}

		  void reset() {
			  for (int i = 0; i < 3; i++) {
				  for (int j = 0; j < 3; j++) {
					  mat[i][j] = 0;
				  }
			  }
		  }

		  mat3 operator*(mat3& ref) {
			  mat3 out;
			  out.reset();
			  for (int i = 0; i < 3; i++) {
				  for (int j = 0; j < 3; j++) {
					  for (int k = 0; k < 3; k++) {
						  //행렬 계산//i 행 k 열
						  out.mat[i][j] += mat[i][k] * ref.mat[k][j];
					  }
				  }
			  }
			  return out;
		  }
	



	};

	class vec3 {//mat 상속
	public: float vec[3][3]{
		0
	};
		  void reset() {
			  vec[0][0] = 0;
			  vec[0][1] = 0;
			  vec[0][2] = 1;
		  }
		  // m*n 행렬 m행 i열 : 3행 1열 배열 
		  vec3() {

		  }
		  vec3(float a, float b) {
			  vec[3][3] = { 0 };
			  vec[0][0] = a;
			  vec[0][1] = b;
			  vec[0][2] = 1;
		  }
		  ~vec3() {

		  }
		  

	public: void showVec3() {
		
			for (int i = 0; i < 1; i++) {
				for (int j = 0; j < 3; j++) {
					cout << " " << vec[i][j];
				}
				
			}
		

	}

		 vec3 operator*(mat3& ref) {
			  vec3 out(3,3);
			  
			  for (int i = 0; i < 1; i++) {
				  for (int j = 0; j < 3; j++) {
					  for (int k = 0; k < 3; k++) {
						  out.vec[i][j] += vec[i][k] * ref.mat[k][j];
					  }
				  }
			  }

			  
			  return out;
		  }
	};

	

	

}




