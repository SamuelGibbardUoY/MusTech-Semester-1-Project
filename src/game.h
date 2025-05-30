#pragma once
#include <string>
#include <vector>

using std::string;
using std::vector;

struct Sample
{
    int id;
    int volume;
    int pan;
};

struct Choice
{
    int go_to;
    string text;
    int narration_id;

    Choice(int next_scene, string choice_text, int narrationid)
        : go_to(next_scene), text(choice_text), narration_id(narrationid) {}
};

struct Scene
{
    int number;
    string text;

    Sample sample;
    int music_id;
    int narration_id;

    vector<Choice> options;
};

vector<Scene> get_scenes();