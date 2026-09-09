// headers

#include "ui.h"

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

    if (ImGui::BeginMainMenuBar())
		{
			if (ImGui::BeginMenu("File"))
			{
				ImGui::EndMenu();
            }

			if (ImGui::BeginMenu("Window"))
            {
                ImGui::EndMenu();
            }
			ImGui::EndMainMenuBar();
		}

		// show some windows
	
		if (ImGui::Begin("Test Window"))
		{
			ImGui::TextUnformatted("Another window");
		}

	ImGui::End();
}