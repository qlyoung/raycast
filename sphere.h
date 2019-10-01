#ifndef __SPHERE_H__
#define __SPHERE_H__

#include "hitable.h"
#include "vec3.h"
#include "material.h"

class sphere: public hitable {
	public:
		sphere() { }
		sphere(vec3 cen, float r, material *m) : center(cen), radius(r) { mat = m; };

		virtual bool hit(const ray& r, float tmin, float tmax, hit_record& rec) const;

		vec3 center;
		float radius;
		material *mat;
};

bool sphere::hit(const ray& r, float t_min, float t_max, hit_record& rec) const {
	vec3 oc = r.origin() - center;
	float a = dot(r.direction(), r.direction());
	float b = 2.0 * dot(oc, r.direction());
	float c = dot(oc, oc) - radius * radius;
	float discriminant = b*b - 4*a*c;

	if (discriminant > 0) {
		/* "close" hit */
		float temp = ((-b - sqrt(discriminant)) / (2.0 * a));
		if (temp  < t_max && temp > t_min) {
			rec.t = temp;
			rec.p = r.point_at_parameter(rec.t);
			rec.normal = (rec.p - center) / radius;
			rec.mat_ptr = mat;
			return true;
		}
		/* "far" hit */
		temp = ((-b + sqrt(discriminant)) / (2.0 * a));
		if (temp  < t_max && temp > t_min) {
			rec.t = temp;
			rec.p = r.point_at_parameter(rec.t);
			rec.normal = (rec.p - center) / radius;
			rec.mat_ptr = mat;
			return true;
		}
	}

	return false;
}

#endif /* __SPHERE_H__ */
