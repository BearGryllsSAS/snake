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
	// ��ʼ������
	len = 0;
	dir = Direction::NONE;
	// ��ʼʱ��ͷ�ڴ�������
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
	// ��ͣ״̬��ִ���ƶ��߼�
	if (dir == Direction::NONE) return;

	// ��ȡ��һ��Ԫ�ص�λ��
	Postion prev = tail[0];
	// ����һ��Ԫ������Ϊ��ͷλ��
	tail[0] = head;
	// ��������λ����������Ϊ��ǰ��һ��λ��
	Postion prev2;
	for (size_t i = 1; i < len; i++) {
		prev2 = tail[i];
		tail[i] = prev;
		prev = prev2;
	}

	// �����û�����ķ��������ͷ��λ��
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
	// �ж����Ƿ�ײǽ
	if (head.x < 0 || head.x >= WIDTH || head.y < 0 || head.y >= HEIGHT) {
		return true;
	}

	// �ж����Ƿ�ҧ�����Լ�
	for (size_t i = 0; i < len; i++) {
		if (head.isEqual(tail[i])) {
			return true;
		}
	}

	return false;
}

bool Snake::eatFoods(Foods* foods)
{
	// �ж����Ƿ�Ե���ʳ��
	if (foods->getPos()->isEqual(head)) {
		// ������+1
		len++;
		return true;
	}
	return false;
}

void Snake::changeDir(Direction dir)
{
	this->dir = dir;
}
