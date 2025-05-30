#include "json_parsing.h"
#include <string>

using std::string;

string options_text[5] = {"Butt crack", "Butt crack", "Butt crack", "Butt crack", "Butt crack"};

Choice return_empty_choice()
{
    Choice temp_choice = {string("Butt crack"), 0, 0};
    return temp_choice;
}

S_Scenes generate_fake_parse()
{
    S_Scenes scenarios;

    scenarios.scene_list[0].scene_text = string("Jungle Journey");
    scenarios.scene_list[0].scene_number = 0;
    scenarios.scene_list[0].music_trigger_id = -1;
    scenarios.scene_list[0].sample_spec = {0, 0, 0};
    scenarios.scene_list[0].scene_narration_id = 0;
    scenarios.scene_list[0].choices[0].choice_text = string("Continue");
    scenarios.scene_list[0].choices[0].choice_narration_id = 0;
    scenarios.scene_list[0].choices[0].following_scene = 1;
    scenarios.scene_list[0].choices[1] = return_empty_choice();
    scenarios.scene_list[0].choices[2] = return_empty_choice();
    scenarios.scene_list[0].choices[3] = return_empty_choice();

    scenarios.scene_list[1].scene_text = string("Forest start");
    scenarios.scene_list[1].scene_number = 1;
    scenarios.scene_list[1].music_trigger_id = 1;
    scenarios.scene_list[1].sample_spec = {2, 3, 0};
    scenarios.scene_list[1].scene_narration_id = 1;
    scenarios.scene_list[1].choices[0].choice_text = string("Wade forward");
    scenarios.scene_list[1].choices[0].choice_narration_id = 0;
    scenarios.scene_list[1].choices[0].following_scene = 2;
    scenarios.scene_list[1].choices[1].choice_text = string("Go around");
    scenarios.scene_list[1].choices[1].choice_narration_id = 0;
    scenarios.scene_list[1].choices[1].following_scene = 3;
    scenarios.scene_list[1].choices[2] = return_empty_choice();
    scenarios.scene_list[1].choices[3] = return_empty_choice();

    scenarios.scene_list[2].scene_text = string("Enter marsh");
    scenarios.scene_list[2].scene_number = 2;
    scenarios.scene_list[2].music_trigger_id = -1;
    scenarios.scene_list[2].sample_spec = {2, 1, 1};
    scenarios.scene_list[2].scene_narration_id = 2;
    scenarios.scene_list[2].choices[0].choice_text = string("Push through");
    scenarios.scene_list[2].choices[0].choice_narration_id = 0;
    scenarios.scene_list[2].choices[0].following_scene = 4;
    scenarios.scene_list[2].choices[1].choice_text = string("Climb vines");
    scenarios.scene_list[2].choices[1].choice_narration_id = 0;
    scenarios.scene_list[2].choices[1].following_scene = 5;
    scenarios.scene_list[2].choices[2] = return_empty_choice();
    scenarios.scene_list[2].choices[3] = return_empty_choice();

    scenarios.scene_list[3].scene_text = string("Marsh continued");
    scenarios.scene_list[3].scene_number = 3;
    scenarios.scene_list[3].music_trigger_id = -1;
    scenarios.scene_list[3].sample_spec = {1, 1, 2};
    scenarios.scene_list[3].scene_narration_id = 3;
    scenarios.scene_list[3].choices[0].choice_text = string("Give up");
    scenarios.scene_list[3].choices[0].choice_narration_id = 0;
    scenarios.scene_list[3].choices[0].following_scene = 2;
    scenarios.scene_list[3].choices[1].choice_text = string("Traverse");
    scenarios.scene_list[3].choices[1].choice_narration_id = 0;
    scenarios.scene_list[3].choices[1].following_scene = 7;
    scenarios.scene_list[3].choices[2] = return_empty_choice();
    scenarios.scene_list[3].choices[3] = return_empty_choice();

    scenarios.scene_list[4].scene_text = string("Bog monster");
    scenarios.scene_list[4].scene_number = 4;
    scenarios.scene_list[4].music_trigger_id = 2;
    scenarios.scene_list[4].sample_spec = {2, 0, 3};
    scenarios.scene_list[4].scene_narration_id = 4;
    scenarios.scene_list[4].choices[0].choice_text = string("Approach");
    scenarios.scene_list[4].choices[0].choice_narration_id = 0;
    scenarios.scene_list[4].choices[0].following_scene = 8;
    scenarios.scene_list[4].choices[1].choice_text = string("Retreat");
    scenarios.scene_list[4].choices[1].choice_narration_id = 0;
    scenarios.scene_list[4].choices[1].following_scene = 9;
    scenarios.scene_list[4].choices[2] = return_empty_choice();
    scenarios.scene_list[4].choices[3] = return_empty_choice();

    scenarios.scene_list[5].scene_text = string("Snake");
    scenarios.scene_list[5].scene_number = 5;
    scenarios.scene_list[5].music_trigger_id = 4;
    scenarios.scene_list[5].sample_spec = {2, 2, 5};
    scenarios.scene_list[5].scene_narration_id = 5;
    scenarios.scene_list[5].choices[0].choice_text = string("Cut snake");
    scenarios.scene_list[5].choices[0].choice_narration_id = 0;
    scenarios.scene_list[5].choices[0].following_scene = 10;
    scenarios.scene_list[5].choices[1].choice_text = string("Do nothing");
    scenarios.scene_list[5].choices[1].choice_narration_id = 0;
    scenarios.scene_list[5].choices[1].following_scene = 11;
    scenarios.scene_list[5].choices[2] = return_empty_choice();
    scenarios.scene_list[5].choices[3] = return_empty_choice();

    scenarios.scene_list[6].scene_text = string("Fall off hill");
    scenarios.scene_list[6].scene_number = 6;
    scenarios.scene_list[6].music_trigger_id = -2;
    scenarios.scene_list[6].sample_spec = {3, 1, 7};
    scenarios.scene_list[6].scene_narration_id = 6;
    scenarios.scene_list[6].choices[0].choice_text = string("Continue");
    scenarios.scene_list[6].choices[0].choice_narration_id = 0;
    scenarios.scene_list[6].choices[0].following_scene = 2;
    scenarios.scene_list[6].choices[1] = return_empty_choice();
    scenarios.scene_list[6].choices[2] = return_empty_choice();
    scenarios.scene_list[6].choices[3] = return_empty_choice();

    scenarios.scene_list[7].scene_text = string("Mole");
    scenarios.scene_list[7].scene_number = 7;
    scenarios.scene_list[7].music_trigger_id = 2;
    scenarios.scene_list[7].sample_spec = {3, 1, 4};
    scenarios.scene_list[7].scene_narration_id = 7;
    scenarios.scene_list[7].choices[0].choice_text = string("Run for life");
    scenarios.scene_list[7].choices[0].choice_narration_id = 0;
    scenarios.scene_list[7].choices[0].following_scene = 6;
    scenarios.scene_list[7].choices[1].choice_text = string("Try fight");
    scenarios.scene_list[7].choices[1].choice_narration_id = 0;
    scenarios.scene_list[7].choices[1].following_scene = 12;
    scenarios.scene_list[7].choices[2] = return_empty_choice();
    scenarios.scene_list[7].choices[3] = return_empty_choice();

    scenarios.scene_list[8].scene_text = string("Rabid fox");
    scenarios.scene_list[8].scene_number = 8;
    scenarios.scene_list[8].music_trigger_id = 3;
    scenarios.scene_list[8].sample_spec = {2, 1, 6};
    scenarios.scene_list[8].scene_narration_id = 8;
    scenarios.scene_list[8].choices[0].choice_text = string("Try vines");
    scenarios.scene_list[8].choices[0].choice_narration_id = 0;
    scenarios.scene_list[8].choices[0].following_scene = 5;
    scenarios.scene_list[8].choices[1].choice_text = string("Face beast");
    scenarios.scene_list[8].choices[1].choice_narration_id = 0;
    scenarios.scene_list[8].choices[1].following_scene = 16;
    scenarios.scene_list[8].choices[2] = return_empty_choice();
    scenarios.scene_list[8].choices[3] = return_empty_choice();

    scenarios.scene_list[9].scene_text = string("Fall into marsh");
    scenarios.scene_list[9].scene_number = 9;
    scenarios.scene_list[9].music_trigger_id = -2;
    scenarios.scene_list[9].sample_spec = {3, 1, 7};
    scenarios.scene_list[9].scene_narration_id = 9;
    scenarios.scene_list[9].choices[0].choice_text = string("Try climb");
    scenarios.scene_list[9].choices[0].choice_narration_id = 0;
    scenarios.scene_list[9].choices[0].following_scene = 5;
    scenarios.scene_list[9].choices[1].choice_text = string("Don't bother");
    scenarios.scene_list[9].choices[1].choice_narration_id = 0;
    scenarios.scene_list[9].choices[1].following_scene = 8;
    scenarios.scene_list[9].choices[2] = return_empty_choice();
    scenarios.scene_list[9].choices[3] = return_empty_choice();

    scenarios.scene_list[10].scene_text = string("Two snakes");
    scenarios.scene_list[10].scene_number = 10;
    scenarios.scene_list[10].music_trigger_id = 3;
    scenarios.scene_list[10].sample_spec = {3, 1, 8};
    scenarios.scene_list[10].scene_narration_id = 10;
    scenarios.scene_list[10].choices[0].choice_text = string("Cut snake");
    scenarios.scene_list[10].choices[0].choice_narration_id = 0;
    scenarios.scene_list[10].choices[0].following_scene = 13;
    scenarios.scene_list[10].choices[1].choice_text = string("Do nothing");
    scenarios.scene_list[10].choices[1].choice_narration_id = 0;
    scenarios.scene_list[10].choices[1].following_scene = 14;
    scenarios.scene_list[10].choices[2] = return_empty_choice();
    scenarios.scene_list[10].choices[3] = return_empty_choice();

    scenarios.scene_list[11].scene_text = string("Hypnotism");
    scenarios.scene_list[11].scene_number = 11;
    scenarios.scene_list[11].music_trigger_id = 5;
    scenarios.scene_list[11].sample_spec = {2, 3, 11};
    scenarios.scene_list[11].scene_narration_id = 11;
    scenarios.scene_list[11].choices[0].choice_text = string("Continue");
    scenarios.scene_list[11].choices[0].choice_narration_id = 0;
    scenarios.scene_list[11].choices[0].following_scene = 15;
    scenarios.scene_list[11].choices[1] = return_empty_choice();
    scenarios.scene_list[11].choices[2] = return_empty_choice();
    scenarios.scene_list[11].choices[3] = return_empty_choice();

    scenarios.scene_list[12].scene_text = string("Mole attack");
    scenarios.scene_list[12].scene_number = 12;
    scenarios.scene_list[12].music_trigger_id = -2;
    scenarios.scene_list[12].sample_spec = {3, 1, 7};
    scenarios.scene_list[12].scene_narration_id = 12;
    scenarios.scene_list[12].choices[0].choice_text = string("Continue");
    scenarios.scene_list[12].choices[0].choice_narration_id = 0;
    scenarios.scene_list[12].choices[0].following_scene = 2;
    scenarios.scene_list[12].choices[1] = return_empty_choice();
    scenarios.scene_list[12].choices[2] = return_empty_choice();
    scenarios.scene_list[12].choices[3] = return_empty_choice();

    scenarios.scene_list[13].scene_text = string("Three snakes");
    scenarios.scene_list[13].scene_number = 13;
    scenarios.scene_list[13].music_trigger_id = 3;
    scenarios.scene_list[13].sample_spec = {3, 3, 5};
    scenarios.scene_list[13].scene_narration_id = 13;
    scenarios.scene_list[13].choices[0].choice_text = string("Continue");
    scenarios.scene_list[13].choices[0].choice_narration_id = 0;
    scenarios.scene_list[13].choices[0].following_scene = 23;
    scenarios.scene_list[13].choices[1] = return_empty_choice();
    scenarios.scene_list[13].choices[2] = return_empty_choice();
    scenarios.scene_list[13].choices[3] = return_empty_choice();

    scenarios.scene_list[14].scene_text = string("Hypno two");
    scenarios.scene_list[14].scene_number = 14;
    scenarios.scene_list[14].music_trigger_id = 5;
    scenarios.scene_list[14].sample_spec = {2, 3, 11};
    scenarios.scene_list[14].scene_narration_id = 14;
    scenarios.scene_list[14].choices[0].choice_text = string("Continue");
    scenarios.scene_list[14].choices[0].choice_narration_id = 0;
    scenarios.scene_list[14].choices[0].following_scene = 15;
    scenarios.scene_list[14].choices[1] = return_empty_choice();
    scenarios.scene_list[14].choices[2] = return_empty_choice();
    scenarios.scene_list[14].choices[3] = return_empty_choice();

    scenarios.scene_list[15].scene_text = string("Complex plane");
    scenarios.scene_list[15].scene_number = 15;
    scenarios.scene_list[15].music_trigger_id = 6;
    scenarios.scene_list[15].sample_spec = {2, 3, 11};
    scenarios.scene_list[15].scene_narration_id = 15;
    scenarios.scene_list[15].choices[0].choice_text = string("-5");
    scenarios.scene_list[15].choices[0].choice_narration_id = 0;
    scenarios.scene_list[15].choices[0].following_scene = 19;
    scenarios.scene_list[15].choices[1].choice_text = string("5z");
    scenarios.scene_list[15].choices[1].choice_narration_id = 0;
    scenarios.scene_list[15].choices[1].following_scene = 19;
    scenarios.scene_list[15].choices[2].choice_text = string("5i");
    scenarios.scene_list[15].choices[2].choice_narration_id = 0;
    scenarios.scene_list[15].choices[2].following_scene = 20;
    scenarios.scene_list[15].choices[3] = return_empty_choice();

    scenarios.scene_list[16].scene_text = string("Fox approach");
    scenarios.scene_list[16].scene_number = 16;
    scenarios.scene_list[16].music_trigger_id = 3;
    scenarios.scene_list[16].sample_spec = {3, 0, 10};
    scenarios.scene_list[16].scene_narration_id = 16;
    scenarios.scene_list[16].choices[0].choice_text = string("Decapitate");
    scenarios.scene_list[16].choices[0].choice_narration_id = 0;
    scenarios.scene_list[16].choices[0].following_scene = 17;
    scenarios.scene_list[16].choices[1].choice_text = string("Stab belly");
    scenarios.scene_list[16].choices[1].choice_narration_id = 0;
    scenarios.scene_list[16].choices[1].following_scene = 18;
    scenarios.scene_list[16].choices[2] = return_empty_choice();
    scenarios.scene_list[16].choices[3] = return_empty_choice();

    scenarios.scene_list[17].scene_text = string("Chop fox");
    scenarios.scene_list[17].scene_number = 17;
    scenarios.scene_list[17].music_trigger_id = -1;
    scenarios.scene_list[17].sample_spec = {3, 1, 12};
    scenarios.scene_list[17].scene_narration_id = 17;
    scenarios.scene_list[17].choices[0].choice_text = string("Continue");
    scenarios.scene_list[17].choices[0].choice_narration_id = 0;
    scenarios.scene_list[17].choices[0].following_scene = 23;
    scenarios.scene_list[17].choices[1] = return_empty_choice();
    scenarios.scene_list[17].choices[2] = return_empty_choice();
    scenarios.scene_list[17].choices[3] = return_empty_choice();

    scenarios.scene_list[18].scene_text = string("Stab fox");
    scenarios.scene_list[18].scene_number = 18;
    scenarios.scene_list[18].music_trigger_id = -2;
    scenarios.scene_list[18].sample_spec = {3, 1, 9};
    scenarios.scene_list[18].scene_narration_id = 18;
    scenarios.scene_list[18].choices[0].choice_text = string("Continue");
    scenarios.scene_list[18].choices[0].choice_narration_id = 0;
    scenarios.scene_list[18].choices[0].following_scene = 24;
    scenarios.scene_list[18].choices[1] = return_empty_choice();
    scenarios.scene_list[18].choices[2] = return_empty_choice();
    scenarios.scene_list[18].choices[3] = return_empty_choice();

    scenarios.scene_list[19].scene_text = string("Fail test");
    scenarios.scene_list[19].scene_number = 19;
    scenarios.scene_list[19].music_trigger_id = -2;
    scenarios.scene_list[19].sample_spec = {3, 1, 13};
    scenarios.scene_list[19].scene_narration_id = 19;
    scenarios.scene_list[19].choices[0].choice_text = string("Continue");
    scenarios.scene_list[19].choices[0].choice_narration_id = 0;
    scenarios.scene_list[19].choices[0].following_scene = 23;
    scenarios.scene_list[19].choices[1] = return_empty_choice();
    scenarios.scene_list[19].choices[2] = return_empty_choice();
    scenarios.scene_list[19].choices[3] = return_empty_choice();

    scenarios.scene_list[20].scene_text = string("Hermit");
    scenarios.scene_list[20].scene_number = 20;
    scenarios.scene_list[20].music_trigger_id = 7;
    scenarios.scene_list[20].sample_spec = {1, 1, 14};
    scenarios.scene_list[20].scene_narration_id = 20;
    scenarios.scene_list[20].choices[0].choice_text = string("Attack");
    scenarios.scene_list[20].choices[0].choice_narration_id = 0;
    scenarios.scene_list[20].choices[0].following_scene = 21;
    scenarios.scene_list[20].choices[1].choice_text = string("Reason");
    scenarios.scene_list[20].choices[1].choice_narration_id = 0;
    scenarios.scene_list[20].choices[1].following_scene = 22;
    scenarios.scene_list[20].choices[2] = return_empty_choice();
    scenarios.scene_list[20].choices[3] = return_empty_choice();

    scenarios.scene_list[21].scene_text = string("Big mistake");
    scenarios.scene_list[21].scene_number = 21;
    scenarios.scene_list[21].music_trigger_id = 8;
    scenarios.scene_list[21].sample_spec = {2, 1, 9};
    scenarios.scene_list[21].scene_narration_id = 21;
    scenarios.scene_list[21].choices[0].choice_text = string("Continue");
    scenarios.scene_list[21].choices[0].choice_narration_id = 0;
    scenarios.scene_list[21].choices[0].following_scene = 23;
    scenarios.scene_list[21].choices[1] = return_empty_choice();
    scenarios.scene_list[21].choices[2] = return_empty_choice();
    scenarios.scene_list[21].choices[3] = return_empty_choice();

    scenarios.scene_list[22].scene_text = string("Soup help");
    scenarios.scene_list[22].scene_number = 22;
    scenarios.scene_list[22].music_trigger_id = 7;
    scenarios.scene_list[22].sample_spec = {1, 3, 15};
    scenarios.scene_list[22].scene_narration_id = 22;
    scenarios.scene_list[22].choices[0].choice_text = string("Continue");
    scenarios.scene_list[22].choices[0].choice_narration_id = 0;
    scenarios.scene_list[22].choices[0].following_scene = 24;
    scenarios.scene_list[22].choices[1] = return_empty_choice();
    scenarios.scene_list[22].choices[3] = return_empty_choice();

    scenarios.scene_list[23].scene_text = string("You lose");
    scenarios.scene_list[23].scene_number = 23;
    scenarios.scene_list[23].music_trigger_id = -2;
    scenarios.scene_list[23].sample_spec = {3, 1, 16};
    scenarios.scene_list[23].scene_narration_id = 23;
    scenarios.scene_list[23].choices[0].choice_text = string("Back to start");
    scenarios.scene_list[23].choices[0].choice_narration_id = 0;
    scenarios.scene_list[23].choices[0].following_scene = 0;
    scenarios.scene_list[23].choices[1] = return_empty_choice();
    scenarios.scene_list[23].choices[2] = return_empty_choice();
    scenarios.scene_list[23].choices[3] = return_empty_choice();

    scenarios.scene_list[24].scene_text = string("You win");
    scenarios.scene_list[24].scene_number = 25;
    scenarios.scene_list[24].music_trigger_id = -2;
    scenarios.scene_list[24].sample_spec = {3, 1, 17};
    scenarios.scene_list[24].scene_narration_id = 24;
    scenarios.scene_list[24].choices[0].choice_text = string("Back to start");
    scenarios.scene_list[24].choices[0].choice_narration_id = 0;
    scenarios.scene_list[24].choices[0].following_scene = 0;
    scenarios.scene_list[24].choices[1] = return_empty_choice();
    scenarios.scene_list[24].choices[2] = return_empty_choice();
    scenarios.scene_list[24].choices[3] = return_empty_choice();

    return scenarios;
}

void reset_options_text()
{
    for (int i = 0; i < 5; i++) options_text[i] = string("Butt crack");
}

void S_Scenes::update_options_text(int scene_index)
{
    reset_options_text();

    int choice_count = 0;
    for (int i = 0; i < 5; i++)
    {
        if (scene_list[scene_index].choices[i].choice_text == string("Butt crack")) break;
        else choice_count++;
    }
    
    printf("choice_count = %d\n", choice_count);

    for (int i = 0; i < choice_count; i++)
    {
        string temp_string = string("                ");
        temp_string.replace(0, scene_list[scene_index].choices[i].choice_text.length(), scene_list[scene_index].choices[i].choice_text);
        options_text[i] = temp_string;
    }
}