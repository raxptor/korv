#ifndef __KORV_MAKE_H__
#define __KORV_MAKE_H__

#include <math.h>

#define MTX_SET_COL(c, dst, x, y, z, w) \
	dst[4*c] = x; \
	dst[4*c+1] = y; \
	dst[4*c+2] = z; \
	dst[4*c+3] = w; \

#define MTX_SET_ROW(r, dst, x, y, z, w) \
	dst[r] = x; \
	dst[r+4] = y; \
	dst[r+8] = z; \
	dst[r+12] = w; \

namespace korv
{
	namespace make
	{
		// Matrices are column major storage. Which means that the element
		// [0,1,2,3] in a matrix forms the first column of the matrix.
		//
		// [ 1 0 0 x ]
		// [ 0 1 0 y ]
		// [ 0 0 1 z ]
		// [ 0 0 0 1 ]
		//
		// is thus stored as
		//
		// [ 1 0 0 0 0 1 0 0 0 0 1 0 x y z 1 ]

		void mat4_persp_proj(float *dst, float w, float h, float zn, float zf)
		{
			for (int i=0;i<16;i++)
			{
				dst[i] = 0.0f;
			}
			dst[0] = 1.0f / w;
			dst[5] = 1.0f / h;
			dst[10] = (zf + zn) / (zn - zf);
			dst[11] = -1;
			dst[14] = 2.0f * (zf * zn) / (zn - zf);
		}

		void mat4_zero(float *dst)
		{
			MTX_SET_COL(0, dst, 0, 0, 0, 0);
			MTX_SET_COL(1, dst, 0, 0, 0, 0);
			MTX_SET_COL(2, dst, 0, 0, 0, 0);
			MTX_SET_COL(3, dst, 0, 0, 0, 0);
		}

		void mat4_id(float *dst)
		{
			MTX_SET_COL(0, dst, 1, 0, 0, 0);
			MTX_SET_COL(1, dst, 0, 1, 0, 0);
			MTX_SET_COL(2, dst, 0, 0, 1, 0);
			MTX_SET_COL(3, dst, 0, 0, 0, 1);
		}

		void mat4_scale(float *dst, float x, float y, float z)
		{
			MTX_SET_COL(0, dst, x, 0, 0, 0);
			MTX_SET_COL(1, dst, 0, y, 0, 0);
			MTX_SET_COL(2, dst, 0, 0, z, 0);
			MTX_SET_COL(3, dst, 0, 0, 0, 1);
		}
	
		void mat4_trans(float *dst, float x, float y, float z)
		{
			MTX_SET_COL(0, dst, 1, 0, 0, 0);
			MTX_SET_COL(1, dst, 0, 1, 0, 0);
			MTX_SET_COL(2, dst, 0, 0, 1, 0);
			MTX_SET_COL(3, dst, x, y, z, 1);
		}

		void mat4_rot_z_sc(float *dst, float sin, float cos)
		{
			MTX_SET_COL(0, dst, cos,  sin, 0, 0);
			MTX_SET_COL(1, dst, -sin, cos, 0, 0);
			MTX_SET_COL(2, dst, 0, 0, 1, 0);
			MTX_SET_COL(3, dst, 0, 0, 0, 1);
		}

		void mat4_rot_z(float *dst, float a)
		{
			mat4_rot_z_sc(dst, sinf(a), cosf(a));
		}

		void mat4_rot_x_sc(float *dst, float sin, float cos)
		{
			MTX_SET_COL(0, dst, 1, 0, 0, 0);
			MTX_SET_COL(1, dst, 0, cos, sin, 0);
			MTX_SET_COL(2, dst, 0, -sin, cos, 0);
			MTX_SET_COL(3, dst, 0, 0, 0, 1);
		}		

		void vec4(float *out, float x, float y, float z, float w)
		{
			out[0] = x;
			out[1] = y;
			out[2] = z;
			out[3] = w;
		}

		void vec3(float *out, float x, float y, float z)
		{
			out[0] = x;
			out[1] = y;
			out[2] = z;
		}

		void vec2(float *out, float x, float y, float z)
		{
			out[0] = x;
			out[1] = y;
		}
	}
}

#undef MTX_SET_COL
#undef MTX_SET_ROW

#endif
