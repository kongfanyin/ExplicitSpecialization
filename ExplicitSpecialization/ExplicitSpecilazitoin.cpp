#define _CRT_SECURE_NO_WARNINGS 1
//显示具体化重载模板

#include<string>
#include<fstream>
#include<iostream>

struct job
{
	char name[40];
	double salary;
	int floor;
};
template<class T>
T add(T a, T b)//按值传递
{
	return a + b;
}
int m = 6;
double x = 10.2;


template <class T>
void Swap(T &a,T &b);//template prototype
template<>void Swap<job>(job &a, job &b);

template<class T>
void Swap(T &a, T &b);

//explicit specialization,显示具体化
template<>void Swap<job>(job &j1, job &j2);//形式一
template<>void Swap(job &j1, job &j2);//形式二
void show(job &j);
int main(char argc, char** argv)
{
	using namespace std;
	cout << add<double>(x, m) << endl;
	cout.precision(2);
	cout.setf(ios::fixed,ios::floatfield);
	int i = 10, j = 20;
	cout << "i,j=" << i << "," << j << endl;
	cout << "using compile_generate int Swapper: \n";
	Swap(i, j);//generates void Swap(int &a,int &b)
	//Swap<double>(m,x);不可行，不能将int装换为double类型
	cout << "now i,j=" << i << "," << j << endl;
	job sue = { "susan frisk",87500.66,9 };
	job kong = { "kong fy",66666.88,18 };
	cout << "job before Swap: \n";
	show(sue);
	show(kong);

	Swap(sue, kong);
	cout << "job after Swap:\n";
	show(sue);
	show(kong);
	return 0;
}
template<class T>
void Swap(T &a, T &b)
{
	T temp;
	temp = a;
	a = b;
	b = temp;
}
template<>void Swap<job>(job &j1, job &j2)
{
	int t1;
	double t2;
	t2 = j1.salary;
	j1.salary = j2.salary;
	j2.salary = t2;
	t1 = j1.floor;
	j1.floor = j2.floor;
	j2.floor = t1;
}
void show(job &j)
{
	using namespace std;
	cout<<"姓名：" << j.name << endl;
	cout << "薪资：" << j.salary << '$'<<endl;
	cout << "工作楼层：" << j.floor << endl;
}