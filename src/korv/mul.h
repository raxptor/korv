#ifndef __KORV_MUL_H__
#define __KORV_MUL_H__

namespace korv
{
	namespace mul
	{
		inline void mat4_vec4(float *dst_vec, const float *src_mtx, const float *src_vec)
		{
			const float x = src_vec[0];
			const float y = src_vec[1];
			const float z = src_vec[2];
			const float w = src_vec[3];
			dst_vec[0] = src_mtx[0]*x + src_mtx[4]*y + src_mtx[8]*z + src_mtx[12]*w;
			dst_vec[1] = src_mtx[1]*x + src_mtx[5]*y + src_mtx[9]*z + src_mtx[13]*w;
			dst_vec[2] = src_mtx[2]*x + src_mtx[6]*y + src_mtx[10]*z + src_mtx[14]*w;
			dst_vec[3] = src_mtx[3]*x + src_mtx[7]*y + src_mtx[11]*z + src_mtx[15]*w;
		}

		inline void mat4(float *out, const float *left, const float *right)
		{
			for (int i=0;i<4;i++)
			{
				mat4_vec4(out + 4*i, left, right + 4*i);
			}
		}
	}
}

#endif
