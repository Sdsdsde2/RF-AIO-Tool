#pragma once

#include <Windows.h>
#include <iostream>
#include <string>
#include "Scanner.h"
#include "Memory.h"
#include "Speed.h"

using namespace std;

//MEMORY_CONSTANTS
#define dwBegin		0x00400000
#define dwEnd		0x0FFFFFFF

//CHANNEL_VALUES
enum _CHANNELS {
	_FREE = 0,
	_AMATEUR = 1,
	_SEMIPRO = 2,
	_PROFESSIONAL = 3,
	_NEET = 4
};
//PING_SETTERS
enum _PING {
	_HIDE = 0,
	_SHOW = 256
};

//POINTERS
#define US_BASE		0x76FB00
#define EU_BASE		0x76EB00
#define NAME		0x5E00
#define CHANNEL		0x545C
#define CARAT 		0x5D98
#define LEVEL		0x5D5C
#define MEDAL		0x5DA8
#define PING		0x138
#define HAIR		0x994
#define HAIR_2		0x54D4
#define EYES		0x9AC
#define EYES_2		0x54EC
#define NOSE		0x9B0
#define NOSE_2		0x54F0
#define WING		0x9C8
#define WING_2		0x5508
#define NECK		0x9CC
#define NECK_2		0x550C
#define MASK		0x9D4
#define MASK_2		0x5514
#define ACS			0x9D0
#define ACS_2		0x5514
#define TAIL		0x9D8
#define TAIL_2		0x551C
#define EAR			0x998
#define EAR_2		0x5520
#define TOP			0x99C
#define TOP_2		0x54DC
#define BOTTOM		0x9A0
#define BOTTOM_2	0x54E0
#define GLOVES		0x9A4
#define GLOVES_2	0x54E4
#define SHOES		0x9A8
#define SHOES_2		0x54E8
#define SCROLL		0x9B8
#define SCROLL_2	0x54F8
#define EXO_A		0x9C0
#define EXO_A_2		0x5500
#define EXO_B		0x9BC
#define EXO_B_2		0x54FC

class Library {
private:
	Scanner *scan;
	Memory *mem;
	Speed *speed;
public:
	//FUNCTION_SWITCHES
	BOOL panicSwitch, crashSwitch, suspendSwitch, gravitySwitch, glideSwitch, walkSwitch, runSwitch,
		hermitSwitch, suicideSwitch, jmpSwitch, D3DSwitch, dGravitySwitch, pingSwitch;

	BOOL rbSwitch; BOOL buSwitch;

	//SETTINGS_VARIABLES
	BOOL euSwitch;

private:
	//DECLARE_ADDRESSES
	DWORD panicAddy, crashAddy_1, crashAddy_2, lmpAddy, AirSuspendAddy, gravityAddy, glideAddy, walkSpdAddy, runSpdAddy,
		hermitAddy, JSuicideAddy, S2JumpAddy, D3DAddy;
public:
	//STATISTICS
	string myUser;

private:
	//GRAB_USE-ABLE_ADDRESSES
	void doSCAN() {

		try {

			panicAddy = 0x769F30;
			lmpAddy = scan->findPattern(dwBegin, dwEnd, (PBYTE)"\xFF\x15\x34\x00\x6E\x00\x6A\x00", "xxx?xxxx");
			crashAddy_1 = scan->findPattern(dwBegin, dwEnd, (PBYTE)"\x88\x47\x07\xC6\x47\x17\x00\xBA", "xxxxxxxx");
			crashAddy_2 = scan->findPattern(dwBegin, dwEnd, (PBYTE)"\xC6\x47\x17\x00\xBA\x0E\x00\x00", "xxxxxxxx");
			glideAddy = scan->findPattern(dwBegin, dwEnd, (PBYTE)"\xC0\x00\x00\xA0\x40\x0A\xD7\x23", "xxxxxxxx");
			AirSuspendAddy = glideAddy - 0x01;
			gravityAddy = glideAddy + 0x01;
			walkSpdAddy = gravityAddy + 0x1B;
			runSpdAddy = gravityAddy + 0x1F;
			hermitAddy = gravityAddy + 0x2F;
			JSuicideAddy = runSpdAddy - 0x0C;
			S2JumpAddy = gravityAddy + 0x10;
			D3DAddy = (DWORD)GetModuleHandleA("d3dx9_35.dll");
			D3DAddy += 0x1596BB;
		}
		catch (...) {

			MessageBoxA(NULL, "An Internal Error Has Occured", "TyE . Dialog", MB_OK | MB_ICONERROR);
			ExitProcess(0);
		}
	}

public:
	//CONSTRUCTOR
	Library(bool doInit) {

		if (doInit) {

			Initialize();
		}

	}
	void Version() {

		try {

			char result[MAX_PATH];
			string temp = string(result, GetModuleFileName(NULL, result, MAX_PATH));
			if (temp.find("RumbleFighterEU") != string::npos)
				euSwitch = TRUE;
			else
				euSwitch = FALSE;
		}
		catch (...) {

			euSwitch = FALSE;
		}
	}
	void Initialize() {

		//INITIALIZE_OBJECTS
		scan = new Scanner();
		mem = new Memory();
		speed = new Speed();

		//SET_USER_STATISTICS
		myUser = "";

		//INITIALIZE_SWITCHES
		panicSwitch = FALSE, crashSwitch = FALSE, suspendSwitch = FALSE, gravitySwitch = FALSE, glideSwitch = FALSE, walkSwitch = FALSE,
			runSwitch = FALSE, suicideSwitch = FALSE, jmpSwitch = FALSE, D3DSwitch = FALSE, dGravitySwitch = FALSE, pingSwitch = FALSE;

		buSwitch = FALSE;

		//SCAN_ADDRESSES
		doSCAN();
	}

#pragma region HACKS_CHEATS

public:

