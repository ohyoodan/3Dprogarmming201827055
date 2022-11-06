#pragma once
#include <iostream>
using namespace std;
//https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=kimjw1218&logNo=70178503080 ȸ��, �̵� , ������
//https://3001ssw.tistory.com/232 ȣ���� �� 60�й�
//https://blog.hexabrain.net/177 ������ �����ε�
//https://steemit.com/kr-dev/@codingman/c-10-3x3--1561681495960 3x3 ����� ��
//https://boycoding.tistory.com/219 ���� �� �� ��ȯ


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
		// 60�й��� ȣ�������� �ٲٰ� ����
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
		//�ܼ��� ���� ���� ��  ���� x,y���� �ϰ������ [1][1]��ġ�� y�� ��ġ
		mat[0][0] = scale;
		mat[1][1] = scale;
		mat[2][2] = 1;
	}
	public:void Translateinput(float x, float y) {
		//��ġ ������
		mat[0][2] = x;
		mat[1][2] = y;
		mat[2][2] = 1;
	}

	public: void showMet3() {
		//��º�
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
						  //��� ���//i �� k ��
						  out.mat[i][j] += mat[i][k] * ref.mat[k][j];
					  }
				  }
			  }
			  return out;
		  }
	



	};

	class vec3 {//mat ���
	public: float vec[3][3]{
		0
	};
		  void reset() {
			  vec[0][0] = 0;
			  vec[0][1] = 0;
			  vec[0][2] = 1;
		  }
		  // m*n ��� m�� i�� : 3�� 1�� �迭 
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




