#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/03/25 17:23:57

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
#ifndef _GAMEVIEW_H_
#define _GAMEVIEW_H_
#include "../AbstractGameView.h"
#include "../../controller/fightobj/Snake.h"
#include "../../controller/fightobj/Foods.h"
/**
 * ��дһ����Ϸ������
 */
class GameView : public AbstractGameView
{
private:
	// ����һ����
	Snake snake;
	// ����һ��ʳ��
	Foods foods;
	// ����ǽ��
	void drawWall();
	// ������Ϸ��̬Ԫ��
	void drawSprite();
	// ���ƻ���
	void drawScore();
protected:
	// ʵ�ֳ�ʼ�����������ڻ���ǽ��ͻ���
	void init() override;
	// ʵ�ֻ��Ʒ��������ڶ�̬�����ߺ�ʳ��
	void draw() override;
	// ʵ���û����뷽��������ʵ���û������ߵķ���
	void handleInput() override;
public:
	// ��д������ͼ��ʵ�����ƶ��������жϡ���ʳ��
	void update() override;
	// ��д�˳���ͼ��ʵ�ִ���Ϸ��������
	void onExit() override;
};

#endif // !_GAMEVIEW_H_