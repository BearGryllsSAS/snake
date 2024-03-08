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
 * ����һ������
 */
class Snake
{
protected:
	// ��ͷ����
	Postion head;
	// ��������
	Postion tail[100];
	// ������
	size_t len;
	// �ƶ�����
	Direction dir;
public:
	// �����ʼ��
	Snake();
	// ��ȡ��ͷ����
	Postion* getHead();
	// ��ȡ��������
	Postion* getTail();
	// ��ȡ������
	size_t getLen();
	// ��ȡ�ߵķ���
	Direction getDir();
public:
	// �ƶ�
	void move();
	// �������������Ƿ�ײǽ���Ƿ�ײ�Լ��ȵ�
	bool checkDead();
	// ��ʳ��飬����Ե��Զ����ӳ��ȣ�������true
	bool eatFoods(Foods* foods);
	// �޸ķ���
	void changeDir(Direction dir);
};

#endif // !_SNAKE_H_