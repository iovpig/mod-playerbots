/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _PLAYERBOT_EXPECTEDLIFETIMEVALUE_H
#define _PLAYERBOT_EXPECTEDLIFETIMEVALUE_H

#include "NamedObjectContext.h"
#include "TargetValue.h"
#include "PossibleTargetsValue.h"
#include "Value.h"

class PlayerbotAI;
class Unit;

// [target health] / [expected group single target dps] = [expected lifetime]
class ExpectedLifetimeValue : public FloatCalculatedValue, public Qualified
{
    public:
        ExpectedLifetimeValue(PlayerbotAI* botAI) :
            FloatCalculatedValue(botAI, "expected lifetime") { }

    public:
        float Calculate() override;
};

class ExpectedGroupDpsValue : public FloatCalculatedValue
{
    public:
        ExpectedGroupDpsValue(PlayerbotAI* botAI) :
            FloatCalculatedValue(botAI, "expected group dps") { }

    public:
        float Calculate() override;
};
#endif
