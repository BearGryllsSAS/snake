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
 * 书写一个游戏界面类
 */
class GameView : public AbstractGameView
{
private:
	// 定义一条蛇
	Snake snake;
	// 定义一个食物
	Foods foods;
	// 绘制墙体
	void drawWall();
	// 绘制游戏动态元素
	void drawSprite();
	// 绘制积分
	void drawScore();
protected:
	// 实现初始化方法，用于绘制墙体和积分
	void init() override;
	// 实现绘制方法，用于动态绘制蛇和食物
	void draw() override;
	// 实现用户输入方法，用于实现用户控制蛇的方向
	void handleInput() override;
public:
	// 重写更新视图，实现蛇移动、死亡判断、吃食物
	void update() override;
	// 重写退出视图，实现打开游戏结束界面
	void onExit() override;
};

#endif // !_GAMEVIEW_H_