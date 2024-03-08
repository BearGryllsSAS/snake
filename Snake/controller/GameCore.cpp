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
	// 隐藏光标
	ConsoleUtil::ctrCursorVisible(false);
	// 加载音频资源
	loadSound("./sounds/bg.mp3", "bg");
	loadSound("./sounds/eat.mp3", "eat");
	loadSound("./sounds/dead.mp3", "dead");
}

void GameCore::end()
{
	// 释放掉当前视图资源
	runtimeData.changeView(nullptr);
	// 释放音频资源
	unloadSound("bg");
	unloadSound("eat");
	unloadSound("dead");
}

void GameCore::start()
{
	// 设置游戏
	setup();
	// 设置第一个视图
	runtimeData.changeView(new GameView());
	// 开启游戏主心跳
	do
	{
		// 获取当前视图
		auto cv = runtimeData.getCurrView();
		// 根据状态执行不同的逻辑
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
			// 空转逻辑
			break;
		}
		// 控制游戏速度
		Sleep(DLT);
	} while (!runtimeData.isExit);
	// 结束资源释放
	end();
}
