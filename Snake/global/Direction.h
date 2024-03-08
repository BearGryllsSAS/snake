#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/03/29 16:37:33

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#ifndef _DIRECTION_H_
#define _DIRECTION_H_

/**
 * 方向枚举
 */
enum class Direction {
	// 表示停止移动
	NONE = 0,
	// 左方
	LEFT,
	// 右方
	RIGHT,
	// 上方
	UP,
	// 下发
	DOWN
};

#endif // !_DIRECTION_H_