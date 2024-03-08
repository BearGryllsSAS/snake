#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/03/29 22:28:00

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
#ifndef _GAMEOVER_H_
#define _GAMEOVER_H_
#include "../AbstractGameView.h"
/**
 * ��дһ����Ϸ������ͼ
 */
class GameOver : public AbstractGameView
{
private:
	// �Ƿ����¿�ʼ��Ϸ
	bool isRestart = false;
public:
	// ��д�˳���ͼ��ʵ�����¿�ʼ��Ϸ�������Ϸ
	void onExit() override;
protected:
	// ʵ����ͼ��ʼ��
	void init() override;
	// ʵ����ͼ����
	void draw() override;
	// ʵ���û����봦��
	void handleInput() override;
};

#endif // !_GAMEOVER_H_