/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/03/29 16:35:24

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
#include "Postion.h"

Postion::Postion(int x, int y)
{
	this->x = x;
	this->y = y;
}

Postion::Postion()
{
	this->x = 0;
	this->y = 0;
}

bool Postion::isEqual(int x, int y)
{
	return this->x == x && this->y == y;
}

bool Postion::isEqual(const Postion& pos)
{
	return this->x == pos.x && this->y == pos.y;
}

void Postion::addX(int x)
{
	this->x += x;
}

void Postion::addY(int y)
{
	this->y += y;
}

void Postion::addXY(int x, int y)
{
	addX(x);
	addY(y);
}