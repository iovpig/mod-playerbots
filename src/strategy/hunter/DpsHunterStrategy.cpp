/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#include "DpsHunterStrategy.h"
#include "Playerbots.h"

class DpsHunterStrategyActionNodeFactory : public NamedObjectFactory<ActionNode>
{
    public:
        DpsHunterStrategyActionNodeFactory()
        {
            creators["aimed shot"] = &aimed_shot;
        }

    private:
        static ActionNode* aimed_shot([[maybe_unused]] PlayerbotAI* botAI)
        {
            return new ActionNode ("aimed shot",
                /*P*/ nullptr,
                /*A*/ NextAction::array(0, new NextAction("multi-shot", 10.0f), nullptr),
                /*C*/ nullptr);
        }
};

DpsHunterStrategy::DpsHunterStrategy(PlayerbotAI* botAI) : GenericHunterStrategy(botAI)
{
    actionNodeFactories.Add(new DpsHunterStrategyActionNodeFactory());
}

NextAction** DpsHunterStrategy::getDefaultActions()
{
    return NextAction::array(0, 
        new NextAction("kill shot", 16.0f),
        new NextAction("chimera shot", 15.0f),
        new NextAction("explosive shot", 15.0f),
        new NextAction("aimed shot", 14.0f), 
        new NextAction("arcane shot", 13.0f),
        new NextAction("steady shot", 12.0f),
        new NextAction("auto shot", 10.0f),
        nullptr);
    // return NextAction::array(0, new NextAction("explosive shot", 11.0f), new NextAction("auto shot", 10.0f), new NextAction("auto attack", 9.0f), nullptr);
}

void DpsHunterStrategy::InitTriggers(std::vector<TriggerNode*>& triggers)
{
    GenericHunterStrategy::InitTriggers(triggers);

    triggers.push_back(new TriggerNode("black arrow", NextAction::array(0, new NextAction("black arrow", 15.0f), nullptr)));
    triggers.push_back(new TriggerNode("low mana", NextAction::array(0, new NextAction("viper sting", 23.0f), nullptr)));
    triggers.push_back(new TriggerNode("hunter's mark", NextAction::array(0, new NextAction("hunter's mark", 11.0f), nullptr)));
    triggers.push_back(new TriggerNode("concussive shot on snare target", NextAction::array(0, new NextAction("concussive shot", 20.0f), nullptr)));
    triggers.push_back(new TriggerNode("no pet", NextAction::array(0, new NextAction("call pet", 21.0f), NULL)));
    triggers.push_back(new TriggerNode("hunters pet low health", NextAction::array(0, new NextAction("mend pet", 21.0f), NULL)));
    /*triggers.push_back(new TriggerNode("has aggro", NextAction::array(0, new NextAction("concussive shot", 20.0f), nullptr)));*/
}

void DpsAoeHunterStrategy::InitTriggers(std::vector<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode("light aoe", NextAction::array(0, new NextAction("multi-shot", 20.0f), nullptr)));
	triggers.push_back(new TriggerNode("medium aoe", NextAction::array(0, new NextAction("volley", 21.0f), nullptr)));
	triggers.push_back(new TriggerNode("serpent sting on attacker", NextAction::array(0, new NextAction("serpent sting on attacker", 17.0f), nullptr)));
}

void DpsHunterDebuffStrategy::InitTriggers(std::vector<TriggerNode*>& triggers)
{
    triggers.push_back(new TriggerNode("no stings", NextAction::array(0, new NextAction("serpent sting", 18.0f), nullptr)));
}
