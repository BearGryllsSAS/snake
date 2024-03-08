#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/11/13 16:45:11

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
#ifndef _SOUND_H_
#define _SOUND_H_

//使用示例
//************************************
// 加载音乐文件
// loadSound("sounds\\bg1.mp3", "bg1");
// 播放音乐
// playSound("bg1", true);
// 设置音量
// settingVolume("bg1", 100);
// 调节音量
// changeVolume("bg1", 900);
// 暂停音乐
// pauseSound("bg1");
// 恢复音乐
// resumeSound("bg1");
//************************************

//************************************
// Method:    commonCmd
// FullName:  commonCmd
// Access:    public 
// Returns:   void
// Qualifier: 执行通用简单指令
// Parameter: const char * cmd 指令名如：close、stop、pause、resume等
// Parameter: const char * name 加载后的别称
//************************************
void commonCmd(const char* cmd, const char* name);
//************************************
// Method:    loadSound
// FullName:  loadSound
// Access:    public 
// Returns:   void
// Qualifier: 加载音频
// Parameter: const char * path 音频路径,如f://mpeg//bg.mp3
// Parameter: const char * name 加载后的别称
//************************************
void loadSound(const char* path, const char* name);
//************************************
// Method:    unloadSound
// FullName:  unloadSound
// Access:    public 
// Returns:   void
// Qualifier: 卸载音频
// Parameter: const char * name 加载后的别称
//************************************
void unloadSound(const char* name);
//************************************
// Method:    playSound
// FullName:  playSound
// Access:    public 
// Returns:   void
// Qualifier: 播放音频
// Parameter: const char * name 加载后的别称
// Parameter: bool isLoop 是否循环播放
//************************************
void playSound(const char* name, bool isLoop = false);
//************************************
// Method:    seekSound
// FullName:  seekSound
// Access:    public 
// Returns:   void
// Qualifier: 设置音频播放位置
// Parameter: const char * name 加载后的别称
// Parameter: int pos 播放位置从0开始
//************************************
void seekSound(const char* name, int pos);
//************************************
// Method:    stopSound
// FullName:  stopSound
// Access:    public 
// Returns:   void
// Qualifier: 停止播放
// Parameter: const char * name 加载后的别称
//************************************
void stopSound(const char* name);
//************************************
// Method:    pauseSound
// FullName:  pauseSound
// Access:    public 
// Returns:   void
// Qualifier: 暂停播放
// Parameter: const char * name 加载后的别称
//************************************
void pauseSound(const char* name);
//************************************
// Method:    resumeSound
// FullName:  resumeSound
// Access:    public 
// Returns:   void
// Qualifier: 恢复播放
// Parameter: const char * name 加载后的别称
//************************************
void resumeSound(const char* name);
//************************************
// Method:    changeVolume
// FullName:  changeVolume
// Access:    public 
// Returns:   int 返回修改后的音量值
// Qualifier: 修改音量，默认为最大值
// Parameter: const char * name 加载后的别称
// Parameter: int ch 修改音量值，减小音量用负数
//************************************
int changeVolume(const char* name, int ch);
//************************************
// Method:    settingVolume
// FullName:  settingVolume
// Access:    public 
// Returns:   int 返回修改后的音量值
// Qualifier: 设置音量，默认为最大值
// Parameter: const char * name 加载后的别称
// Parameter: int volume 设置为音量值，有效范围为0-1000
//************************************
int settingVolume(const char* name, int volume);

#endif