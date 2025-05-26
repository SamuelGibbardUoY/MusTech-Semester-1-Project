#pragma once
#include <string>

struct Sample_Trigger
{
    int volume;
    int pan;
    int id;
};

struct Choice
{
    std::string choice_text;
    int choice_narration_id;
    int following_scene;
};

struct Scene_Template
{
    std::string scene_text;
    int scene_number;

    int music_trigger_id;
    Sample_Trigger sample_spec;
    int scene_narration_id;

    Choice choices[4];
};

struct Scenes
{
    Scene_Template scene_list[3];
};

Scenes generate_fake_parse();