#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/03/29 16:07:10

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
#ifndef _SNAKE_H_
#define _SNAKE_H_
#include "../../global/Postion.h"
#include "../../global/Direction.h"
#include "Foods.h"
/**
 * 定义一个蛇类
 */
class Snake
{
protected:
	// 蛇头坐标
	Postion head;
	// 蛇身坐标
	Postion tail[100];
	// 蛇身长度
	size_t len;
	// 移动方向
	Direction dir;
public:
	// 构造初始化
	Snake();
	// 获取蛇头坐标
	Postion* getHead();
	// 获取蛇身坐标
	Postion* getTail();
	// 获取蛇身长度
	size_t getLen();
	// 获取蛇的方向
	Direction getDir();
public:
	// 移动
	void move();
	// 检测死亡：检查是否撞墙、是否撞自己等等
	bool checkDead();
	// 吃食检查，如果吃到自动增加长度，并返回true
	bool eatFoods(Foods* foods);
	// 修改方向
	void changeDir(Direction dir);
};

#endif // !_SNAKE_H_