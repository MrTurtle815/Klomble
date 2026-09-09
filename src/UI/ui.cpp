// headers

#include "../Application/application.h"
#include "ui.h"

// utils

#include <stdio.h>

void initImGui()
{
    rlImGuiSetup(true);

    #ifdef IMGUI_HAS_DOCK
        ImGui::GetIO().ConfigFlags |= ImGuiConfigFlags_DockingEnable;
    #endif
}

void drawUi()
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
        ImGui::Text("Brick");
	}

	ImGui::End();
}