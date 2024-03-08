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
 * 定义常量和全局变量
 */
#ifndef _GLOBAL_H_
#define _GLOBAL_H_
#define _CRT_SECURE_NO_WARNINGS
 // 导入通用头
#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

// 游戏窗口的宽度
#define WIDTH 40
// 游戏窗口的高度
#define HEIGHT 20
// 游戏休眠时长
#define DLT 400
// 声明一个视图类型
class AbstractGameView;
/**
 * 游戏运行时数据对象
 */
class GameRunTimeData {
private:
	// 当前视图对象
	AbstractGameView* currView;
public:
	// 是否退出游戏
	bool isExit;
	// 得分
	int score;
	// 默认构造
	GameRunTimeData();
	// 切换视图对象
	void changeView(AbstractGameView* nextView);
	// 获取当前视图对象
	AbstractGameView* getCurrView() const;
};

// 引用一个运行时数据全局变量
extern GameRunTimeData runtimeData;

#endif // !_GLOBAL_H_