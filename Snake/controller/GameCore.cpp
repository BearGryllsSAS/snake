/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/03/25 18:33:30

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
#include "GameCore.h"
#include "../global/Global.h"
#include "../util/ConsoleUtil.h"
#include "../view/page/GameView.h"
#include "../util/Sound.h"

void GameCore::setup()
{
	// ���ع��
	ConsoleUtil::ctrCursorVisible(false);
	// ������Ƶ��Դ
	loadSound("./sounds/bg.mp3", "bg");
	loadSound("./sounds/eat.mp3", "eat");
	loadSound("./sounds/dead.mp3", "dead");
}

void GameCore::end()
{
	// �ͷŵ���ǰ��ͼ��Դ
	runtimeData.changeView(nullptr);
	// �ͷ���Ƶ��Դ
	unloadSound("bg");
	unloadSound("eat");
	unloadSound("dead");
}

void GameCore::start()
{
	// ������Ϸ
	setup();
	// ���õ�һ����ͼ
	runtimeData.changeView(new GameView());
	// ������Ϸ������
	do
	{
		// ��ȡ��ǰ��ͼ
		auto cv = runtimeData.getCurrView();
		// ����״ִ̬�в�ͬ���߼�
		switch (cv->getStaus())
		{
		case ViewStatus::ON_ENTER:
			cv->onEnter();
			break;
		case ViewStatus::ON_UPDATE:
			cv->update();
			break;
		case ViewStatus::ON_EXIT:
			cv->onExit();
		default:
			// ��ת�߼�
			break;
		}
		// ������Ϸ�ٶ�
		Sleep(DLT);
	} while (!runtimeData.isExit);
	// ������Դ�ͷ�
	end();
}
