#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/03/25 16:26:38

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
/**
 * ���峣����ȫ�ֱ���
 */
#ifndef _GLOBAL_H_
#define _GLOBAL_H_
#define _CRT_SECURE_NO_WARNINGS
 // ����ͨ��ͷ
#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

// ��Ϸ���ڵĿ��
#define WIDTH 40
// ��Ϸ���ڵĸ߶�
#define HEIGHT 20
// ��Ϸ����ʱ��
#define DLT 400
// ����һ����ͼ����
class AbstractGameView;
/**
 * ��Ϸ����ʱ���ݶ���
 */
class GameRunTimeData {
private:
	// ��ǰ��ͼ����
	AbstractGameView* currView;
public:
	// �Ƿ��˳���Ϸ
	bool isExit;
	// �÷�
	int score;
	// Ĭ�Ϲ���
	GameRunTimeData();
	// �л���ͼ����
	void changeView(AbstractGameView* nextView);
	// ��ȡ��ǰ��ͼ����
	AbstractGameView* getCurrView() const;
};

// ����һ������ʱ����ȫ�ֱ���
extern GameRunTimeData runtimeData;

#endif // !_GLOBAL_H_