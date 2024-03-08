/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/03/25 16:28:35

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
#include "Global.h"
#include "../view/AbstractGameView.h"

// 定义一个运行时数据全局变量
GameRunTimeData runtimeData;

GameRunTimeData::GameRunTimeData()
{
	isExit = false;
	score = 0;
	currView = nullptr;
}

void GameRunTimeData::changeView(AbstractGameView* nextView)
{
	if (currView) delete currView;
	currView = nextView;
}

AbstractGameView* GameRunTimeData::getCurrView() const
{
	return currView;
}
