#ifndef _SPHERE_H_
#define _SPHERE_H_

class Sphere
{
public:
	Sphere(double radius);
	void Draw();
	double GetRadius();
	void SetRadius(double sphereRadius);
private:
	double m_radius; //Membros de classe come�am com m(Por qu�? Tamb�m n�o sei)
};

#endif