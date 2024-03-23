#pragma once
#include "Command.h"
#include <memory>

struct CommandAndKey
{
	std::unique_ptr<dae::Command> command;
	int key;
};

