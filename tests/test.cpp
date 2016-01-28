#include <korv/vec.h>
#include <korv/make.h>
#include <korv/mul.h>
#include <korv/conj.h>

using namespace korv;

int main()
{
	quatf rot;
	make::quat_axis_angle(rot, 0, 0, 1, 0.25f * 3.1415f);
	quatf conj_rot;
	conj::quat(conj_rot, rot);

	quatf p;
	make::quat_point3(p, 10, 10, 0);


	quatf t0, t1;
	mul::quat(t0, p, conj_rot);
	mul::quat(t1, rot, t0);

	return 0;
}
