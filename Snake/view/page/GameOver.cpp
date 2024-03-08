/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/03/29 22:28:29

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
#include "GameOver.h"
#include "GameView.h"
#include "../../global/Global.h"

void GameOver::onExit()
{
	// ���и���ʵ��
	AbstractGameView::onExit();
	// ��������¿�ʼ��Ϸ
	if (isRestart)
	{
		runtimeData.changeView(new GameView());
	}
	else
	{
		runtimeData.isExit = true;
	}
}

void GameOver::init()
{
	system("cls");
	cout << "��Ϸ������" << endl;
	cout << "���õĻ���:" << runtimeData.score << endl;
}

void GameOver::draw()
{
	
}

void GameOver::handleInput()
{
	cout << "�Ƿ����¿�ʼ��Ϸ��y/n����";
	char ch = _getch();
	if (ch == 'y' || ch == 'Y')
	{
		isRestart = true;
	}
	// ִ����ͼ�˳�
	this->status = ViewStatus::ON_EXIT;
}
