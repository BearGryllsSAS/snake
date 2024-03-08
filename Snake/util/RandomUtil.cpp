/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/03/26 17:01:44

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
#include "RandomUtil.h"

void RandomUtil::changeSeed()
{
	//ʹ�����ӳ�ʼ��linear_congruential_engine����Ϊ����ʹ��������������������ֲ�������������������ֲ�.
	linearRan = std::minstd_rand(sd());
}

RandomUtil::RandomUtil()
{
	changeSeed();
}

int RandomUtil::randInt(int min, int max, bool chSeed /*= false*/)
{
	//���������
	if (chSeed)
	{
		changeSeed();
	}
	//��������
	std::uniform_int_distribution<int> dis(min, max);
	//ʹ��linear engine������,�����������ע�����ﴫ��Ĳ���һ��ֵ����һ������
	return dis(linearRan);
}

int RandomUtil::nextInt(int max, bool chSeed /*= false*/)
{
	return randInt(0, max, chSeed);
}

float RandomUtil::randFloat(float min, float max, bool chSeed /*= false*/)
{
	//���������
	if (chSeed)
	{
		changeSeed();
	}
	//��������
	std::uniform_real_distribution <float> dis(min, max);
	//ʹ��linear engine������,�����������ע�����ﴫ��Ĳ���һ��ֵ����һ������
	return dis(linearRan);
}

float RandomUtil::nexFloat(float max, bool chSeed /*= false*/)
{
	return randFloat(0, max, chSeed);
}

bool RandomUtil::nextBool(bool chSeed /*= false*/)
{
	return nextInt(1, chSeed) == 1;
}
