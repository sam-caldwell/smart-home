#pragma once

#include "utils/Token.h"
#include "utils/TokenQueue.h"

// This is a collection of tokens. We are abstracted from string for future proofing.
using Tokens = TokenQueue<Token>;
