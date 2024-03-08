/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/03/25 17:25:14

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
#include "GameView.h"
#include "GameOver.h"
#include "../../global/Global.h"
#include "../../util/ConsoleUtil.h"
#include "../../util/Sound.h"

void GameView::drawWall()
{
	// 首先清屏
	system("cls");
	// 定义墙体显示字符
	char wallChar = '#';
	// 绘制上边框
	for (int i = 0; i < WIDTH; i++) {
		cout << wallChar;
	}
	cout << endl;
	// 绘制左右边框
	int row = 1;
	for (int i = 0; i < HEIGHT; i++) {
		// 绘制左边框
		cout << wallChar;
		// 设置控制台光标位置
		ConsoleUtil::gotoXY(WIDTH - 1, row++);
		// 绘制右边框
		cout << wallChar;
		// 换行
		cout << endl;
	}
	// 绘制下边框
	for (int i = 0; i < WIDTH; i++) {
		cout << wallChar;
	}
}

void GameView::drawSprite()
{
	for (int i = 0; i < HEIGHT; i++) {
		ConsoleUtil::gotoXY(1, i + 1);
		for (int j = 1; j < WIDTH - 1; j++) {
			// 绘制蛇头
			if (snake.getHead()->isEqual(j, i))
			{
				cout << "O";
			}
			// 绘制食物
			else if (foods.getPos()->isEqual(j, i))
			{
				cout << "F";
			}
			else
			{
				bool printTail = false;
				for (size_t k = 0; k < snake.getLen(); k++)
				{
					// 绘制蛇身
					if (snake.getTail()[k].isEqual(j, i)) {
						cout << "o";
						printTail = true;
						break;
					}
				}
				// 绘制空白区域
				if (!printTail)
				{
					cout << " ";
				}
			}
		}
	}
}

void GameView::drawScore()
{
	ConsoleUtil::gotoXY(0, HEIGHT + 2);
	cout << "获得积分:" << runtimeData.score << endl;
}

void GameView::init()
{
	// 初始化数据
	runtimeData.score = 0;
	// 绘制静态元素
	drawWall();
	drawScore();
	// 播放背景音乐
	playSound("bg", true);
}

void GameView::draw()
{
	drawSprite();
}

void GameView::handleInput()
{
	// 检测用户是否有输入
	if (_kbhit()) {
		Direction currDir = snake.getDir();
		// 获取用户输入的字符
		switch (_getch()) {
		case 'a':
			if (currDir != Direction::RIGHT)
				snake.changeDir(Direction::LEFT);
			break;
		case 'd':
			if (currDir != Direction::LEFT)
				snake.changeDir(Direction::RIGHT);
			break;
		case 'w':
			if (currDir != Direction::DOWN)
				snake.changeDir(Direction::UP);
			break;
		case 's':
			if (currDir != Direction::UP)
				snake.changeDir(Direction::DOWN);
			break;
		case ' ':
			snake.changeDir(Direction::NONE); // 暂停游戏
			break;
		case 'x':
			this->status = ViewStatus::ON_EXIT; // 设置为退出视图状态
			break;
		default:
			break;
		}
	}
}

void GameView::update()
{
	// 呼叫父类更新
	AbstractGameView::update();
	// 进行蛇移动
	snake.move();
	// 检查是否死亡
	if (snake.checkDead()) 
	{
		// 播放死亡音效
		playSound("dead");
		// 退出进入游戏结束界面
		this->status = ViewStatus::ON_EXIT;
		return;
	}
	// 吃食检查
	if (snake.eatFoods(&foods))
	{
		// 播放吃的食物音效
		playSound("eat");
		// 增加积分
		runtimeData.score += 10;
		// 重新设置食物坐标
		foods.autoGeneratePos();
		// 重新绘制积分
		drawScore();
	}
}

void GameView::onExit()
{
	// 呼叫父类退出
	AbstractGameView::onExit();
	// 切换到结束界面
	runtimeData.changeView(new GameOver());
	// 关闭背景音乐
	stopSound("bg");
}

