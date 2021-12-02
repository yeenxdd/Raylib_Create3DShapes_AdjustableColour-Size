/*******************************************************************************************
*
*   raylib [core] example - Initialize 3d camera mode
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2014 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 550;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - 3d camera mode");

    //GUI controls initialization
    int width = 200;
    int height = 100;
    bool drawCube=false;
    bool drawSphere=false;
    bool drawCuboid=false;


    // Define the camera to look into our 3d world
    Camera3D camera = { 0 };
    camera.position = (Vector3){ 0.0f, 10.0f, 10.0f };  // Camera position
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };      // Camera looking at point
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
    camera.fovy = 45.0f;                                // Camera field-of-view Y
    camera.projection = CAMERA_PERSPECTIVE;             // Camera mode type

    //shapes size     
    float cubeSize = 2.0f;
    float sphereSize = 1.0f; //sphere radius, ring,slice
    Vector3 cuboidSize = {2.0f,3.0f,4.0f};
    
    //shapes position
    Vector3 cubePosition = { -3.0f, 0.0f, 0.0f };
    Vector3 spherePosition = { -3.0f, 0.0f, 0.0f };
    Vector3 cuboidPosition = { -3.0f, 0.0f, 0.0f };
    
    //shapes colour
    Color cubeColour = (Color){25,55,25,255};
    Color sphereColour=(Color){25,55,25,255};
    Color cuboidColour=(Color){25,55,25,255};

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
            ClearBackground(RAYWHITE);
            
            //Draw GUI controls
            drawCube=GuiCheckBox((Rectangle){ 640, 80, 20, 20 }, "Cube", drawCube);
            drawSphere=GuiCheckBox((Rectangle){ 640, 110, 20, 20 }, "Sphere", drawSphere);
            drawCuboid=GuiCheckBox((Rectangle){ 640, 140, 20, 20 }, "Cuboid", drawCuboid);
            
            cubeSize = GuiSliderBar((Rectangle){ 640, 180, 105, 20 }, "Cube Size", NULL, cubeSize, 0, 10);
            if(GuiButton( (Rectangle){ 640, 210, 120, 20 }, "Random Cube Colour" ))
                cubeColour = (Color){ GetRandomValue(0, 255), GetRandomValue(0, 255), GetRandomValue(0, 255), 255 };

            sphereSize=GuiSliderBar((Rectangle){ 640, 250, 105, 20 }, "Sphere Radius", NULL, sphereSize, 0.1f, 5.0f);
            if(GuiButton( (Rectangle){ 640, 280, 120, 20 }, "Random Sphere Colour" ))
                sphereColour = (Color){ GetRandomValue(0, 255), GetRandomValue(0, 255), GetRandomValue(0, 255), 255 };

            cuboidSize.x = GuiSliderBar((Rectangle){ 640, 320, 105, 20 }, "Cuboid Length", NULL, cuboidSize.x, 0, 10);
            cuboidSize.y = GuiSliderBar((Rectangle){ 640, 350, 105, 20 }, "Cuboid Height", NULL, cuboidSize.y, 0, 10);
            cuboidSize.z = GuiSliderBar((Rectangle){ 640, 380, 105, 20 }, "Cuboid Width", NULL, cuboidSize.z, 0, 10);
            if(GuiButton( (Rectangle){ 640, 420, 120, 20 }, "Random Cuboid Colour" ))
                cuboidColour = (Color){ GetRandomValue(0, 255), GetRandomValue(0, 255), GetRandomValue(0, 255), 255 };
            
            BeginMode3D(camera);
            
                
                if(drawCube){
                    DrawCube(cubePosition, cubeSize, cubeSize, cubeSize, cubeColour);
                    DrawCubeWires(cubePosition, cubeSize, cubeSize, cubeSize, BLACK);
                }
                
                if(drawSphere){
                    DrawSphere(spherePosition,sphereSize,sphereColour);
                    DrawSphereWires(spherePosition,sphereSize,sphereSize,sphereSize,BLACK);
                }
                
                if(drawCuboid){
                    DrawCube(cuboidPosition, cuboidSize.x, cuboidSize.y, cuboidSize.z, cuboidColour);
                    DrawCubeWires(cuboidPosition,cuboidSize.x, cuboidSize.y, cuboidSize.z, BLACK);
                }

                //DrawGrid(10, 1.0f);
                

            EndMode3D();

            DrawText("Welcome to the third dimension!", 10, 40, 20, DARKGRAY);

            DrawFPS(10, 10);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}