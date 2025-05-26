#pragma once
#include <string>

using std::string;

extern string options_text[5];

struct Sample_Trigger
{
    int volume;
    int pan;
    int id;
};

struct Choice
{
    string choice_text;
    int choice_narration_id;
    int following_scene;
};

struct Scene_Template
{
    string scene_text;
    int scene_number;

    int music_trigger_id;
    Sample_Trigger sample_spec;
    int scene_narration_id;

    Choice choices[4];
};

struct S_Scenes
{
    Scene_Template scene_list[3];

    void update_options_text(int scene_index);
};

void reset_options_text();
Choice return_empty_choice();
S_Scenes generate_fake_parse();