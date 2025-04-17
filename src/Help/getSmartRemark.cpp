// File: getSmartRemark.cpp
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: a selector for smart remark generation

#include <Help/Help.h>

std::string getSmartRemark() {
    static const std::vector<std::string> remarks = {
        "If you need more help, seek a professional.",
        "Did you remember your new TPS coversheet?",
        "I believe you have my stapler?",
        "Try turning it off and on again.",
        "Did your cat walk on the keyboard?",
        "This isn't the coffee machine, buddy.",
        "That's not how any of this works.",
        "You might want to consult a human next time.",
        "Would you like to play a game?",
        "Eh...no chess. How about a good game of Global Thermonuclear War?",
        "If you're feeling warmer, check your pulse.\n(If you smell sulfur you may have bigger issues.)",
        "My other computer is a Gibson.",
        "My grandfather was WOPR.",
        "Strange game.  The only winning move is not to play.",
        "No fighting in the war room!",
        "The whole point of the doomsday machine is lost if you keep it a secret!\n--Dr. Strangelove"
    };

    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<size_t> dist(0, remarks.size() - 1);

    return remarks[dist(gen)];
}
