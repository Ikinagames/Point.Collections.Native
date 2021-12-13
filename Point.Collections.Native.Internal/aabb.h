// Copyright 2021 Seung Ha Kim
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
#include "math.h"
#include "float.h"

namespace Point {
	namespace Collections {
#define AABB_SIZE(_aabb) Math::mul(_aabb.extents, 2)
#define AABB_MIN(_aabb) Math::sub(_aabb.center, _aabb.extents)
#define AABB_MAX(_aabb) Math::add(_aabb.center, _aabb.extents)

		WIN32_DLL_UNMANAGED_API struct aabb
		{
			float3 center;
			float3 extents;
		};
	}
}