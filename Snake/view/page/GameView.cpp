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
	// ��������
	system("cls");
	// ����ǽ����ʾ�ַ�
	char wallChar = '#';
	// �����ϱ߿�
	for (int i = 0; i < WIDTH; i++) {
		cout << wallChar;
	}
	cout << endl;
	// �������ұ߿�
	int row = 1;
	for (int i = 0; i < HEIGHT; i++) {
		// ������߿�
		cout << wallChar;
		// ���ÿ���̨���λ��
		ConsoleUtil::gotoXY(WIDTH - 1, row++);
		// �����ұ߿�
		cout << wallChar;
		// ����
		cout << endl;
	}
	// �����±߿�
	for (int i = 0; i < WIDTH; i++) {
		cout << wallChar;
	}
}

void GameView::drawSprite()
{
	for (int i = 0; i < HEIGHT; i++) {
		ConsoleUtil::gotoXY(1, i + 1);
		for (int j = 1; j < WIDTH - 1; j++) {
			// ������ͷ
			if (snake.getHead()->isEqual(j, i))
			{
				cout << "O";
			}
			// ����ʳ��
			else if (foods.getPos()->isEqual(j, i))
			{
				cout << "F";
			}
			else
			{
				bool printTail = false;
				for (size_t k = 0; k < snake.getLen(); k++)
				{
					// ��������
					if (snake.getTail()[k].isEqual(j, i)) {
						cout << "o";
						printTail = true;
						break;
					}
				}
				// ���ƿհ�����
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
	cout << "��û���:" << runtimeData.score << endl;
}

void GameView::init()
{
	// ��ʼ������
	runtimeData.score = 0;
	// ���ƾ�̬Ԫ��
	drawWall();
	drawScore();
	// ���ű�������
	playSound("bg", true);
}

void GameView::draw()
{
	drawSprite();
}

void GameView::handleInput()
{
	// ����û��Ƿ�������
	if (_kbhit()) {
		Direction currDir = snake.getDir();
		// ��ȡ�û�������ַ�
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
			snake.changeDir(Direction::NONE); // ��ͣ��Ϸ
			break;
		case 'x':
			this->status = ViewStatus::ON_EXIT; // ����Ϊ�˳���ͼ״̬
			break;
		default:
			break;
		}
	}
}

void GameView::update()
{
	// ���и������
	AbstractGameView::update();
	// �������ƶ�
	snake.move();
	// ����Ƿ�����
	if (snake.checkDead()) 
	{
		// ����������Ч
		playSound("dead");
		// �˳�������Ϸ��������
		this->status = ViewStatus::ON_EXIT;
		return;
	}
	// ��ʳ���
	if (snake.eatFoods(&foods))
	{
		// ���ųԵ�ʳ����Ч
		playSound("eat");
		// ���ӻ���
		runtimeData.score += 10;
		// ��������ʳ������
		foods.autoGeneratePos();
		// ���»��ƻ���
		drawScore();
	}
}

void GameView::onExit()
{
	// ���и����˳�
	AbstractGameView::onExit();
	// �л�����������
	runtimeData.changeView(new GameOver());
	// �رձ�������
	stopSound("bg");
}

