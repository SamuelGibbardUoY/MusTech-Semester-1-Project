#include "json_parsing.h"
#include <string>

using std::string;

string options_text[5] = {"", "", "", "", ""};

Choice return_empty_choice()
{
    Choice temp_choice = {string(""), 0, 0};
    return temp_choice;
}

S_Scenes generate_fake_parse()
{
    S_Scenes scenarios;

    scenarios.scene_list[0].scene_text = string("Forest Clearing");
    scenarios.scene_list[0].scene_number = 1;
    scenarios.scene_list[0].music_trigger_id = 1;
    scenarios.scene_list[0].sample_spec = {4, 6, 1};
    scenarios.scene_list[0].scene_narration_id = 1;
    scenarios.scene_list[0].choices[0].choice_text = string("Turn left?");
    scenarios.scene_list[0].choices[0].choice_narration_id = 2;
    scenarios.scene_list[0].choices[0].following_scene = 2;
    scenarios.scene_list[0].choices[1].choice_text = string("Turn right?");
    scenarios.scene_list[0].choices[1].choice_narration_id = 3;
    scenarios.scene_list[0].choices[1].following_scene = 3;
    scenarios.scene_list[0].choices[2] = return_empty_choice();
    scenarios.scene_list[0].choices[3] = return_empty_choice();

    scenarios.scene_list[1].scene_text = string("Camp Site");
    scenarios.scene_list[1].scene_number = 2;
    scenarios.scene_list[1].music_trigger_id = 2;
    scenarios.scene_list[1].sample_spec = {1, 6, 2};
    scenarios.scene_list[1].scene_narration_id = 4;
    scenarios.scene_list[1].choices[0].choice_text = string("Fight bear?");
    scenarios.scene_list[1].choices[0].choice_narration_id = 5;
    scenarios.scene_list[1].choices[0].following_scene = 4;
    scenarios.scene_list[1].choices[1].choice_text = string("Hug bear?");
    scenarios.scene_list[1].choices[1].choice_narration_id = 6;
    scenarios.scene_list[1].choices[1].following_scene = 5;
    scenarios.scene_list[1].choices[2] = return_empty_choice();
    scenarios.scene_list[1].choices[3] = return_empty_choice();

    scenarios.scene_list[2].scene_text = string("Cliff side");
    scenarios.scene_list[2].scene_number = 3;
    scenarios.scene_list[2].music_trigger_id = 3;
    scenarios.scene_list[2].sample_spec = {7, 6, 3};
    scenarios.scene_list[2].scene_narration_id = 3;
    scenarios.scene_list[2].choices[0].choice_text = string("Turn back?");
    scenarios.scene_list[2].choices[0].choice_narration_id = 8;
    scenarios.scene_list[2].choices[0].following_scene = 6;
    scenarios.scene_list[2].choices[1].choice_text = string("Jump?");
    scenarios.scene_list[2].choices[1].choice_narration_id = 9;
    scenarios.scene_list[2].choices[1].following_scene = 7;
    scenarios.scene_list[2].choices[2] = return_empty_choice();
    scenarios.scene_list[2].choices[3] = return_empty_choice();

    return scenarios;
}

void reset_options_text()
{
    for (int i = 0; i < 5; i++) options_text[i] = string("");
}

void S_Scenes::update_options_text(int scene_index)
{
    reset_options_text();

    int choice_count = 0;
    for (int i = 0; i < 5; i++)
    {
        if (scene_list[scene_index].choices[i].choice_text == string("")) break;
        else choice_count++;
    }

    for (int i = 0; i < choice_count; i++)
    {
        options_text[i] = scene_list[scene_index].choices[i].choice_text;
        for (int i = 0; i < (16 - scene_list[scene_index].choices[i].choice_text.length()); i++)
        {
            options_text[i].append(string(" "));
        }
    }
}