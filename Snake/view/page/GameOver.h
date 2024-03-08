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
 * 书写一个游戏结束视图
 */
class GameOver : public AbstractGameView
{
private:
	// 是否重新开始游戏
	bool isRestart = false;
public:
	// 重写退出视图，实现重新开始游戏或结束游戏
	void onExit() override;
protected:
	// 实现视图初始化
	void init() override;
	// 实现视图绘制
	void draw() override;
	// 实现用户输入处理
	void handleInput() override;
};

#endif // !_GAMEOVER_H_