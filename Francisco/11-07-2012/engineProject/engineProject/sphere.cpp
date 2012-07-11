#include "sphere.h"
#include "gl/glut.h"

Sphere::Sphere(double radius)
{
	m_radius = radius;
}

void Sphere::Draw()
{
	glutSolidSphere(m_radius,64,64);
}

double Sphere::GetRadius()
{
	return m_radius;
}

void Sphere::SetRadius(double sphereRadius)
{
	m_radius = sphereRadius;
}