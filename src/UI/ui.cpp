// headers

#include "../Application/application.h"
#include "../Scene/scene.h"
#include "ui.h"

// utils

#include <stdio.h>
#include <vector>
#include <string>

void initImGui()
{
    rlImGuiSetup(true);

    #ifdef IMGUI_HAS_DOCK
        ImGui::GetIO().ConfigFlags |= ImGuiConfigFlags_DockingEnable;
    #endif
}

void drawUi(World& world)
{
    #ifdef IMGUI_HAS_DOCK
		ImGui::DockSpaceOverViewport(0,  NULL, ImGuiDockNodeFlags_PassthruCentralNode);
    #endif

    if(ImGui::BeginMainMenuBar())
    {
        if(ImGui::BeginMenu("File"))
        {           
            if (ImGui::MenuItem("Klomble"))
            {
                printf("weeeeee");
            }

            if (ImGui::MenuItem("Quit"))
            {
                
            }
            ImGui::EndMenu();
        }

        ImGui::EndMainMenuBar();
    }
	
	if (ImGui::Begin("Explorer"))
	{
        for (auto& brick : world.getBricks())
        {
            const char* idString = std::to_string(brick->identification).c_str();
            ImGui::MenuItem(idString);
        }
	}

	ImGui::End();
}