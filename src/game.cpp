#include "game.h"

vector<Scene> get_scenes() {
/*
Simulate parsing a JSON game file
*/
    vector<Scene> scene_list;
    scene_list.resize(25);

    scene_list[0].text = string("Jungle Journey");
    scene_list[0].number = 0;
    scene_list[0].sample = {0, 0, 0};
    scene_list[0].music_id = -1;
    scene_list[0].narration_id = 0;
    scene_list[0].options.push_back(Choice(1, "Continue", 25));

    scene_list[1].text = string("Forest start");
    scene_list[1].number = 1;
    scene_list[1].sample = {0, 2, 3};
    scene_list[1].music_id = 1;
    scene_list[1].narration_id = 1;
    scene_list[1].options.push_back(Choice(2, "Wade forward", 26));
    scene_list[1].options.push_back(Choice(3, "Go around", 27));

    scene_list[2].text = string("Enter marsh");
    scene_list[2].number = 2;
    scene_list[2].sample = {1, 2, 1};
    scene_list[2].music_id = -1;
    scene_list[2].narration_id = 2;
    scene_list[2].options.push_back(Choice(4, "Push through", 28));
    scene_list[2].options.push_back(Choice(5, "Climb vines", 29));

    scene_list[3].text = string("Marsh continued");
    scene_list[3].number = 3;
    scene_list[3].sample = {2, 1, 1};
    scene_list[3].music_id = -1;
    scene_list[3].narration_id = 3;
    scene_list[3].options.push_back(Choice(2, "Give up", 30));
    scene_list[3].options.push_back(Choice(7, "Traverse", 31));

    scene_list[4].text = string("Bog monster");
    scene_list[4].number = 4;
    scene_list[4].sample = {3, 2, 0};
    scene_list[4].music_id = 2;
    scene_list[4].narration_id = 4;
    scene_list[4].options.push_back(Choice(8, "Approach", 32));
    scene_list[4].options.push_back(Choice(9, "Retreat", 33));

    scene_list[5].text = string("Snake");
    scene_list[5].number = 5;
    scene_list[5].sample = {5, 2, 2};
    scene_list[5].music_id = 4;
    scene_list[5].narration_id = 5;
    scene_list[5].options.push_back(Choice(10, "Cut snake", 34));
    scene_list[5].options.push_back(Choice(11, "Do nothing", 35));

    scene_list[6].text = string("Fall off hill");
    scene_list[6].number = 6;
    scene_list[6].sample = {7, 3, 1};
    scene_list[6].music_id = -2;
    scene_list[6].narration_id = 6;
    scene_list[6].options.push_back(Choice(2, "Continue", 25));

    scene_list[7].text = string("Mole");
    scene_list[7].number = 7;
    scene_list[7].sample = {4, 3, 1};
    scene_list[7].music_id = 2;
    scene_list[7].narration_id = 7;
    scene_list[7].options.push_back(Choice(6, "Run for life", 36));
    scene_list[7].options.push_back(Choice(12, "Try fight", 37));

    scene_list[8].text = string("Rabid fox");
    scene_list[8].number = 8;
    scene_list[8].sample = {6, 2, 1};
    scene_list[8].music_id = 3;
    scene_list[8].narration_id = 8;
    scene_list[8].options.push_back(Choice(5, "Try vines", 38));
    scene_list[8].options.push_back(Choice(16, "Face beast", 39));

    scene_list[9].text = string("Fall into marsh");
    scene_list[9].number = 9;
    scene_list[9].sample = {7, 3, 1};
    scene_list[9].music_id = -2;
    scene_list[9].narration_id = 9;
    scene_list[9].options.push_back(Choice(5, "Try climb", 40));
    scene_list[9].options.push_back(Choice(8, "Don't bother", 41));

    scene_list[10].text = string("Two snakes");
    scene_list[10].number = 10;
    scene_list[10].sample = {8, 3, 1};
    scene_list[10].music_id = 3;
    scene_list[10].narration_id = 10;
    scene_list[10].options.push_back(Choice(13, "Cut snake", 34));
    scene_list[10].options.push_back(Choice(14, "Do nothing", 35));

    scene_list[11].text = string("Hypnotism");
    scene_list[11].number = 11;
    scene_list[11].sample = {11, 2, 3};
    scene_list[11].music_id = 5;
    scene_list[11].narration_id = 11;
    scene_list[11].options.push_back(Choice(15, "Continue", 25));

    scene_list[12].text = string("Mole attack");
    scene_list[12].number = 12;
    scene_list[12].sample = {7, 3, 1};
    scene_list[12].music_id = -2;
    scene_list[12].narration_id = 12;
    scene_list[12].options.push_back(Choice(2, "Continue", 25));

    scene_list[13].text = string("Three snakes");
    scene_list[13].number = 13;
    scene_list[13].sample = {5, 3, 3};
    scene_list[13].music_id = 3;
    scene_list[13].narration_id = 13;
    scene_list[13].options.push_back(Choice(23, "Continue", 25));

    scene_list[14].text = string("Hypno two");
    scene_list[14].number = 14;
    scene_list[14].sample = {11, 2, 3};
    scene_list[14].music_id = 5;
    scene_list[14].narration_id = 14;
    scene_list[14].options.push_back(Choice(15, "Continue", 25));

    scene_list[15].text = string("Complex plane");
    scene_list[15].number = 15;
    scene_list[15].sample = {11, 2, 3};
    scene_list[15].music_id = 6;
    scene_list[15].narration_id = 15;
    scene_list[15].options.push_back(Choice(19, "-5", 42));
    scene_list[15].options.push_back(Choice(19, "5z", 43));
    scene_list[15].options.push_back(Choice(20, "5i", 44));

    scene_list[16].text = string("Fox approach");
    scene_list[16].number = 16;
    scene_list[16].sample = {10, 3, 0};
    scene_list[16].music_id = 3;
    scene_list[16].narration_id = 16;
    scene_list[16].options.push_back(Choice(17, "Decapitate", 45));
    scene_list[16].options.push_back(Choice(18, "Stab belly", 46));

    scene_list[17].text = string("Chop fox");
    scene_list[17].number = 17;
    scene_list[17].sample = {12, 3, 1};
    scene_list[17].music_id = -1;
    scene_list[17].narration_id = 17;
    scene_list[17].options.push_back(Choice(23, "Continue", 25));

    scene_list[18].text = string("Stab fox");
    scene_list[18].number = 18;
    scene_list[18].sample = {9, 3, 1};
    scene_list[18].music_id = -2;
    scene_list[18].narration_id = 18;
    scene_list[18].options.push_back(Choice(24, "Continue", 25));

    scene_list[19].text = string("Fail test");
    scene_list[19].number = 19;
    scene_list[19].sample = {13, 3, 1};
    scene_list[19].music_id = -2;
    scene_list[19].narration_id = 19;
    scene_list[19].options.push_back(Choice(23, "Continue", 25));

    scene_list[20].text = string("Hermit");
    scene_list[20].number = 20;
    scene_list[20].sample = {14, 1, 1};
    scene_list[20].music_id = 7;
    scene_list[20].narration_id = 20;
    scene_list[20].options.push_back(Choice(21, "Attack", 47));
    scene_list[20].options.push_back(Choice(22, "Reason", 48));

    scene_list[21].text = string("Big mistake");
    scene_list[21].number = 21;
    scene_list[21].sample = {9, 2, 1};
    scene_list[21].music_id = 8;
    scene_list[21].narration_id = 21;
    scene_list[21].options.push_back(Choice(23, "Continue", 25));

    scene_list[22].text = string("Soup help");
    scene_list[22].number = 22;
    scene_list[22].sample = {15, 1, 3};
    scene_list[22].music_id = 7;
    scene_list[22].narration_id = 22;
    scene_list[22].options.push_back(Choice(24, "Continue", 26));

    scene_list[23].text = string("You lose");
    scene_list[23].number = 23;
    scene_list[23].sample = {16, 3, 1};
    scene_list[23].music_id = -2;
    scene_list[23].narration_id = 23;
    scene_list[23].options.push_back(Choice(0, "Back to start", 49));

    scene_list[24].text = string("You win");
    scene_list[24].number = 25;
    scene_list[24].sample = {17, 3, 1};
    scene_list[24].music_id = -2;
    scene_list[24].narration_id = 24;
    scene_list[24].options.push_back(Choice(0, "Back to start", 49));

    return scene_list;
}