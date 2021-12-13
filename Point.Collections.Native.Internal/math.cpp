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

#include "pch.h"
#include "aabb.h"
#include "float.h"

namespace Point {
    namespace Collections {
        namespace Math {
            bool contains(Collections::aabb _aabb, Collections::float3 position) 
            {
                float3 
                    min = AABB_MIN(_aabb),
                    max = AABB_MAX(_aabb);

                return position.x >= min.x
                    && position.y >= min.y
                    && position.z >= min.z
                    && position.x < max.x
                    && position.y < max.y
                    && position.z < max.z;
            }
            float3 add(const float3 x, const int y)
            {
                float3 output = x;
                output.x += y;
                output.y += y;
                output.z += y;

                return output;
            }
            float3 add(const float3 x, const float y)
            {
                float3 output = x;
                output.x += y;
                output.y += y;
                output.z += y;

                return output;
            }
            float3 add(const float3 x, const float3 y)
            {
                float3 output = x;
                output.x += y.x;
                output.y += y.y;
                output.z += y.z;

                return output;
            }

            float3 sub(const float3 x, const int y)
            {
                float3 output = x;
                output.x -= y;
                output.y -= y;
                output.z -= y;

                return output;
            }
            float3 sub(const float3 x, const float y)
            {
                float3 output = x;
                output.x -= y;
                output.y -= y;
                output.z -= y;

                return output;
            }
            float3 sub(const float3 x, const float3 y)
            {
                float3 output = x;
                output.x -= y.x;
                output.y -= y.y;
                output.z -= y.z;

                return output;
            }
        }
    }
}