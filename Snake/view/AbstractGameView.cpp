/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/03/29 21:39:58

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
#include "AbstractGameView.h"

void AbstractGameView::onEnter()
{
	init();
	this->status = ViewStatus::ON_UPDATE;
}

void AbstractGameView::update()
{
	handleInput();
	draw();
}

void AbstractGameView::onExit()
{
	this->status = ViewStatus::NONE;
}

ViewStatus AbstractGameView::getStaus()
{
	return this->status;
}
