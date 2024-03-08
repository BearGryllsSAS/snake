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
 * 随机数工具类
 */
class RandomUtil
{
private:
	//随机种子生成器
	std::random_device sd;
	//linear_congruential_engine对象
	std::minstd_rand linearRan;
	//修改随机种子
	void changeSeed();
public:
	//构造初始化随机种子
	RandomUtil();
	
	//************************************
	// Method:    randInt
	// FullName:  RandomUtil::randInt
	// Access:    public 
	// Returns:   int 随机数
	// Qualifier: 生成min-max之间的随机数，随机数区间[min,max]
	// Parameter: int min 最小值
	// Parameter: int max 最大值
	// Parameter: bool chSeed 是否修改种子，默认不修改
	//************************************
	int randInt(int min, int max, bool chSeed = false);

	//************************************
	// Method:    nextInt
	// FullName:  RandomUtil::nextInt
	// Access:    public 
	// Returns:   int 随机数
	// Qualifier: 生成0-max之间的随机数，随机数区间[0,max]
	// Parameter: int max 最大值
	// Parameter: bool chSeed 是否修改种子，默认不修改
	//************************************
	int nextInt(int max, bool chSeed = false);
	
	//************************************
	// Method:    randFloat
	// FullName:  RandomUtil::randFloat
	// Access:    public 
	// Returns:   float 随机数
	// Qualifier: 生成min-max之间的随机数，随机数区间[min,max)
	// Parameter: float min 最小值
	// Parameter: float max 最大值
	// Parameter: bool chSeed 是否修改种子，默认不修改
	//************************************
	float randFloat(float min, float max, bool chSeed = false);
	
	//************************************
	// Method:    nexFloat
	// FullName:  RandomUtil::nexFloat
	// Access:    public 
	// Returns:   float 随机数
	// Qualifier: 生成0-max之间的随机数，随机数区间[0,max)
	// Parameter: float max 最大值
	// Parameter: bool chSeed 是否修改种子，默认不修改
	//************************************
	float nexFloat(float max, bool chSeed = false);
	
	//************************************
	// Method:    nextBool
	// FullName:  RandomUtil::nextBool
	// Access:    public 
	// Returns:   bool ture or false
	// Qualifier: 随机生成一个布尔值
	// Parameter: bool chSeed 是否修改种子，默认不修改
	//************************************
	bool nextBool(bool chSeed = false);
};
#endif // _RANDOMUTIL_H_