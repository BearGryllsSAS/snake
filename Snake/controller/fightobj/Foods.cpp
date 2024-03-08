/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/03/29 16:44:35

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
#include "Foods.h"
#include "../../util/RandomUtil.h"
#include "../../global/Global.h"

RandomUtil frand;

Foods::Foods()
{
	autoGeneratePos();
}

void Foods::autoGeneratePos()
{
	pos = { frand.randInt(1,WIDTH - 1),frand.randInt(0,HEIGHT - 1) };
}

void Foods::setPos(Postion pos)
{
	this->pos = pos;
}

Postion* Foods::getPos()
{
	return &pos;
}
