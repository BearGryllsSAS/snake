#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/03/29 16:32:19

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
#ifndef _FOODS_H_
#define _FOODS_H_
#include "../../global/Postion.h"
/**
 * 书写一个食物类
 */
class Foods
{
protected:
	// 食物坐标
	Postion pos;
public:
	// 构造初始化
	Foods();
	// 自动生成坐标
	void autoGeneratePos();
	// 设置坐标
	void setPos(Postion pos);
	// 获取食物坐标
	Postion* getPos();
};

#endif // !_FOODS_H_