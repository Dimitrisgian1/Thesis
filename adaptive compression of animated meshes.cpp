#include "SceneMesh3D.h"


using namespace std;
using namespace vvr;
using namespace Eigen;


int main(int argc, char* argv[])
{
	string line;
	Matrix<float, Dynamic, Dynamic> Dx;
	Matrix<float, Dynamic, Dynamic> Dy;
	Matrix<float, Dynamic, Dynamic> Dz;
	Matrix<float, Dynamic, Dynamic> DxT;
	Matrix<float, Dynamic, Dynamic> DyT;
	Matrix<float, Dynamic, Dynamic> DzT;
	Matrix<float, Dynamic, Dynamic> Ax;
	Matrix<float, Dynamic, Dynamic> Ay;
	Matrix<float, Dynamic, Dynamic> Az;

	Dx.resize(175, 10002);
	Dy.resize(175, 10002);
	Dz.resize(175, 10002);
	DxT.resize(175, 10002);
	DyT.resize(175, 10002);
	DzT.resize(175, 10002);
	Ax.resize(175, 175);
	Ay.resize(175, 175);
	Az.resize(175, 175);


	for (int i = 0; i < 175; i++)
	{
		ifstream myfile("C:\\Users\\Δημήτρης\\Desktop\\διπλωματικη\\VertsX.txt");

		if (myfile)  
		{
			for (int j = 0; j < 10002; j++)
			{
				(getline(myfile, line));  
				float v1;
				string s1;

				v1 = stof(line);

				Dx(i, j) = v1;
			}
			myfile.close();
		}		
		else std::cout << "fooey\n";
	}

	for (int i = 0; i < 175; i++)
	{
		ifstream myfile("C:\\Users\\Δημήτρης\\Desktop\\διπλωματικη\\VertsY.txt");

		if (myfile)  
		{
			for (int j = 0; j < 10002; j++)
			{
				(getline(myfile, line)); 
				float v1;
				string s1;

				v1 = stof(line);

				Dy(i, j) = v1;
			}
			myfile.close();
		}
		else std::cout << "fooey\n";
	}

	for (int i = 0; i < 175; i++)
	{
		ifstream myfile("C:\\Users\\Δημήτρης\\Desktop\\διπλωματικη\\VertsZ.txt");

		if (myfile)  
		{
			for (int j = 0; j < 10002; j++)
			{
				(getline(myfile, line)); 
				float v1;
				string s1;

				v1 = stof(line);

				Dz(i, j) = v1;
			}
			myfile.close();
		}
		else std::cout << "fooey\n";
	}

	DxT = Dx.transpose();
	DyT = Dy.transpose();
	DzT = Dz.transpose();

	Ax = Dx * DxT ;
	Ay = Dy * DyT / (3 * 175);
	Az = Dz * DzT / (3 * 175);

	std::cout << "Done!" << endl;
	//std::cout << Ax << std::endl;
	BDCSVD<MatrixXf> svd(Ax, ComputeThinU | ComputeThinV);

	std::cout << svd.singularValues() << std::endl;


	std::cin.get();
	return 0;
}

