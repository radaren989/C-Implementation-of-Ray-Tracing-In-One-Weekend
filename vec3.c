#include "vec3.h"
#include <math.h>

vec3 vec3_create(double x, double y, double z)
{
	return (vec3){x, y, z};
};

double vec3_length(vec3 u)
{
	return sqrt(u.x * u.x + u.y * u.y + u.z * u.z);
};

vec3 vec3_inc(vec3 u)
{
	u.x++;
	u.y++;
	u.z++;
	return u;
};

vec3 vec3_add(vec3 u, double val)
{
	u.x += val;
	u.y += val;
	u.z += val;
	return u;
};

vec3 vec3_subtr(vec3 u, double val)
{
	u.x -= val;
	u.y -= val;
	u.z -= val;
	return u;
};

vec3 vec3_mult(vec3 u, double val)
{
	u.x *= val;
	u.y *= val;
	u.z *= val;
	return u;
};

vec3 vec3_div(vec3 u, double val)
{
	return vec3_mult(u, (1 / val));
};

vec3 vec3_add_vec(vec3 u, vec3 v)
{
	return (vec3){u.x + v.x, u.y + v.y, u.z + v.z};
};

vec3 vec3_subtr_vec(vec3 u, vec3 v)
{
	return (vec3){u.x - v.x, u.y - v.y, u.z - v.z};
};

vec3 vec3_mult_vec(vec3 u, vec3 v)
{
	return (vec3){u.x * v.x, u.y * v.y, u.z * v.z};
};

double vec3_dot(vec3 u, vec3 v)
{
	return (u.x * v.x + u.y * v.y + u.z * v.z);
};

vec3 vec3_cross(vec3 u, vec3 v)
{
	return (vec3){u.y * v.z - u.z * v.y,
								u.z * v.x - u.x * v.z,
								u.x * v.y - u.y * v.x};
};

vec3 vec3_unit(vec3 u)
{
	return vec3_div(u, vec3_length(u));
}

double vec3_length_squared(vec3 u)
{
	return ((u.x * u.x + u.y * u.y + u.z * u.z));
}

vec3 vec3_reversed(vec3 u)
{
	return (vec3){-u.x, -u.y, -u.z};
}
