#ifndef __KORV_CONJ_H__
#define __KORV_CONJ_H__

namespace korv
{
	namespace conj
	{
        void quat(float* out, float *in)
        {
            out[0] = in[0];
            out[1] = -in[1];
            out[2] = -in[2];
            out[3] = -in[3];
        }

		void vec3_quat(float* out, float *quat, float *vec3)
		{

		}
    }    
}

#endif
