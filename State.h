#pragma once

class State
{
    public:
        virtual void load(int stack = 0) = 0;
        virtual int unload() = 0;
        virtual int update() = 0;
        virtual void render() = 0;
};
