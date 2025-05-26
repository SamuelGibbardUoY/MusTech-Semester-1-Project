#include "json_parsing.h"

Scenes generate_fake_parse()
{
    Scenes scenarios;

    scenarios.scene_list[0].scene_text = std::string("Forest Clearing");
    scenarios.scene_list[0].scene_number = 1;
    scenarios.scene_list[0].music_trigger_id = 1;
    scenarios.scene_list[0].sample_spec = {4, 6, 1};
    scenarios.scene_list[0].scene_narration_id = 1;
    scenarios.scene_list[0].choices[0].choice_text = std::string("Turn left?");
    scenarios.scene_list[0].choices[0].choice_narration_id = 2;
    scenarios.scene_list[0].choices[0].following_scene = 2;
    scenarios.scene_list[0].choices[1].choice_text = std::string("Turn right?");
    scenarios.scene_list[0].choices[1].choice_narration_id = 3;
    scenarios.scene_list[0].choices[1].following_scene = 3;

    scenarios.scene_list[1].scene_text = std::string("Camp Site");
    scenarios.scene_list[1].scene_number = 2;
    scenarios.scene_list[1].music_trigger_id = 2;
    scenarios.scene_list[1].sample_spec = {1, 6, 2};
    scenarios.scene_list[1].scene_narration_id = 4;
    scenarios.scene_list[1].choices[0].choice_text = std::string("Fight bear?");
    scenarios.scene_list[1].choices[0].choice_narration_id = 5;
    scenarios.scene_list[1].choices[0].following_scene = 4;
    scenarios.scene_list[1].choices[1].choice_text = std::string("Hug bear?");
    scenarios.scene_list[1].choices[1].choice_narration_id = 6;
    scenarios.scene_list[1].choices[1].following_scene = 5;

    scenarios.scene_list[2].scene_text = std::string("Cliff side");
    scenarios.scene_list[2].scene_number = 3;
    scenarios.scene_list[2].music_trigger_id = 3;
    scenarios.scene_list[2].sample_spec = {7, 6, 3};
    scenarios.scene_list[2].scene_narration_id = 3;
    scenarios.scene_list[2].choices[0].choice_text = std::string("Turn back?");
    scenarios.scene_list[2].choices[0].choice_narration_id = 8;
    scenarios.scene_list[2].choices[0].following_scene = 6;
    scenarios.scene_list[2].choices[1].choice_text = std::string("Jump?");
    scenarios.scene_list[2].choices[1].choice_narration_id = 9;
    scenarios.scene_list[2].choices[1].following_scene = 7;

    return scenarios;
}