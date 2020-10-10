/*
SoLoud audio engine
Copyright (c) 2013-2015 Jari Komppa

This software is provided 'as-is', without any express or implied
warranty. In no event will the authors be held liable for any damages
arising from the use of this software.

Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute it
freely, subject to the following restrictions:

   1. The origin of this software must not be misrepresented; you must not
   claim that you wrote the original software. If you use this software
   in a product, an acknowledgment in the product documentation would be
   appreciated but is not required.

   2. Altered source versions must be plainly marked as such, and must not be
   misrepresented as being the original software.

   3. This notice may not be removed or altered from any source
   distribution.
*/

#include "C_Mutex.h"

#include "soloud.h"
#include "soloud_thread.h"
#include "C_ThreadingTools.h"

namespace SoLoud
{
	namespace Thread
	{
		void* createMutex()
		{
			return (void*)new C_Mutex();
		}

		void destroyMutex(void *aHandle)
		{
            C_Mutex *mtx = (C_Mutex*)aHandle;
			delete mtx;
		}

		void lockMutex(void *aHandle)
		{
            C_Mutex *mtx = (C_Mutex*)aHandle;
			if (mtx)
			{
				mtx->Lock();
			}
		}

		void unlockMutex(void *aHandle)
		{
            C_Mutex *mtx = (C_Mutex*)aHandle;
            if (mtx)
            {
                mtx->Unlock();
            }
		}

		void sleep(int aMSec)
		{
			C_ThreadingTools::Sleep(aMSec);
		}
	}
}
