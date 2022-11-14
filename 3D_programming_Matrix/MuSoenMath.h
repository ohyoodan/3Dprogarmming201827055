#pragma once
#include <iostream>
#define sin(x)( 0.011111*x)
#define cos(x)( 0.011111*x)
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


	public: void Rotateinput(float Degree) {
		//60�й��� ȣ�������� �ٲٰ� ����
		float PI = 3.1415;
		float theta = (PI / 180) * (Degree);
		//float cos = 1;//0���� �� 1 30�� 1/2 45�� log2/2 60�� log3/2 90�� 1
		//float sin = 0;//0�� �϶� 0 30�� log3/2�� 45�� log2/2 60�� 1/2 90�� 1

		matrix3[0][0] = 1 - theta; //cos;
		matrix3[1][1] = 1 - theta;// cos;
		matrix3[1][0] = 0 - theta;//sin;
		matrix3[0][1] = 0 - (-1 * theta);//(-1 * sin);
	}


		  void Scaleinput(float scale) {
			  matrix3[0][0] = scale;
			  matrix3[1][1] = scale;
			  matrix3[2][2] = 1;
		  }


		  void Translateinput(float x, float y) {
			  matrix3[0][2] = x;
			  matrix3[1][2] = y;
			  matrix3[2][2] = 1;
		  }

		  void reset() {// �� ������ �ٲ�帳�ϴ�.
			  for (int i = 0; i < 3; i++) {
				  for (int j = 0; j < 3; j++) {
					  matrix3[i][j] = 0;
				  }
			  }
		  }
		  void identity() {//���� ��� �����帳�ϴ�.
			  reset();
			  for (int i = 0; i < 3; i++) {
				  matrix3[i][i] = 1;
			  }
		  }

		  void transpose() {//��ġ �ص帳�ϴ�.

			  float TestMatrix[3][3] = { 0 };

			  for (int r = 0; r < 3; r++) {
				  for (int c = 0; c < 3; c++) {
					  TestMatrix[c][r] = matrix3[r][c];

				  }
			  }
			  for (int i = 0; i < 3; i++) {
				  for (int j = 0; j < 3; j++) {
					  matrix3[i][j] = TestMatrix[i][j];

				  }
			  }


		  }
		  void show() {//�����帳�ϴ�.

			  for (int i = 0; i < 3; i++) {
				  cout << endl;
				  for (int j = 0; j < 3; j++) {
					  cout << " " << matrix3[i][j];
				  }
			  }
			  cout << endl;

		  }
		  float getmatrixfloat(int a, int b) {
			  float t = matrix3[a][b];
			  return t;
		  }

		  void setmatrixfloat(int a, int b, float c) {
			  matrix3[a][b] = c;
		  }

	};



	class mat4 : public mat {

	public:mat4() {
		identity();
	}


		  mat4(float(*arr)[4]) {
			  for (int i = 0; i < 4; i++) {
				  for (int j = 0; j < 4; j++) {
					  matrix4[i][j] = arr[i][j];
				  }
			  }

		  }

		  ~mat4() {

		  }

		  void reset() {
			  for (int i = 0; i < 4; i++) {
				  for (int j = 0; j < 4; j++) {
					  matrix4[i][j] = 0;
				  }
			  }
		  }

		  void identity() {
			  reset();
			  for (int i = 0; i < 4; i++) {
				  matrix4[i][i] = 1;
			  }

		  }
		  void transpose() {
			  float TestMatrix[4][4] = { 0 };
			  for (int r = 0; r < 4; r++) {
				  for (int c = 0; c < 4; c++) {
					  TestMatrix[c][r] = matrix4[r][c];
				  }
			  }
			  for (int i = 0; i < 3; i++) {
				  for (int j = 0; j < 3; j++) {
					  matrix4[i][j] = TestMatrix[i][j];

				  }
			  }
		  }

		  void show() {
			  for (int i = 0; i < 4; i++) {
				  cout << endl;
				  for (int j = 0; j < 4; j++) {
					  cout << " " << matrix4[i][j];
				  }
			  }
			  cout << endl;
		  }
		  float getmatrixfloat(int a, int b) {
			  float t = matrix4[a][b];
			  return t;
		  }

		  mat4 operator*(mat4 ref) {

			  mat4 out;
			  out.reset();
			  for (int i = 0; i < 4; i++) {
				  for (int j = 0; j < 4; j++) {
					  for (int k = 0; k < 4; k++) {
						  //��� ���//i �� k ��

						  out.matrix4[i][j] += matrix4[i][k] * ref.matrix4[k][j];
					  }
				  }
			  }

			  return out;
		  }
		  mat4 operator+(mat4& ref) {//���Ͱ��� ����
			  mat4 out;
			  out.reset();
			  for (int i = 0; i < 4; i++) {
				  for (int j = 0; j < 4; j++) {
					  out.matrix4[i][j] += matrix4[i][j] + ref.getmatrixfloat(i, j);
				  }
			  }
			  
			  return out;
		  }
		  mat4 operator-(mat4& ref) {//���Ͱ��� ����
			  mat4 out;
			  out.reset();
			  for (int i = 0; i < 4; i++) {
				  for (int j = 0; j < 4; j++) {

					  out.matrix4[i][j] += matrix4[i][j] - ref.getmatrixfloat(i, j);

				  }
			  }
			  return out;
		  }
		  mat4 operator/(int a) {//��� ������
			  mat4 out;
			  out.reset();
			  for (int i = 0; i < 4; i++) {
				  for (int j = 0; j < 4; j++) {
					  out.matrix4[i][j] += matrix4[i][j] / a;
				  }
			  }
			  return out;
		  }
		  mat4 operator*(int a) {//��� ��
			  mat4 out;
			  out.reset();
			  for (int i = 0; i < 4; i++) {
				  for (int j = 0; j < 4; j++) {

					  out.matrix4[i][j] += matrix4[i][j] * a;

				  }
			  }
			  return out;


		  }

	};




	class mat3 : public mat {

	public:	mat3() {
		identity();
	}


		  mat3(float(*arr)[3]) {
			  for (int i = 0; i < 3; i++) {
				  for (int j = 0; j < 3; j++) {
					  matrix3[i][j] = arr[i][j];
				  }
			  }

		  }

		  ~mat3() {

		  }



		  mat3 operator*(mat3& ref) {//��İ�  ����

			  mat3 out;
			  out.reset();
			  for (int i = 0; i < 3; i++) {
				  for (int j = 0; j < 3; j++) {
					  for (int k = 0; k < 3; k++) {
						  //��� ���//i �� k ��

						  out.matrix3[i][j] += matrix3[i][k] * ref.matrix3[k][j];
					  }
				  }
			  }

			  return out;
		  }
		  mat3 operator+(mat3& ref) {//��İ��� ����
			  mat3 out;
			  out.reset();
			  for (int i = 0; i < 3; i++) {
				  for (int j = 0; j < 3; j++) {
					  out.matrix3[i][j] += matrix3[i][j] + ref.matrix3[i][j];

				  }
			  }
			  return out;
		  }
		  mat3 operator-(mat3& ref) {//��İ��� ����
			  mat3 out;
			  out.reset();
			  for (int i = 0; i < 3; i++) {
				  for (int j = 0; j < 3; j++) {
					  out.matrix3[i][j] += matrix3[i][j] - ref.matrix3[i][j];

				  }
			  }
			  return out;
		  }
		  mat3 operator*(int a) {
			  mat3 out;
			  out.reset();
			  for (int i = 0; i < 3; i++) {
				  for (int j = 0; j < 3; j++) {
					  out.matrix3[i][j] += matrix3[i][j] * a;

				  }
			  }
			  return out;
		  }
		  mat3 operator/(int a) {
			  mat3 out;
			  out.reset();
			  for (int i = 0; i < 3; i++) {
				  for (int j = 0; j < 3; j++) {
					  out.matrix3[i][j] += matrix3[i][j] / a;

				  }
			  }
			  return out;
		  }
	};


	class vec3 : public mat {
		bool t = false;//1x3��

	public:  void reset() {
		matrix3[0][0] = 0;
		matrix3[0][1] = 0;
		matrix3[0][2] = 0;
	}
		  // m*n ��� m�� i�� : 1�� 3�� �迭 
		  vec3() {
			  matrix3[0][0] = 0;
			  matrix3[0][1] = 0;
			  matrix3[0][2] = 1;
		  }
		  vec3(float a, float b) {
			  reset();
			  matrix3[0][0] = a;
			  matrix3[0][1] = b;
			  matrix3[0][2] = 1;
		  }
		  ~vec3() {

		  }
		  
		  void transpose() {


			  if (!t) {
				  t = true;
				  float TestMatrix[3][3] = { 0 };
				  for (int i = 0; i < 3; i++) {
					  TestMatrix[i][0] = matrix3[0][i];
				  }

				  for (int i = 0; i < 3; i++) {
					  for (int j = 0; j < 3; j++) {
						  matrix3[i][j] = TestMatrix[i][j];

					  }
				  }
			  }
			  else {

				  t = false;
				  float TestMatrix[3][3] = { 0 };
				  for (int i = 0; i < 3; i++) {
					  TestMatrix[0][i] = matrix3[i][0];
				  }

				  for (int i = 0; i < 3; i++) {
					  for (int j = 0; j < 3; j++) {
						  matrix3[i][j] = TestMatrix[i][j];

					  }
				  }
			  }
		  }

		  void show() {
			  if (!t) {
				  cout << endl;
				  for (int i = 0; i < 1; i++) {
					  for (int j = 0; j < 3; j++) {
						  cout << " " << matrix3[i][j];
					  }

				  }
				  cout << endl;
			  }
			  else {
				  cout << endl;
				  for (int i = 0; i < 3; i++) {
					  for (int j = 0; j < 1; j++) {
						  cout << endl;
						  cout << " " << matrix3[i][j];
						  cout << endl;
					  }

				  }
				  cout << endl;
			  }
		  }

		  vec3 operator*(mat3& ref) {//�ٸ� �ڷ�� ���ϱ�

			  vec3 out;
			  out.reset();
			  for (int i = 0; i < 3; i++) {
				  for (int j = 0; j < 3; j++) {
					  for (int k = 0; k < 3; k++) {
						  out.matrix3[i][j] += matrix3[i][k] * ref.getmatrixfloat(k, j);
					  }
				  }
			  }
			  if (!t) {
				  out.t = false;
			  }
			  else {
				  out.t = true;
			  }
			  return out;


		  }
		  vec3 operator+(vec3& ref) {//���Ͱ��� ����
			  vec3 out;
			  out.reset();
			  for (int i = 0; i < 3; i++) {
				  for (int j = 0; j < 3; j++) {
					  out.matrix3[i][j] += matrix3[i][j] + ref.getmatrixfloat(i, j);
				  }
			  }
			  if (!t) {
				  out.t = false;
			  }
			  else {
				  out.t = true;
			  }
			  return out;
		  }
		  vec3 operator-(vec3& ref) {//���Ͱ��� ����
			  vec3 out;
			  out.reset();
			  for (int i = 0; i < 3; i++) {
				  for (int j = 0; j < 3; j++) {

					  out.matrix3[i][j] += matrix3[i][j] - ref.getmatrixfloat(i, j);

				  }
			  }if (!t) {
				  out.t = false;
			  }
			  else {
				  out.t = true;
			  }
			  return out;
		  }
		  vec3 operator/(int a) {//��� ������
			  vec3 out;
			  out.reset();
			  for (int i = 0; i < 3; i++) {
				  for (int j = 0; j < 3; j++) {
					  out.matrix3[i][j] += matrix3[i][j] / a;
				  }
			  }if (!t) {
				  out.t = false;
			  }
			  else {
				  out.t = true;
			  }
			  return out;
		  }
		  vec3 operator*(int a) {//��� ��
			  vec3 out(0, 0);
			  out.reset();
			  for (int i = 0; i < 3; i++) {
				  for (int j = 0; j < 3; j++) {

					  out.matrix3[i][j] += matrix3[i][j] * a;

				  }
			  }if (!t) {
				  out.t = false;
			  }
			  else {
				  out.t = true;
			  }
			  return out;

		  }
	};

		  class vec4 : public mat {
			  bool t = false;//1x4��

		  public:  void reset() {
			  matrix4[0][0] = 0;
			  matrix4[0][1] = 0;
			  matrix4[0][2] = 0;
			  matrix4[0][3] = 0;
		  }
				// m*n ��� m�� i�� : 1�� 3�� �迭 
				vec4() {
					matrix4[0][0] = 0;
					matrix4[0][1] = 0;
					matrix4[0][2] = 0;
					matrix4[0][3] = 0;
				}
				vec4(float a, float b,float c) {
					reset();
					matrix4[0][0] = a;
					matrix4[0][1] = b;
					matrix4[0][2] = c;
					matrix4[0][3] = 1;
				}
				~vec4() {

				}
				void transpose() {
					


					if (!t) {
						t = true;
						float TestMatrix[4][4] = { 0 };
						for (int i = 0; i < 4; i++) {
							TestMatrix[i][0] = matrix4[0][i];
						}

						for (int i = 0; i < 4; i++) {
							for (int j = 0; j < 3; j++) {
								matrix4[i][j] = TestMatrix[i][j];

							}
						}
					}
					else {

						t = false;
						float TestMatrix[4][4] = { 0 };
						for (int i = 0; i < 4; i++) {
							TestMatrix[0][i] = matrix3[i][0];
						}

						for (int i = 0; i < 4; i++) {
							for (int j = 0; j < 4; j++) {
								matrix4[i][j] = TestMatrix[i][j];

							}
						}
					}
				}

				void show() {
					if (!t) {
						cout << endl;
						for (int i = 0; i < 1; i++) {
							for (int j = 0; j < 4; j++) {
								cout << " " << matrix4[i][j];
							}

						}
						cout << endl;
					}
					else {
						cout << endl;
						for (int i = 0; i < 4; i++) {
							for (int j = 0; j < 1; j++) {
								cout << endl;
								cout << " " << matrix4[i][j];
								cout << endl;
							}

						}
						cout << endl;
					}
				}

				vec4 operator*(mat4& ref) {//�ٸ� �ڷ�� ���ϱ�

					vec4 out;
					out.reset();
					for (int i = 0; i < 4; i++) {
						for (int j = 0; j < 4; j++) {
							for (int k = 0; k < 4; k++) {
								out.matrix4[i][j] += matrix4[i][k] * ref.getmatrixfloat(k, j);
							}
						}
					}
					if (!t) {
						out.t = false;
					}
					else {
						out.t = true;
					}
					return out;


				}
				vec4 operator+(vec4& ref) {//���Ͱ��� ����
					vec4 out;
					out.reset();
					for (int i = 0; i < 4; i++) {
						for (int j = 0; j < 4; j++) {
							out.matrix4[i][j] += matrix4[i][j] + ref.getmatrixfloat(i, j);
						}
					}
					if (!t) {
						out.t = false;
					}
					else {
						out.t = true;
					}
					return out;
				}
				vec4 operator-(vec4& ref) {//���Ͱ��� ����
					vec4 out;
					out.reset();
					for (int i = 0; i < 4; i++) {
						for (int j = 0; j < 4; j++) {

							out.matrix4[i][j] += matrix4[i][j] - ref.getmatrixfloat(i, j);

						}
					}if (!t) {
						out.t = false;
					}
					else {
						out.t = true;
					}
					return out;
				}
				vec4 operator/(int a) {//��� ������
					vec4 out;
					out.reset();
					for (int i = 0; i < 4; i++) {
						for (int j = 0; j < 4; j++) {
							out.matrix4[i][j] += matrix4[i][j] / a;
						}
					}if (!t) {
						out.t = false;
					}
					else {
						out.t = true;
					}
					return out;
				}
				vec4 operator*(int a) {//��� ��
					vec4 out;
					out.reset();
					for (int i = 0; i < 4; i++) {
						for (int j = 0; j < 4; j++) {

							out.matrix4[i][j] += matrix4[i][j] * a;

						}
					}if (!t) {
						out.t = false;
					}
					else {
						out.t = true;
					}
					return out;



				}




		  };


		  /*vec3 operator*(vec3& ref1, mat3& ref2){
			  vec3 out(0, 0);
			  float abc[3][3];
			  out.reset();

			  for (int i = 0; i < 3; i++) {
				  for (int j = 0; j < 3; j++) {
					  for (int k = 0; k < 3; k++) {
						  abc[i][j] += ref1.getmatrixfloat(i, k) * ref2.getmatrixfloat(k, j);


					  }
					  out.setmatrixfloat(i, j, abc[i][j]);
				  }
			  }

			  return out;
		  }*/


	
}

