#pragma once
#include <iostream>
#define rows 3
using namespace std;
//https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=kimjw1218&logNo=70178503080 ȸ��, �̵� , ������
//https://3001ssw.tistory.com/232 ȣ���� �� 60�й�
//https://blog.hexabrain.net/177 ������ �����ε�
//https://steemit.com/kr-dev/@codingman/c-10-3x3--1561681495960 3x3 ����� ��
//https://boycoding.tistory.com/219 ���� �� �� ��ȯ
//https://calcproject.tistory.com/415 �ﰢ�Լ� �� �ﰢ��


namespace MuSoenMath {
	class mat {

	protected:float matrix3[3][3]{
			0
		};

		float matrix4[4][4]{
			0
		};

		bool Mat4chack = false;
	public: void Rotateinput(float Degree) {
		
	}


	void Scaleinput(float scale) {
			  
	}


	void Translateinput(float x, float y) {

	}

	void reset() {// �� ������ �ٲ�帳�ϴ�.
		if (Mat4chack = false) {
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					matrix3[i][j] = 0;
				}
			}
		}if (Mat4chack = true) {
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					matrix4[i][j] = 0;
				}
			}
		}
	}
	void identity() {//���� ��� �����帳�ϴ�.
		reset();
		matrix3[0][0] = 1;
		matrix3[1][1] = 1;
		matrix3[2][2] = 1;

		matrix4[0][0] = 1;
		matrix4[1][1] = 1;
		matrix4[2][2] = 1;
		matrix4[3][3] = 1;
	}

	void transpose() {//��ġ �ص帳�ϴ�.
		float abcd = 0;
		float dcba = 0;
		for (int r = 0; r < 3; r++) {

			for (int c = 0; c < 3; c++) {
				abcd = matrix3[c][r];
				dcba = matrix3[r][c];
				matrix3[c][r] = dcba;
				matrix3[r][c] = abcd;
			}
		}


	}
	void show() {//�����帳�ϴ�.
		if (Mat4chack =false) {
			for (int i = 0; i < 3; i++) {
				cout << endl;
				for (int j = 0; j < 3; j++) {
					cout << " " << matrix3[i][j];
				}
			}
		}
	}

	};




	class mat4 : mat {



		mat4(float(*arr)[4], int i, int j, int k) {

		}
		~mat4() {

		}
		

	};




	class mat3  : public mat{

		  

		  
	public: mat3(float arr[3][3], int i, int j) {
			matrix3 = arr;
			Mat4chack = false;
		  }
		  
		  ~mat3() {

		  }

	
	//public: void Rotateinput(float Degree) {
	//	// 60�й��� ȣ�������� �ٲٰ� ����
	//	float PI = 3.1415;
	//	float theta = (PI / 180) * (Degree);
	//	float cos = 1;//0���� �� 1 30�� 1/2 45�� log2/2 60�� log3/2 90�� 1
	//	float sin = 0;//0�� �϶� 0 30�� log3/2�� 45�� log2/2 60�� 1/2 90�� 1

	//	mat[0][0] = theta; //cos;
	//	mat[1][1] = theta;// cos;
	//	mat[1][0] = theta;//sin;
	//	mat[0][1] = -theta;//(-1 * sin);
	//}

	//public:void Scaleinput(float scale) {
	//	//�ܼ��� ���� ���� ��  ���� x,y���� �ϰ������ [1][1]��ġ�� y�� ��ġ
	//	mat[0][0] = scale;
	//	mat[1][1] = scale;
	//	mat[2][2] = 1;
	//}
	//public:void Translateinput(float x, float y) {
	//	
	//	mat[2][0] = x;
	//	mat[2][1] = y;
	//	mat[2][2] = 1;
	//}

	//public: void show() {
	//	//��º�
	//	for (int i = 0; i < 3; i++) {
	//		cout << endl;
	//		for (int j = 0; j < 3; j++) {
	//			cout << " " << mat[i][j];
	//		}
	//	}

	//}


	//	  mat3 operator*(mat3& ref) {
	//		  mat3 out;
	//		  out.reset();
	//		  for (int i = 0; i < 3; i++) {
	//			  for (int j = 0; j < 3; j++) {
	//				  for (int k = 0; k < 3; k++) {
	//					  //��� ���//i �� k ��
	//					  out.mat[i][j] += mat[i][k] * ref.mat[k][j];
	//				  }
	//			  }
	//		  }
	//		  return out;
	//	  }
		 
		  
	

	};


	class vec3 {
	public: float vec[3][3]{
		0
	};
		  void reset() {
			  vec[0][0] = 0;
			  vec[0][1] = 0;
			  vec[0][2] = 0;
		  }
		  // m*n ��� m�� i�� : 3�� 1�� �迭 
		  vec3() {
			  vec[0][0] = 0;
			  vec[0][1] = 0;
			  vec[0][2] = 1;
		  }
		  vec3(float a, float b) {
			  vec[2][2] = { 0 };
			  vec[0][0] = a;
			  vec[0][1] = b;
			  vec[0][2] = 1;
		  }
		  ~vec3() {

		  }
		  

	public: void show() {
		
			for (int i = 0; i < 1; i++) {
				for (int j = 0; j < 3; j++) {
					cout << " " << vec[i][j];
				}
				
			}
		

	}

		/* vec3 operator*(mat3& ref) {
			  vec3 out(0,0);
			  out.reset();
			  for (int i = 0; i < 3; i++) {
				  for (int j = 0; j < 3; j++) {
					  for (int k = 0; k < 3; k++) {
						  out.vec[i][j] += vec[i][k] * ref.mat[k][j];
					  }
				  }
			  }

			  
			  return out;
		  }*/
	};

	

	

}




