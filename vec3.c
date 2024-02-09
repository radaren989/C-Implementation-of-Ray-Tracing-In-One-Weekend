#include "vec3.h"
#include "utils.h"

vec3 vec3_create(double x, double y, double z)
{
	return (vec3){x, y, z};
};

double vec3_length(vec3 u)
{
	return sqrt(vec3_length_squared(u));
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
};

double vec3_length_squared(vec3 u)
{
	return vec3_dot(u, u);
}

vec3 vec3_reversed(vec3 u)
{
	return (vec3){-u.x, -u.y, -u.z};
}

vec3 vec3_random()
{

  vec3 v = {random_double(), random_double(), random_double()};
  return v;
}

vec3 vec3_random_in(double min, double max)
{
  vec3 v = {random_double_in(min, max), random_double_in(min, max), random_double_in(min, max)};
  return v;
}

vec3 vec3_random_in_unit_sphere()
{
	while (1)
	{
		vec3 p = vec3_random_in(-1, 1);

		if (vec3_length(p) >= 1)
			continue;
		return p;
	}
}

vec3 vec3_random_unit()
{
	return vec3_unit(vec3_random_in_unit_sphere());
}

vec3 random_on_hemisphere(vec3 normal)
{
	vec3 on_unit_sphere = vec3_random_unit();
	if (vec3_dot(on_unit_sphere, normal) > 0.0)
		return on_unit_sphere;
	else
		return vec3_reversed(on_unit_sphere);
}

bool vec3_near_zero(vec3 u)
{
	const double s = 1e-8;
	return (fabs(u.x) < s) && (fabs(u.y) < s) && (fabs(u.z) < s);
}

vec3 vec3_reflect(vec3 u, vec3 n)
{
	return vec3_subtr_vec(u, vec3_mult(n, 2 * vec3_dot(u, n)));
}
