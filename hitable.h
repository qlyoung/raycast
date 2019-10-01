#ifndef __HITABLE_H__
#define __HITABLE_H__

#include "ray.h"

class material;

struct hit_record {
	/* Ray parameter at which hit occurs */
	float t;
	/* Point of hit */
	vec3 p;
	/* Normal of hit surface */
	vec3 normal;

	material *mat_ptr;
};

class hitable {
	public:
		virtual bool hit(const ray& r, float t_min, float t_max, hit_record& rec) const = 0;

};

#endif /* __HITABLE_H__ */
