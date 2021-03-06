// Copyright 2021 Ikina Games
// Author : Seung Ha Kim (Syadeu)
// 
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
// 
//     http://www.apache.org/licenses/LICENSE-2.0
// 
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

#include "pch.h"
#include "float.h"
#include "aabb.h"

namespace Point {
	namespace Collections {
		namespace Math {
			float3 add(const float3 x, const int y);
			float3 add(const float3 x, const float y);
			float3 add(const float3 x, const float3 y);
			/// <summary>
			/// - operator
			/// </summary>
			float3 sub(const float3 x, const int y);
			float3 sub(const float3 x, const float y);
			float3 sub(const float3 x, const float3 y);

			float3 mul(const float3 x, const int y);
			float3 mul(const float3 x, const float y);

			bool contains(const aabb _aabb, const float3 position);

			//////////////////////////////////////////////////////////////

			DLLEXPORT void binaryComparer(void* x, void* y, const int length, bool* output);


			//////////////////////////////////////////////////////////////
			/*							Audio							*/
			DLLEXPORT void unity_todB(double* linear, double* output);
			DLLEXPORT void unity_fromdB(double* dB, double* output);
			/*															*/
			//////////////////////////////////////////////////////////////
		}
	}
}