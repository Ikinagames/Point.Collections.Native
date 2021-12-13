#pragma once

#define WIN32_DLL_UNMANGLED_API extern "C" _declspec(dllexport)

namespace Point {
	namespace Collections {
		WIN32_DLL_UNMANGLED_API void vector_normalize(double* x, double* y, double* z);
	}
}