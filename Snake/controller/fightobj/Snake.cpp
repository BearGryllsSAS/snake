/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/03/29 16:07:25

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
#include "Snake.h"
#include "../../global/Global.h"

Snake::Snake()
{
	// 初始化数据
	len = 0;
	dir = Direction::NONE;
	// 初始时蛇头在窗口中央
	head = { WIDTH / 2, HEIGHT / 2 };
}

Postion* Snake::getHead()
{
	return &head;
}

Postion* Snake::getTail()
{
	return tail;
}

size_t Snake::getLen()
{
	return this->len;
}

Direction Snake::getDir()
{
	return this->dir;
}

void Snake::move()
{
	// 暂停状态不执行移动逻辑
	if (dir == Direction::NONE) return;

	// 获取第一个元素的位置
	Postion prev = tail[0];
	// 将第一个元素设置为蛇头位置
	tail[0] = head;
	// 后续身体位置依次设置为它前面一个位置
	Postion prev2;
	for (size_t i = 1; i < len; i++) {
		prev2 = tail[i];
		tail[i] = prev;
		prev = prev2;
	}

	// 根据用户输入的方向更新蛇头的位置
	switch (dir) {
	case Direction::LEFT:
		head.addX(-1);
		break;
	case Direction::RIGHT:
		head.addX(1);
		break;
	case Direction::UP:
		head.addY(-1);
		break;
	case Direction::DOWN:
		head.addY(1);
		break;
	default:
		break;
	}
}

bool Snake::checkDead()
{
	// 判断蛇是否撞墙
	if (head.x < 0 || head.x >= WIDTH || head.y < 0 || head.y >= HEIGHT) {
		return true;
	}

	// 判断蛇是否咬到了自己
	for (size_t i = 0; i < len; i++) {
		if (head.isEqual(tail[i])) {
			return true;
		}
	}

	return false;
}

bool Snake::eatFoods(Foods* foods)
{
	// 判断蛇是否吃到了食物
	if (foods->getPos()->isEqual(head)) {
		// 蛇身长度+1
		len++;
		return true;
	}
	return false;
}

void Snake::changeDir(Direction dir)
{
	this->dir = dir;
}
