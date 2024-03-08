#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/03/26 17:01:25

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
#ifndef _RANDOMUTIL_H_
#define _RANDOMUTIL_H_
#include <random>
#include <iostream>
/**
 * �����������
 */
class RandomUtil
{
private:
	//�������������
	std::random_device sd;
	//linear_congruential_engine����
	std::minstd_rand linearRan;
	//�޸��������
	void changeSeed();
public:
	//�����ʼ���������
	RandomUtil();
	
	//************************************
	// Method:    randInt
	// FullName:  RandomUtil::randInt
	// Access:    public 
	// Returns:   int �����
	// Qualifier: ����min-max֮�������������������[min,max]
	// Parameter: int min ��Сֵ
	// Parameter: int max ���ֵ
	// Parameter: bool chSeed �Ƿ��޸����ӣ�Ĭ�ϲ��޸�
	//************************************
	int randInt(int min, int max, bool chSeed = false);

	//************************************
	// Method:    nextInt
	// FullName:  RandomUtil::nextInt
	// Access:    public 
	// Returns:   int �����
	// Qualifier: ����0-max֮�������������������[0,max]
	// Parameter: int max ���ֵ
	// Parameter: bool chSeed �Ƿ��޸����ӣ�Ĭ�ϲ��޸�
	//************************************
	int nextInt(int max, bool chSeed = false);
	
	//************************************
	// Method:    randFloat
	// FullName:  RandomUtil::randFloat
	// Access:    public 
	// Returns:   float �����
	// Qualifier: ����min-max֮�������������������[min,max)
	// Parameter: float min ��Сֵ
	// Parameter: float max ���ֵ
	// Parameter: bool chSeed �Ƿ��޸����ӣ�Ĭ�ϲ��޸�
	//************************************
	float randFloat(float min, float max, bool chSeed = false);
	
	//************************************
	// Method:    nexFloat
	// FullName:  RandomUtil::nexFloat
	// Access:    public 
	// Returns:   float �����
	// Qualifier: ����0-max֮�������������������[0,max)
	// Parameter: float max ���ֵ
	// Parameter: bool chSeed �Ƿ��޸����ӣ�Ĭ�ϲ��޸�
	//************************************
	float nexFloat(float max, bool chSeed = false);
	
	//************************************
	// Method:    nextBool
	// FullName:  RandomUtil::nextBool
	// Access:    public 
	// Returns:   bool ture or false
	// Qualifier: �������һ������ֵ
	// Parameter: bool chSeed �Ƿ��޸����ӣ�Ĭ�ϲ��޸�
	//************************************
	bool nextBool(bool chSeed = false);
};
#endif // _RANDOMUTIL_H_