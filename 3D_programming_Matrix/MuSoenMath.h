#pragma once
#include <iostream>
using namespace std;
//https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=kimjw1218&logNo=70178503080 ȸ��, �̵� , ������
//https://3001ssw.tistory.com/232 ȣ���� �� 60�й�
//https://blog.hexabrain.net/177 ������ �����ε�
//https://steemit.com/kr-dev/@codingman/c-10-3x3--1561681495960 3x3 ����� ��
//https://boycoding.tistory.com/219 ���� �� �� ��ȯ


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
		  // m*n ��� m�� i�� : 3�� 1�� �迭 
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
						  //C[i][j] += A[i][k] * B[k][j];
					  }
				  }
			  }
		  }
	};





	class mat3 {
		//�ʱ�ȭ
	public: float  mat[3][3]{
		{1,0,0},
		{0,1,0},
		{0,0,1}
	};



		  mat3(f) {


		  }
		  ~mat3() {

		  }

	public: void Rotateinput(float Degree) {
		// 60�й��� ȣ�������� �ٲٰ� ����
		float PI = 3.141592;
		float theta = (PI / 180) * (Degree);
		float cos;
		float sin;
		mat[0][0] = cos;
		mat[1][1] = cos;
		mat[1][0] = sin;
		mat[0][1] = (-1 * sin);
	}

	public:void Scaleinput(float scale) {
		//�ܼ��� ���� ���� ��  ���� x,y���� �ϰ������ [1][1]��ġ�� y�� ��ġ
		mat[0][0] = scale;
		mat[1][1] = scale;
	}
	public:void Translateinput(float x, float y) {
		//��ġ �Ǿ��� ����
		mat[2][0] = x;
		mat[2][1] = y;
	}




		  mat3 operator*(mat3& ref) {
			  /*for (int i = 0; i < 3; i++) {
				  for (int j = 0; j < 3; j++) {
					  for (int k = 0; k < 3; k++) {
						  C[i][j] += mat[i][k] * B[k][j];
					  }
				  }*/
		  }
	};

}