	//REBIRTH_HACK
	void Rebirth() {

		rbSwitch = FALSE;
		DWORD rbAddy = scan->search(0x06200000, dwEnd, (PBYTE)"\x72\xC7\x4C\x00\x27", "xxxxx");
		mem->WriteMemory((VOID*)(rbAddy), (PBYTE)"\xB1\xD0\x10", 3);
		rbSwitch = TRUE;
	}
	//INFINITE_PANIC_*TEST
	void Panic() {
		switch (panicSwitch) {
		case FALSE:

			mem->WriteMemory((VOID*)(panicAddy), (PBYTE)"\xA7", 1);
			panicSwitch = TRUE;
			break;
		case TRUE:

			mem->WriteMemory((VOID*)(panicAddy), (PBYTE)"\xC8", 1);
			panicSwitch = FALSE;
			break;
		}
	}
	//ROOM_CRASH
	void Crash() {

		mem->WriteMemory((VOID*)(lmpAddy), (PBYTE)"\x90\x90\x90", 3);
		mem->WriteMemory((VOID*)(crashAddy_1), (PBYTE)"\x88\x47\x03", 3);
		mem->WriteMemory((VOID*)(crashAddy_2), (PBYTE)"\xC6\x47\x13", 3);
	}
	//AIR_SUSPENSION
	void AirSuspend() {
		switch (suspendSwitch) {
		case FALSE:

			mem->WriteMemory((VOID*)(AirSuspendAddy), (PBYTE)"\x90\x90\x90", 3);
			suspendSwitch = TRUE;
			break;
		case TRUE:

			mem->WriteMemory((VOID*)(AirSuspendAddy), (PBYTE)"\x80\xC0", 2);
			suspendSwitch = FALSE;
			break;
		}
	}
	//GRAVITY_JUMP
	void GravityJump() {
		switch (gravitySwitch) {
		case FALSE:

			*(float*)(gravityAddy) = 100;
			gravitySwitch = TRUE;
			break;
		case TRUE:

			*(float*)(gravityAddy) = 5;
			gravitySwitch = FALSE;
			break;
		}
	}
	//GLIDE_BASIC
	void Glide() {
		switch (glideSwitch) {
		case FALSE:

			mem->WriteMemory((VOID*)(glideAddy), (PBYTE)"\xBF", 1);
			glideSwitch = TRUE;
			break;
		case TRUE:

			mem->WriteMemory((VOID*)(glideAddy), (PBYTE)"\xC0", 1);
			glideSwitch = FALSE;
			break;
		}
	}
	//WALKING_SPEED_HACK
	void WalkSpeed() {
		switch (walkSwitch) {
		case FALSE:

			mem->WriteMemory((VOID*)(walkSpdAddy), (PBYTE)"\x40", 1);
			walkSwitch = TRUE;
			break;
		case TRUE:

			mem->WriteMemory((VOID*)(walkSpdAddy), (PBYTE)"\x3F", 1);
			walkSwitch = FALSE;
			break;
		}
	}
	//RUNNING_SPEED_HACK
	void RunSpeed() {
		switch (runSwitch) {
		case FALSE:

			mem->WriteMemory((VOID*)(runSpdAddy), (PBYTE)"\x40", 1);
			runSwitch = TRUE;
			break;
		case TRUE:

			mem->WriteMemory((VOID*)(runSpdAddy), (PBYTE)"\x3F", 1);
			runSwitch = FALSE;
			break;
		}
	}
	//HERMIT_JUMP
	void HermitJump() {
		switch (hermitSwitch) {
		case FALSE:

			mem->WriteMemory((VOID*)(hermitAddy), (PBYTE)"\x40", 1);
			hermitSwitch = TRUE;
			break;
		case TRUE:

			mem->WriteMemory((VOID*)(hermitAddy), (PBYTE)"\x3F", 1);
			hermitSwitch = FALSE;
			break;
		}
	}
	//SUICIDE_JUMP X2
	void JSuicide() {
		switch (suicideSwitch) {
		case FALSE:

			mem->WriteMemory((VOID*)(JSuicideAddy), (PBYTE)"\xCC\x00\x00\x80", 4);
			suicideSwitch = TRUE;
			break;
		case TRUE:

			mem->WriteMemory((VOID*)(JSuicideAddy), (PBYTE)"\x40\x00\x00\x20", 4);
			suicideSwitch = FALSE;
			break;
		}
	}
	//HYPER_JUMP X2
	void HyperJump() {
		switch (jmpSwitch) {
		case FALSE:

			mem->WriteMemory((VOID*)(S2JumpAddy), (PBYTE)"\x00\x00\x70\x41", 4);
			jmpSwitch = TRUE;
			break;
		case TRUE:

			mem->WriteMemory((VOID*)(S2JumpAddy), (PBYTE)"\xCD\xCC\x4C\x40", 4);
			jmpSwitch = FALSE;
			break;
		}
	}
	//D3D_CRUSH
	void D3DCrush() {

		switch (D3DSwitch) {
		case FALSE:

			mem->WriteMemory((VOID*)(D3DAddy), (PBYTE)"\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90", 16);
			D3DSwitch = TRUE;
			break;
		case TRUE:

			mem->WriteMemory((VOID*)(D3DAddy), (PBYTE)"\x89\x54\x31\x20\x8B\x40\x54\xC7\x44\x01\x54\x01\x00\x00\x00\x33", 16);
			D3DSwitch = FALSE;
			break;
		}
	}
	//DEAD_GRAVITY
	void DeadGravity() {

		switch (dGravitySwitch) {
		case FALSE:

			mem->WriteMemory((VOID*)(gravityAddy), (PBYTE)"\x00\x00\xC8\xFF", 4);
			dGravitySwitch = TRUE;
			break;
		case TRUE:

			mem->WriteMemory((VOID*)(gravityAddy), (PBYTE)"\x00\x00\xA0\x40", 4);
			dGravitySwitch = TRUE;
			break;
		}
	}
	//GET_USER_CHARACTER
	string getIGN() {

		string mUser = "";
		try {

			if (!euSwitch)
				mUser = mem->ReadStr(US_BASE, NAME);
			else
				mUser = mem->ReadStr(EU_BASE, NAME);
		}
		catch (...) {}

		return mUser;
	}
	//NAME_HACK
	void setIGN(string newName) {

		try {

			if (!euSwitch)
				mem->WriteStr(US_BASE, NAME, newName);
			else
				mem->WriteStr(EU_BASE, NAME, newName);
		}
		catch (...) {}
	}
	//GET_LEVEL
	int getLevel() {

		int mLevel = 0;
		try {

			if (!euSwitch)
				mLevel = mem->ReadPtr(US_BASE, LEVEL);
			else
				mLevel = mem->ReadPtr(EU_BASE, LEVEL);
		}
		catch (...) {}
		return mLevel;
	}
	//CHANNEL_HACK
	void channelHack(int chan) {

		if (!euSwitch)
			mem->WritePtr(US_BASE, CHANNEL, chan);
		else
			mem->WritePtr(EU_BASE, CHANNEL, chan);
	}
	int getChannel() {
		int chan = 0;
		try {

			if (!euSwitch)
				chan = mem->ReadPtr(US_BASE, CHANNEL);
			else
				chan = mem->ReadPtr(EU_BASE, CHANNEL);

		}
		catch (...) {}

		return chan;
	}
	//CHECK_INGAME
	BOOL inGame() {
		switch (getLevel()) {
		case 0:

			return false;
		}
		return true;
	}
	//PING_VIEW	
	void doPING() {
		switch (pingSwitch) {
		case FALSE:

			if (!euSwitch)
				mem->WritePtr(US_BASE, PING, _PING::_SHOW);
			else
				mem->WritePtr(EU_BASE, PING, _PING::_SHOW);

			pingSwitch = TRUE;
			break;
		case TRUE:

			if (!euSwitch)
				mem->WritePtr(US_BASE, PING, _PING::_HIDE);
			else
				mem->WritePtr(EU_BASE, PING, _PING::_HIDE);

			pingSwitch = FALSE;
			break;
		}
	}
	//ITEM_GRAB
	INT getGear(DWORD EQUIP) {

		INT _ID = 0;
		try {

			if (!euSwitch)
				_ID = mem->ReadPtr(US_BASE, EQUIP);
			else
				_ID = mem->ReadPtr(EU_BASE, EQUIP);
		}
		catch (...) {}
		return _ID;
	}
	//ITEM_FREEZE
	void setGear(DWORD EQUIP, int ITEM)
	{

		if (!euSwitch)
			mem->WritePtr(US_BASE, EQUIP, ITEM);
		else
			mem->WritePtr(EU_BASE, EQUIP, ITEM);
	}
	//SPEED_HACK
	void doSPEED(BOOL Enabled, INT SPEED = 0) {

		switch (Enabled) {
		case TRUE:

			speed->setSPEED(SPEED);
			speed->doSPEED();
			break;
		case FALSE:

			speed->setSPEED(1);
			speed->doSPEED();
			break;
		}
	}

#pragma endregion
};
